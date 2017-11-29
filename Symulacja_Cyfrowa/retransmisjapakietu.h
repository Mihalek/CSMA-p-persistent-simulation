#ifndef RETRANSMISJAPAKIETU_H_
#define RETRANSMISJAPAKIETU_H_
#include"system.h"
#include"pakiet.h"
#include<Windows.h>


class RetransmisjaPakietu{
private:
	System* system_;
	int id_;
	double czas_;
public:
	RetransmisjaPakietu(int id ,System * system);
	void Wykonaj(bool flaga_);

	double ZwrocCzas();



};

#endif RETRANSMISJAPAKIETU_H_