#include <windows.h>
#include <commctrl.h>
#include <strsafe.h>

#define IDENTIF_LIST 1
#define IDENTIF_STATIC 2

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);       // prototype

typedef struct {
    wchar_t resource[30];
    wchar_t login[20];
    wchar_t passw[20];
} cData;

cData data[] = {
    {L"Mail.ru", L"test@mail.ru", L"test1"},        // now as a RAW data, for testing purposes
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR pCmdLine, int nCmdShow) {
    MSG  msg;
    WNDCLASSW wc = { 0 };
    wc.lpszClassName = L"clWND";
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_SCROLLBAR + 1);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);

    // main window creation call
    CreateWindowW(wc.lpszClassName, L"PasswNote [v1.0]",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 430, 200, 0, 0, hInstance, 0);

    // msg.wParam handler (https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getmessage)
    while (GetMessage(&msg, NULL, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}


// handle signals from api-elements
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    static HWND hwndList, hwndStatic;
    wchar_t buf[128];

    switch (msg) {

    // On first time window create (https://docs.microsoft.com/en-us/windows/win32/winmsg/wm-create)
    case WM_CREATE:

        hwndList = CreateWindowW(WC_LISTBOXW, NULL, WS_CHILD
            | WS_VISIBLE | LBS_NOTIFY, 10, 10, 150, 120, hwnd,
            (HMENU)IDENTIF_LIST, NULL, NULL);

        hwndStatic = CreateWindowW(WC_STATICW, NULL, WS_CHILD | WS_VISIBLE,
            200, 10, 200, 45, hwnd, (HMENU)IDENTIF_STATIC, NULL, NULL);

        // send message by lparam (https://docs.microsoft.com/en-us/windows/win32/controls/lb-addstring) to hwndList window [list of web-resources]
        for (int i = 0; i < ARRAYSIZE(data); i++) {
            SendMessageW(hwndList, LB_ADDSTRING, 0, (LPARAM)data[i].resource);
        }

        break;

    case WM_COMMAND:

        // catch signal about selector changes in hwndList (https://docs.microsoft.com/en-us/windows/win32/controls/lbn-selchange)
        if (LOWORD(wParam) == IDENTIF_LIST) {
            if (HIWORD(wParam) == LBN_SELCHANGE) {
                int sel = (int)SendMessageW(hwndList, LB_GETCURSEL, 0, 0);
                StringCbPrintfW(buf, ARRAYSIZE(buf), L"Login: %s\nPassw: %s",
                    data[sel].login, data[sel].passw);
                SetWindowTextW(hwndStatic, buf);
            }
        }

        break;

    // cross click handle
    case WM_DESTROY:

        PostQuitMessage(0);
        break;
    }

    return (DefWindowProcW(hwnd, msg, wParam, lParam));
}