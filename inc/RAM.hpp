


#ifndef RAM_HPP
# define RAM_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class RAM : public IMonitorModule {
	private:
		long long	 _mem;
		char _mem_size;
		double _memMB;
		long long  _used;
		double	 _usedMB;
		char _used_size;
		long long  _wired;
		double	 _wiredMB;
		char _wired_size;
		long long  _unused;
		double	 _unusedMB;
		char _unused_size;
		int _show;
		int _height;
		int _start;
	public:
		RAM();
		~RAM();
		RAM(RAM const & a);
		RAM& operator=(RAM const & a);

		void reload();
		long long getUsedMem();
		int getHeight();
		char getUsedSize();
		long long getWiredMem();
		char getWiredSize();
		void	setStart(int i);
		long long getUnusedMem();
		char getUnusedSize();
		void calculateLoad();
		double getUsedMB();
		double getUnusedMB();
		double getWiredMB();
		int getShow();
		void setShow(int i);
		int getStart();

};



#endif
