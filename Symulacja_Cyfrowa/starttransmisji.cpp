#include "starttransmisji.h"
#include<Windows.h>
void StartTransmisji::UstawCzas(double a)
{
	czas_ = a;
}
double StartTransmisji::ZwrocCzas()
{
	return czas_;
}
StartTransmisji::StartTransmisji(int id, double czas, System* system) :id_(id), system_(system), czas_(czas) {
	


}

void StartTransmisji::Wykonaj(bool flaga)
{

	if (system_->GetKanal()->IloscPakietowWKanale() == 0) {
		if (flaga == true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << endl;
			cout << system_->ZwrocCzas();
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 06);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 06);
			cout << "ZDARZENIE CZASOWE START TRANSMISJI DLA PAKIETU Z NADAJNIKA " << system_->ZwrocZPierwszychPakietowZBuforow(id_)->GetNadawca();
			cout << " O ID " << system_->ZwrocZPierwszychPakietowZBuforow(id_)->GetIdentyfikator() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}


		system_->UstawRozpoczecieTransmisji(true);
		system_->UstawIDnadtran(id_);
		


		czas_ = system_->GetNadajnik(id_)->ZwrocCzasNajblizszejTransmisji();
	}
	else {
		if (flaga) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 06);
			cout << "KANAL W TYM CZASIE STAL SIE ZAJETY, ANULOWANA TRANSMISJA PAKIETU Z NADAJNIKA " << system_->ZwrocZPierwszychPakietowZBuforow(id_)->GetNadawca()<<endl;
			cout << "O ID " << system_->ZwrocZPierwszychPakietowZBuforow(id_)->GetIdentyfikator() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		}


	

}




