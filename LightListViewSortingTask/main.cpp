// main.cpp - содержит точку входа в Win32-приложение проекта.
// Этот проект демонстрирует логику сортировки в элементе управления 
// ListView, используя индексные таблицы.

#include <windows.h>
#include <CommCtrl.h>
#include "resource.h"
#include "lv.h"

INT_PTR CALLBACK ListDialogProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	TCHAR *test_strings[] = {
		TEXT("Blabla"), TEXT("Yes! YEs!"),
		TEXT("Test string!!"), TEXT("Hello World"),
		TEXT("Goodbye, cruel world"), TEXT("No, no!"),
		TEXT("It's a kind of magic"), TEXT("Fork me!"),
		TEXT("Test String!_"), TEXT("Too many words"),
	};
	string_data_array arr = { test_strings, 
		sizeof(test_strings) / sizeof(test_strings[0]) 
	};

	InitCommonControls(); // для работы ListView
	return DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_LISTDIALOG), 0, 
		ListDialogProc, (LPARAM) &arr);
}

INT_PTR CALLBACK ListDialogProc(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static struct ListDlgStruct {
		HWND hList, hListHeader;
		string_data_array *arr;
	} s;
	NMHEADER *hdr; // WM_NOTIFY

	switch (msg) {
	case WM_INITDIALOG:
		if (!lParam) { // пустой параметр не надо передавать.
			EndDialog(hDlg, -1);
			return FALSE;
		}
		s.hList = GetDlgItem(hDlg, IDC_LIST1);
		s.hListHeader = ListView_GetHeader(s.hList);
		s.arr = (string_data_array *)lParam;
		initListView(s.hList, *s.arr);
		return TRUE;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wParam));
			return TRUE;
		}
		return FALSE;
	case WM_NOTIFY: // обработка уведомлений от заголовка ListView.
		hdr = (NMHEADER *)lParam;
		if (hdr->hdr.code == HDN_ITEMCLICK && 
			hdr->hdr.hwndFrom == s.hListHeader) {
			
		}
	}
	return FALSE;
}
