#include "MainWindow.h"
#include"CommandButton.h"

namespace view
{
	gid_map mainGuiId{};
	//GuiModel model;

	LRESULT MainWindow::OnReceiveMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		switch (uMsg)
		{
		case WM_NCDESTROY:
			SetWindowLongPtr(m_hwnd, GWLP_USERDATA, 0);
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		case WM_CREATE:
		{
			mainGuiId[MAIN_WINDOW] = m_hwnd;

			Rect rc{ 5,100,250,245 };

			GuiModel Model{ m_hwnd };
			mainGuiId[GUI_MODEL] = Model.getWindow();

			Display displayWin{ Model };

			HRESULT hr1 = displayWin.Create(m_hwnd, DISPLAY);
			mainGuiId[DISPLAY] = displayWin.getWindow();

			HRESULT hr = inptWin.Create(m_hwnd, INPUT_WIDGET, rc);
			mainGuiId[INPUT_WIDGET] = inptWin.getWindow();

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
		case CALCM_CHARACTER_ENTERED:
		{
			printf("character button press!");
			char v = (char)wParam;
			//gid[GUI_MODEL].onShift();
		}break;
		case CALCM_COMMAND_ENTERED:
		{
			printf("command button press!");
			const TCHAR* v = (TCHAR*)wParam;
			// ::raise(UserInterface::CommandEntered, std::make_shared<CommandData>(cmd));
		}break;
		case CALCM_ENTER_PRESSED:
		{
			printf("Enter button press!");
			const TCHAR* v = (TCHAR*)wParam;
			//gid[GUI_MODEL].onShift();
		}break;
		case CALCM_PROCEDURE_PRESSED:
		{
			printf("Enter button press!");
			//const TCHAR* v = (TCHAR*)wParam;
			//gid[GUI_MODEL].onShift();
		}break;
		case CALCM_PLUS_MINUS_PRESSED:
		{
			printf("+/- button press!");
			//const TCHAR* v = (TCHAR*)wParam;
			//gid[GUI_MODEL].onShift();
		}break;
		case CALCM_BACKSPACE_ENTERED:
		{
			printf("BKSP button press!");
			//const TCHAR* v = (TCHAR*)wParam;
			//gid[GUI_MODEL].onShift();
		}break;
		case CALCM_MODEL_CHANGED:
		{
			printf("send by the Gui model...!");
			//const TCHAR* v = (TCHAR*)wParam;
			SendMessage(mainGuiId[DISPLAY], CALCM_MODEL_CHANGED, wParam, 0);

			//gid[DISPLAY].onModelChanged();
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

	void MainWindow::OnCreate()
	{
	}

	void MainWindow::OnPaint()
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(m_hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(m_hwnd, &ps);

	}

}
