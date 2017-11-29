#include "wyslaniepakietu.h"
#include<iostream>
#include <cstdlib>
#include<time.h>
#include<Windows.h>
#include<fstream>



WyslaniePakietu::WyslaniePakietu(System *system):system_(system){}



void WyslaniePakietu::Wykonaj(bool flaga_) {


	Pakiet *pakiet_ = system_->ZwrocZPierwszychPakietowZBuforow(system_->ZwrocIDnadtran());
	system_->UstawRozpoczecieTransmisji(false);
	system_->GetNadajnik(pakiet_->GetNadawca())->UsunNajstarszyPakietZBufora();
	if (flaga_) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 06);
		cout << "Z BUFORA NADAJNIKA ZNIKNAL PAKIET O ID " << system_->ZwrocZPierwszychPakietowZBuforow(pakiet_->GetNadawca())->GetNadawca();
		cout << " O ID " << system_->ZwrocZPierwszychPakietowZBuforow(pakiet_->GetNadawca())->GetIdentyfikator() << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
	
	int a = system_->GetNadajnik(pakiet_->GetNadawca())->ZwrocLiczbeRetransmisji();
	//stat
	for (int i = 0; i <a;i++) {
		system_->PowiekszStatLiczbeRetransmisji();
	}//
	system_->GetNadajnik(pakiet_->GetNadawca())->WyzerujRetransmisje();
	pakiet_->UstawKolizje(false);
	//stat
	system_->UstawCzasOczekiwania(system_->ZwrocCzasOczekiwania() + (system_->ZwrocCzas() - pakiet_->ZwrocCzasUtworzeniePakietu()));
	//

	system_->GetKanal()->DodajPakiet(pakiet_);
	system_->UstawOdebraniePakietu(system_->ZwrocCzas() + pakiet_->ZwrocJakDlugoTrwaTransmisjaPakietu());
	if (flaga_) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		cout << system_->ZwrocCzas();
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "W KANALE TRANSMITOWANY JEST PAKIET Z NADAJNIKA " << pakiet_->GetNadawca() << endl;
		cout << "O NR ID " << pakiet_->GetIdentyfikator() << ", Powinien znalezc sie w odbiorniku w czasie " << system_->ZwrocOdebraniePakietu() << endl;

	}

	
}
		
	

