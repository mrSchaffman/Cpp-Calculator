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
#ifndef STACK_EVENT_DATA_H
#define STACK_EVENT_DATA
#include"EventData.h"
namespace model
{

	class StackEventData : public utility::EventData
	{
	public:
		enum ErrorType
		{
			TOO_FEW_ARGUMENT,
			EMPTY,
		};

		StackEventData(ErrorType e) : err{ e } {}
		const char* getMessage()const { return getMessage(err); }

		// usefull for the Exeption
		static const char* getMessage(ErrorType er)
		{
			switch (er)
			{
			case model::StackEventData::TOO_FEW_ARGUMENT:
				return "Stack must have at least two elements!";
			case model::StackEventData::EMPTY:
				return "Attempting to pop empty Stack!";
			default:
				return "";
			}
		}
		ErrorType getErrorType()const { return err; }

	private:
		ErrorType err;

	};
}
#endif // !STACK_EVENT_DATA_H


