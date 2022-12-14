#include "CommandButton.h"
HRESULT CommandButton::Create(HWND hParent, const TCHAR* szCaption, int nID, const Rect& rcBound)
{
    CREATESTRUCT create;
    ZeroMemory(&create, sizeof(CREATESTRUCT));

    create.x = rcBound.left;
    create.y = rcBound.top;
    create.cx = rcBound.right - create.x;
    create.cy = rcBound.bottom - create.y;

    create.hwndParent = hParent;
    create.lpszName = szCaption;
    create.hMenu = (HMENU)(INT_PTR)nID;
    create.lpszClass = TEXT("BUTTON");
    create.style = BS_PUSHBUTTON | BS_FLAT;

    if (m_hwnd != NULL)
    {
        // The control was already created.
        return E_FAIL;
    }

    if (create.hwndParent == NULL)
    {
        return E_INVALIDARG;
    }

    HINSTANCE hinst = create.hInstance;

    if (hinst == NULL)
    {
        hinst = GetInstance();
    }

    if (hinst == NULL)
    {
        return E_INVALIDARG;
    }


    HWND hwnd = CreateWindowEx(
        create.dwExStyle, create.lpszClass, create.lpszName,
        create.style | WS_CHILD | WS_VISIBLE,
        create.x, create.y, create.cx, create.cy, create.hwndParent, create.hMenu,
        hinst, create.lpCreateParams);

    if (hwnd == 0)
    {
        return __HRESULT_FROM_WIN32(GetLastError());
    }

    SetWindow(hwnd);
    return S_OK;

}

CreateStruct::CreateStruct()
{
    ZeroMemory(this, sizeof(*this));
}

void CreateStruct::SetBoundingRect(const Rect& rc)
{
    x = rc.left;
    y = rc.top;
    cx = rc.right - x;
    cy = rc.bottom - y;
}
