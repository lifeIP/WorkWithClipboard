#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <windows.h>
#include <atlstr.h>
#include <wchar.h>

bool set_data_Clipboard(char* source) {
	//� ��� ���������� ����� �������� �����, ������� � ���������� ���������� � ����� ������
	//������ ������ � ����� ������
	if (OpenClipboard(NULL))//��������� ����� ������
	{
		HGLOBAL hgBuffer;
		char* chBuffer;
		EmptyClipboard(); //������� �����
		hgBuffer = GlobalAlloc(GMEM_DDESHARE, strlen(source) + 1);//�������� ������
		chBuffer = (char*)GlobalLock(hgBuffer); //��������� ������
		strcpy(chBuffer, LPCSTR(source));
		GlobalUnlock(hgBuffer);//������������ ������
		SetClipboardData(CF_TEXT, hgBuffer);//�������� ����� � ����� ������
		CloseClipboard(); //��������� ����� ������
		return 1;
	}
	return 0;
}

