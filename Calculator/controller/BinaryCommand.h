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

#ifndef BINARY_COMMAND_H
#define BINARY_COMMAND_H
#include"Command.h"
namespace controller
{
	class BinaryCommand : public Command
	{
	public:
		BinaryCommand(const BinaryCommand&cmd) :Command(cmd), m_state1{ cmd.m_state1 },m_state2{ cmd.m_state2 }{}
		virtual~BinaryCommand() = default;
	protected:
		virtual void checkPreCondition()const;
		virtual void checkPostCondition()const {}

	private:		// unary operation
		virtual double binaryOperation(double,double)noexcept = 0;
	private:		// inherited from Command base class
		virtual void executeImpl()override;
		virtual void undoImpl()override;

	private:
		double m_state1;
		double m_state2;

	};
}
#endif // !BINARY_COMMAND_H


