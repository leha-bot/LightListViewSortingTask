// main.cpp - содержит точку входа в Win32-приложение проекта.
// Этот проект демонстрирует логику сортировки в элементе управления 
// ListView, используя индексные таблицы.

#include <windows.h>
#include "resource.h"

INT_PTR CALLBACK ListDialogProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	char *test_strings[] = {
		"Blabla", "Yes! YEs!",
		"Test string!!", "Hello World",
		"Goodbye, cruel world", "No, no!",
		"It's a kind of magic", "Fork me!",
		"Test String!_", "Too many words", 0
	};

	return DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_LISTDIALOG), 0, 
		ListDialogProc, (LPARAM) test_strings);
}

INT_PTR CALLBACK ListDialogProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return 0;
}
