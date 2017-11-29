#ifndef ODBIORNIK_H_
#define ODBIORNIK_H_
#include<vector>
#include"pakiet.h"

using namespace std;

//klasa reprezentujaca odbiornik sieci telekomunikacyjnej


class Odbiornik {
private:
	int id_; // nr odbiornika od 0 do ...
	Pakiet* odebranypakiet_; // zmienna przechowujaca ostatni odebrany pakiet przez odbiornik
	vector<Pakiet*> odebranepakiety_; // wektor przechowujacy odebrane pakiety przez odbiornik

public:
	Odbiornik(int);  // konstruktor klasy odbiornik ktorego argumentem jest jego nr
	~Odbiornik(); // destruktor klasy odbiornik 
	int GetID();  //funkcja zwracajaca nr odbiornika
	void SetOdebranyPakiet(Pakiet*);  // funkcja ustawiajaca ostatni odebrany pakiet
	Pakiet* ZwrocOdebranyPakiet(); // funkcja zwracajaca ostatni odebrany pakiet
	void DodajDoOdebranychPakietow(Pakiet*); //funkcja dodajaca pakiet do odebranych przez odbiornik

};




#endif ODBIORNIK_H_