#include "init_tape.h"
int main()
{
	std::string input, output;
	std::cout << "������� ����: ";
	std::cin >> input;
	std::cout << "�������� ���� ";
	std::cin >> output;
	tapes t(input, output);
	t.init_tape();
	t.sorts();
	t.show_tape();
}
