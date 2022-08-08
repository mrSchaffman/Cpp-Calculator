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
#ifndef POWER_COMMAND_H
#define POWER_COMMAND_H
#include"BinaryCommand.h"
namespace controller
{
	class PowerCommand : public BinaryCommand
	{
	public:
		PowerCommand() = default;
		~PowerCommand() = default;
		explicit PowerCommand(const PowerCommand&cmd) :BinaryCommand(cmd) {}

		double binaryOperation(double d1,double d2)noexcept override { return std::pow(d1,d2); }

	private:
		PowerCommand*cloneImpl()const noexcept override { return new PowerCommand{ *this }; }
		const char* getHelpImpl() noexcept override
		{
			return "Replace the top must elemet with the power: x^y !";
		}

	private:
		PowerCommand(PowerCommand&&) = delete;
		PowerCommand& operator=(const PowerCommand&) = delete;
		PowerCommand& operator=(PowerCommand&&) = delete;
	};

}
#endif // !POWER_COMMAND_H

