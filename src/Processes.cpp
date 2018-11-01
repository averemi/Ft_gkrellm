




#include "../inc/Processes.hpp"
#include "../inc/ft_gkrellm.h"

Processes::Processes() {
	reload();
	_show = 0;
	_height = 2;
	_start = 0;
}

Processes::~Processes() {}

Processes::Processes(Processes const &a) {
	*this = a;
}

Processes& Processes::operator=(Processes const & a) {
	if (this != &a) {
		_total = a._total;
		_running = a._running;;
		_show = a._show;
		_height = a._height;
		_start = a._start;
	}
	return *this;
}

int Processes::getHeight() {
	return _height;
}

void	Processes::reload() {
	char buff[1024];

	std::string s;
	FILE *proc = popen("top -l 1 | grep \"Processes:\"", "r");

    if (!proc)
   		std::cout << "ERROR opening Processes info" << std::endl;	
	fgets(buff, sizeof(buff), proc);
	pclose(proc);

	s = buff;
	_total = atoi(buff + 11);
	size_t count = s.find("total, ");
	_running = atoi(buff + count + 7);
}

int Processes::getTotal() {
	return _total;
}

int Processes::getRunning() {
	return _running;
}

int Processes::getShow() {
	return _show;
}
		
void Processes::setShow(int i) {
	_show = i;
}

int		Processes::getStart() {
	return _start;
}

void		Processes::setStart(int i) {
	_start = i;
}
