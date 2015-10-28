// lv.h - содержит прототипы функций для работы со списком
// ListView

#ifndef _LIGHTLISTVIEW_SORTTASK_LV_H_
#define _LIGHTLISTVIEW_SORTTASK_LV_H_

#include <windef.h> // HWND

struct string_data_array {
	TCHAR **strings;
	size_t len;
};

bool initListView(HWND hList, const string_data_array &str_array);

#endif