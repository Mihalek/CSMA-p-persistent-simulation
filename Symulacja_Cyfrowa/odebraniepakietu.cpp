#include "odebraniepakietu.h"
#include <Windows.h>
OdebraniePakietu::OdebraniePakietu(double czas, System *system) :czas_(czas), system_(system)
{
	faza_.open("faza_poczatkowa.txt", ios::app);
	faza_ <<endl;
	pakiety_.open("pakiety.txt", ios::out | ios::ate);
}

OdebraniePakietu::~OdebraniePakietu() {
	faza_.close();
	pakiety_.close();
}



double OdebraniePakietu::ZwrocCzas()
{
	return czas_;
}

void OdebraniePakietu::UstawCzas(double a)
{
	czas_ = a;
}

void OdebraniePakietu::Wykonaj(bool flaga)
{
	if (flaga) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);





		cout << endl;
		cout << system_->ZwrocCzas();
		cout << endl;
		cout << "ZDARZENIE CZASOWE ODEBRANIE PAKIETU" << endl;
		cout << "ODEBRANO PAKIET O o ID " << system_->GetKanal()->PobierzPakiet()->GetIdentyfikator() <<" W CZASIE "<<system_->ZwrocCzas()<< endl;
		cout << "Z nadajnika " << system_->GetKanal()->PobierzPakiet()->GetNadawca() << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}


	system_->GetOdbiornik(system_->GetKanal()->PobierzPakiet()->GetNadawca())->SetOdebranyPakiet(system_->GetKanal()->PobierzPakiet());
	system_->GetOdbiornik(system_->GetKanal()->PobierzPakiet()->GetNadawca())->DodajDoOdebranychPakietow(system_->GetOdbiornik(system_->GetKanal()->PobierzPakiet()->GetNadawca())->ZwrocOdebranyPakiet());
	//stat
	system_->PowiekszStatLiczbeOdebranychPakietow();
	system_->UstawOpoznieniePakietowe((system_->ZwrocOpoznieniePakietowe()) + (system_->ZwrocCzas() - system_->GetKanal()->PobierzPakiet()->ZwrocCzasUtworzeniePakietu()));
	system_->GetNadajnik(system_->GetKanal()->PobierzPakiet()->GetNadawca())->PowiekszliczbeOdebranychPakietow();
	//
	if (system_->GetKanal()->IloscPakietowWKanale() == 1) {
		system_->GetKanal()->UsunPakiety();
	}
	system_->UstawWysylanieAck(true);
	double a = system_->ZwrocStatLiczbeRetransmisji()/ system_->ZwrocStatLiczbeOdebranychPakietow();
	faza_ << a << ' ';
	double b = system_->ZwrocStatLiczbeOdebranychPakietow();
	pakiety_<< b <<' ';
	
	




}
