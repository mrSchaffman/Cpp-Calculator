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

#ifndef COMMAND_REPOSITORY_H
#define COMMAND_REPOSITORY_H

#include"Command.h"
#include<string>
#include<set>

using std::string;
using std::set;

namespace controller
{
	class CommandRegistry
	{
	public:
		static CommandRegistry& getInstance();
		void addCommand(const string name, CommandPtr cmd);
		CommandPtr removeCommand(const string name);

		size_t count();
		CommandPtr getCommandByName(const string& name)const;
		set<string>& getAllCommandNames()const;
	private:
		CommandRegistry();			// { pImpl = std::make_unique<CommandRegistry>(); }
		~CommandRegistry();

		class CommandRegistryImpl;
		std::unique_ptr< CommandRegistryImpl> pImpl;

	private:
		// not needed
		CommandRegistry(CommandRegistry&) = delete;
		CommandRegistry(CommandRegistry&&) = delete;
		CommandRegistry& operator=(CommandRegistry&) = delete;
		CommandRegistry& operator=(CommandRegistry&&) = delete;

	};
}
#endif // !COMMAND_REPOSITORY_H


