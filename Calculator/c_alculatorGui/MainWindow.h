#pragma once

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include"BaseWindow.h"
#include"Resource.h"
#include"InputWidget.h"
#include<map>

using std::map;


#ifndef UNICODE
#define UNICODE
#endif // !UNICODE

#define MAX_BYTE 256
typedef map<size_t, HWND> gid_map;

namespace view
{
	//enum ID
	//{
	//	EDIT_DISPLAY = 300,
	//	BTN_0,
	//	BTN_1,
	//	BTN_2,
	//	BTN_3,
	//	BTN_4,
	//	BTN_5,
	//	BTN_6,
	//	BTN_7,
	//	BTN_8,
	//	BTN_9,
	//	BTN_COMMA,
	//	BTN_PLUS_MINUS,
	//	BTN_PLUS,
	//	BTN_MINUS,
	//	BTN_MULTI,
	//	BTN_DIVIDE,
	//	BTN_SHIFT,
	//	BTN_BKSP,
	//	BTN_EEX,
	//	BTN_ENTER,
	//	BTN_POW,
	//	BTN_TAN,
	//	BTN_COS,
	//	BTN_SIN,
	//	BTN_UNDO,
	//	BTN_REDO,
	//	BTN_PROC,
	//	LABEL_ASIN,
	//	LABEL_ACOS,
	//	LABEL_ATAN,
	//	LABEL_ROOT,
	//	LABEL_CLEAR,
	//	LABEL_SWAP,
	//};
	class MainWindow : public BaseWindow
	{
	public:

	private:
		LRESULT OnReceiveMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) override;
		LPCTSTR  ClassName() const override { return L"Main Window Class"; }
		LPCTSTR WindowName() const override { return L"Calculator"; }
		LPCTSTR MenuName() const override{ return MAKEINTRESOURCE(IDC_APP_MENU); }

		void OnCreate();
		void OnPaint() override;
	private:
		static map<size_t, HWND>gid;
	};
}
#endif // !MAIN_WINDOW_H


