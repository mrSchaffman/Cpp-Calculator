#include "MainWindow.h"

namespace view
{
	map<size_t, HWND>MainWindow::gid = {};

	LRESULT MainWindow::OnReceiveMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_NCDESTROY:
			SetWindowLongPtr(m_hwnd, GWLP_USERDATA, 0);
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		case WM_CREATE:
			OnCreate();
			return 0;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{

			case BTN_UNDO:
			{
				printf("Undo_button press!");
			}break;
			case IDM_REGISTER:
			{

			}break;
			case IDM_UNREGISTER:
			{

			}break;
			case IDM_EXIT:
				PostQuitMessage(0);
				break;
			default:
				break;
			}
		}
		break;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		case WM_PAINT:
			OnPaint();
			return 0;
		default:
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		}
		return TRUE;
	}

	void MainWindow::OnCreate()
	{
		gid[EDIT_DISPLAY] = CreateWindowEx(
			0,
			L"EDIT",
			L"1:\n2:\n3:\n4:\n5:\n6:",
			WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_READONLY,
			5, 5,
			215, 100,
			m_hwnd,
			(HMENU)(EDIT_DISPLAY),
			m_hInstance,
			NULL
		);
		gid[BTN_UNDO] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Undo",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE | BS_FLAT,
			5, 115,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_UNDO),
			m_hInstance,
			NULL
		);

		gid[BTN_REDO] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Redo",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 115,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_REDO),
			m_hInstance,
			NULL
		);

		gid[BTN_PROC] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Proc",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 115,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_PROC),
			m_hInstance,
			NULL
		);

		gid[LABEL_ASIN] = CreateWindowEx(
			0,
			L"STATIC",
			L"asin",
			WS_CHILD | WS_VISIBLE | BS_TEXT | SS_CENTER,
			5, 180,
			50, 20,
			m_hwnd,
			(HMENU)(LABEL_ASIN),
			m_hInstance,
			NULL
		);

		gid[LABEL_ACOS] = CreateWindowEx(
			0,
			L"STATIC",
			L"acos",
			WS_CHILD | WS_VISIBLE | BS_TEXT | SS_CENTER,
			60, 180,
			50, 20,
			m_hwnd,
			(HMENU)(LABEL_ASIN),
			m_hInstance,
			NULL
		);

		gid[LABEL_ATAN] = CreateWindowEx(
			0,
			L"STATIC",
			L"atan",
			WS_CHILD | WS_VISIBLE | BS_TEXT | SS_CENTER,
			115, 180,
			50, 20,
			m_hwnd,
			(HMENU)(LABEL_ATAN),
			m_hInstance,
			NULL
		);
		gid[LABEL_ROOT] = CreateWindowEx(
			0,
			L"STATIC",
			L"root",
			WS_CHILD | WS_VISIBLE | BS_TEXT | SS_CENTER,
			170, 180,
			50, 20,
			m_hwnd,
			(HMENU)(LABEL_ROOT),
			m_hInstance,
			NULL
		);

		gid[BTN_SIN] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Sin",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 200,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_SIN),
			m_hInstance,
			NULL
		);
		gid[BTN_COS] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Cos",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 200,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_COS),
			m_hInstance,
			NULL
		);

		gid[BTN_TAN] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Tan",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 200,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_TAN),
			m_hInstance,
			NULL
		);

		gid[BTN_POW] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Pow",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			170, 200,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_POW),
			m_hInstance,
			NULL
		);

		gid[LABEL_SWAP] = CreateWindowEx(
			0,
			L"STATIC",
			L"Swap",
			WS_CHILD | WS_VISIBLE | BS_TEXT | SS_CENTER,
			5, 235,
			50, 20,
			m_hwnd,
			(HMENU)(LABEL_SWAP),
			m_hInstance,
			NULL
		);

		gid[LABEL_ATAN] = CreateWindowEx(
			0,
			L"STATIC",
			L"Clear",
			WS_CHILD | WS_VISIBLE | BS_TEXT | SS_CENTER,
			115, 235,
			50, 20,
			m_hwnd,
			(HMENU)(LABEL_ATAN),
			m_hInstance,
			NULL
		);

		gid[BTN_SIN] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Enter",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 255,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_SIN),
			m_hInstance,
			NULL
		);

		gid[BTN_EEX] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Eex",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 255,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_EEX),
			m_hInstance,
			NULL
		);

		gid[BTN_BKSP] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Bksp",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 255,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_BKSP),
			m_hInstance,
			NULL
		);

		gid[BTN_SHIFT] = CreateWindowEx(
			0,
			L"BUTTON",
			L"Shift",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			170, 255,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_SHIFT),
			m_hInstance,
			NULL
		);
		gid[BTN_7] = CreateWindowEx(
			0,
			L"BUTTON",
			L"7",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 290,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_7),
			m_hInstance,
			NULL
		);

		gid[BTN_8] = CreateWindowEx(
			0,
			L"BUTTON",
			L"8",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 290,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_8),
			m_hInstance,
			NULL
		);

		gid[BTN_9] = CreateWindowEx(
			0,
			L"BUTTON",
			L"9",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 290,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_9),
			m_hInstance,
			NULL
		);

		gid[BTN_SHIFT] = CreateWindowEx(
			0,
			L"BUTTON",
			L"/",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			170, 290,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_SHIFT),
			m_hInstance,
			NULL
		);
		gid[BTN_4] = CreateWindowEx(
			0,
			L"BUTTON",
			L"4",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 325,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_4),
			m_hInstance,
			NULL
		);

		gid[BTN_5] = CreateWindowEx(
			0,
			L"BUTTON",
			L"5",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 325,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_5),
			m_hInstance,
			NULL
		);

		gid[BTN_6] = CreateWindowEx(
			0,
			L"BUTTON",
			L"6",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 325,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_6),
			m_hInstance,
			NULL
		);

		gid[BTN_MULTI] = CreateWindowEx(
			0,
			L"BUTTON",
			L"*",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			170, 325,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_MULTI),
			m_hInstance,
			NULL
		);
		gid[BTN_1] = CreateWindowEx(
			0,
			L"BUTTON",
			L"1",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 360,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_1),
			m_hInstance,
			NULL
		);

		gid[BTN_2] = CreateWindowEx(
			0,
			L"BUTTON",
			L"2",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 360,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_2),
			m_hInstance,
			NULL
		);

		gid[BTN_3] = CreateWindowEx(
			0,
			L"BUTTON",
			L"3",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 360,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_3),
			m_hInstance,
			NULL
		);

		gid[BTN_MINUS] = CreateWindowEx(
			0,
			L"BUTTON",
			L"-",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			170, 360,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_MINUS),
			m_hInstance,
			NULL
		);
		gid[BTN_0] = CreateWindowEx(
			0,
			L"BUTTON",
			L"0",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			5, 395,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_0),
			m_hInstance,
			NULL
		);

		gid[BTN_COMMA] = CreateWindowEx(
			0,
			L"BUTTON",
			L".",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			60, 395,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_COMMA),
			m_hInstance,
			NULL
		);

		gid[BTN_PLUS_MINUS] = CreateWindowEx(
			0,
			L"BUTTON",
			L"+/-",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			115, 395,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_PLUS_MINUS),
			m_hInstance,
			NULL
		);

		gid[BTN_PLUS] = CreateWindowEx(
			0,
			L"BUTTON",
			L"+",
			WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
			170, 395,
			50, 30,
			m_hwnd,
			(HMENU)(BTN_PLUS),
			m_hInstance,
			NULL
		);

	}

	void MainWindow::OnPaint()
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(m_hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(m_hwnd, &ps);

	}

}
