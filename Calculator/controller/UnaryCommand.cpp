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

#include "UnaryCommand.h"
#include"Exception.h"
#include"Stack.h"
namespace controller
{
	void UnaryCommand::checkPreCondition() const
	{
		if (model::Stack::getInstance().size() < 1)
			throw utility::Exception("The Model Stack must have at least one element!");
	}
	void UnaryCommand::executeImpl()noexcept
	{
		m_state = model::Stack::getInstance().pop(true);
		model::Stack::getInstance().push(unaryOperation(m_state),true);
	}
	void UnaryCommand::undoImpl()noexcept
	{
		model::Stack::getInstance().pop(true);
		model::Stack::getInstance().push(m_state);
	}
}