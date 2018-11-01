



#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

# include "ft_gkrellm.h"
# include "Userinfo.hpp"
# include "IMonitorDisplay.hpp"
# include "Time.hpp"
# include "OSinfo.hpp"
# include "CPU.hpp"
# include "RAM.hpp"
# include "Network.hpp"
# include "Processes.hpp"
# include "LoadAvg.hpp"
# include "Unicorn.hpp"

class Graphic : public IMonitorDisplay {
	private:
		Userinfo _user;
		Time	_time;
		OSinfo	_os;
		CPU		_cpu;
		RAM		_ram;
		Network _network;
		Processes _pros;
		LoadAvg _load;
		int		 _yMax;
		int		_xMax;
		int		_xWin;
		int		_yWin;
		int _x;
		int _y;
		WINDOW * _winfo;
		Unicorn _unicorn;
	public:
		Graphic();
		~Graphic();
		Graphic(Graphic const & a);
		Graphic& operator=(Graphic const & a);

		void  makeBackground(WINDOW * _winfo, int y1, int y2);
		void  CPUgraph(WINDOW * _winfo, int y);
		void  RAMgraph(WINDOW * _winfo, int y);;
		void displayAll();
		int   chooseColor(int count);
		void   UserInfoDisplay();
    	void	DateTimeDisplay();
    	void	OSinfoDisplay();
    	void	CPUdisplay();
    	void	RAMdisplay();
    	void	NetworkDisplay();
    	void	ProcessDisplay();
    	void	LoadAvgDisplay();
    	void	displayMenu();
    	void	drawUnicorn();

};


#endif
