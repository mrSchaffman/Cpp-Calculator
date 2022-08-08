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
#ifndef ENTER_NUMBER_COMMAND_H
#define ENTER_NUMBER_COMMAND_H
#include"Command.h"
#include"Stack.h"
namespace controller
{
	class EnterNumberCommand : public Command
	{
	public:
		~EnterNumberCommand() = default;
		explicit EnterNumberCommand(double d) :Command{}, m_number{ d }{}
		explicit EnterNumberCommand(const EnterNumberCommand&cmd) :Command(cmd), m_number{cmd.m_number}{}

	private:
		void undoImpl() noexcept override { model::Stack::getInstance().pop(true); }
		EnterNumberCommand*cloneImpl()const noexcept override { return new EnterNumberCommand{ *this }; }
		const char* getHelpImpl()const noexcept override
		{
			return "Press enter to execute one operation!";
		}
		virtual void executeImpl()noexcept { model::Stack::getInstance().push(m_number); }

		double m_number;

	private:
		EnterNumberCommand(EnterNumberCommand&&) = delete;
		EnterNumberCommand& operator=(const EnterNumberCommand&) = delete;
		EnterNumberCommand& operator=(EnterNumberCommand&&) = delete;
	};

}
#endif // !ENTER_NUMBER_COMMAND_H

