#include "MainWindow.h"
#include"CommandButton.h"

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
		{
			Rect rc{ 5,100,250,245 };

			GuiModel Model{ m_hwnd };
			gid[GUI_MODEL] = Model.getWindow();

			Display displayWin{ Model };


			HRESULT hr1 = displayWin.Create(m_hwnd, DISPLAY);
			gid[DISPLAY] = displayWin.getWindow();

			HRESULT hr = inptWin.Create(m_hwnd, INPUT_WIDGET, rc);
			//gid[INPUT_WIDGET] = inptWin.getWindow();

		}
			return 0;
		case WM_COMMAND:
		{
			switch (LOWORD(wParam))
			{

			case IDM_EXIT:
				PostQuitMessage(0);
				break;
			default:
				break;
			}
		}
			break;
		case CALCM_SHIFT_PRESSED:
		{
			printf("Shift_button press!");
			//gid[GUI_MODEL].onShift();
		}break;
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

	void MainWindow::OnPaint()
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(m_hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(m_hwnd, &ps);

	}

}
