#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cmath>

namespace C {
	
	const double R = 20.0;					///Membrane resistance
	const double tau = 20;					///Membrane time constant
	const double h = 0.1;					///Time step
	const double Vth = 20;					///Spike threshold
	const double Vreset = 10;				///Membrane potential after the spike
	const double refractory_time = 2;		///Refractory time
	const double J = 1;						///Value of the current received if a neuron spikes
	const unsigned long refractory_steps=20;///steps per refractory_time
	
	const double c1 =exp(-h/tau);			///Constant for the ODE integration
	const double c2 =R*(1.0-c1);			///Constant for the ODE integration
	
	const double delay = 1.5 ;							///synaptic delay in ms
	
	
	///number of neurons
	const double n = 0.25;
	const int n_excitatory = 10000;
	const int n_inhibitory = n * n_excitatory;
	const int n_total = n_excitatory + n_inhibitory;
	
	///number of connections between neurons
	const double eps = 0.1;
	const int c_excitatory = eps * n_excitatory;
	const int c_inhibitory = eps * n_inhibitory;
	const int c_total = c_excitatory + c_inhibitory;
	
	
	///constants to run the simulation
	const unsigned long time_simulation = 5000;
	
}

#endif
