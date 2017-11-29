#include "pakiet.h"

Pakiet::Pakiet(int id, double CzasUtworzeniaPakietu, int CTP) : id_(id), CzasUtworzeniaPakietu_(CzasUtworzeniaPakietu), CTP_(CTP), starttransmisji_(false){
	czas = 0;
	ustawieniekolizji_ = false;
	liczbaretransmisji_ = 0;

}
Pakiet::Pakiet(int id) : id_(id), starttransmisji_(false), odebrany_(false),liczbaretransmisji_(0) {}


Pakiet::~Pakiet()
{
}

void Pakiet::UstawUtworzenie(bool a)
{	
	utworzony_ = a;
}

bool Pakiet::ZwrocUtworzenie()
{
	return utworzony_;
}

double Pakiet::ZwrocCzasUtworzeniePakietu()
{
	return CzasUtworzeniaPakietu_;
}

int Pakiet::GetNadawca()
{
	return id_;
}
int Pakiet::GetOdbiorca()
{
	return id_;
}
bool Pakiet::ZwrocKolizje()
{
	return ustawieniekolizji_;
}
void Pakiet::UstawKolizje(bool a)
{
	ustawieniekolizji_ = a;
}
void Pakiet::SetIdentyfikator(int a)
{
	identyfikator = a;
}
int Pakiet::GetIdentyfikator()
{
	return identyfikator;
}
void Pakiet::UstawJakDlugoTrwaTransmisjaPakietu(double a)
{
	czas_tranmisji_ = a;
}
double Pakiet::ZwrocJakDlugoTrwaTransmisjaPakietu()
{
	return czas_tranmisji_;
}
void Pakiet::SetStartTransmisji(bool zmienna)
{
	starttransmisji_ = zmienna;
}

bool Pakiet::GetStartTransmisji()
{
	return starttransmisji_;
}

void Pakiet::UstawCzasTransmisji(double a)
{
	czas = a;
}

double Pakiet::ZwrocCzasTransmisji()
{
	return czas;
}

void Pakiet::SetOdebrany(bool zmienna)
{
	odebrany_ = zmienna;
}

void Pakiet::SetLiczbaRetransmisji(int a)
{
	liczbaretransmisji_ = a;
}

int Pakiet::GetLiczbaRetransmisji()
{
	return liczbaretransmisji_;
}






