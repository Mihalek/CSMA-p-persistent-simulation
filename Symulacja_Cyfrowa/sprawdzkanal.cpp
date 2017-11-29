#include "sprawdzkanal.h"
#include<Windows.h>
#include<cstdio>
#include<ctime>

SprawdzKanal::SprawdzKanal(int id,double czas, System *system) :id_(id),czas_(czas), system_(system)
{

}


void SprawdzKanal::Wykonaj(bool flaga)
{
	if (system_->GetNadajnik(id_)->ZwrocRozmiarBufora() != 0) {
		if (flaga) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << endl;
			cout << system_->ZwrocCzas();
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			cout << "-------------------ZDARZENIE CZASOWE SPRAWDZENIE KANALU DLA NADAJNIKA O ID " << id_ << endl;
			cout << "SPRAWDZAM KIEDY BEDZIE WOLNY KANAL DLA PAKIETU O ID " << system_->GetNadajnik(id_)->ZwrocNajstarszyPakiet()->GetIdentyfikator() << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}

		if (system_->GetKanal()->IloscPakietowWKanale() == 0) {
			Pakiet *a = system_->GetNadajnik(id_)->ZwrocNajstarszyPakiet();
			system_->DodajDoPierwszePakietyZBuforow(id_, a);

			if (flaga) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				cout << "USTAWIAM PAKIET DO TRANSMISJI O ID " << a->GetIdentyfikator() << endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}

			int z = system_->GetGeneratorPrawd(id_)->GeneratorRownomiernyCalkowity(id_, 1, 100);
			if (z <= 20) {
				a->UstawCzasTransmisji(round(czas_ + 0.5));
				system_->GetNadajnik(id_)->UstawCzasNajblizszejTransmisji(round(czas_ + 0.5));
				czas_ = (round(czas_ + 0.5)) + 0.5;
				if (flaga) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					cout << "PRAWDOPODOBIENSTWO TRAFIONE " << endl;
					cout << "TRANSMISJA ODBEDZIE SIE O CZASIE " << a->ZwrocCzasTransmisji() << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
			else {
				czas_ = round(czas_ + 0.5);
				if (flaga) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					cout << "PRAWDOPODOBIENSTWO NIETRAFIONE " << endl;
					cout << "NASTEPNE SPRAWDZANIE ODBEDZIE SIE W CZASIE " << czas_ << endl;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
			}
		}


		else {
			czas_ = czas_ + 0.5;

			if (flaga) {

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				cout << "NASTEPNE SPRAWDZENIE ODBEDZIE SIE W CZASIE " << ZwrocCzas() << endl;

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}

		}
	}
}
double SprawdzKanal::ZwrocCzas()
{
	return czas_;
}

void SprawdzKanal::UstawCzas(double a)
{
	czas_ = a;
}
