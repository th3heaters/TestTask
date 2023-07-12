#include "init_tape.h"
int main()
{
	tapes t;
	t.init_tape("tape_input.txt");
	t.sort_tape("tape_output.txt");
	//t.show_tape();
}
