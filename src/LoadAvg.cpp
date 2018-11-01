






#include "../inc/LoadAvg.hpp"
#include "../inc/ft_gkrellm.h"

LoadAvg::LoadAvg() {
	reload();
	_show = 0;
	_height = 2;
	_start = 0;
}

LoadAvg::~LoadAvg() {}

LoadAvg::LoadAvg(LoadAvg const &a) {
	*this = a;
}

LoadAvg& LoadAvg::operator=(LoadAvg const & a) {
	if (this != &a) {
		_one_min = a._one_min;
		_five_min = a._five_min;
		_fifteen_min = a._fifteen_min;
		_show = a._show;
		_height = a._height;
		_start = a._start;
	}
	return *this;
}

void	LoadAvg::reload() {
	char buff[1024];

	std::string s;
	FILE *load = popen("top -l 1 | grep \"Load Avg\"", "r");

    if (!load)
   		std::cout << "ERROR opening LoadAvg info" << std::endl;	
	fgets(buff, sizeof(buff), load);
	pclose(load);

	s = buff;
	_one_min = atof(buff + 10);
	int i = 0;
	while (buff[10 + i] != ',')
		i++;
	i++;
	_five_min = atof(buff + 10 + i);
	while (buff[10 + i] != ',')
		i++;
	i++;
	_fifteen_min = atof(buff + 10 + i);
}

double LoadAvg::getOneMin() {
	return _one_min;
}

double LoadAvg::getFiveMin() {
	return _five_min;
}

int LoadAvg::getHeight() {
	return _height;
}


double LoadAvg::getFifteenMin() {
	return _fifteen_min;
}

int LoadAvg::getShow() {
	return _show;
}
		
void LoadAvg::setShow(int i) {
	_show = i;
}

int		LoadAvg::getStart() {
	return _start;
}

void		LoadAvg::setStart(int i) {
	_start = i;
}

