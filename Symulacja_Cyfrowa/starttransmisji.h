#ifndef STARTTRANSMISJI_H_
#define STARTTRANSMISJI_H_

#include<iostream>
#include"pakiet.h"
#include"system.h"

using namespace std;

class StartTransmisji{
private:
	System* system_;
	double czas_;
	int id_;

public:
	void UstawCzas(double a);
	double ZwrocCzas();
	StartTransmisji(int ,double, System *);
	void Wykonaj(bool flaga);


};


#endif STARTTRANSMISJI_H_
