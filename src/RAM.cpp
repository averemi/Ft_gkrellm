




#include "../inc/RAM.hpp"
#include "../inc/ft_gkrellm.h"

RAM::RAM() {
	char buff1[128];

	std::string s1;

	FILE *mem = popen("system_profiler SPHardwareDataType | grep \"Memory:\" ", "r");

	if (!mem)
   		std::cout << "ERROR opening Memory info" << std::endl;	
	fgets(buff1, sizeof(buff1), mem);
	_mem = atoi(buff1 + 14);
	pclose(mem);
	int i = 0;
	while (isdigit(buff1[14 + i]))
		i++;
	_mem_size = buff1[14 + i + 1];
	if (_mem_size == 'G')
		_memMB = _mem * 1024;
	else if (_mem_size == 'K')
		_memMB = _mem / 1024;
	else if (_mem_size == 'B')
		_memMB = (_mem / 1024) / 1024;
	else
		_memMB = _mem;
	reload();
	_show = 0;
	_height = 4;
	_start = 0;
}

RAM::~RAM() {}

RAM::RAM(RAM const &a) {
	*this = a;
}

RAM& RAM::operator=(RAM const & a) {
	if (this != &a) {
		_used = a._used;
		_wired = a._wired;
		_unused = a._unused;
		_show = a._show;
		_height = a._height;
		_start = a._start;
		_mem = a._mem;
		_mem_size = a._mem_size;
		_memMB = a._memMB;
		_usedMB = a._usedMB;
		_used_size = a._used_size;
		_wiredMB = a._wiredMB;
		_wired_size = a._wired_size;
		_unusedMB = a._unusedMB;
		_unused_size = a._unused_size;
	}
	return *this;
}

void	RAM::reload() {
	char buff[256];

	std::string s;
	FILE *ram = popen("top -l 1 | grep \"PhysMem:\"", "r");

    if (!ram)
   		std::cout << "ERROR opening RAM info" << std::endl;	
	fgets(buff, sizeof(buff), ram);
	pclose(ram);
	s = buff;
	int i = 0;
	while (!isdigit(buff[i]))
		i++;
	_used = atof(buff + i);
	size_t count = s.find(" used");
	_used_size = buff[count - 1];
	count = s.find(" (");
	_wired = atof(buff + count + 2);
	count = s.find(" wired),");
	_wired_size = buff[count - 1];
	_unused = atof(buff + count + 8);
	count = s.find(" unused");
	_unused_size =buff[count - 1];
	calculateLoad();
}

int RAM::getHeight() {
	return _height;
}

void	RAM::calculateLoad() {
	if (_used_size == 'G')
		_usedMB = _used * 1024;
	else if (_used_size == 'K')
		_usedMB = _used / 1024;
	else if (_used_size == 'B')
		_usedMB = (_used / 1024) / 1024;
	else
		_usedMB = _used;
	if (_unused_size == 'G')
		_unusedMB = _unused * 1024;
	else if (_unused_size == 'K')
		_unusedMB = _unused / 1024;
	else if (_unused_size == 'B')
		_unusedMB = (_unused / 1024) / 1024;
	else
		_unusedMB = _unused;
	if (_wired_size == 'G')
		_wiredMB = _wired * 1024;
	else if (_wired_size == 'K')
		_wiredMB = _wired / 1024;
	else if (_wired_size == 'B')
		_wiredMB = (_wired / 1024) / 1024;
	else
		_wiredMB = _wired;
	
	_usedMB = (_usedMB / _memMB) * 100;
	_unusedMB = (_unusedMB / _memMB) * 100;
	_wiredMB = (_wiredMB / _memMB) * 100;
}

char RAM::getUsedSize() {
	return _used_size;
}

char RAM::getWiredSize() {
	return _wired_size;
}

char RAM::getUnusedSize() {
	return _unused_size;
}


int RAM::getShow() {
	return _show;
}
		
void RAM::setShow(int i) {
	_show = i;
}

long long RAM::getUsedMem() {
	return _used;
}

long long RAM::getWiredMem(){
	return _wired;
}

long long RAM::getUnusedMem() {
	return _unused;
}

double RAM::getUnusedMB() {
	return _unusedMB;
}

double RAM::getUsedMB() {
	return _usedMB;
}

double RAM::getWiredMB() {
	return _wiredMB;
}


int		RAM::getStart() {
	return _start;
}

void		RAM::setStart(int i) {
	_start = i;
}
