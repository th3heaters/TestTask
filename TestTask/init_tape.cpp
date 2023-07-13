#include "init_tape.h"
tapes::tapes(std::string inputf, std::string outputf)
{
	input = inputf;
	outputf = outputf;
}
void tapes::init_tape()
{	using namespace std::this_thread;
	using namespace std::chrono_literals;
	using namespace std;
	ifstream lines("config.txt");
	vector <string> conf;
	while (!lines.eof())
	{
		string buf;
		getline(lines, buf);
		conf.push_back(buf);
	}
	read = stoi(conf[0].substr(conf[0].find_last_of(' '), conf[0].size()));
	record = stoi(conf[1].substr(conf[1].find_last_of(' '), conf[1].size()));
	rewind = stoi(conf[2].substr(conf[2].find_last_of(' '), conf[2].size()));
	shift = stoi(conf[3].substr(conf[3].find_last_of(' '), conf[3].size()));
	ifstream tapeIn(input);
	int num;
	std::chrono::milliseconds recorddelay(record);
	std::chrono::milliseconds shiftdelay(shift);
	while (!tapeIn.eof())
	{
		tapeIn >> num;
		std::this_thread::sleep_for(recorddelay);
		std::this_thread::sleep_for(shiftdelay);
		tp.push_back(num);
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
	tp.sort();
	std::ofstream lines(output);
	for (std::list<int>::iterator it = tp.begin(); it != tp.end(); ++it)
	{
		lines << *it << " ";
		std::this_thread::sleep_for(recorddelay);
	}
}
void tapes::show_tape()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	std::chrono::milliseconds readdelay(read);
	std::chrono::milliseconds shiftdelay(shift);
	for (std::list<int>::iterator it = tp.begin(); it != tp.end(); ++it)
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
	std::chrono::milliseconds recorddelay(record);
	std::chrono::milliseconds rewinddelay(rewind);
	std::ofstream lines(output);
	std::list<int>::iterator it;
	std::this_thread::sleep_for(rewinddelay);
	std::this_thread::sleep_for(recorddelay);
	tp.push_back(val);
}