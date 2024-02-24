#include "radiobutton.h"

void createRadioButton( HWND m_hwnd )
{   
    int id1 = 111, id2 = 112;
    HWND hwnd = CreateWindowEx(
        0,
        L"BUTTON",
        L"RB1",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_GROUP | WS_EX_WINDOWEDGE,
        120,          // x position 
        120,          // y position 
        50,           // Button width
        50,          // Button height
        m_hwnd,       // Parent window
        (HMENU)id1,    // No menu.
        (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE), 
        NULL          // Pointer not needed.
    );

    CreateWindowEx(
        0,
        L"BUTTON",
        L"RB2",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_AUTORADIOBUTTON | WS_EX_WINDOWEDGE,
        180,          // x position 
        120,          // y position 
        50,          // Button width
        50,          // Button height
        m_hwnd,       // Parent window
        (HMENU)id2,    // No menu.
        (HINSTANCE)GetWindowLongPtr(m_hwnd, GWLP_HINSTANCE), 
        NULL          // Pointer not needed.
    );

    SendMessage(hwnd, BM_SETCHECK, BST_CHECKED, NULL );
}