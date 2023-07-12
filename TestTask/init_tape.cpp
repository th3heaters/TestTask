#include "init_tape.h"
#include <stdexcept>
tapes::tapes()
{

	ifstream lines("config.txt");
	//ofstream Output(output);
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
tapes::~tapes()
{

}
void tapes::init_tape(string filename)
{
	ifstream tapeIn(filename);
	int num;
	tapeIn >> num;
	this->tp=new tape;
	this->tp->val = num;
	this->tp->prev = NULL;
	this->tp->next = NULL;
	tape *tail = new tape;
	tail = this->tp;
	while (!tapeIn.eof())
	{
		tapeIn >> num;
		//cout << num << " ";
		tape* tmp = new tape;
		tmp->next = NULL;
		tmp->val = num;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
}
void tapes::sort_tape(string output)
{
	tape *hooks[32] = {};
	tape *node = new tape;
	tape *prev_node = new tape;
	while (this->tp != NULL)
	{
		node = this->tp;
		int i = 0;
		for (i; i < 32; i++)
		{
			if (hooks[i] == NULL)
			{
				hooks[i] = node;
				break;
			}
		}
		this->tp = this->tp->next;
		node = this->tp;
		prev_node = hooks[i];
		hooks[i] = NULL;
		//слияние 2х списков отсортированных
		
		prev_node->next = node;
		node->next = nullptr;
		hooks[i+1] = prev_node; //подвешиваем итоговый список на крючок
		while (hooks[i+1] != NULL)
		{
			cout << hooks[i+1]->val << " ";
			hooks[i+1] = hooks[i+1]->next;
		}
		break;
	}
}
void tapes::show_tape()
{
	while (this->tp != NULL)
	{
		cout << this->tp->val << " ";
		this->tp = this->tp->next;
	}
}