#pragma once
#include"system.h"
#include"kanaltransmisyjny.h"

class SprawdzKanal {
private:
	System* system_;
	int id_;
	double czas_;
public:

	SprawdzKanal(int id,double czas, System *system);
	void Wykonaj(bool flaga);
	double ZwrocCzas();
	void UstawCzas(double);


};