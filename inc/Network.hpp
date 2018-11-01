


#ifndef NETWORK_HPP
# define NETWORK_HPP

# include "ft_gkrellm.h"
# include "IMonitorModule.hpp"

class Network : public IMonitorModule {
	private:
		long long _in;
		long long _out;
		char _insize;
		char _outsize;
		long long _inM;
		long long _outM;
		int _start;
		int _show;
		int _height;
	public:
		Network();
		~Network();
		Network(Network const & a);
		Network& operator=(Network const & a);

		void		reload();
		long long getIn();
		void	setStart(int i);
		long long getOut();
				int getShow();
		void setShow(int i);
		int getHeight();
		long long getInM();
		long long getOutM();
		char getInSize();
		char getOutSize();
		int	getStart();

};



#endif
