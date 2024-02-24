#ifndef UNICODE
#define UNICODE
#endif

#define IDC_BUTTON (100)
#define IDC_SPLITBUTTON (101)
#define IDC_CHECKBOX (102)
#define IDC_GROUPBOX (103)
#define IDC_RADIOBUTTON (104)

#include <Windows.h>
#include <vector>
#include <string>
#include <Commctrl.h>
#include <OAIdl.h>
#include "button.h"
#include "splitbutton.h"
#include "checkbox.h"
#include "radiobutton.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


class WinClass{
    public:
        WinClass( HINSTANCE hInstance, const wchar_t className[], const wchar_t titleName[], int x, int y, int w, int h, int nCmdShow ){
            wc = { };
            wc.lpfnWndProc   = WindowProc;
            wc.hInstance     = hInstance;
            wc.lpszClassName = className;

            RegisterClass(&wc);

            hwnd = CreateWindowEx(
                0,
                className,    // Window class
                titleName,    // Window text
                WS_OVERLAPPEDWINDOW | WS_EX_WINDOWEDGE,            // Window style

                // Size and position
                CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

                NULL,       // Parent window    
                NULL,       // Menu
                hInstance,  // Instance handle
                this        // Additional application data
            );

            this->nCmdShow = nCmdShow;
        }

        ~WinClass(){
            DestroyWindow(hwnd);
        }

        LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
        };

        void display(){
            ShowWindow(hwnd, nCmdShow);
        }

    private:
        WNDCLASS wc;
        HWND hwnd; 
        int nCmdShow = NULL;           
};

int WINAPI wWinMain(HINSTANCE hInstance, 
                    HINSTANCE hPrevInstance,
                    PWSTR pCmdLine, int nCmdShow)
{

    WinClass wcl( hInstance, L"Test", L"Test", 10, 10, 100, 200, nCmdShow ) ;
    wcl.display();

    // int i = 100;

    // // Register the window class.
    // const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    // WNDCLASS wc = { };

    // wc.lpfnWndProc   = WindowProc;
    // wc.hInstance     = hInstance;
    // wc.lpszClassName = CLASS_NAME;

    // RegisterClass(&wc);

    // // Create the window.

    // HWND hwnd = CreateWindowEx(
    //     0,                              // Optional window styles.
    //     CLASS_NAME,                     // Window class
    //     L"Learn to Program Windows",    // Window text
    //     WS_OVERLAPPEDWINDOW | WS_EX_WINDOWEDGE,            // Window style

    //     // Size and position
    //     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

    //     NULL,       // Parent window    
    //     NULL,       // Menu
    //     hInstance,  // Instance handle
    //     NULL        // Additional application data
    //     );

    // if (hwnd == NULL)
    // {   
    //     return 0;
    // }


    // HWND hButton = createButton( hwnd, IDC_BUTTON );
    // if (hButton == NULL)
    // {
    //     return 0;
    // }

    // HWND hSplitButton = createSplitButton( hwnd, IDC_SPLITBUTTON );
    // if (hSplitButton == NULL)
    // {   
    //     return 0;
    // }

    // HWND hCheckbox = createCheckBox( hwnd, IDC_CHECKBOX );
    // if (hCheckbox == NULL)
    // {   
    //     return 0;
    // }

    // createRadioButton( hwnd );
    

    // HWND hGroupbox = CreateWindowEx(
    //     0,
    //     L"BUTTON",
    //     L"OK",
    //     WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_GROUPBOX,
    //     10,         // x position 
    //     110,        // y position 
    //     100,        // Button width
    //     100,        // Button height
    //     hwnd,       // Parent window
    //     (HMENU)IDC_GROUPBOX,       // No menu.
    //     (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), 
    //     NULL        // Pointer not needed.
    // );
    // if (hGroupbox == NULL)
    // {   
    //     return 0;
    // }

    // ShowWindow(hwnd, nCmdShow);

    // UpdateWindow(hwnd);
    // Run the message loop.

    MSG msg = { };

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

BOOL bInit = false;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_INITDIALOG:
        {

        }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    case WM_CLOSE:
        {
            if (MessageBox(hwnd, L"Really quit?", L"My application", MB_OKCANCEL) == IDOK)
                DestroyWindow(hwnd);            
        }
        return 0;
    case WM_EXITSIZEMOVE:
        {
            // Invalidate();
        }
    case WM_PAINT:
        {   
            if (!bInit)
            {
                RECT  rect;
                // PAINTSTRUCT ps;
                // HDC hdc = BeginPaint(hwnd, &ps);

                // All painting occurs here, between BeginPaint and EndPaint.
                
                // GetClientRect(hwnd, &rect);
                // SetTextColor(hdc, RGB(0xFF, 0x00, 0x00));
                // SetBkMode(hdc, TRANSPARENT);
                // rect.left = 40;
                // rect.top = 10;
                // DrawText(hdc, L"Hello World!", -1, &rect, DT_SINGLELINE | DT_NOCLIP);            
                // EndPaint(hwnd, &ps);

                PAINTSTRUCT ps2;
                HDC hdc2 = BeginPaint(hwnd, &ps2);
                hdc2 = BeginPaint(hwnd, &ps2);
                FillRect(hdc2, &ps2.rcPaint, (HBRUSH) (COLOR_WINDOW));
                EndPaint(hwnd, &ps2);
            }else{
                UpdateWindow(hwnd);
            }

        }
        return 0;

    case WM_LBUTTONDOWN:
        {
            if (LOWORD(wParam) == (WORD)hwnd)
            {
                std::vector<wchar_t> pathBuf; 
                
                DWORD copied = 0;
                do {
                    pathBuf.resize(pathBuf.size()+MAX_PATH);
                    copied = GetModuleFileName(0, &pathBuf.at(0), pathBuf.size());
                } while( copied >= pathBuf.size() );

                pathBuf.resize(copied);

                std::wstring path(pathBuf.begin(),pathBuf.end());

                MessageBox(hwnd, path.c_str( ), L"This program is:", MB_OK | MB_ICONINFORMATION );
            }
        }
        return 0;

    case WM_COMMAND:
        {
            if (LOWORD(wParam) == IDC_BUTTON) {
                MessageBox(hwnd, L"Testing Button", L"This program is:", MB_OK | MB_ICONINFORMATION );
            }
            else if (LOWORD(wParam) == IDC_CHECKBOX){
                if (IsDlgButtonChecked(hwnd, IDC_CHECKBOX))
                {
                    CheckDlgButton( hwnd, IDC_CHECKBOX, BST_UNCHECKED);
                }else{
                    CheckDlgButton( hwnd, IDC_CHECKBOX, BST_CHECKED);
                }
            }
            return 0;
        }

    case WM_KEYDOWN:
        {
            if(wParam == L'F')
            {
                SetWindowText( hwnd, L"Respect");
            }
        }
        return 0;

    case WM_KEYUP:
        {
            if(wParam == L'G')
            {
                SetWindowText( hwnd, L"Reset");
            }
        }
        return 0;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
   
}