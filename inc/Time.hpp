

#ifndef TIME_HPP
# define TIME_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class Time : public IMonitorModule {
	private:
		tm *_time;
		int _show;
		int _height;
		int _start;
	public:
		Time();
		~Time();
		Time(Time const & a);
		Time& operator=(Time const & a);

		void reload();
		int getShow();
		void setShow(int i);
		int getHeight();
		tm * getDateTime();
		int getStart();
		void	setStart(int i);
};


#endif
