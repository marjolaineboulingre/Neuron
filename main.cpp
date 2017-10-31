#include <cassert>
#include <iostream>
#include <fstream>
#include "neuron.hpp"
#include "network.hpp"
#include "simulation.hpp"


using namespace std;


int main(int argc, char* argv[]) 
{
	/*ofstream spike("potential.dat"); 
	
	if(argc>1)			///send an error
	{
		I_ext=atof(argv[1]);
	}*/
	
	Simulation sim;
	sim.run2neurons();
	sim.run();
	
	return 0;
}
