#pragma once
/*
	Copyright (C) 2022  Barth.Feudong
	Author can be contacted here: <https://github.com/mrSchaffman/Cpp-Calculator>

	This file is part of the Calculator project.
	using the COM, the win32 API for the GUI,
	the MVC Architecture.

	Calculator is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Calculator is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#ifndef COMMAND_H
#define COMMAND_H
#include<memory>
using std::unique_ptr;
using std::shared_ptr;

namespace controller
{
	// Command Pattern
	// abstract Command Class
	class Command
	{
	public:
		virtual~Command() = default;
		void execute() 
		{ 
			checkPreCondition();
			executeImpl();
			checkPostCondition();
		}
		void undo() { undoImpl(); }
		const char* getHelp() { return getHelpImpl(); }

		// prototype pattern
		Command*clone()const { return cloneImpl(); }

		virtual void release() { delete this; }
	protected:
		// to be use by the subclasses
		Command() = default;
		Command(const Command&) = default;

	private:
		virtual void executeImpl()=0;
		virtual void undoImpl() = 0;
		virtual Command*cloneImpl()const = 0;
		virtual const char* getHelpImpl() = 0;

		// concrete command shoul override this function if needed.
		virtual void checkPreCondition()const {}
		virtual void checkPostCondition()const {}

	private:
		// uneeded
		Command(Command&&) = delete;
		Command& operator=(const Command&) = delete;
		Command& operator=(Command&&) = delete;
	};

	// helper
	inline void commandDeleter(Command*p) { p->release(); }
	using CommandPtr = unique_ptr<Command, decltype(&commandDeleter)>;
	inline auto make_command_ptr(Command* p) { return CommandPtr{ p, &commandDeleter }; }
	
	template<typename T, typename...Args>
	auto make_command_ptr(Args&&...args) 
	{ 
		return CommandPtr{ 
			new T{std::forward<Args>(args)...}, 
			&commandDeleter 
		}; 
	} // auto ptr = make_command_ptr<UserCommand>(a, b,c,g);

}
#endif // !COMMAND_H


