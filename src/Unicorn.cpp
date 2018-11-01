




#include "../inc/Unicorn.hpp"
#include "../inc/ft_gkrellm.h"

Unicorn::Unicorn() {
	_show = 0;
	_height = 9;
	_uni = 0;
	_start = 0;
}

Unicorn::~Unicorn() {}

Unicorn::Unicorn(Unicorn const &a) {
	*this = a;
}

Unicorn& Unicorn::operator=(Unicorn const & a) {
	if (this != &a) {
		_show = a._show;
		_height = a._height;
		_uni = a._uni;
		_start = a._start;
	}
	return *this;
}

int Unicorn::getShow() {
	return _show;
}

int Unicorn::getHeight() {
	return _height;
}


int Unicorn::getUni() {
	return _uni;
}


void Unicorn::setUni(int i) {
	_uni = i;
}

void Unicorn::setShow(int i) {
	_show = i;
}

void Unicorn::reload() {}


int		Unicorn::getStart() {
	return _start;
}

void		Unicorn::setStart(int i) {
	_start = i;
}

