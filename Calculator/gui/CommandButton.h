#pragma once
/*
	Copyright (C) 2022  Barth.Feudong
	Author can be contacted here: <https://github.com/mrSchaffman/Cpp-Calculator>

	This file is part of the Calculator project.
	using the COM, the win32 API for the GUI,
	the MVC Architecture.

	Calculator is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Calculator is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#ifndef COMMAND_BUTTON_H
#define COMMAND_BUTTON_H
#include"Control.h"
#include<assert.h>
class CommandButton: public Control
{
public:
    CommandButton() : m_hwnd(0) {}
    HRESULT Create(HWND hParent, const TCHAR* szCaption, int nID, const Rect& rcBound);

    void SetWindow(HWND hwnd) { m_hwnd = hwnd; }
    HWND Window() const { return m_hwnd; }

    void Enable(BOOL bEnable)
    {
        if (!bEnable && m_hwnd == GetFocus())
        {
            // If we're being disabled and this control has focus,
            // set the focus to the next control.

            ::SendMessage(GetParent(m_hwnd), WM_NEXTDLGCTL, 0, FALSE);
        }

        EnableWindow(m_hwnd, bEnable);
    }

    LRESULT SendMessage(UINT msg, WPARAM wParam, LPARAM lParam) const
    {
        assert(m_hwnd);
        return ::SendMessage(m_hwnd, msg, wParam, lParam);
    }

    bool HasStyle(LONG style) const
    {
        return (GetWindowLong(m_hwnd, GWL_STYLE) & style) == style;
    }

    LONG AddStyle(LONG style)
    {
        LONG old_style = GetWindowLong(m_hwnd, GWL_STYLE);
        return SetWindowLong(m_hwnd, GWL_STYLE, old_style | style);
    }

    LONG RemoveStyle(LONG style)
    {
        LONG old_style = GetWindowLong(m_hwnd, GWL_STYLE);
        old_style = old_style & (~style);
        return SetWindowLong(m_hwnd, GWL_STYLE, old_style);
    }

    LONG EnableStyle(bool bEnable, LONG style)
    {
        return (bEnable ? AddStyle(style) : RemoveStyle(style));
    }

	void SetCheck(int nCheck)
	{
		SendMessage(BM_SETCHECK, (WPARAM)nCheck, 0L);
		//SendMessage(BM_CLICK, (WPARAM)nCheck, 0L);
	}

	BOOL IsChecked()
	{
		return SendMessage(BM_GETCHECK, 0, 0) == BST_CHECKED;
	}

private:
    HWND m_hwnd;

};

// CreateStruct: Thin wrapper for CREATESTRUCT structure.
class CreateStruct : public CREATESTRUCT
{
public:
    CreateStruct();
    void SetBoundingRect(const Rect& rc);
};


HINSTANCE	GetInstance();
HBITMAP		SetBitmapImg(HINSTANCE hinst, WORD nID, HWND hwnd);

#endif // !COMMAND_BUTTON_H


