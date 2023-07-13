#include "init_tape.h"
int main()
{
	std::string input, output;
	std::cout << "входной файл: ";
	std::cin >> input;
	std::cout << "выходной файл ";
	std::cin >> output;
	tapes t(input, output);
	t.init_tape();
	t.sorts();
	t.show_tape();
}
