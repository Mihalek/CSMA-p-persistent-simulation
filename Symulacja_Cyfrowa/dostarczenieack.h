#pragma once
#include"system.h"
class DostarczenieAck {
private:
	System *system_;
	double czas_;
public:
	DostarczenieAck(double czas, System *system);
	void Wykonaj(bool flaga);
	double ZwrocCzas();
	void UstawCzas(double);

};