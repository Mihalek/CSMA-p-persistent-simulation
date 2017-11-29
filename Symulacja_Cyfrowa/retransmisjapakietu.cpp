#include "retransmisjapakietu.h"
#include<cmath>



RetransmisjaPakietu::RetransmisjaPakietu(int id, System * system):id_(id),system_(system)
{
	czas_ = -1;
	

}

void RetransmisjaPakietu::Wykonaj(bool flaga_)

{
	system_->GetNadajnik(id_)->ZwiekszLiczbeRetransmisji();
	if (system_->GetNadajnik(id_)->ZwrocLiczbeRetransmisji() <= 7) {
		int R = system_->GetGeneratorCTP(id_)->GeneratorRownomiernyCalkowity(id_, 0, pow(2, system_->GetNadajnik(id_)->ZwrocLiczbeRetransmisji() - 1));
		czas_ = system_->GetNadajnik(id_)->ZwrocNajstarszyPakiet()->ZwrocJakDlugoTrwaTransmisjaPakietu()* R;
		if (czas_ == 0) {
			czas_ = 0.5;
		}
		
		if (flaga_) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << endl;
			cout << system_->ZwrocCzas();
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << endl;
			cout << "ZDARZENIE WARUNKOWE RETRANSMISJA PAKIETU O ID " << system_->ZwrocZPierwszychPakietowZBuforow(id_)->GetIdentyfikator() << endl;
			cout << "NR RETRANSMISJI WYNOSI " << system_->GetNadajnik(id_)->ZwrocLiczbeRetransmisji() << endl;
			cout << endl;

		}


		if (flaga_) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << endl;
			cout << "Czas po ktorym pakiet sprawdzi czy kanal jest wolny wynosi " << czas_ << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);


		}


	}
	else {
		system_->GetNadajnik(id_)->WyzerujRetransmisje();
		czas_ = 0.5;
		if (flaga_) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			cout << endl;
			cout << system_->ZwrocCzas();
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
			cout << endl;
			cout << "Retransmisja nie powiodla sie dla pakietu o id " << system_->ZwrocZPierwszychPakietowZBuforow(id_)->GetIdentyfikator() << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		}
		system_->GetNadajnik(id_)->UsunNajstarszyPakietZBufora();
		system_->GetNadajnik(id_)->PowiekszliczbeStraconychPakietow();
		//stat
		system_->PowiekszStatliczbeStraconychPakietow();
		//
	}
	
	system_->GetNadajnik(id_)->UstawKoniecznoscRetransmisji(false);


}

double RetransmisjaPakietu::ZwrocCzas()
{
	return czas_;
}



