#ifndef NEURON_H
#define NEURON_H


#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;
	
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
	

	
class Neuron {
	
	private:
	
								
	
	
	double membrane_potential; 				///Membrane potential
	double Iext;							///external current
	double delay;							///synaptic delay in ms
	unsigned long t_spike;					///time of last spike
	unsigned long n_spikes;					///number of spikes
	unsigned long clock;					///internal time of the neuron
	unsigned long delay_steps; 				///synaptic delay in steps
	
	vector<double> potential_historical;	///historical of the mebrane potential
	vector<double> times_historical;		///historical of the times spikes
	vector<double> spike_buff;				///Input buffer for spikes

	
	public:
	
		Neuron();
		
		///getters
		double getMembranePotential() const;
		double getExtCurrent() const;
		unsigned long getLastTimeSpike() const;
		unsigned long getClock() const;

		///setters
		void setMembranePotential(double mem_pot);
		void setExtCurrent(double I);
		
		
		bool isSpiking() const;						///test if the neuron spikes
		bool isRefractory(long c) const;					///test if the neuron is refractory	

		void updatePotential(); 					///update the potential of the neuron
		void update();								///update the state of the neuron
		void receive_spike(unsigned long arrival, double potential); 		///when the neuron receives a spike

		double convertMs(long c); 				///convert a time (in ms) in steps
};


#endif 
