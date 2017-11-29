#ifndef ODEBRANIEPAKIETU_H_
#define ODEBRANIEPAKIETU_H_
#include"system.h"
#include<fstream>

class OdebraniePakietu {
private:
	System * system_;
	double czas_;
	fstream faza_;
	fstream pakiety_;


public:
	OdebraniePakietu(double, System*);
	double ZwrocCzas();
	void UstawCzas(double);
	void Wykonaj(bool);
	~OdebraniePakietu();




};


#endif ODEBRANIEPAKIETU_H_