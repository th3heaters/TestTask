#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <chrono>
#include <cmath>
#include <thread>
class tapes {
private:
	std::list <int> tp{};
	int read, record, rewind, shift;
	std::string input, output;
public:
	tapes(std::string inputf, std::string outputf);
	void init_tape();
	void sorts();
	void show_tape();
	void add(int val);
	int getread();
	int getrecord();
	int getrewind();
	int getshift();
	std::list <int> getTape();
};