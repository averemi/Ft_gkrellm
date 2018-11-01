


#ifndef PROCESSES_HPP
# define PROCESSES_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class Processes : public IMonitorModule {
	private:
		int _total;
		int _running;
		int _show;
		int _height;
		int _start;
	public:
		Processes();
		~Processes();
		Processes(Processes const & a);
		Processes& operator=(Processes const & a);

		void		reload();
		int			getTotal();
		void	setStart(int i);
		int			getRunning();
		int getHeight();
		int getShow();
		void setShow(int i);
		int getStart();
};



#endif
