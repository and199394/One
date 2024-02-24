#include "checkbox.h"

HWND createCheckBox( HWND m_hwnd, const int &id )
{
    HWND hwnd = CreateWindowEx(
                0,
                L"BUTTON",
                L"OK",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_CHECKBOX,
                120,         // x position 
                10,          // y position 
                100,         // Button width
                50,         // Button height
                m_hwnd,       // Parent window
                (HMENU)id,       // No menu.
                (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE), 
                NULL        // Pointer not needed.
            );
    return hwnd;
}