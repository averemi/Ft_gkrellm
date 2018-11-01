



#ifndef TEXT_HPP
# define TEXT_HPP

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

class Text : public IMonitorDisplay {
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
		Unicorn _unicorn;
		int _x;
		int _y;
		WINDOW * _winfo;
	public:
		Text();
		~Text();
		Text(Text const & a);
		Text& operator=(Text const & a);

		void  makeBackground(WINDOW * _winfo, int y1, int y2);
		void displayAll();
		void   UserInfoDisplay();
    	void	DateTimeDisplay();
    	void	OSinfoDisplay();
    	void	CPUdisplay();
    	void	RAMdisplay();
    	void	NetworkDisplay();
    	void	ProcessDisplay();
    	void	LoadAvgDisplay();
    	void	displayMenu();
    	void  drawUnicorn();

};


#endif
