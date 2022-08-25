#include "Display.h"
namespace view
{
	HRESULT Display::Create(HWND parent, int nID, int nLinesStack, int minCharWide)
	{
		//WNDCLASSEX cs;
		//ZeroMemory(&cs, sizeof(WNDCLASSEX));

		//cs.cbSize = sizeof(WNDCLASSEX);
		//cs.lpszClassName = TEXT("STATIC");
		//cs.lpfnWndProc = DisplayProc;
		//cs.hInstance = GetModuleHandle(NULL);
		//RegisterClassEx(&cs);

		if (hwndDisplay != NULL) return E_FAIL;
		if (parent == NULL) return E_INVALIDARG;

		HWND hwnd = CreateWindowEx(
			0,
			TEXT("STATIC"),
			L"6:",
			WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS,
			5, 5,
			250, 90,
			parent,
			(HMENU)(INT_PTR)nID,
			GetModuleHandle(NULL),
			NULL
		);
		if (hwndDisplay == 0)
			return __HRESULT_FROM_WIN32(GetLastError());

		hwndDisplay= hwnd;
		return S_OK;

	}
	void Display::onModelChanged()
	{
	}
	void Display::onSize()
	{
	}
	string Display::createLine(int lineNumber, double value, int stackSize)
	{
		return string();
	}
	LRESULT CALLBACK DisplayProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
			//case CALCM_MODEL_CHANGED:
			//	gid[DISPLAY].onModelChanged(char(wParam));
			return 0;
		default:
			DefWindowProc(hwnd, msg, wParam, lParam);
			break;
		}
	}

}