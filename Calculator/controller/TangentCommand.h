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
#ifndef TANGENT_COMMAND_H
#define TANGENT_COMMAND_H
#include"UnaryCommand.h"
namespace controller
{
	class TangentCommand : public UnaryCommand
	{
	public:
		TangentCommand() = default;
		~TangentCommand() = default;
		explicit TangentCommand(const TangentCommand&cmd) :UnaryCommand(cmd) {}

		double unaryOperation(double d)noexcept override { return std::tan(d); }

	private:
		Command*cloneImpl()const override { return new TangentCommand{ *this }; }
		const char* getHelpImpl() override
		{
			return "Replace the top must elemet with it cosine: tan(x). x must be in radian!";
		}

	private:
		TangentCommand(TangentCommand&&) = delete;
		TangentCommand& operator=(const TangentCommand&) = delete;
		TangentCommand& operator=(TangentCommand&&) = delete;
	};

}
#endif // !TANGENT_COMMAND_H

