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
#ifndef COSINE_COMMAND_H
#define COSINE_COMMAND_H
#include"UnaryCommand.h"
namespace controller
{
	class CosineCommand : public UnaryCommand
	{
	public:
		CosineCommand() = default;
		~CosineCommand() = default;
		explicit CosineCommand(const CosineCommand&cmd):UnaryCommand(cmd){}

		double unaryOperation(double d)noexcept override { return std::cos(d); }

	private:
		CosineCommand*cloneImpl()const noexcept override { return new CosineCommand{ *this }; }
		const char* getHelpImpl() noexceptoverride
		{ 
			return "Replace the top must elemet with it cosine: cos(x). x must be in radian!"; 
		}

	private:
		CosineCommand(CosineCommand&&) = delete;
		CosineCommand& operator=(const CosineCommand&) = delete;
		CosineCommand& operator=(CosineCommand&&) = delete;
	};
}
#endif // !COSINE_COMMAND_H


