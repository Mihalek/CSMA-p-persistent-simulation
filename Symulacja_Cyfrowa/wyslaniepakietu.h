#ifndef WYSLANIEPAKIETU_H_
#define WYSLANIEPAKIETU_H_

#include<iostream>
#include"pakiet.h"
#include"system.h"
#include<fstream>
class WyslaniePakietu{
private:
	System *system_;
	fstream wyniki_;
	fstream wyniki2_;

public:
	WyslaniePakietu(System *);
	void Wykonaj(bool flaga);





};

#endif WYSLANIEPAKIETU_H_