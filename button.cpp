#include "button.h"

HWND createButton( HWND m_hwnd, const int &id )
{
    return  CreateWindowEx(
                0,
                L"BUTTON",
                L"TESTING",
                WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON | WS_EX_WINDOWEDGE, //BS_PUSHBUTTON, BS_SPLITBUTTON, BS_DEFSPLITBUTTON
                10,         // x position 
                10,         // y position 
                100,        // Button width
                50,        // Button height
                m_hwnd,       // Parent window
                (HMENU)id,       // No menu.
                (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE), 
                NULL        // Pointer not needed.
            );
}