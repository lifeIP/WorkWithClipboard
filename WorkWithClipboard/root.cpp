#include "Header.h"


int main() {
	std::system("chcp 1251");
	char *source;
	get_data_Clipboard(&source);
	std::cout << source << std::endl;
}