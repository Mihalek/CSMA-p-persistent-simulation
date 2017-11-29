#ifndef PAKIET_H_
#define PAKIET_H_

//Klasa reprezentujaca pakiet transmitowany przez siec bezprzewodowa


class Pakiet {
private:
	int id_; // nr nadajnika i odbiornika
	double CzasUtworzeniaPakietu_; //czas w ktorym pakiet pojawil sie w buforze
	int CTP_;  // czas transmisji pakietu
	int identyfikator;  //nr pakietu nadawany od 0 do ...
	bool starttransmisji_; // zmienna przechowujaca czy pakiet zos
	double czas_tranmisji_; //czas transmisji pakietu	
	int liczbaretransmisji_; //liczba retransmisji danego pakietu
	bool ustawieniekolizji_; // czy wystapila kolizja dla pakietu
	bool odebrany_; // czy pakiet zostal odebrany
	double czas; // czas w jakim czasie bedzie transmisja pakietu
	bool utworzony_; // czy pakiet zostal utworzony
public:
	Pakiet(int, double, int);
	Pakiet(int);
	~Pakiet();
	void UstawUtworzenie(bool a);
	bool ZwrocUtworzenie();
	double ZwrocCzasUtworzeniePakietu();
	int GetNadawca();
	int GetOdbiorca();
	bool ZwrocKolizje();
	void UstawKolizje(bool);
	void SetIdentyfikator(int);
	int GetIdentyfikator(); 
	void UstawJakDlugoTrwaTransmisjaPakietu(double);
	double ZwrocJakDlugoTrwaTransmisjaPakietu();
	void SetStartTransmisji(bool);
	bool GetStartTransmisji();
	void UstawCzasTransmisji(double czas);
	double ZwrocCzasTransmisji();
	void SetOdebrany(bool);
	void SetLiczbaRetransmisji(int);
	int GetLiczbaRetransmisji();
	

};


#endif PAKIET_H_
