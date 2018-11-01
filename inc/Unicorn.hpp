


#ifndef UNICORN_HPP
# define UNICORN_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class Unicorn : public IMonitorModule {
	private:
		int _show;
		int _height;
		int _uni;
		int _start;
	public:
		Unicorn();
		~Unicorn();
		Unicorn(Unicorn const & a);
		Unicorn& operator=(Unicorn const & a);

		int getShow();
		int getHeight();
		int getUni();
		void setUni(int i);
		void setShow(int i);
		void reload();
		int getStart();
		void	setStart(int i);
};

#endif
