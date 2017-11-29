#ifndef KANALTRANSMISYJNY_H_
#define KANALTRANSMISYJNY_H_

#include<iostream>
#include<vector>
#include"pakiet.h"
using namespace std;

// Klasa reprezentujaca kanal transmisyjny pomiedzy nadajnikiem a odbiornikiem


class KanalTransmisyjny {
private:
	vector<Pakiet*> kanal_;  // wektor reprezentujacy kanal transmisyjny
public:
	void DodajPakiet(Pakiet*);  //funkcja sluzaca do dodania pakietu transmitowanego do kanalu
	int IloscPakietowWKanale();	 //funkcja zwracajaca ilosc pakietow w kanale
	bool CzyJestPusty(); //funkcja sprawdzajaca czy kanal jest pusty
	Pakiet* PobierzPakiet(); //funkcja pobierajaca pakiet z kanalu transmisyjnego
	void UsunPakiet(Pakiet*); //funkcja usuwajaca konkretny pakiet z kanalu
	void UsunPakiety();  //funkcja usuwajaca wszystkie pakiety z kanalu



};


#endif KANALTRANSMISYJNY_H_
