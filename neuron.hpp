#ifndef NEURON_H
#define NEURON_H


#include <iostream>
#include <vector>

const int C = 1;
const int tau = 20;
const int h = 0.01;
const double Vth = 20;
const double Vreset = 10;
const double refractory_time = 2;
const double I = 0;

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
		virtual ~Neuron() = default;
		
		double getMembranePotential() const;
		//double getNumberSpikes() const;	
		//double getTimeSpikes() const;
		
		double setMembranePotential(double mem_pot);
		bool isSpiking() const;
		bool isRefractory(double time) const;
		
		void update(double current, double time);
};

#endif 
