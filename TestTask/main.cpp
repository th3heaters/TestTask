#include "init_tape.h"
int main()
{
	std::string input, output;
	std::cout << "input tape file: ";
	std::cin >> input;
	std::cout << "output tape file: ";
	std::cin >> output;
	tapes t(input, output);
	t.init_tape();
	t.sorts();
	//t.show_tape();
}
