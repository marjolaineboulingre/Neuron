#include <cassert>
#include <iostream>
#include <fstream>
#include "neuron.hpp"
#include "network.hpp"
#include "constants.hpp"

using namespace std;


int main(int argc, char* argv[]) 
{
	Network network;
	unsigned int time_sim(0);
	
	//network.run2neurons(time_sim);
	//network.run(time_sim);
	
	//network.saveTimeSpikes();
	
	int progress(1);
	int progress_rate(0.01*C::time_simulation);
	
	
	network.createNetwork();
	network.createConnections();
	
	while(time_sim < C::time_simulation) 
	{
		if(time_sim > progress_rate) 
		{
			cout << progress << "%" << endl;
			progress += 1;
			progress_rate += 0.01*C::time_simulation;
		}
	
	network.update(time_sim);
	++time_sim; 
	}
	
	return 0;
}
