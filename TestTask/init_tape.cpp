#include "init_tape.h"
tapes::tapes(std::string inputf, std::string outputf)
{
	using namespace std;
	this->input = inputf;
	this->output = outputf;
	ifstream lines("config.txt");
	vector <string> conf;
	while (!lines.eof())
	{
		string buf;
		getline(lines, buf);
		conf.push_back(buf);
	}
	this->read = stoi(conf[0].substr(conf[0].find_last_of(' '), conf[0].size()));
	this->record = stoi(conf[1].substr(conf[1].find_last_of(' '), conf[1].size()));
	this->rewind = stoi(conf[2].substr(conf[2].find_last_of(' '), conf[2].size()));
	this->shift = stoi(conf[3].substr(conf[3].find_last_of(' '), conf[3].size()));
}
void tapes::init_tape()
{	using namespace std::this_thread;
	using namespace std::chrono_literals;
	using namespace std;
	ifstream tapeIn(input);
	int num;
	std::chrono::milliseconds recorddelay(this->record);
	std::chrono::milliseconds shiftdelay(this->shift);
	while (!tapeIn.eof())
	{
		tapeIn >> num;
		std::this_thread::sleep_for(recorddelay);
		std::this_thread::sleep_for(shiftdelay);
		this->tp.push_back(num);
	}
}
void tapes::sorts()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	std::chrono::milliseconds recorddelay(record);
	std::chrono::milliseconds readdelay(read);
	std::chrono::milliseconds shiftdelay(shift);
	std::this_thread::sleep_for((readdelay+shiftdelay+recorddelay)*tp.size()*log(tp.size()));
	this->tp.sort();
	std::ofstream lines(output);
	for (std::list<int>::iterator it = this->tp.begin(); it != this->tp.end(); ++it)
	{
		lines << *it << " ";
		std::this_thread::sleep_for(recorddelay);
	}
}
void tapes::show_tape()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	std::chrono::milliseconds readdelay(this->read);
	std::chrono::milliseconds shiftdelay(this->shift);
	for (std::list<int>::iterator it = this->tp.begin(); it != this->tp.end(); ++it)
	{
		std::cout << *it << " ";
		std::this_thread::sleep_for(readdelay);
		std::this_thread::sleep_for(shiftdelay);
	}
}
void tapes::add(int val)
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	std::chrono::milliseconds recorddelay(this->record);
	std::chrono::milliseconds rewinddelay(this->rewind);
	std::ofstream lines(output);
	std::list<int>::iterator it;
	std::this_thread::sleep_for(rewinddelay);
	std::this_thread::sleep_for(recorddelay);
	tp.push_back(val);
}
int tapes::getread()
{
	int delay = this->read;
	return delay;
}
int tapes::getrecord()
{
	int delay = this->record;
	return delay;
}

int tapes::getrewind()
{
	int delay = this->rewind;
	return delay;
}
int tapes::getshift()
{
	int delay = this->shift;
	return delay;
}
std::list <int> tapes::getTape()
{
	std::list <int> tape;
	tape = this->tp;
	return tape;
}
