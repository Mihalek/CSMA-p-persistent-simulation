#ifndef SYSTEM_H_
#define SYSTEM_H_
#include"kanaltransmisyjny.h"
#include"nadajnik.h"
#include"odbiornik.h"
#include<queue>
#include"pakiet.h"

// Klasa reprezentujaca system calej sieci bezprzewodowej
// Zawiera wszystkie nadajniki i odbiorniki, tworzony jest tutaj kanal transmisyjny
// oraz wszystkie funkcje pomocnicze potrzebne do przeprowadzenia symulacji


class System {
private:
	int ilosc_; // ilosc nadajnikow i odbiornikow
	KanalTransmisyjny *kanaltransmisyjny; // Wskaznik na kanal transmisyjny przekazujacy wysylajacy pakiety pomiedzy nadajnikiem i odbiornikiem
	vector <Nadajnik*> nadajniki_; // wektor przechowujacy nadajniki
	vector <Odbiornik*> odbiorniki_; // wektor przechowujacy odbiorniki
	vector <Generator*> generatoryCGP_; // wektor przechowujacy generatory CGP
	vector <Generator*> generatoryCTP_; // wektor przechowujacy generatory CTP
	vector <Generator*> generatoryPrawd_; // wektor przechowujacy generatory Prawdopodobienstwa
	vector <Pakiet*> pakiety_transmitowane_; // wektor przechowujacy pakiety transmitowane
	vector<Pakiet*> pierwsze_pakiety_z_buforow_; // wektor przechowujacy pierwsze pakiety z buforow
	queue <Pakiet*> kolejka_pakietow_; // kolejka pakietow do transmisji
	int numer_symulacji_; // numer aktualnej symulacji
	int identyfikatory; // zmienna pomocnicza nadawajaca numery ID kolejno utworzonym pakietom
	int czas_symulacji; // czas symulacji
	int liczba_kolizji_; // liczba kolizji w calej sieci
	double czas_najblizszej_transmisji_; //czas w ktorym bedzie transmitowany najblizszy pakiet
	double odebranie_pakietu_; // czas w ktorym zostanie odebrany najblizszy pakiet
	double opoznienie_pakietowe_; // zmienna przechowujaca sume opoznien pakietowych wszystkich pakietow transmitowanych w sieci
	bool kolizja_; //flaga informujaca o tym czy wystapila kolizja i czy konieczna bedzie retransmisja pakietow
	double stat_odebrane_pakiety_w_sieci; //liczba odebranych pakietow przez cala siec
	double stat_stracone_pakiety_w_sieci; //liczba straconych pakietow przez cala siec
	double czas_oczekiwania_; // zmienna przechowujaca sume czasow oczekiwania wszystkich pakietow transmitowanych w sieci
	bool wysylanieack_; // flaga informujaca o tym czy mozna wyslac powiadomienie ACK
	int wyslane_pakiety_; // ilosc wyslanych pakietow
	int id;  // id nadajnika z ktorego bedzie najblizsza transmisja
	Pakiet* pakiet_do_transmisji_; // pakiet ktory aktualnie jest transmitowany w systemie
	double czas; // czas systemowy
	bool rozpoczecie_transmisji_; // flaga informujaca o tym czy nastapilo rozpoczecie transmisji w sieci
	double stat_liczba_retransmisji; //zmienna przechowujaca aktualna liczbe retransmisji wszystkich nadanych pakietow
public:
	System(int, __int64 ziarna[],int numer_symulacji, int czas_sym);
	KanalTransmisyjny* GetKanal();
	Odbiornik* GetOdbiornik(int);
	Nadajnik *GetNadajnik(int);
	double ZwrocCzas();
	void UstawCzasOczekiwania(double a);
	double ZwrocCzasOczekiwania();
	Pakiet* ZwrocPakietTransmitowanyOID(int);
	void UstawOdebraniePakietu(double);
	int zwrocwyslanepakiety();
	void powiekszwyslanepakiety();
	void DodajPakietTransmitowany(Pakiet*);
	Pakiet* ZwrocPakietTransmitowany();
	void UsunPakietTransmitowany();
	void UsunKopie();
	void UstawKolizjePakietow(int id, bool kolizja);
	void UstawWysylanieAck(bool);
	bool ZwrocWysylanieAck();
	void UstawPakietyZKolizja();
	int ZwrocRozmiarKolejkiPakietowTransmitowanych();
	void UstawKolizjePakietuTransmitowanego(int,bool);
	void UsunPierwszyPakietZKolejki();
	void UstawKolizjeNaPakietachNieTransmitowanychIUsun();
	double ZwrocOdebraniePakietu();
	void UstawCzasNajblizszejTransmisji(double a);
	double ZwrocCzasNajblizszejTransmisji();
	void UstawRozpoczecieTransmisji(bool rozptran);
	void PowiekszStatLiczbeOdebranychPakietow();
	void PowiekszStatliczbeStraconychPakietow();
	double ZwrocStatLiczbeOdebranychPakietow();
	double ZwrocStatliczbeStraconychPakietow();
	void UstawOpoznieniePakietowe(double);
	void WyzerujLiczbeRetransmisji();
	void WyzerujLiczbeOdebranychPakietow();
	void WyzerujLiczbeStraconychPakietow();
	double ZwrocOpoznieniePakietowe();
	bool ZwrocRozpoczecieTransmisji();
	Pakiet* ZwrocPakietZKolejki(int id);
	void UstawCzas(double);
	void DodajDoKolejki(Pakiet*);
	void UstawPakietDoTransmisji(Pakiet*);
	void PowiekszStatLiczbeRetransmisji();
	double ZwrocStatLiczbeRetransmisji();
	Pakiet * ZwrocPakietDoTransmisji();
	Pakiet* ZwrocPierwszyPakiet();
	Generator *GetGeneratorCGP(int id);
	Generator *GetGeneratorCTP(int id);
	Generator *GetGeneratorPrawd(int id);
	int ZwrocIdentyfikatory();
	void UstawIdentyfikatory(int);
	void DodajDoPierwszePakietyZBuforow(int id, Pakiet* a);
	Pakiet* ZwrocZPierwszychPakietowZBuforow(int id);
	int ZwrocIDnadtran();
	void UstawIDnadtran(int a);






};

#endif SYSTEM_H_