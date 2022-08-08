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

#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include"Publisher.h"
namespace view
{
	class UserInterface : public utility::Publisher
	{
	public:
		// event raised by this class
		static const std::string commandEntered;
	public:
		using utility::Publisher::subscribe;
		using utility::Publisher::unsubscribe;

		UserInterface() { registerEvent(commandEntered); }
		virtual ~UserInterface() = default;

		virtual void onStackChanged() = 0;
		virtual void updateDisplay(const std::string& msg) = 0;

	private:

	};
}
#endif // !USER_INTERFACE_H


