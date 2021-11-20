#define no_init_all deprecated
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <commctrl.h>
#include <strsafe.h>
#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include "InitConsole.h"

#define IDENTIF_LIST 1
#define IDENTIF_STATIC 2
#define IDENTIF_SAVEDATA 3
#define IDENTIF_BTNSAVE 4
#define MAX_ARRSIZE 512

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);       // prototype

typedef struct {
	int wNum;
	wchar_t identifName[30];
} dbgIdentifWindows;

dbgIdentifWindows identifWindows[] = {
	{1, L"IDENTIF_LIST"},
	{2, L"IDENTIF_STATIC"},
	{3, L"IDENTIF_SAVEDATA"},
	{4, L"IDENTIF_BTNSAVE"},
};


typedef struct {
    wchar_t resource[30];
    wchar_t login[20];
    wchar_t passw[20];
} cData;

cData data[] = {
    {L"Mail.ru", L"test@mail.ru", L"test1"},        // now as a RAW data, for testing purposes
};

void dbgStringStdout(int wParamI) {
	wchar_t outStr[MAX_ARRSIZE];
	int n = sizeof(identifWindows);
	bool flag_service = false;

	// search-up the <identifWindows> structure
	for (int i = 0; i < n; i++)
	{
		if (identifWindows[i].wNum == wParamI) {
			wsprintf(outStr, L"\n\nIt works! wParam > [%d] | Window > [%s]", wParamI, identifWindows[i].identifName);
			flag_service = true;
			break;
		}
		else {
			continue;
		}
	}
	if (!flag_service) {
		wsprintf(outStr, L"\n\nERROR! Not detected window-element wParam > [%d] | Window > [???]", wParamI);
	}
	OutputDebugString(outStr);
}

wchar_t getExPath(void)
{
	wchar_t resultPath[MAX_PATH];
	return (resultPath, GetModuleFileName(NULL, resultPath, MAX_PATH));
}

char* fileRW(char saveData[], char flagRW[]) {
	FILE* descripFile;
	wchar_t dirPrefix = getExPath();
	const char* dirPath = "D:\\proj\\CPP\\passwnote\\";

	char fsCMP[] = "save\0";
	char flCMP[] = "load\0";
	int iter_ld = 0;
	char buffer_loadData[50];
	char storageLoadedData[1024];
	char errRET[] = "NULL";
	char fullPath[50];
	
	strcpy(fullPath, dirPath);                // скопировать строку

	if (strcmp(fsCMP, flagRW) == 0) {
		strcpy(fullPath, strcat(fullPath, "passw_data.dat")); 

		if ((descripFile = fopen(fullPath, "a+")) != NULL) {
			fputs(saveData, descripFile);
		}
		else {
			puts("[ERROR] File didn't open correctly, no way to save data..");
		}
		fclose(descripFile);
		return (saveData);
	}
	else if (strcmp(flCMP, flagRW) == 0) {
		strcpy(fullPath, strcat(fullPath, "passw_data.dat"));
		if ((descripFile = fopen(fullPath, "r")) != NULL) {
			// пока не дойдем до конца, считываем по 256 байт
			while ((fgets(buffer_loadData, sizeof(buffer_loadData), descripFile)) != NULL)
			{
				for (int i = 0; i < sizeof(buffer_loadData); i++) {
					storageLoadedData[iter_ld] = buffer_loadData[i];
					iter_ld += 1;
				}
			}
		}
		else {
			puts("[ERROR] File didn't open correctly, no way to load data..");
		}
		return (storageLoadedData);
	}
	return (errRET);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR pCmdLine, int nCmdShow) {
    MSG  msg;
    WNDCLASSW wc = { 0 };
    wc.lpszClassName = L"clWND";
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_SCROLLBAR + 1);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);

	InitConsole();
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

    static HWND hwndList, hwndStatic, hwndSaveData, hwndButton;
    wchar_t credsSendBuf[128];
	wchar_t credsGetBuf[128];
	wchar_t outBuff[512] = {'\0'};

    switch (msg) {

    // On first time window create (https://docs.microsoft.com/en-us/windows/win32/winmsg/wm-create)
    case WM_CREATE:

        hwndList = CreateWindowW(WC_LISTBOXW, NULL, WS_CHILD
            | WS_VISIBLE | LBS_NOTIFY, 10, 10, 150, 120, hwnd,
            (HMENU)IDENTIF_LIST, NULL, NULL);

		// button for save credentials to file (passw_data.dat) and add data to LISTBOXW
		hwndButton = CreateWindowW(L"BUTTON", L"SAVE", WS_TABSTOP
			| WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 260, 130, 80, 30, hwnd,
			(HMENU)IDENTIF_BTNSAVE, NULL, NULL);

		// window with displayed selected data in window LISTBOXW
        hwndStatic = CreateWindowW(WC_STATICW, NULL, WS_CHILD | WS_VISIBLE,
            200, 10, 200, 45, hwnd, (HMENU)IDENTIF_STATIC, (HINSTANCE)GetWindowLongPtr(hwnd, GWLP_HINSTANCE), NULL);

		// window with editable text insertion
		hwndSaveData = CreateWindowW(WC_EDIT, NULL, WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL,
			200, 80, 200, 45, hwnd, (HMENU)IDENTIF_SAVEDATA, NULL, NULL);

        // send message (type of the website) by lparam (https://docs.microsoft.com/en-us/windows/win32/controls/lb-addstring) to hwndList window [list of web-resources]
        for (int i = 0; i < ARRAYSIZE(data); i++) {
            SendMessageW(hwndList, LB_ADDSTRING, 0, (LPARAM)data[i].resource);
        }

        break;

    case WM_COMMAND:

        // catch signal [LBN_SELCHANGE] about selector changes in hwndList (https://docs.microsoft.com/en-us/windows/win32/controls/lbn-selchange)
        if (LOWORD(wParam) == IDENTIF_LIST) {
            if (HIWORD(wParam) == LBN_SELCHANGE) {
                int sel = (int)SendMessageW(hwndList, LB_GETCURSEL, 0, 0);
                StringCbPrintfW(credsSendBuf, ARRAYSIZE(credsSendBuf), L"Login: %s\nPassw: %s",
                    data[sel].login, data[sel].passw);
                SetWindowTextW(hwndStatic, credsSendBuf);
            }
        }

		// button <SAVE> click
		if (wParam == 4) {
			//dbgStringStdout(wParam);		// dbg wParam=? function callout
			int lengthTXT = GetWindowTextLength(hwndSaveData) + 1;
			
			char *buff;
			buff = (char*)malloc(lengthTXT * sizeof(int));
			char fSAVE[] = "save\0";

			char* buff_read;
			buff_read = (char*)malloc(256 * sizeof(int));
			char fLOAD[] = "load\0";

			GetWindowText(hwndSaveData, credsGetBuf, lengthTXT);
			size_t len = wcstombs(buff, credsGetBuf, lengthTXT);

			// ___dbg console callout  TRELLO : [<bug_#2> loadable console with STDOUT / IN interception]___
			std::cout << buff << std::endl << std::endl;
			// ----------------------------------------------------------------------------------------------
			
			// TRELLO : [<bug_#3> remove carriage shift, it causes [double \n\n between login - passw] in passw file]
			for (int i = 0; i < lengthTXT; i++) {
				if (buff[i] == '\r') {
					for (int j = i; buff[j] != '\0'; j++)
						buff[j] = buff[j + 1];
					lengthTXT--;
				}
			}
			// --------------------------------------------------------------------------------------------------------

			// TRELLO : [<bug_#1> Output credentials with \n\n]
			char wrBuffIndents[] = "\n\n";
			buff = (char*) realloc(buff, (strlen(wrBuffIndents)+ strlen(buff)) * sizeof(char*));
			strcpy(buff, strcat(buff, "\n\n"));
			// --------------------------------

			// ___dbg console callout  TRELLO : [<bug_#2> loadable console with STDOUT / IN interception]___
			std::cout << buff << std::endl;
			std::cout << lengthTXT;
			// ---------------------------------------------------------------------------------------------

			// buff_read= fileRW(buff, fLOAD);	// add to inputted text (old content in the file)

			fileRW(buff, fSAVE);
			free(buff);
		}
		
        break;

    // cross click handle
    case WM_DESTROY:

        PostQuitMessage(0);
        break;
    }

    return (DefWindowProcW(hwnd, msg, wParam, lParam));
}