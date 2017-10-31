#include "simulation.hpp"
#include <iostream>



Simulation::Simulation()
	:
	timeSimulation(C::time_simulation), network()
{}




void Simulation::run2neurons() {
	
	Neuron n1;
	Neuron n2;
	
	int i_start = 1000 ;
	int i_stop = 4000;
	double Iext = 1.01;
	
	for(int t=0; t<=timeSimulation; ++t)
	{
		if((t>=i_start) and (t<=i_stop)) 
		{
			n1.setExtCurrent(Iext);
		}
		else
		{
			n1.setExtCurrent(0.0);
		}
		n1.update(1);
		n2.update(1);
		
		if (n1.isSpiking()) {
			std::cout << "Spikes 1 at : " << n1.convertMs(n1.getLastTimeSpike()) << std::endl;
			n2.receive_spike( n1.getLastTimeSpike() + n1.getDelay(), n1.getMembranePotential());
		}
		
		if(n2.isSpiking()) {
			std::cout << "Spikes 2 at: " << n2.convertMs(n2.getLastTimeSpike()) << std::endl;
		
		}
	}
	
}



void Simulation::run(){
		
	Network net;
	net.createNetwork();
	net.createConnections();
	unsigned long t(0);
	
	while(t < timeSimulation) {
		net.update(t);
		
		/*for(auto n = 0; n < C::n_total; ++n)
		{
			if (net[n].isSpiking())*/
			
		std::cout << "1" << std::endl;
		++t;
	}
	
}


