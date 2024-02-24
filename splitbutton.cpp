#include "splitbutton.h"

HWND createSplitButton( HWND m_hwnd, const int &id )
{
    return  CreateWindowEx(
                0,
                L"BUTTON",
                L"OK",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_SPLITBUTTON, //BS_PUSHBUTTON, BS_SPLITBUTTON, BS_DEFSPLITBUTTON
                10,         // x position 
                120,         // y position 
                100,        // Button width
                50,        // Button height
                m_hwnd,       // Parent window
                (HMENU)id,       // No menu.
                (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE), 
                NULL        // Pointer not needed.
            );
}