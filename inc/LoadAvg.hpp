




#ifndef LOADAVG_HPP
# define LOADAVG_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class LoadAvg : public IMonitorModule {
	private:
		double _one_min;
		double _five_min;
		double _fifteen_min;
		int _show;
		int _height;
		int _start;
	public:
		LoadAvg();
		~LoadAvg();
		LoadAvg(LoadAvg const & a);
		LoadAvg& operator=(LoadAvg const & a);

		void		reload();
		double			getOneMin();
		double			getFiveMin();
		void	setStart(int i);
		int getHeight();
		double			getFifteenMin();
		int getShow();
		void setShow(int i);
		int getStart();
};



#endif
