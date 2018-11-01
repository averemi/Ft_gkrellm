


#ifndef USERINFO_HPP
# define USERINFO_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"


class Userinfo : public IMonitorModule {
	private:
		std::string _hostname;
		std::string _username;
		int _show;
		int _height;
		int _start;
	public:
		Userinfo();
		~Userinfo();
		Userinfo(Userinfo const & a);
		Userinfo& operator=(Userinfo const & a);

		const char* getHostName();
		const char* getUserName();
		void reload();
		int getShow();
		void setShow(int i);
		int getHeight();
		int getStart();
		void	setStart(int i);

};


#endif
