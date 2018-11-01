



#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

# include "ft_gkrellm.h"

class IMonitorDisplay {
	public:
		virtual void makeBackground(WINDOW * _winfo, int y1, int y2) = 0;
		virtual void UserInfoDisplay() = 0;
		virtual void DateTimeDisplay() = 0;
		virtual void OSinfoDisplay() = 0;
		virtual void CPUdisplay() = 0;
		virtual void RAMdisplay() = 0;
		virtual void NetworkDisplay() = 0;
		virtual void ProcessDisplay() = 0;
		virtual void LoadAvgDisplay() = 0;
		virtual void displayMenu() = 0;
		virtual void drawUnicorn() = 0;
		virtual void displayAll() = 0;

};


#endif

