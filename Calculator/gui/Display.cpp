#include "Display.h"
#include<ostream>
#include<string>

using std::ostringstream;

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

		hwndDisplay = hwnd;
		return S_OK;

	}
	void Display::onModelChanged()
	{
		const GuiModel::State& state = model.getState();
		if (state.filter == GuiModel::Filter::SHIFTED)
		{
			//shiftIndicator_->show();
		}
		//else shiftIndicator_->hide();

		//ostringstream oss;
		//auto hasInput = state.curInput.size() != 0;
		//auto start = nLinesStack_ - (hasInput ? 1 : 0);

		//for (int i = start - 1; i > -1; --i)
		//{
		//	bool valueExists = i < static_cast<int>(state.curStack.size());
		//	oss << createLine(i, (valueExists ? state.curStack[i] : 0 /*dummy value*/), state.curStack.size()) << (i != 0 ? "\n" : "");
		//}

		//if (hasInput)
		//{
		//	oss << "\n"
		//		<< state.curInput;
		//}

		//label_->setText(QString::fromStdString(oss.str()));

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
		case CALCM_MODEL_CHANGED:
		{
			//const GuiModel::State& state = model.getState();
			//if (state.filter == GuiModel::Filter::SHIFTED)
			//{
			//	//shiftIndicator_->show();
			//}
			//else shiftIndicator_->hide();

			//ostringstream oss;
			//auto hasInput = state.curInput.size() != 0;
			//auto start = nLinesStack_ - (hasInput ? 1 : 0);

			//for (int i = start - 1; i > -1; --i)
			//{
			//	bool valueExists = i < static_cast<int>(state.curStack.size());
			//	oss << createLine(i, (valueExists ? state.curStack[i] : 0 /*dummy value*/), state.curStack.size()) << (i != 0 ? "\n" : "");
			//}

			//if (hasInput)
			//{
			//	oss << "\n"
			//		<< state.curInput;
			//}

			//label_->setText(QString::fromStdString(oss.str()));

		}
		return 0;
		default:
			DefWindowProc(hwnd, msg, wParam, lParam);
			break;
		}
	}

}