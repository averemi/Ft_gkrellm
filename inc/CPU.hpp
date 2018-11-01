


#ifndef CPU_HPP
# define CPU_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class CPU : public IMonitorModule {
	private:
		std::string _model;
		int _cores;
		int _cpus;
		const char * _clock_speed;
		double _speed;
		double  _user;
		double  _sys;
		double  _idle;
		int		_show;
		int _height;
		int _start;
	public:
		CPU();
		~CPU();
		CPU(CPU const & a);
		CPU& operator=(CPU const & a);

		void setStaticData();
		void setDynamicData();
		void cpu_activity();
		const char * getModel();
		int getCpus();
		int getCores();
		const char * getClockSpeed();
		int getHeight();
		double getActUser();
		double getActSys();
		double getActIdle();
		int getShow();
		void setShow(int i);
		double getSpeed();
		void	reload();
		int		getStart();
		void	setStart(int i);

};



#endif
