#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <windows.h>
#include <atlstr.h>
#include <wchar.h>
#include <cstdlib>


bool set_data_Clipboard(char* source) {
	//в эту переменную нужно записать текст, который в дальнейшем поместится в буфер обмена
	//запись текста в буфер обмена
	if (OpenClipboard(NULL))//открываем буфер обмена
	{
		HGLOBAL hgBuffer;
		char* chBuffer;
		EmptyClipboard(); //очищаем буфер
		hgBuffer = GlobalAlloc(GMEM_DDESHARE, strlen(source) + 1);//выделяем память
		chBuffer = (char*)GlobalLock(hgBuffer); //блокируем память
		strcpy(chBuffer, LPCSTR(source));
		GlobalUnlock(hgBuffer);//разблокируем память
		SetClipboardData(CF_TEXT, hgBuffer);//помещаем текст в буфер обмена
		CloseClipboard(); //закрываем буфер обмена
		return 1;
	}
	return 0;
}

bool get_data_Clipboard(char** source) {
//в эту переменную сохраним текст из буфера обмена
	if (OpenClipboard(NULL))//открываем буфер обмена
	{
		HANDLE hData = GetClipboardData(CF_TEXT);//извлекаем текст из буфера обмена
		char* chBuffer = (char*)GlobalLock(hData);//блокируем память
		*source = chBuffer;
		GlobalUnlock(hData);//разблокируем память
		CloseClipboard();//закрываем буфер обмена
		return 1;
	}
	return 0;
}
