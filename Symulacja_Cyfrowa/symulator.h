#pragma once
#include"pakiet.h"
#include"system.h"
#include<vector>
#include"odebraniepakietu.h"
#include"utworzeniepakietu.h"
#include"kolizja.h"
#include"retransmisjapakietu.h"
#include"starttransmisji.h"
#include"wyslanieack.h"
#include"sprawdzkanal.h"
#include"dostarczenieack.h"
#include <fstream>
#include <cstdlib>
#include"wyslaniepakietu.h"

// Klasa odpowiadajaca za symulacje dzialania sieci , znajduje sie w niej funkcja symulujaca oraz funkcja odpowiadajaca za statystyki


class Symulator{

	// Wskaznik na Zdarzenia

	UtworzeniePakietu* nowy_pakiet1_;
	UtworzeniePakietu* nowy_pakiet2_;
	UtworzeniePakietu* nowy_pakiet3_;
	UtworzeniePakietu* nowy_pakiet4_;
	UtworzeniePakietu* nowy_pakiet5_;
	UtworzeniePakietu* nowy_pakiet6_;
	UtworzeniePakietu* nowy_pakiet7_;
	UtworzeniePakietu* nowy_pakiet8_;
	UtworzeniePakietu* nowy_pakiet9_;
	UtworzeniePakietu* nowy_pakiet10_;
	SprawdzKanal* sprawdz_kanal1_;
	SprawdzKanal* sprawdz_kanal2_;
	SprawdzKanal* sprawdz_kanal3_;
	SprawdzKanal* sprawdz_kanal4_;
	SprawdzKanal* sprawdz_kanal5_;
	SprawdzKanal* sprawdz_kanal6_;
	SprawdzKanal* sprawdz_kanal7_;
	SprawdzKanal* sprawdz_kanal8_;
	SprawdzKanal* sprawdz_kanal9_;
	SprawdzKanal* sprawdz_kanal10_;
	StartTransmisji* start_transmisji1_;
	StartTransmisji *start_transmisji2_;
	StartTransmisji* start_transmisji3_;
	StartTransmisji* start_transmisji4_;
	StartTransmisji* start_transmisji5_;
	StartTransmisji* start_transmisji6_;
	StartTransmisji *start_transmisji7_;
	StartTransmisji* start_transmisji8_;
	StartTransmisji* start_transmisji9_;
	StartTransmisji* start_transmisji10_;
	WyslaniePakietu *wyslanie_pakietu_;
	OdebraniePakietu *odebranie_pakietu_;
	Kolizja *kolizja_;
	WyslanieAck *wyslanie_ack_;
	DostarczenieAck *dostarczenie_ack_;
	RetransmisjaPakietu *retransmisja_pakietu1_;
	RetransmisjaPakietu *retransmisja_pakietu2_;
	RetransmisjaPakietu *retransmisja_pakietu3_;
	RetransmisjaPakietu *retransmisja_pakietu4_;
	RetransmisjaPakietu *retransmisja_pakietu5_;
	RetransmisjaPakietu *retransmisja_pakietu6_;
	RetransmisjaPakietu *retransmisja_pakietu7_;
	RetransmisjaPakietu *retransmisja_pakietu8_;
	RetransmisjaPakietu *retransmisja_pakietu9_;
	RetransmisjaPakietu *retransmisja_pakietu10_;
	System *system_; // Wskaznik na system sieci bezprzewodowej
	vector<double> czasy_zdarzen_; // wektor z czasami zdarzen
	double eps_; // zmienna pomocnicza do wybierania najmniejszego czasu w wektorze
	int flaga_; // flaga informujaca czy chcemy wyswietlac logi czy nie
	int ilosc_; // zmienna informujaca o ilosci nadajnikow i odbiornikow
	int flaga2_; // flaga informujaca czy chcemy wlaczyc symulacje z trybek ciaglym lub krokowym
	int numer_symulacji_; // numer aktualnej symulacji
	int czas_symulacji_; // czas trwania symulacji
	double faza_poczatkowa_; // zmienna przechowuja czas konca fazy poczatkowej
	fstream wyniki_; // deklaracja zmiennej pozwalajacej nam zapisywac wyniki do pliku tekstowego
public:
	Symulator(int ilosc, __int64 ziarna_[], int flaga, int flaga2, double faza_poczatkowa, int numer_symulacji, int czas_symulacji);

	~Symulator();
	void Symuluj();
	void Statystyki(int);
	void WyczyscStatystyki();
	bool PorownajCzasy(double czas_systemowy, double czas_zdarzenia);
	double UaktualnijCzas();
	System* ZwrocSystem();



};

