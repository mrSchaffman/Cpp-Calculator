#include"MainWindow.h"
#pragma comment(linker,"\"/manifestdependency:type='win32' \
	name='Microsoft.Windows.Common-Controls' version='6.0.0.0' \
	processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")

using namespace view;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPInstance, PWSTR pCmdLine, int nCmdShow)
{
	MainWindow win;

	if (FAILED(win.Create(hInstance)))
	{
		return 0;
	}

	win.Show(nCmdShow);

	MSG message = {};
	while (GetMessage(&message, NULL, 0, 0) > 0)
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}


	return 0;
}
