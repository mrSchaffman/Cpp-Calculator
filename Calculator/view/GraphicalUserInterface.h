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


#ifndef GRAPHICAL_USER_INTERFACE_H
#define GRAPHICAL_USER_INTERFACE_H
#include<Windows.h>
#include<memory>
#include"UserInterface.h"
namespace view
{
	// This is the Class to run in the main in order to obtain a Window on the Screen. win32 API
	class GraphicalUserInterface : public UserInterface
	{
	public:
		GraphicalUserInterface(HINSTANCE hInstance, int nCmdShow);
		~GraphicalUserInterface();
		//bool run();
	private:
		// not needed to be publicly visible... inherited from the UserInterface base Class.
		void onStackChanged()override;
		void updateDisplay(const std::string& msg) override;

	private:
		class GraphicalUserInterfaceImpl;
		std::unique_ptr<GraphicalUserInterfaceImpl> pImpl;
	};
}
#endif // !GRAPHICAL_USER_INTERFACE_H


