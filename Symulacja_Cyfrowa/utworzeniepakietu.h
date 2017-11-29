#ifndef UTWORZENIEPAKIETU_H_
#define UTWORZENIEPAKIETU_H_

#include"nadajnik.h"
#include"system.h"
class UtworzeniePakietu{
private:
	double czas_;
	int id_;
	System *system_;
	int nr_nadajnika_;

public:
	UtworzeniePakietu(int nr_nadajnika, double czas, int id, System *system);
	double ZwrocCzas();
	void Wykonaj(bool flaga);

};

#endif UTWORZENIEPAKIETU_H_