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
#include"UnaryCommand.h"
#include"Stack.h"
namespace controller
{
	class EnterNumberCommand : public UnaryCommand
	{
	public:
		EnterNumberCommand() = default;
		~EnterNumberCommand() = default;
		explicit EnterNumberCommand(const EnterNumberCommand&cmd) :UnaryCommand(cmd) {}

		double unaryOperation(double d)noexcept override { return std::tan(d); }

	private:
		void undoImpl()override { model::Stack::getInstance().pop(true); }
		Command*cloneImpl()const override { return new EnterNumberCommand{ *this }; }
		const char* getHelpImpl() override
		{
			return "Press enter to execute one operation!";
		}

	private:
		EnterNumberCommand(EnterNumberCommand&&) = delete;
		EnterNumberCommand& operator=(const EnterNumberCommand&) = delete;
		EnterNumberCommand& operator=(EnterNumberCommand&&) = delete;
	};

}
#endif // !ENTER_NUMBER_COMMAND_H

