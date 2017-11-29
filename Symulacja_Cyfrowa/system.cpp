#include "system.h"
#include<Windows.h>


System::System(int ilosc, __int64 ziarna[41], int numer_symulacji,int czas_sym) : ilosc_(ilosc),czas(0),numer_symulacji_(numer_symulacji),czas_symulacji(czas_sym)
{
	rozpoczecie_transmisji_ = false;
	liczba_kolizji_ = 0;
	czas_oczekiwania_ = 0;
	kanaltransmisyjny = new KanalTransmisyjny();
	stat_liczba_retransmisji = 0;
	stat_odebrane_pakiety_w_sieci = 0;
	opoznienie_pakietowe_ = 0;
	stat_stracone_pakiety_w_sieci = 0;
	for (int i = 0;i  <10; i++) {
		nadajniki_.push_back(new Nadajnik(i)); 
		odbiorniki_.push_back(new Odbiornik(i));

	}
	
	for (int i = 0;i < 10; i++) {
		generatoryCGP_.push_back(new Generator(i, ziarna[i]));
		generatoryCTP_.push_back(new Generator(i, ziarna[i+1]));
		generatoryPrawd_.push_back(new Generator(i, ziarna[i + 2]));
	}
	
	for (int i = 0; i < 10;i++) {
		pierwsze_pakiety_z_buforow_.push_back(nullptr);
	}

	czas = 0;
	identyfikatory =0;
	pakiet_do_transmisji_ = nullptr;
	czas_najblizszej_transmisji_ = -1;
	wysylanieack_ = false;
	wyslane_pakiety_ = 0;


}




void System::UstawCzas(double a) {
	czas = a;
}

void System::DodajDoKolejki(Pakiet *pakiet)
{
	kolejka_pakietow_.push(pakiet);

}

void System::UstawPakietDoTransmisji(Pakiet *a)
{
	pakiet_do_transmisji_ = a;
}

void System::PowiekszStatLiczbeRetransmisji()
{
	stat_liczba_retransmisji = stat_liczba_retransmisji + 1;
}

double System::ZwrocStatLiczbeRetransmisji()
{
	return stat_liczba_retransmisji;
}

Pakiet * System::ZwrocPakietDoTransmisji()
{
	return pakiet_do_transmisji_;
}

Pakiet * System::ZwrocPierwszyPakiet()
{	
	Pakiet* a = kolejka_pakietow_.front();
	
	return a;                                                                                                                                    
}




double System::ZwrocCzas() {
	
	return czas;
}
void System::UstawCzasOczekiwania(double a)
{
	czas_oczekiwania_ = a;
}
double System::ZwrocCzasOczekiwania()
{
	return czas_oczekiwania_;
}
void System::UstawOdebraniePakietu(double a)
{
	odebranie_pakietu_ = a;
}
int System::zwrocwyslanepakiety()
{
	return wyslane_pakiety_;
}
void System::powiekszwyslanepakiety()
{
	wyslane_pakiety_ = wyslane_pakiety_ + 1;
}
void System::DodajPakietTransmitowany(Pakiet *a)
{
	pakiety_transmitowane_.push_back(a);
}
Pakiet * System::ZwrocPakietTransmitowany()
{
	return pakiety_transmitowane_[0];
}

Pakiet* System::ZwrocPakietTransmitowanyOID(int id)
{
	return pakiety_transmitowane_.at(id);
}

void System::UsunPakietTransmitowany()
{
	pakiety_transmitowane_.erase(pakiety_transmitowane_.begin());
}
int System::ZwrocRozmiarKolejkiPakietowTransmitowanych()
{
	return pakiety_transmitowane_.size();
}
void System::UstawKolizjePakietuTransmitowanego(int id, bool a)
{
	pakiety_transmitowane_[id]->UstawKolizje(a);
}
void System::UsunPierwszyPakietZKolejki()
{
	kolejka_pakietow_.pop();
}

void System::UstawKolizjeNaPakietachNieTransmitowanychIUsun()
{
	for (int i = 0;i < ZwrocRozmiarKolejkiPakietowTransmitowanych();i++) {
		pakiety_transmitowane_[i]->UstawKolizje(true);
		liczba_kolizji_ = liczba_kolizji_ + 1;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << endl;
		cout << ZwrocCzas() << endl;
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		cout << "Kolizja Pakietu O ID  " << pakiety_transmitowane_[i]->GetIdentyfikator() << endl;
		cout << "W czasie "<<ZwrocCzas()<< endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);



	}

	//pakiety_transmitowane_.erase(pakiety_transmitowane_.begin() + 1, pakiety_transmitowane_.begin() + pakiety_transmitowane_.size());


}
double System::ZwrocOdebraniePakietu()
{
	return odebranie_pakietu_;
}
void System::UstawCzasNajblizszejTransmisji(double a)
{
	czas_najblizszej_transmisji_ = a;
}
double System::ZwrocCzasNajblizszejTransmisji()
{
	return czas_najblizszej_transmisji_;
}
void System::UstawRozpoczecieTransmisji(bool rozptran)
{
	rozpoczecie_transmisji_ = rozptran;
}
void System::PowiekszStatLiczbeOdebranychPakietow()
{
	stat_odebrane_pakiety_w_sieci = stat_odebrane_pakiety_w_sieci + 1;
}
void System::PowiekszStatliczbeStraconychPakietow()
{
	stat_stracone_pakiety_w_sieci = stat_stracone_pakiety_w_sieci + 1;
}
double System::ZwrocStatLiczbeOdebranychPakietow()
{
	return stat_odebrane_pakiety_w_sieci;
}
double System::ZwrocStatliczbeStraconychPakietow()
{
	return stat_stracone_pakiety_w_sieci;
}
void System::UstawOpoznieniePakietowe(double a)
{
	opoznienie_pakietowe_ = a;
}
void System::WyzerujLiczbeRetransmisji()
{
	stat_liczba_retransmisji = 0;
}
void System::WyzerujLiczbeOdebranychPakietow()
{
	stat_odebrane_pakiety_w_sieci = 0;
	for (int i = 0; i < 10;i++) {
		GetNadajnik(i)->WyzerujLiczbeOdebranychPakietow();
	}
	
}
void System::WyzerujLiczbeStraconychPakietow()
{
	stat_stracone_pakiety_w_sieci = 0;
	for (int i = 0; i < 10;i++) {
		GetNadajnik(i)->WyzerujLiczbeStraconychPakietow();
	}
}
double System::ZwrocOpoznieniePakietowe()
{
	return opoznienie_pakietowe_;
}
bool System::ZwrocRozpoczecieTransmisji()
{
	return rozpoczecie_transmisji_;
}
Pakiet * System::ZwrocPakietZKolejki(int id)
{
	return pakiety_transmitowane_.at(id);
}

int System::ZwrocIdentyfikatory() {
	return identyfikatory;
}
void System::UstawIdentyfikatory(int a) {
	identyfikatory = a;

}


void System::DodajDoPierwszePakietyZBuforow(int id, Pakiet *a)
{	
	pierwsze_pakiety_z_buforow_[id] = a;
}

Pakiet * System::ZwrocZPierwszychPakietowZBuforow(int id)
{
	return pierwsze_pakiety_z_buforow_[id];
}


int System::ZwrocIDnadtran()
{
	return id;
}

void System::UstawIDnadtran(int a)
{
	id = a;
}

Generator * System::GetGeneratorCTP(int id)
{
	return generatoryCTP_.at(id);
}
Generator * System::GetGeneratorPrawd(int id)
{
	return generatoryPrawd_.at(id);
}
Generator * System::GetGeneratorCGP(int id)
{
	return generatoryCGP_.at(id);
}


void System::UsunKopie() {
	for (int i = 0; i < ZwrocRozmiarKolejkiPakietowTransmitowanych()-1; i++) {
		for (int j = i + 1;j < ZwrocRozmiarKolejkiPakietowTransmitowanych(); j++) {
			{
				{
					if (pakiety_transmitowane_[i]->GetIdentyfikator() == pakiety_transmitowane_[j]->GetIdentyfikator()) {
						pakiety_transmitowane_.erase(pakiety_transmitowane_.begin() + j);

					}
				}

			}
		}
	}
}

void System::UstawKolizjePakietow(int id,bool kolizja)
{
}

void System::UstawWysylanieAck(bool a)
{
	wysylanieack_ = a;
}

bool System::ZwrocWysylanieAck()
{
	return wysylanieack_;
}

void System::UstawPakietyZKolizja()
{
	for (int i = 0;i < ZwrocRozmiarKolejkiPakietowTransmitowanych();i++) {
		if (pakiety_transmitowane_[i]->ZwrocCzasTransmisji() == this->ZwrocCzas()) {
			pakiety_transmitowane_[i]->UstawKolizje(true);

		}


	}
}


KanalTransmisyjny * System::GetKanal()
{
	return kanaltransmisyjny;
}

Odbiornik * System::GetOdbiornik(int id)
{
	return odbiorniki_.at(id);

}

Nadajnik * System::GetNadajnik(int id_)
{
	return nadajniki_.at(id_);
}
