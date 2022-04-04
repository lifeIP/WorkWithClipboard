#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <windows.h>
#include <atlstr.h>
#include <wchar.h>
#include "Header.h"
#include <cstdlib>

int main() {
	setlocale(LC_ALL, "RUS");
	std::system("chcp 1251");
	char *source;
	get_data_Clipboard(&source);
	//std::cout << source << std::endl;
}