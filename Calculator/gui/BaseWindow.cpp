#include "BaseWindow.h"
#include "utils.h"
namespace view
{

	BaseWindow::BaseWindow() : m_hwnd(NULL), m_hInstance(NULL)
	{
	}

	HRESULT BaseWindow::Register()
	{
		WNDCLASSEX wcex;

		wcex.cbSize = sizeof(WNDCLASSEX);

		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.lpfnWndProc = WindowProc;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hInstance = m_hInstance;
		wcex.hIcon = NULL;
		wcex.hCursor =  LoadCursor(NULL, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(COLOR_DESKTOP + 1);
		wcex.lpszMenuName = MenuName();
		wcex.lpszClassName = ClassName();
		wcex.hIconSm = NULL;

		ATOM atom = RegisterClassEx(&wcex);

		if (atom == 0)
		{
			return __HRESULT_FROM_WIN32(GetLastError());
		}
		else
		{
			return S_OK;
		}
	}

	HRESULT BaseWindow::Create(HINSTANCE hInstance)
	{
		m_hInstance = hInstance;

		HRESULT hr = Register();
		if (SUCCEEDED(hr))
		{
			HWND hwnd = CreateWindowEx(
				0,
				ClassName(),
				WindowName(),
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT, 0, 
				725, 300,
				NULL,
				NULL,
				m_hInstance,
				this			// taking itself as data.
			);

			if (hwnd == 0)
			{
				hr = __HRESULT_FROM_WIN32(GetLastError());
			}
		}

		return hr;
	}

	HRESULT BaseWindow::Show(int nCmdShow)
	{
		ShowWindow(m_hwnd, nCmdShow);
		UpdateWindow(m_hwnd);
		return S_OK;
	}

	LRESULT CALLBACK BaseWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		BaseWindow* pWin = NULL;

		if (uMsg == WM_NCCREATE)
		{
			// When we create the window, we pass in a pointer to this class 
			// as part of the CREATESTRUCT structure.
			LPCREATESTRUCT lpcs = (LPCREATESTRUCT)lParam;
			pWin = (BaseWindow*)lpcs->lpCreateParams;

			// Set the window handle.
			pWin->m_hwnd = hwnd;

			// Set the pointer to the class as user data.

			_SetWindowLongPtr(hwnd, GWLP_USERDATA, pWin);
		}
		else
		{
			// Get the pointer to the class.
			pWin = _GetWindowLongPtr<BaseWindow*>(hwnd, GWLP_USERDATA);
		}

		if (pWin)
		{
			return pWin->OnReceiveMessage(uMsg, wParam, lParam);
		}
		else
		{
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}

}
