
#include <iostream>
#include "neuron.hpp"
using namespace std;




int main() {
	
	double start_time(0);
	double stop_time(0);
	double Iext(0);
	double a(0);
	double b(0);
	
	
	cout << "How long do you want the simulation to last ?" << endl;
	cin >> stop_time;
	
	cout << "Which time interval do you want for the external current ? " << endl;
	cin >> a;
	cin >> b;
	cout << "Which external current do you want for this interval? " << endl;
	cin >> Iext;
	
	double simulation_time(start_time);
	
	Neuron neuron;
	
	while (simulation_time <= stop_time) 
	{
		if ((simulation_time >= a) and (simulation_time < b)) 
		{
			neuron.update(Iext, simulation_time);
		}
		else
		{
			neuron.update(I, simulation_time);
		}
		simulation_time += h;
	}
	return 0;
}
