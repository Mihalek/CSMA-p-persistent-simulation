#include "wyslanieack.h"
#include <Windows.h>
WyslanieAck::WyslanieAck(System *system) :system_(system)
{


}

void WyslanieAck::Wykonaj(bool flaga)
{
	system_->GetKanal()->DodajPakiet(new Pakiet(system_->GetOdbiornik(system_->ZwrocIDnadtran())->ZwrocOdebranyPakiet()->GetOdbiorca()));
	

	if (flaga) {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		cout << endl;
		cout << system_->ZwrocCzas();
		cout << endl;
		cout << "ZDARZENIE WARUNKOWE WYSYLANIE ACK " << endl;
		cout << "PLANOWANE DOSTARCZENIE W CZASIE " << system_->ZwrocCzas() + 1 << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	system_->UstawWysylanieAck(false);
	
	UstawCzas(system_->ZwrocCzas() + 1);

}

double WyslanieAck::ZwrocCzas()
{
	return czas;
}

void WyslanieAck::UstawCzas(double a)
{
	czas = a;
}
