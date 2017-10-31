#ifndef SIMULATION_H
#define SIMULATION_H

#include "network.hpp"



class Simulation {
	
	private:
	Network network;
	unsigned long timeSimulation;
	
		
	public:
	Simulation();
	
	void run2neurons();
	void run();

	
};


#endif
