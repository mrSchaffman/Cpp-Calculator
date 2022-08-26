#pragma once
#ifndef DISPLAY_H
#define DISPLAY_H
#include"GuiModel.h"

namespace view
{
	LRESULT CALLBACK DisplayProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	// the View of The View Subsystem
	class Display
	{

	public:
		Display(const GuiModel& g)
			:model{ g },
			hwndDisplay{ NULL },
			hwndStatusBar{ NULL },
			hwndLabelShiftIndicator{ NULL },
			nLinesStack{ 0 },
			nCharWide{ 0 },
			ID{ 0 }
		{};
		HRESULT Create(HWND parent, int nID, int nLinesStack = 6, int minCharWide = 25);
		HWND getWindow() const { return hwndDisplay; }

	public:
		void onModelChanged();
		void onSize();

	private:
		string createLine(int lineNumber, double value, int stackSize);

	private:
		const GuiModel& model;

		HWND hwndDisplay;
		HWND hwndStatusBar;
		HWND hwndLabelShiftIndicator;
		int nLinesStack;
		int nCharWide;
		int ID;
	};

}
#endif // !DISPLAY_H


