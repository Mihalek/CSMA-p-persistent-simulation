#include "utworzeniepakietu.h"
#include<Windows.h>

UtworzeniePakietu::UtworzeniePakietu(int nr_nadajnika, double czas, int id, System *system):czas_(czas),id_(id), system_(system),nr_nadajnika_(nr_nadajnika){}

double UtworzeniePakietu::ZwrocCzas()
{
	return czas_;
}

void UtworzeniePakietu::Wykonaj(bool flaga)
{

	if (flaga == true) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		cout << system_->ZwrocCzas();
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	int CTP = system_->GetGeneratorCTP(nr_nadajnika_)->GeneratorRownomiernyCalkowity(id_, 1, 10);
		Pakiet *pakiet_ = new Pakiet(id_, czas_, CTP);
		pakiet_->UstawJakDlugoTrwaTransmisjaPakietu(CTP);
		pakiet_->SetIdentyfikator(system_->ZwrocIdentyfikatory());
		system_->GetNadajnik(nr_nadajnika_)->DodajPakietDoBufora(pakiet_);


	if (flaga == true) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "ZDARZENIE UTWORZENIE PAKIETU  W NADAJNIKU O ID  " << nr_nadajnika_ << endl;
		cout << "UTWORZONO PAKIET W NADAJNIKU O ID " << pakiet_->GetIdentyfikator() << " W CZASIE " << czas_ << " O CZASIE TRANSMISJI " << CTP << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	
	czas_ =0.01+ czas_ + (round(system_->GetGeneratorCGP(nr_nadajnika_)->GeneratorWykladniczy() / 100 * 10) / 10);
	
	if (flaga == true) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "NASTEPNA GENERACJA ODBEDZIE SIE W NADAJNIKU O ID " << nr_nadajnika_ << " W CZASIE " << czas_ << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
		system_->UstawIdentyfikatory(system_->ZwrocIdentyfikatory() + 1);

	}


