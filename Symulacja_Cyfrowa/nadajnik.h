#ifndef NADAJNIK_H_
#define NADAJNIK_H_

#include<iostream>
#include<queue>
#include"pakiet.h"
#include "generator.h"

using namespace std;

//klasa reprezentujaca nadajnik bezprzewodowej sieci telekomunikacyjnej

class Nadajnik {
private:
	int id_;  //nr nadajnika
	queue <Pakiet*> bufor_; //bufor w ktorym pakiety oczekuja na transmisje
	double czas_transmisji_; //czas transmisji pakietu przez kanal transmisyjny - losowa wartosc
	bool retransmisja_; // czy pakiet byl retransmitowany
	int liczba_retransmisji_; // zmienna majaca na celu przechowywanie liczby retransmisji z nadajnika
	int czas_transmisji_najstarszego_pakietu; // zmienna przechowujaca czas transmisji pierwszego pakietu w buforze
	double liczba_odebranych_pakietow_; // liczba odebranych pakietow przez odbiornik o id nadajnika
	double liczba_straconych_pakietow_; // liczba straconych pakietow nadawanych tym nadajnikiem
public:
	void UstawCzasTransmisjiNajstarszegoPakietu(int);  //funkcja ustawiajaca czas transmisji najstarszego pakietu
	int ZwrocCzasTransmisjiNajstarszegoPakietu();  //funkcja zwracajaca czas transmisji najstarszego pakietu
	Nadajnik(int);	//konstruktor klasy nadajnik ktorego argumentem jest jego nr id od 0 do ...
	void WyzerujRetransmisje(); //funkcja zerujaca liczbe retransmisji
	void ZwiekszLiczbeRetransmisji(); //funkcja zwiekszajaca liczbe retransmisji o 1 
	int ZwrocLiczbeRetransmisji(); //funkcja zwracajaca liczbe retransmisji 
	double ZwrocCzasNajblizszejTransmisji(); //funkcja zwracajaca czas najblizszej transmisji z nadajnika
	void DodajPakietDoBufora(Pakiet*); //funkcja dodajaca pakiet do buforu
	void UstawCzasNajblizszejTransmisji(double); //funkcja ustawiajaca czas najblizszej transmisji z nadajnika
	int GetID(); //funkcja zwracajaca ID nadajnika
	Pakiet* ZwrocNajstarszyPakiet(); //funkcja zwracajaca najstarszy pakiet ktory pojawil sie w buforze nadajnika
	void UstawKoniecznoscRetransmisji(bool); //funkcja ustawiajaca koniecznosc retransmisji najstarszego pakietu z buforu nadajnika
	bool ZwrocKoniecznoscRetransmisji(); //funkcja zwracajaca koniecznosc retransmisji najstarszego pakietu z buforu nadajnika
	void PowiekszliczbeOdebranychPakietow(); //funkcja powiekszajaca liczbe odebranych pakietow o 1 
	void PowiekszliczbeStraconychPakietow(); //funkcja powiekszajaca liczbe straconych pakietow o 1
	double ZwrocliczbeOdebranychPakietow(); //funkcja zwracajaca liczbe odebranych pakietow
	double ZwrocliczbeStraconychPakietow(); //funkcja zwracajaca liczbe straconych pakietow
	void WyzerujLiczbeOdebranychPakietow(); //funkcja czyszcz¹ca statystyki odebranych pakietow w systemie oraz w stacjach
	void WyzerujLiczbeStraconychPakietow(); //funkcja czyszcz¹ca statystyki straconych pakietow w systemie oraz w stacjach
	void UsunNajstarszyPakietZBufora(); //funkcja usuwajaca najstarszy pakiet z bufora nadajnika
	int ZwrocRozmiarBufora(); //funkcja zwracajaca ilosc pakietow w buforze
	~Nadajnik(); //destruktor klasy nadajnik
};


#endif NADAJNIK_H_