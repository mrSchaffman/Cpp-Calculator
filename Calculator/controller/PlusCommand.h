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

#ifndef PLUS_COMMAND_H
#define PLUS_COMMAND_H
#include"BinaryCommand.h"
namespace controller
{
	class PlusCommand : public BinaryCommand
	{
	public:
		PlusCommand() = default;
		~PlusCommand() = default;
		explicit PlusCommand(const PlusCommand&cmd):BinaryCommand(cmd){}
	private:
		double binaryOperation(double d1, double d2)noexcept { return d1 + d2; }
		PlusCommand*cloneImpl()const noexcept override { return new PlusCommand{ *this }; }
		const char* getHelpImpl() noexcept override{ return "Add the top must numbers on the stack!"; }

	};
}
#endif // !PLUS_COMMAND_H


