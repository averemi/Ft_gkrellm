


#include "../inc/Network.hpp"
#include "../inc/ft_gkrellm.h"

Network::Network() {
	reload();
	_show = 0;
	_height = 3;
	_start = 0;
}

Network::~Network() {}

Network::Network(Network const &a) {
	*this = a;
}

Network& Network::operator=(Network const & a) {
	if (this != &a) {
		_in = a._in;
		_out = a._out;
		_insize = a._insize;
		_inM = a._inM;
		_outsize = a._outsize;
		_outM = a._outM;
		_start = a._start;
		_show = a._show;
		_height = a._height;
	}
	return *this;
}

void	Network::reload() {
	char buff[1024];
	std::string s;
	FILE *network = popen("top -l 1 | grep \"Networks:\"", "r");

    if (!network)
   		std::cout << "ERROR opening Network info" << std::endl;	
	fgets(buff, sizeof(buff), network);
	pclose(network);
	s = buff;
	size_t from = s.find("packets: ");
	size_t to = s.find(" in, ");
	_in = atoi(buff + from + 9);
	int i = 0;
	while (isdigit(buff[from + 9 + i]))
		i++;
	_inM = atoi(buff + from + 9 + i + 1);
	
	while (isdigit(buff[from + 9 + i + 1]))
		i++;
	_insize = buff[from + 9 + i + 1];
	_out = atoi(buff + to + 5);
	int j = 0;
	while (isdigit(buff[to + 5 + j]))
		j++;
	_outM = atoi(buff + to + 5 + j + 1);
	
	while (isdigit(buff[to + 5 + j + 1]))
		j++;
	_outsize = buff[to + 5 + j + 1];
}

int Network::getShow() {
	return _show;
}

int Network::getHeight() {
	return _height;
}


void Network::setShow(int i) {
	_show = i;
}

long long Network::getIn() {
	return _in;
}

long long Network::getOut() {
	return _out;
}

long long Network::getInM() {
	return _inM;
}

long long Network::getOutM() {
	return _outM;
}

char Network::getInSize() {
	return _insize;
}

char Network::getOutSize() {
	return _outsize;
}


int		Network::getStart() {
	return _start;
}

void		Network::setStart(int i) {
	_start = i;
}

