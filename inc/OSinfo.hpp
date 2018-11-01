


#ifndef OSINFO_HPP
# define OSINFO_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class OSinfo : public IMonitorModule {
	private:
		std::string _version;
		std::string _kernel;
		std::string _boot_vol;
		std::string _boot_mode;
		std::string _secure_virt_mem;
		std::string _system_integr;
		std::string _time_since_boot;
		int _start;
		int _show;
		int _height;
	public:
		OSinfo();
		~OSinfo();

		OSinfo(OSinfo const &a);
		OSinfo& operator=(OSinfo const &a);
		void	setStart(int i);
		const char * getVersion();
		const char * getKernel();
		const char * getBootVol();
		const char * getBootMode();
		const char * getSecureVirtMem();
		const char * getSystemIntegr();
		const char * getTimeSinceBoot();
		void	reload();
		int getStart();
		int getShow();
		void setShow(int i);
		int getHeight();

};


#endif
