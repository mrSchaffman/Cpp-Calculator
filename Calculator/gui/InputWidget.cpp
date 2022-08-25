#include "InputWidget.h"

namespace view
{
	map<size_t, HWND>InputWidget::iGid = {};
	HWND m_hwnd = NULL;
	CommandButton bt0;
	CommandButton bt1;
	CommandButton bt2;
	CommandButton bt3;
	CommandButton bt4;
	CommandButton bt5;
	CommandButton bt6;
	CommandButton bt7;
	CommandButton bt8;
	CommandButton bt9;
	CommandButton btUndo;
	CommandButton btRedo;
	CommandButton btProc;
	CommandButton btPlus;
	CommandButton btMinus;
	CommandButton btDivide;
	CommandButton btMulti;
	CommandButton btPlusMinus;
	CommandButton btComma;
	CommandButton btEnter;
	CommandButton btCos;
	CommandButton btSin;
	CommandButton btTan;
	CommandButton btPow;
	CommandButton btBksp;
	CommandButton btEex;
	CommandButton btShift;

	//UINT InputWidget::uCharacterEnteredMsg =0;
	//UINT InputWidget::uCommandEnteredMsg=0;
	//UINT InputWidget::uEnterPressedMsg=0;
	//UINT InputWidget::uProcedurePressedMsg=0;
	//UINT InputWidget::uShiftPressedMsg=0;
	//UINT InputWidget::uPlusMinusMsg=0;

	LRESULT InputWidget::InputWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		// L 1
		static 	Rect rU{ 5,5,BTN_WIDTH,BTN_HEIGH };
		static 	Rect rR{ BTN_WIDTH + 5,5,BTN_WIDTH,BTN_HEIGH };
		static 	Rect rP{ 2 * (BTN_WIDTH )+5,5,BTN_WIDTH,BTN_HEIGH };

		// L 2
		static 	Rect r4{ 5,BTN_HEIGH + 5,BTN_WIDTH,BTN_HEIGH };
		static 	Rect r5{ BTN_WIDTH + 5,BTN_HEIGH + 5,BTN_WIDTH,BTN_HEIGH };
		static 	Rect r6{ 2 * (BTN_WIDTH )+5,BTN_HEIGH + 5,BTN_WIDTH,BTN_HEIGH };
		static 	Rect r7{ 3 * (BTN_WIDTH )+5,BTN_HEIGH + 5,BTN_WIDTH,BTN_HEIGH };

		// L 3
		static 	Rect r8{ 5,2 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r9{ BTN_WIDTH + 5,2 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r10{ 2 * (BTN_WIDTH )+5,2 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r11{ 3 * (BTN_WIDTH )+5,2 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };

		// L 4
		static 	Rect r12{ 5,3 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r13{ BTN_WIDTH + 5,3 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r14{ 2 * (BTN_WIDTH )+5,3 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r15{ 3 * (BTN_WIDTH )+5,3 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };

		// L 5
		static 	Rect r16{ 5,4 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r17{ BTN_WIDTH + 5,4 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r18{ 2 * (BTN_WIDTH )+5,4 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r19{ 3 * (BTN_WIDTH)+5,4 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };

		// L 6
		static 	Rect r20{ 5,5 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r21{ BTN_WIDTH + 5,5 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r22{ 2 * (BTN_WIDTH )+5,5 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r23{ 3 * (BTN_WIDTH )+5,5 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };

		// L 7
		static 	Rect r24{ 5,6 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r25{ BTN_WIDTH + 5,6 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r26{ 2 * (BTN_WIDTH) + 5,6 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };
		static 	Rect r27{ 3 * (BTN_WIDTH) + 5,6 * (BTN_HEIGH + 5),BTN_WIDTH,BTN_HEIGH };


		switch (uMsg)
		{
		case WM_NCDESTROY:
			SetWindowLongPtr(hwnd, GWLP_USERDATA, 0);
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		case WM_CREATE:
		{
			//uPlusMinusMsg = RegisterWindowMessage(L"Plus Minus Pressed");
			//uShiftPressedMsg = RegisterWindowMessage(L"Shift Pressed");
			//uProcedurePressedMsg = RegisterWindowMessage(L"Procedure Pressed");
			//uEnterPressedMsg = RegisterWindowMessage(L"Enter Pressed");
			//uCommandEnteredMsg = RegisterWindowMessage(L"Command Pressed");
			//CM_CHARACTE_ENTERED = RegisterWindowMessage(L"Character Pressed");

			HRESULT hr1 = btUndo.Create(hwnd, L"Undo", BTN_UNDO, rU);
			HRESULT hr2 = btRedo.Create(hwnd, L"Redo", BTN_REDO, rR);
			HRESULT hr3 = btProc.Create(hwnd, L"Proc", BTN_PROC, rP);

			HRESULT hr4 = btSin.Create(hwnd, L"Sin", BTN_SIN, r4);
			HRESULT hr5 = btCos.Create(hwnd, L"Cos", BTN_COS, r5);
			HRESULT hr6 = btTan.Create(hwnd, L"Tan", BTN_TAN, r6);
			HRESULT hr7 = btPow.Create(hwnd, L"Pow", BTN_POW, r7);

			HRESULT hr8 = btEnter.Create(hwnd, L"Enter", BTN_ENTER, r8);
			HRESULT hr9 = btEex.Create(hwnd, L"Eex", BTN_EEX, r9);
			HRESULT hr10 = btBksp.Create(hwnd, L"Bksp", BTN_BKSP, r10);
			HRESULT hr11 = btShift.Create(hwnd, L"Shift", BTN_SHIFT, r11);

			HRESULT hr12 = bt7.Create(hwnd, L"7", BTN_7, r12);
			HRESULT hr13 = bt8.Create(hwnd, L"8", BTN_8, r13);
			HRESULT hr14 = bt9.Create(hwnd, L"9", BTN_9, r14);
			HRESULT hr15 = btDivide.Create(hwnd, L"/", BTN_DIVIDE, r15);

			HRESULT hr16 = bt4.Create(hwnd, L"4", BTN_4, r16);
			HRESULT hr17 = bt5.Create(hwnd, L"5", BTN_5, r17);
			HRESULT hr18 = bt6.Create(hwnd, L"6", BTN_6, r18);
			HRESULT hr19 = btMulti.Create(hwnd, L"*", BTN_MULTI, r19);

			HRESULT hr20 = bt1.Create(hwnd, L"1", BTN_1, r20);
			HRESULT hr21 = bt2.Create(hwnd, L"2", BTN_2, r21);
			HRESULT hr22 = bt3.Create(hwnd, L"3", BTN_3, r22);
			HRESULT hr23 = btMinus.Create(hwnd, L"-", BTN_MINUS, r23);

			HRESULT hr24 = bt0.Create(hwnd, L"0", BTN_0, r24);
			HRESULT hr25 = btComma.Create(hwnd, L".", BTN_COMMA, r25);
			HRESULT hr26 = btPlusMinus.Create(hwnd, L"+/-", BTN_PLUS_MINUS, r26);
			HRESULT hr27 = btPlus.Create(hwnd, L"+", BTN_PLUS, r27);

			iGid[BTN_0] = bt0.getWindow();
			iGid[BTN_1] = bt1.getWindow();
			iGid[BTN_2] = bt2.getWindow();
			iGid[BTN_3] = bt3.getWindow();
			iGid[BTN_4] = bt4.getWindow();
			iGid[BTN_5] = bt5.getWindow();
			iGid[BTN_6] = bt6.getWindow();
			iGid[BTN_7] = bt7.getWindow();
			iGid[BTN_8] = bt8.getWindow();
			iGid[BTN_9] = bt9.getWindow();

			iGid[BTN_COMMA] = btComma.getWindow();
			iGid[BTN_PLUS_MINUS] = btPlusMinus.getWindow();
			iGid[BTN_PLUS] = btPlus.getWindow();
			iGid[BTN_MINUS] = btMinus.getWindow();
			iGid[BTN_MULTI] = btMulti.getWindow();
			iGid[BTN_DIVIDE] = btDivide.getWindow();

			iGid[BTN_SHIFT] = btShift.getWindow();
			iGid[BTN_BKSP] = btBksp.getWindow();
			iGid[BTN_EEX] = btEex.getWindow();
			iGid[BTN_ENTER] = btEnter.getWindow();
			iGid[BTN_POW] = btPow.getWindow();
			iGid[BTN_TAN] = btTan.getWindow();
			iGid[BTN_SIN] = btSin.getWindow();
			iGid[BTN_COS] = btCos.getWindow();

			iGid[BTN_UNDO] = btUndo.getWindow();
			iGid[BTN_REDO] = btRedo.getWindow();
			iGid[BTN_PROC] = btProc.getWindow();


		}
			return 0;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{

			case BTN_0:
				onZero();
				break;
			case BTN_1:
				onOne();
				break;
			case BTN_2:
				onTwo();
				break;
			case BTN_3:
				onThree();
				break;
			case BTN_4:
				onFour();
				break;
			case BTN_5:
				onFive();
				break;
			case BTN_6:
				onSix();
				break;
			case BTN_7:
				onSeven();
				break;
			case BTN_8:
				onEight();
				break;
			case BTN_9:
				onNine();
				break;
			case BTN_SHIFT:
				shiftPressed();
				break;
			default:
				break;
			}
		}
		break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}

	}

	HRESULT InputWidget::Create(HWND hParent, int nID, const Rect& rcBound)
	{
		WNDCLASSEX wcex;
		ZeroMemory(&wcex, sizeof(WNDCLASSEX));

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = InputWindowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = (HINSTANCE)GetModuleHandle(NULL);
		wcex.hIcon = NULL;
		wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_APPWORKSPACE + 1);
		wcex.lpszMenuName = NULL;
		wcex.lpszClassName = L"inputWidget";
		wcex.hIconSm = NULL;

		ATOM atom = RegisterClassEx(&wcex);

		if (atom == 0)
		{
			return __HRESULT_FROM_WIN32(GetLastError());
		}
		else
		{
			CREATESTRUCT create;
			ZeroMemory(&create, sizeof(CREATESTRUCT));

			create.x = rcBound.left;
			create.y = rcBound.top;
			create.cx = rcBound.right;// -create.x;
			create.cy = rcBound.bottom;// -create.y;

			create.hwndParent = hParent;
			create.hMenu = (HMENU)(INT_PTR)nID;
			create.lpszClass = wcex.lpszClassName;
			create.style = WS_CHILDWINDOW | WS_CLIPCHILDREN;

			if (m_hwnd != NULL)
			{
				// The control was already created.
				return E_FAIL;
			}

			if (create.hwndParent == NULL)
			{
				return E_INVALIDARG;
			}

			HINSTANCE hinst = create.hInstance;

			if (hinst == NULL)
			{
				hinst = GetInstance();
			}

			if (hinst == NULL)
			{
				return E_INVALIDARG;
			}


			HWND hwnd = CreateWindowEx(
				create.dwExStyle,
				create.lpszClass,
				create.lpszName,
				create.style | WS_CHILD | WS_VISIBLE,
				create.x, create.y,
				create.cx, create.cy,
				create.hwndParent,
				create.hMenu,
				hinst,
				create.lpCreateParams
			);

			if (hwnd == 0)
			{
				return __HRESULT_FROM_WIN32(GetLastError());
			}

			m_hwnd = hwnd;
			return S_OK;
		}


	}


	void InputWidget::shiftPressed()
	{
		SendMessage(GetParent(m_hwnd), CALCM_SHIFT_PRESSED, 0, 0);
	}

	void InputWidget::allocateButtons()
	{
	}

	void InputWidget::setupShortcuts()
	{
	}

	void InputWidget::makeConnections()
	{
	}

	void InputWidget::layoutButtons()
	{
		CommandButton bt;
		Rect rc{ 5,5,50,50 };
		HRESULT hr = bt.Create(m_hwnd, L"Proc", BTN_PROC, rc);


	}

	void InputWidget::onEex()
	{
	}

	void InputWidget::onDecimal()
	{
	}

	void InputWidget::onPlusMinus()
	{
	}

	void InputWidget::onZero()
	{
		HWND destWind = FindWindow(TEXT("GuiModel"), L"GuiModel");
		//if (destWind)
		//	//SendMessage(destWind, CALCM_CHARACTE_ENTERED, '0', 0);
	}

	void InputWidget::onOne()
	{
	}

	void InputWidget::onTwo()
	{
	}

	void InputWidget::onThree()
	{
	}

	void InputWidget::onFour()
	{
	}

	void InputWidget::onFive()
	{
	}

	void InputWidget::onSix()
	{
	}

	void InputWidget::onSeven()
	{
	}

	void InputWidget::onEight()
	{
	}

	void InputWidget::onNine()
	{
	}

}
