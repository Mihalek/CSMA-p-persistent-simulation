#ifndef KOLIZJA_H_
#define KOLIZJA_H_

#include"system.h"
#include<Windows.h>

class Kolizja{
	System *system_;
public:
	Kolizja(System*);
	void Wykonaj(bool flaga);
};



#endif KOLIZJA_H_