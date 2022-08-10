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
#ifndef GRAPHICAL_USER_INTERFACE_CONTROLLER_H
#define GRAPHICAL_USER_INTERFACE_CONTROLLER_H
#include<Windows.h>
#include<string>
#include"Publisher.h"
#include"Resource.h"
#include"GraphicalUserInterfaceModel.h"
//#include"Dispatcher.h"  i need a broker 
using std::string;

namespace view
{
	// this hold all the User Interface widgets...
	// the user interface take two distinct inputs from the user: numbers and commands.

	// this class pass the command to the Dispatcher
	class GraphicalUserInterfaceController : public utility::Publisher
	{
	public:
		// Event raised by this class
		static const string enterPressed;
		static const string characterEntered;
		static const string backspacePressed;
		static const string plusMinusPressed;
		static const string shiftPressed;
		
		// the Graphical User Interface Model must subscribe to this event
		static const string commandEntered;
	public:
		GraphicalUserInterfaceController(GraphicalUserInterfaceModel& m,HWND parent);
		~GraphicalUserInterfaceController();
		static LRESULT CALLBACK WindowControllerProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	public:
		using utility::Publisher::subscribe;
		using utility::Publisher::unsubscribe;
	private:
		HWND m_parent;
		HWND btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9;
		HWND btnPlus, btnMinus,btnSubstract, btnMultiply, btnDivide, btnPlusMinus, btnComma;
		HWND btnCosine, btnSine, btnTangent, btnPower, btnExp;
		HWND btnEnter, btnShift, btnBackspace;
		HWND btnUndo, btnRedo, btnProc;
		HWND lblArcosine, lblArcsine,lblArctan,lblSwap,lblClear;

		static GraphicalUserInterfaceModel& m_model;
	};
}
#endif // !GRAPHICAL_USER_INTERFACE_CONTROLLER_H


