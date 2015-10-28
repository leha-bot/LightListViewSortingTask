// lv.cpp - содержит логику инициализации и заполнения 
// ListView.
#include <windows.h>
#include <commctrl.h>
#include "lv.h"

bool initListView(HWND hList, const string_data_array &str_array)
{
	LVCOLUMN lvc = { 0 };
	LVITEM lvi = { 0 };
	RECT rt;

	GetClientRect(hList, &rt);

	lvc.mask = LVCF_TEXT | LVCF_WIDTH;
	lvc.pszText = TEXT("Список строк");
	lvc.cx = rt.right;

	ListView_InsertColumn(hList, 0, &lvc);

	for (size_t i = 0; i < str_array.len; i++) {
		lvi.mask = LVIF_TEXT;
		lvi.pszText = str_array.strings[i];
		ListView_InsertItem(hList, &lvi);
	}
	return true;
}



void sortListView(HWND hList, const string_data_array &arr)
{
	// ListView_SortItems(hList, 0, &arr);
}