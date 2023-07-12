#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class tapes {
public:
	tapes();
	void init_tape(string filename);
	void sort_tape(string output);
	void show_tape();
	~tapes();
private:
	struct tape
	{
		int val;
		struct tape* next;
		struct tape* prev;
	};
	tape *tp;
	int read, record, rewind, shift;
};