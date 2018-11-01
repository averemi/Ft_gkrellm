


#include "../inc/ft_gkrellm.h"
#include "../inc/Time.hpp"

Time::Time() {
	reload();
	_show = 0;
	_height = 2;
	_start = 0;
}

Time::~Time() {}

Time::Time(Time const &a) {
	*this = a;
}

Time& Time::operator=(Time const &a) {
	if (this != &a) {
		_time = a._time;
		_show = a._show;
		_height = a._height;
		_start = a._start;
	}
	return *this;
}

int Time::getShow() {
	return _show;
}
		
void Time::setShow(int i) {
	_show = i;
}

int Time::getHeight() {
	return _height;
}

void Time::reload() {
	time_t t = time(NULL);
	_time = localtime(&t);
}

tm * Time::getDateTime() {
	return _time;
}


int		Time::getStart() {
	return _start;
}

void		Time::setStart(int i) {
	_start = i;
}
