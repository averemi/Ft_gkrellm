

#include "../inc/Userinfo.hpp"
#include "../inc/ft_gkrellm.h"




Userinfo::Userinfo() {
	reload();
	_show = 0;
	_height = 3;
	_start = 0;
}

Userinfo::~Userinfo() {}

Userinfo::Userinfo(Userinfo const & a) {
	*this = a;
}

Userinfo& Userinfo::operator=(Userinfo const & a) {
	if (this != &a) {
		_hostname = a._hostname;
		_username = a._username;
		_show = a._show;
		_height = a._height;
		_start = a._start;
	}
	return *this;
}

void		Userinfo::reload() {
	char hostname[HOST_NAME_MAX];
	char username[USER_NAME_MAX];

	gethostname(hostname, HOST_NAME_MAX);
	_hostname = static_cast<std::string>(hostname);
	getlogin_r(username, USER_NAME_MAX);
	_username = static_cast<std::string>(username);
}

const char * Userinfo::getHostName() {
	return _hostname.c_str();
}

int Userinfo::getShow() {
	return _show;
}
		
void Userinfo::setShow(int i) {
	_show = i;
}

int Userinfo::getHeight() {
	return _height;
}


const char * Userinfo::getUserName() {
	return _username.c_str();
}


int		Userinfo::getStart() {
	return _start;
}

void		Userinfo::setStart(int i) {
	_start = i;
}
