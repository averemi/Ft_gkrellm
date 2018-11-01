


#include "../inc/CPU.hpp"
#include "../inc/ft_gkrellm.h"

CPU::CPU() {
	setStaticData();
	reload();

	_show = 0;
	_height = 6;
	_start = 0;
}

CPU::~CPU() {}

CPU::CPU(CPU const &a) {
	*this = a;
}

CPU& CPU::operator=(CPU const & a) {
	if (this != &a) {
		_model = a._model;
		_cores = a._cores;
		_cpus = a._cpus;
		_clock_speed = a._clock_speed;
		_speed = a._speed;
		_user = a._user;
		_sys = a._sys;
		_idle = a._idle;
		_show = a._show;
		_height = a._height;
		_start = a._start;
	}
	return *this;
}

void	CPU::setStaticData() {
	char buff[128];
	char buff1[128];
	char buff2[128];
	std::fill (buff, buff + 128, 0);
	std::fill (buff1, buff1 + 128, 0);
	std::fill (buff2, buff2 + 128, 0);

	std::string s;


	FILE *model = popen("sysctl -n machdep.cpu.brand_string", "r");

    if (!model)
   		std::cout << "ERROR opening CPU info" << std::endl;	
	fgets(buff, sizeof(buff), model);
	pclose(model);
	s = static_cast<std::string>(buff);
	_model = s;

	FILE *cores = popen("system_profiler SPHardwareDataType | grep \"Number of Cores\" ", "r");

	if (!cores)
   		std::cout << "ERROR opening CPU info" << std::endl;	
	fgets(buff2, sizeof(buff2), cores);
	_cores = atoi(buff2 + 29);
	pclose(cores);

	FILE *cpus = popen("system_profiler SPHardwareDataType | grep \"Number of Processors\" ", "r");

	if (!cpus)
   		std::cout << "ERROR opening CPU info" << std::endl;	
	fgets(buff1, sizeof(buff1), cpus);
	_cpus = atoi(buff1 + 28);
	pclose(cpus);

}

double CPU::getSpeed() {
	return _speed;
}

const char * CPU::getModel() {
	return _model.c_str();
}

int CPU::getCores() {
	return _cores;
}

int CPU::getCpus() {
	return _cpus;
}

const char * CPU::getClockSpeed() {
	return _clock_speed;
}

double CPU::getActUser() {
	return _user;
}

double CPU::getActSys(){
	return _sys;
}

double CPU::getActIdle() {
	return _idle;
}

int CPU::getShow() {
	return _show;
}
		
void CPU::setShow(int i) {
	_show = i;
}

int CPU::getHeight() {
	return _height;
}

void CPU::reload() {
	char buff4[1024];
	std::string s4;
	FILE *clock_speed = popen("sysctl hw.cpufrequency", "r");

    if (!clock_speed)
   		std::cout << "ERROR opening CPU info" << std::endl;	
	fgets(buff4, sizeof(buff4), clock_speed);
	pclose(clock_speed);
	int j = 0;
	while (!isdigit(buff4[j]))
		j++;
	long long s7 = atoll(buff4 + 17);
	s7 = s7 / 10000000;
	_speed = static_cast<double>(s7) / 100;


	char buff1[1024];
	std::fill (buff1, buff1 + 1024, 0);

	FILE * activity = popen("top -l 1 | grep \"CPU usage\"", "r");
	std::string s1;

	if (!activity)
   		std::cout << "ERROR opening CPU info" << std::endl;	
   	fgets(buff1, sizeof(buff1), activity);
   	pclose(activity);
   	 s1 = buff1;
	
	int i = 0;
	while (!isdigit(buff1[i]))
		i++;
	_user = atof(buff1 + i);
	size_t count = s1.find(" user, ");
	_sys = atof(buff1 + count + 7);
	count = s1.find(" sys, ");
	_idle = atof(buff1 + count + 6);
}

int		CPU::getStart() {
	return _start;
}

void		CPU::setStart(int i) {
	_start = i;
}
