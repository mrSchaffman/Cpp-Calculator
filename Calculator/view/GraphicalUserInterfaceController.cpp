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

#include "GraphicalUserInterfaceController.h"
namespace view
{
	GraphicalUserInterfaceController::GraphicalUserInterfaceController(GraphicalUserInterfaceModel& m,HWND parent): m_parent{parent}
	{

	}
	GraphicalUserInterfaceController::~GraphicalUserInterfaceController()
	{
	}
	LRESULT GraphicalUserInterfaceController::WindowControllerProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{
			case IDC_BT0:
			case IDC_BT1:
			case IDC_BT2:
			case IDC_BT3:
			case IDC_BT4:
			case IDC_BT5:
			case IDC_BT6:
			case IDC_BT7:
			case IDC_BT8:
			case IDC_BT9:
			{
				// to do
				m_model.onCharacterEntered('v');
			}break;
			case IDC_BT_ENTER:
			{

				m_model.onEnter();
			}break;
			case IDC_BT_SHIFT:
				m_model.onShift();
				break;
			case IDC_BT_BACKSPACE:
				m_model.onBackspace();
					break;
			case IDC_BT_PLUS:
			case IDC_BT_MINUS:
			case IDC_BT_PLUS_MINUS:
			case IDC_BT_DIV:
			case IDC_BT_MULTI:
			case IDC_BT_EXP:
			case IDC_BT_POWER:
			case IDC_BT_UNDO:
			case IDC_BT_REDO:
			case IDC_BT_PROCEDURE:
			case IDC_BT_COMMA:
			case IDC_BT_COS:
			case IDC_BT_SIN:
			case IDC_BT_TAN:
			{
				// get the string
				// to do
				m_model.onCommandEntered("", "");
			}
			default:
				break;
			}
		}break;
		default:
			DefWindowProc(hwnd,uMsg,wParam,lParam);
		}
		return LRESULT();
	}
}