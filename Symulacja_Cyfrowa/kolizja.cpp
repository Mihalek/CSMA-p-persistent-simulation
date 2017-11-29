#include "kolizja.h"




Kolizja::Kolizja(System *system):system_(system)
{
	

}

void Kolizja::Wykonaj(bool flaga)
{
	for (int i = 0; i < 10;i++) {
		if (system_->GetNadajnik(i)->ZwrocCzasNajblizszejTransmisji() == system_->ZwrocCzas())
		{	
			if (flaga == true) {
				system_->ZwrocZPierwszychPakietowZBuforow(i)->UstawKolizje(true);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				cout << endl;
				cout << system_->ZwrocCzas();
				cout << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "Kolizja Pakietu O ID  " << system_->ZwrocZPierwszychPakietowZBuforow(i)->GetIdentyfikator() << endl;
				cout << "W czasie " << system_->ZwrocCzas() << endl;
			}

			system_->GetNadajnik(i)->UstawKoniecznoscRetransmisji(true);
		}
		system_->UstawRozpoczecieTransmisji(false);
	}
}
