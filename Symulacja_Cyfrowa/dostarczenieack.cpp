#include "dostarczenieack.h"
#include <Windows.h>
DostarczenieAck::DostarczenieAck(double czas, System * system):czas_(czas),system_(system)
{
}

void DostarczenieAck::Wykonaj(bool flaga)
{
	
	if (system_->GetKanal()->IloscPakietowWKanale() == 2) {
		if (flaga == true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			cout << endl;
			cout << system_->ZwrocCzas();
			cout << endl;
			cout << "WYSTAPILA KOLIZJA POMIEDZY PAKIETEM A ACK " << endl;
			cout << "POTRZEBNA RETRANSMISJA" << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		system_->GetKanal()->UsunPakiety();

	}
	else {
		if (flaga == true) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			cout << endl;
			cout << system_->ZwrocCzas();
			cout << endl;
			cout << "DOSTARCZONO ACK " << endl;
			cout << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
		system_->GetKanal()->UsunPakiety();
		system_->UstawWysylanieAck(false);

		//stat
		system_->powiekszwyslanepakiety();
		//

	}

	}

double DostarczenieAck::ZwrocCzas()
{
	return czas_;
}

void DostarczenieAck::UstawCzas(double a)
{
	czas_ = a;
}
