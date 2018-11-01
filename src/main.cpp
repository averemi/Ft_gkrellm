

#include "../inc/ft_gkrellm.h"
#include "../inc/Text.hpp"
#include "../inc/Graphic.hpp"

int		main(int ac, char *av[]) {
	// bonuses: virtual memory (vm_stat) - or some other useful information! (+1 or + 2 modules)
	if (ac == 2) {
		if (strlen(av[1]) == 2 && av[1][0] == '-' &&\
			av[1][1] == 't') {
			Text text;
			text.displayAll();
		}
			
		else if (strlen(av[1]) == 2 && av[1][0] == '-' &&\
			av[1][1] == 'g') {
			Graphic graph;
			graph.displayAll();
		}	
	}
	else {
		std::cout << "Usage: ./ft_gkrellm -t" << std::endl;
		std::cout << "       ./ft_gkrellm -g" << std::endl;
	}
	return 0;
}

