#include "GuiModel.h"
#include <utility>
using std::pair;

namespace view
{
	GuiModel::GuiModel(HWND p) : parent{p},guiModelHandle{NULL}
	{
		WNDCLASSEX winC;
		ZeroMemory(&winC, sizeof(WNDCLASSEX));

		winC.cbSize = sizeof(WNDCLASSEX);
		winC.lpszClassName = TEXT("GuiModel");
		winC.lpfnWndProc = GuiModelProc;
		winC.hInstance = GetModuleHandle(NULL);
		RegisterClassEx(&winC);

		guiModelHandle = CreateWindowEx(
			0,
			winC.lpszClassName,
			L"Gui Model",
			WS_CHILD,
			0, 0, 0, 0,
			p,
			NULL,
			winC.hInstance,
			NULL
		);
	}
	void GuiModel::stackChanged(const vector<double>& v)
	{
		m_state.currentStack = v;
		//SendMessage(parent, CALCM_MODEL_CHANGED, 0, 0);
	}
	const GuiModel::State& GuiModel::getState() const
	{
		return m_state;
	}
	void GuiModel::clearInput() const
	{
		//m_state.currentInput.{""};
		//SendMessage(parent, CALCM_MODEL_CHANGED, 0, 0);
	}
	void GuiModel::onShift()
	{
		m_state.filter == Filter::SHIFTED ? 
			Filter::UNSHIFTED 
				: Filter::SHIFTED;
		SendMessage(parent, CALCM_MODEL_CHANGED, 0, 0);
	}
	void GuiModel::onEnter()
	{
		if (m_state.currentInput.empty())
			onCommandEntered("dup", "swap");
		else 
		{
			clearInput();
			onCommandEntered(m_state.currentInput, "");
		}
	}
	void GuiModel::onCharactedEntered(char c)
	{
		m_state.currentInput += c;
		//SendMessage(parent, CALCM_MODEL_CHANGED, 0, 0);
	}
	void GuiModel::onBackspace()
	{
		if (m_state.currentInput.size() > 0)
		{
			m_state.currentInput = m_state.currentInput.substr(0, m_state.currentInput.size() - 1);
			//SendMessage(parent, CALCM_MODEL_CHANGED, 0, 0);
		}
		else
			onCommandEntered("drop", "clear");

	}
	void GuiModel::onPlusMinus()
	{
		if (m_state.currentInput.empty())
		{
			onCommandEntered("neg", "");
			return;
		}
		auto pos = m_state.currentInput.find('e');

		// +/- changes sign for whole number if before exponent
		// or exponent if after e
		if (pos == string::npos)
		{
			if (!m_state.currentInput.empty() && m_state.currentInput[0] == '-')
				m_state.currentInput = m_state.currentInput.substr(1, m_state.currentInput.length() - 1);
			else
				m_state.currentInput = '-' + m_state.currentInput;
		}
		else
		{
			auto left = m_state.currentInput.substr(0, pos + 1);
			auto right = m_state.currentInput.substr(pos + 1, m_state.currentInput.size() - pos);
			auto halves =  std::make_pair(left, right);

			if (m_state.currentInput.size() > pos && m_state.currentInput[pos + 1] == '-')
			{
				m_state.currentInput = halves.first + halves.second.substr(1, halves.second.length() - 1);
			}
			else
			{
				m_state.currentInput = halves.first + '-' + halves.second;
			}
		}
		//SendMessage(parent, CALCM_MODEL_CHANGED, 0, 0);
	}
	void GuiModel::onCommandEntered(string primaryCmd, string secondaryCmd)
	{
	}
	LRESULT CALLBACK GuiModelProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		//case CALCM_CHARACTE_ENTERED:
		//	GuiModel::onCharactedEntered(char(wParam));
			break;
		default:
			DefWindowProc(hwnd, msg, wParam, lParam);
			break;
		}
		return E_NOTIMPL;
	}
}