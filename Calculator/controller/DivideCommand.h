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

#ifndef DIVIDE_COMMAND_H
#define DIVIDE_COMMAND_H
#include"BinaryCommand.h"
#include"Stack.h"
#include"Exception.h"
namespace controller
{
	class DivideCommand : public BinaryCommand
	{
	public:
		DivideCommand() = default;
		~DivideCommand() = default;
		explicit DivideCommand(const DivideCommand&cmd) :BinaryCommand(cmd) {}
	private:
		void checkPreCondition()const
		{
			if (model::Stack::getInstance().top() == 0)
				throw utility::Exception("The top most number must be != 0.0 ");
		}
		double binaryOperation(double d1, double d2)noexcept { return d1 / d2; }
		DivideCommand*cloneImpl()const noexcept override { return new DivideCommand{ *this }; }
		const char* getHelpImpl()const noexcept override{ return "Divide the next top element by the top most numbers on the stack!"; }
	};
}
#endif // !DIVIDE_COMMAND_H


