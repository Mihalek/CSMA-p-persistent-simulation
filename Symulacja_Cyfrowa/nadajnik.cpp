#include "nadajnik.h"

void Nadajnik::UstawCzasTransmisjiNajstarszegoPakietu(int a)
{
	czas_transmisji_najstarszego_pakietu = a;
}

int Nadajnik::ZwrocCzasTransmisjiNajstarszegoPakietu()
{
	return czas_transmisji_najstarszego_pakietu;
}

Nadajnik::Nadajnik(int id) : id_(id) {
	czas_transmisji_ = -1;
	retransmisja_ = false;
	liczba_retransmisji_ = 0;
	liczba_odebranych_pakietow_ = 0;
	liczba_straconych_pakietow_ = 0;
}
void Nadajnik::WyzerujRetransmisje()
{
	liczba_retransmisji_ = 0;
}
void Nadajnik::ZwiekszLiczbeRetransmisji()
{
	liczba_retransmisji_ += 1;
}
int Nadajnik::ZwrocLiczbeRetransmisji()
{
	return liczba_retransmisji_;
}
double Nadajnik::ZwrocCzasNajblizszejTransmisji()
{
	return czas_transmisji_;
}
;

void Nadajnik::DodajPakietDoBufora(Pakiet * wygenerowany_pakiet_)
{
	bufor_.push(wygenerowany_pakiet_);

}

void Nadajnik::UstawCzasNajblizszejTransmisji(double a)
{
	czas_transmisji_ = a;
}

int Nadajnik::GetID()
{
	return id_;
}

int Nadajnik::ZwrocRozmiarBufora() {
	return bufor_.size();
}

Pakiet * Nadajnik::ZwrocNajstarszyPakiet()
{
	if (bufor_.size() == NULL) {
		return NULL;
		
	}

	else {
		return bufor_.front();
		
	}
}

void Nadajnik::UstawKoniecznoscRetransmisji(bool a)
{
	retransmisja_ = a;
}

bool Nadajnik::ZwrocKoniecznoscRetransmisji()
{
	return retransmisja_;
}

void Nadajnik::PowiekszliczbeOdebranychPakietow()
{
	liczba_odebranych_pakietow_ = liczba_odebranych_pakietow_ + 1;
}

void Nadajnik::PowiekszliczbeStraconychPakietow()
{
	liczba_straconych_pakietow_ = liczba_straconych_pakietow_ + 1;
}

double Nadajnik::ZwrocliczbeOdebranychPakietow()
{
	return liczba_odebranych_pakietow_;
}

double Nadajnik::ZwrocliczbeStraconychPakietow()
{
	return liczba_straconych_pakietow_;
}

void Nadajnik::WyzerujLiczbeOdebranychPakietow()
{
	liczba_odebranych_pakietow_ = 0;
}

void Nadajnik::WyzerujLiczbeStraconychPakietow()
{
	liczba_straconych_pakietow_ = 0;
}

void Nadajnik::UsunNajstarszyPakietZBufora()
{
	if (bufor_.size() != NULL) {
		bufor_.pop();
	}
}

Nadajnik::~Nadajnik()
{
}
