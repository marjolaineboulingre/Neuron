#ifndef NEURON_H
#define NEURON_H


#include <iostream>
#include <vector>

const int C = 1;
const int tau = 20;
const double h = 0.1;
const double Vth = 20;
const double Vreset = 10;
const double refractory_time = 2;
const double I = 0;
const double J = 1;

using namespace std;

class Neuron {
	
	private:
	
		double membrane_potential;
		//int number_spikes;
		int last_time_spikes;
		vector<double> potential_historical;
		vector<double> times_historical;
	
	public:
	
		Neuron(double mp, int t); 
		Neuron();
		//virtual ~Neuron() = default;
		
		double getMembranePotential() const;
		//double getNumberSpikes() const;	

		void setMembranePotential(double mem_pot);
		
		bool isSpiking() const;
		bool isRefractory(double time) const;
		double getLastSpike() const;
		
		void update(double current, double time);
};

#endif 
