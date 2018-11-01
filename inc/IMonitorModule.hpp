
#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include "ft_gkrellm.h"

class IMonitorModule {
	public:
		virtual void reload() = 0;
		virtual int getShow() = 0;
		virtual void setShow(int i) = 0;
		virtual int getHeight() = 0;
		virtual int getStart() = 0;
		virtual void setStart(int i) = 0;
};


#endif

