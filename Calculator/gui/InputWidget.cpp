#include "InputWidget.h"

namespace view
{
	map<size_t, HWND>InputWidget::gid = {};

	LRESULT InputWidget::InputWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_NCDESTROY:
			SetWindowLongPtr(hwnd, GWLP_USERDATA, 0);
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		case WM_CREATE:
		{
			CommandButton bt;
			Rect rc{ 5,5,50,50 };
			HRESULT hr = bt.Create(hwnd, L"Proc", BTN_PROC, rc);
			//layoutButtons();

			CommandButton bt2;
			Rect rc2 = { 65,5,50,50 };
			HRESULT hr2 = bt2.Create(hwnd, L"Undo", BTN_UNDO, rc2);

		}
			return 0;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{

			case BTN_UNDO:
			{
				printf("Undo_button press!");
			}break;
			case BTN_PROC:
			{
				printf("proc_button press!");
			}break;
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

			return S_OK;
		}


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

}
