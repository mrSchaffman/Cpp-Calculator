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

#include "Display.h"

namespace view
{
	Display::Display(GraphicalUserInterfaceModel & m, HWND p, int nLinesStack, int minCharWide)
		: Observer{"Display"},
		model{m},
		parent{p}
	{
		CreateWindowEx(
			0,
			"EDIT",
			"Display",
			WS_CHILD | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			parent,
			NULL,
			GetModuleHandle(NULL),
			NULL
		);

		
	}
	void Display::updateStatusBar(const std::string & msg)
	{
	}
	void Display::notifyImpl(std::shared_ptr<utility::EventData>data)
	{
		// 1- Pull the data 
		// 2- diplay the data
		// 3- updateStatus();
	}
}