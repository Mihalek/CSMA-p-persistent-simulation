
#include "symulator.h"
#include <cmath>



Symulator::Symulator(int ilosc, __int64 ziarna_[30], int flaga,int flaga2, double faza_poczatkowa, int numer_symulacji, int czas_symulacji)
{

	system_ = new System(ilosc, ziarna_, numer_symulacji, czas_symulacji);
	nowy_pakiet1_ = new UtworzeniePakietu(0, system_->GetGeneratorCGP(0)->GeneratorWykladniczy()/100, 0, system_);
	nowy_pakiet2_ = new UtworzeniePakietu(1, system_->GetGeneratorCGP(1)->GeneratorWykladniczy() / 100, 1, system_);
	nowy_pakiet3_ = new UtworzeniePakietu(2, system_->GetGeneratorCGP(2)->GeneratorWykladniczy() / 100 , 2, system_);
	nowy_pakiet4_ = new UtworzeniePakietu(3, system_->GetGeneratorCGP(3)->GeneratorWykladniczy() / 100 , 3, system_);
	nowy_pakiet5_ = new UtworzeniePakietu(4, system_->GetGeneratorCGP(4)->GeneratorWykladniczy() / 100,4, system_);
	nowy_pakiet6_ = new UtworzeniePakietu(5, system_->GetGeneratorCGP(5)->GeneratorWykladniczy() / 100, 5, system_);
	nowy_pakiet7_ = new UtworzeniePakietu(6, system_->GetGeneratorCGP(6)->GeneratorWykladniczy() / 100, 6, system_);
	nowy_pakiet8_ = new UtworzeniePakietu(7, system_->GetGeneratorCGP(7)->GeneratorWykladniczy() / 100, 7, system_);
	nowy_pakiet9_ = new UtworzeniePakietu(8, system_->GetGeneratorCGP(8)->GeneratorWykladniczy() / 100, 8, system_);
	nowy_pakiet10_ = new UtworzeniePakietu(9, system_->GetGeneratorCGP(9)->GeneratorWykladniczy() / 100, 9, system_);

	wyslanie_pakietu_ = new WyslaniePakietu(system_);

	odebranie_pakietu_ = new OdebraniePakietu(-1, system_);

	kolizja_ = new Kolizja(system_);

	wyslanie_ack_ = new WyslanieAck(system_);

	retransmisja_pakietu1_ = new RetransmisjaPakietu(0, system_);
	retransmisja_pakietu2_ = new RetransmisjaPakietu(1, system_);
	retransmisja_pakietu3_ = new RetransmisjaPakietu(2, system_);
	retransmisja_pakietu4_ = new RetransmisjaPakietu(3, system_);
	retransmisja_pakietu5_ = new RetransmisjaPakietu(4, system_);
	retransmisja_pakietu6_ = new RetransmisjaPakietu(5, system_);
	retransmisja_pakietu7_ = new RetransmisjaPakietu(6, system_);
	retransmisja_pakietu8_ = new RetransmisjaPakietu(7, system_);
	retransmisja_pakietu9_ = new RetransmisjaPakietu(8, system_);
	retransmisja_pakietu10_ = new RetransmisjaPakietu(9, system_);
	dostarczenie_ack_ = new DostarczenieAck(-1, system_);


	czasy_zdarzen_.push_back(nowy_pakiet1_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet2_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet3_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet4_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet5_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet6_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet7_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet8_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet9_->ZwrocCzas());
	czasy_zdarzen_.push_back(nowy_pakiet10_->ZwrocCzas());

	sprawdz_kanal1_ = new SprawdzKanal(0, czasy_zdarzen_[0] + 0.5, system_);
	sprawdz_kanal2_ = new SprawdzKanal(1, czasy_zdarzen_[1] + 0.5, system_);
	sprawdz_kanal3_ = new SprawdzKanal(2, czasy_zdarzen_[2] + 0.5, system_);
	sprawdz_kanal4_ = new SprawdzKanal(3, czasy_zdarzen_[3] + 0.5, system_);
	sprawdz_kanal5_ = new SprawdzKanal(4, czasy_zdarzen_[4] + 0.5, system_);
	sprawdz_kanal6_ = new SprawdzKanal(5, czasy_zdarzen_[5] + 0.5, system_);
	sprawdz_kanal7_ = new SprawdzKanal(6, czasy_zdarzen_[6] + 0.5, system_);
	sprawdz_kanal8_ = new SprawdzKanal(7, czasy_zdarzen_[7] + 0.5, system_);
	sprawdz_kanal9_ = new SprawdzKanal(8, czasy_zdarzen_[8] + 0.5, system_);
	sprawdz_kanal10_ = new SprawdzKanal(9, czasy_zdarzen_[9] + 0.5, system_);



	czasy_zdarzen_.push_back(sprawdz_kanal1_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal2_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal3_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal4_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal5_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal6_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal7_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal8_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal9_->ZwrocCzas());
	czasy_zdarzen_.push_back(sprawdz_kanal10_->ZwrocCzas());

	start_transmisji1_ = new StartTransmisji(0, -1, system_);
	start_transmisji2_ = new StartTransmisji(1, -1, system_);
	start_transmisji3_ = new StartTransmisji(2, -1, system_);
	start_transmisji4_ = new StartTransmisji(3, -1, system_);
	start_transmisji5_ = new StartTransmisji(4, -1, system_);
	start_transmisji6_ = new StartTransmisji(5, -1, system_);
	start_transmisji7_ = new StartTransmisji(6, -1, system_);
	start_transmisji8_ = new StartTransmisji(7, -1, system_);
	start_transmisji9_ = new StartTransmisji(8, -1, system_);
	start_transmisji10_ = new StartTransmisji(9, -1, system_);


	czasy_zdarzen_.push_back(start_transmisji1_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji2_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji3_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji4_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji5_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji6_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji7_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji8_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji9_->ZwrocCzas());
	czasy_zdarzen_.push_back(start_transmisji10_->ZwrocCzas());
	czasy_zdarzen_.push_back(odebranie_pakietu_->ZwrocCzas());
	czasy_zdarzen_.push_back(dostarczenie_ack_->ZwrocCzas());

	eps_ = 0.000000001;
	flaga_ = flaga;
	flaga2_ = flaga2;
	numer_symulacji_ = numer_symulacji;
	czas_symulacji_ = czas_symulacji;
	ilosc_ = ilosc;
	faza_poczatkowa_ = faza_poczatkowa;

}


void Symulator::Symuluj()
{
	bool flaga_fazy = true;

	
	while (system_->ZwrocCzas() <= czas_symulacji_)
	{
		if (system_->ZwrocCzas() > faza_poczatkowa_ && flaga_fazy == true) {
			WyczyscStatystyki();
			flaga_fazy = false;
		}

		int licznik_startow_ = 0; //Ilosc pakietow transmitowanych w tej samej chwili
		
		//ZDARZENIA CZASOWE
		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet1_->ZwrocCzas()))
		{
			nowy_pakiet1_->Wykonaj(flaga_);
			czasy_zdarzen_[0] = nowy_pakiet1_->ZwrocCzas();
			if (flaga2_) system("pause");

		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet2_->ZwrocCzas()))
		{
			nowy_pakiet2_->Wykonaj(flaga_);
			czasy_zdarzen_[1] = nowy_pakiet2_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet3_->ZwrocCzas()))
		{
			nowy_pakiet3_->Wykonaj(flaga_);
			czasy_zdarzen_[2] = nowy_pakiet3_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet4_->ZwrocCzas()))
		{
			nowy_pakiet4_->Wykonaj(flaga_);
			czasy_zdarzen_[3] = nowy_pakiet4_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet5_->ZwrocCzas()))
		{
			nowy_pakiet5_->Wykonaj(flaga_);
			czasy_zdarzen_[4] = nowy_pakiet5_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet6_->ZwrocCzas()))
		{
			nowy_pakiet6_->Wykonaj(flaga_);
			czasy_zdarzen_[5] = nowy_pakiet6_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet7_->ZwrocCzas()))
		{
			nowy_pakiet7_->Wykonaj(flaga_);
			czasy_zdarzen_[6] = nowy_pakiet7_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet8_->ZwrocCzas()))
		{
			nowy_pakiet8_->Wykonaj(flaga_);
			czasy_zdarzen_[7] = nowy_pakiet8_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet9_->ZwrocCzas()))
		{
			nowy_pakiet9_->Wykonaj(flaga_);
			czasy_zdarzen_[8] = nowy_pakiet9_->ZwrocCzas();
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), nowy_pakiet10_->ZwrocCzas()))
		{
			nowy_pakiet10_->Wykonaj(flaga_);
			czasy_zdarzen_[9] = nowy_pakiet10_->ZwrocCzas();
			if (flaga2_) system("pause");
		}


		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal1_->ZwrocCzas()))
		{
			sprawdz_kanal1_->Wykonaj(flaga_);
			czasy_zdarzen_[10] = sprawdz_kanal1_->ZwrocCzas();
			czasy_zdarzen_[20] = system_->GetNadajnik(0)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji1_->UstawCzas(system_->GetNadajnik(0)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal2_->ZwrocCzas()))
		{
			sprawdz_kanal2_->Wykonaj(flaga_);
			czasy_zdarzen_[11] = sprawdz_kanal2_->ZwrocCzas();
			czasy_zdarzen_[21] = system_->GetNadajnik(1)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji2_->UstawCzas(system_->GetNadajnik(1)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal3_->ZwrocCzas()))
		{
			sprawdz_kanal3_->Wykonaj(flaga_);
			czasy_zdarzen_[12] = sprawdz_kanal3_->ZwrocCzas();
			czasy_zdarzen_[22] = system_->GetNadajnik(2)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji3_->UstawCzas(system_->GetNadajnik(2)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal4_->ZwrocCzas()))
		{
			sprawdz_kanal4_->Wykonaj(flaga_);
			czasy_zdarzen_[13] = sprawdz_kanal4_->ZwrocCzas();
			czasy_zdarzen_[23] = system_->GetNadajnik(3)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji4_->UstawCzas(system_->GetNadajnik(3)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal5_->ZwrocCzas()))
		{
			sprawdz_kanal5_->Wykonaj(flaga_);
			czasy_zdarzen_[14] = sprawdz_kanal5_->ZwrocCzas();
			czasy_zdarzen_[24] = system_->GetNadajnik(4)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji5_->UstawCzas(system_->GetNadajnik(4)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal6_->ZwrocCzas()))
		{
			sprawdz_kanal6_->Wykonaj(flaga_);
			czasy_zdarzen_[15] = sprawdz_kanal6_->ZwrocCzas();
			czasy_zdarzen_[25] = system_->GetNadajnik(5)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji6_->UstawCzas(system_->GetNadajnik(5)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal7_->ZwrocCzas()))
		{
			sprawdz_kanal7_->Wykonaj(flaga_);
			czasy_zdarzen_[16] = sprawdz_kanal7_->ZwrocCzas();
			czasy_zdarzen_[26] = system_->GetNadajnik(6)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji7_->UstawCzas(system_->GetNadajnik(6)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal8_->ZwrocCzas()))
		{
			sprawdz_kanal8_->Wykonaj(flaga_);
			czasy_zdarzen_[17] = sprawdz_kanal8_->ZwrocCzas();
			czasy_zdarzen_[27] = system_->GetNadajnik(7)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji8_->UstawCzas(system_->GetNadajnik(7)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal9_->ZwrocCzas()))
		{
			sprawdz_kanal9_->Wykonaj(flaga_);
			czasy_zdarzen_[18] = sprawdz_kanal9_->ZwrocCzas();
			czasy_zdarzen_[28] = system_->GetNadajnik(8)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji9_->UstawCzas(system_->GetNadajnik(8)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), sprawdz_kanal10_->ZwrocCzas()))
		{
			sprawdz_kanal10_->Wykonaj(flaga_);
			czasy_zdarzen_[19] = sprawdz_kanal10_->ZwrocCzas();
			czasy_zdarzen_[29] = system_->GetNadajnik(9)->ZwrocCzasNajblizszejTransmisji();
			start_transmisji10_->UstawCzas(system_->GetNadajnik(9)->ZwrocCzasNajblizszejTransmisji());
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji1_->ZwrocCzas()))
		{
			start_transmisji1_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}
		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji2_->ZwrocCzas()))
		{
			start_transmisji2_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji3_->ZwrocCzas()))
		{
			start_transmisji3_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji4_->ZwrocCzas()))
		{
			start_transmisji4_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}
		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji5_->ZwrocCzas()))
		{
			start_transmisji5_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}
		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji6_->ZwrocCzas()))
		{
			start_transmisji6_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}
		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji7_->ZwrocCzas()))
		{
			start_transmisji7_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji8_->ZwrocCzas()))
		{
			start_transmisji8_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji9_->ZwrocCzas()))
		{
			start_transmisji9_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}


		if (PorownajCzasy(system_->ZwrocCzas(), start_transmisji10_->ZwrocCzas()))
		{
			start_transmisji10_->Wykonaj(flaga_);
			licznik_startow_ = licznik_startow_ + 1;
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), odebranie_pakietu_->ZwrocCzas()))
		{
			odebranie_pakietu_->Wykonaj(flaga_);
			if (flaga2_) system("pause");
		}

		if (PorownajCzasy(system_->ZwrocCzas(), dostarczenie_ack_->ZwrocCzas()))
		{
			dostarczenie_ack_->Wykonaj(flaga_);
			if (flaga2_) system("pause");
		}



		//ZDARZENIA WARUNKOWE
		if (licznik_startow_ > 1) 
		{
			kolizja_->Wykonaj(flaga_);
			if (flaga2_) system("pause");
		}
		if (system_->GetNadajnik(0)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu1_->Wykonaj(flaga_);
			czasy_zdarzen_[10] = system_->ZwrocCzas() + retransmisja_pakietu1_->ZwrocCzas();
			sprawdz_kanal1_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu1_->ZwrocCzas());
			if (flaga2_) system("pause");
		}
		if (system_->GetNadajnik(1)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu2_->Wykonaj(flaga_);
			czasy_zdarzen_[11] = system_->ZwrocCzas() + retransmisja_pakietu2_->ZwrocCzas();
			sprawdz_kanal2_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu2_->ZwrocCzas());
			if (flaga2_) system("pause");
		}
		if (system_->GetNadajnik(2)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu3_->Wykonaj(flaga_);
			czasy_zdarzen_[12] = system_->ZwrocCzas() + retransmisja_pakietu3_->ZwrocCzas();
			sprawdz_kanal3_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu3_->ZwrocCzas());
			if (flaga2_) system("pause");
		}

		if (system_->GetNadajnik(3)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu4_->Wykonaj(flaga_);
			czasy_zdarzen_[13] = system_->ZwrocCzas() + retransmisja_pakietu4_->ZwrocCzas();
			sprawdz_kanal4_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu4_->ZwrocCzas());
			if (flaga2_) system("pause");
		}

		if (system_->GetNadajnik(4)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu5_->Wykonaj(flaga_);
			czasy_zdarzen_[14] = system_->ZwrocCzas() + retransmisja_pakietu5_->ZwrocCzas();
			sprawdz_kanal5_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu5_->ZwrocCzas());
			if (flaga2_) system("pause");
		}

		if (system_->GetNadajnik(5)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu6_->Wykonaj(flaga_);
			czasy_zdarzen_[15] = system_->ZwrocCzas() + retransmisja_pakietu6_->ZwrocCzas();
			sprawdz_kanal6_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu6_->ZwrocCzas());
			if (flaga2_) system("pause");
		}

		if (system_->GetNadajnik(6)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu7_->Wykonaj(flaga_);
			czasy_zdarzen_[16] = system_->ZwrocCzas() + retransmisja_pakietu7_->ZwrocCzas();
			sprawdz_kanal7_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu7_->ZwrocCzas());
			if (flaga2_) system("pause");
		}

		if (system_->GetNadajnik(7)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu8_->Wykonaj(flaga_);
			czasy_zdarzen_[17] = system_->ZwrocCzas() + retransmisja_pakietu8_->ZwrocCzas();
			sprawdz_kanal8_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu8_->ZwrocCzas());
			if (flaga2_) system("pause");
		}
		if (system_->GetNadajnik(8)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu9_->Wykonaj(flaga_);
			czasy_zdarzen_[18] = system_->ZwrocCzas() + retransmisja_pakietu9_->ZwrocCzas();
			sprawdz_kanal9_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu9_->ZwrocCzas());
			if (flaga2_) system("pause");
		}

		if (system_->GetNadajnik(9)->ZwrocKoniecznoscRetransmisji() == true) {
			retransmisja_pakietu10_->Wykonaj(flaga_);
			czasy_zdarzen_[19] = system_->ZwrocCzas() + retransmisja_pakietu10_->ZwrocCzas();
			sprawdz_kanal10_->UstawCzas(system_->ZwrocCzas() + retransmisja_pakietu10_->ZwrocCzas());
			if (flaga2_) system("pause");
		}


		if (system_->ZwrocRozpoczecieTransmisji() == true) {
			wyslanie_pakietu_->Wykonaj(flaga_);
			czasy_zdarzen_[30] = system_->ZwrocOdebraniePakietu();
			odebranie_pakietu_->UstawCzas(czasy_zdarzen_[30]);
			if (flaga2_) system("pause");

		}

		if (system_->ZwrocWysylanieAck() == true) {

			wyslanie_ack_->Wykonaj(flaga_);
			czasy_zdarzen_[31] = wyslanie_ack_->ZwrocCzas();
			dostarczenie_ack_->UstawCzas(czasy_zdarzen_[31]);
			if (flaga2_) system("pause");
		}


		system_->UstawCzas(UaktualnijCzas());

		}
	}

	void Symulator::Statystyki(int k)
	{
		wyniki_.open("wyniki.txt", ios::app);
		cout << "----------------------------" << endl;
		wyniki_ << "----------------------------" << endl;
		cout << "SYMULACJA NR " << k << endl;\
		wyniki_ << "SYMULACJA NR " << k << endl;
		cout << "----------------------------" << endl;
		wyniki_ << "----------------------------" << endl;

		double odebrane_pakiety_w_sieci = system_->ZwrocStatLiczbeOdebranychPakietow();
		double stracone_pakiety_w_sieci = system_->ZwrocStatliczbeStraconychPakietow();
		double nadane_pakiety = odebrane_pakiety_w_sieci + stracone_pakiety_w_sieci;
		double liczba_utraconych_pakietow_w_nadajniku, liczba_odebranych_pakietow_w_nadajniku, temp, laczna_liczba_nadanych_pakietow_w_nadajniku, srednia_stopa_bledow, maksymalna_stopa_bledow;
		srednia_stopa_bledow = 0;
		maksymalna_stopa_bledow = 0;
		temp = 0;
		double liczba_nadaj = 10.0;
		for (int i = 0;i < 10;i++) {
			liczba_utraconych_pakietow_w_nadajniku = system_->GetNadajnik(i)->ZwrocliczbeStraconychPakietow();
			liczba_odebranych_pakietow_w_nadajniku = system_->GetNadajnik(i)->ZwrocliczbeOdebranychPakietow();
			laczna_liczba_nadanych_pakietow_w_nadajniku = liczba_odebranych_pakietow_w_nadajniku + liczba_utraconych_pakietow_w_nadajniku;
			if (liczba_odebranych_pakietow_w_nadajniku != 0) {
			temp = liczba_utraconych_pakietow_w_nadajniku / laczna_liczba_nadanych_pakietow_w_nadajniku;
			}
			else {
				temp = 0;
				liczba_nadaj = liczba_nadaj - 1;
			}
			srednia_stopa_bledow = srednia_stopa_bledow + temp;
			if (temp > maksymalna_stopa_bledow) {
				maksymalna_stopa_bledow = temp;
			}
		}
		srednia_stopa_bledow = srednia_stopa_bledow / liczba_nadaj;
		cout << "Srednia pakietowa stopa bledow: " << srednia_stopa_bledow << endl;
		wyniki_ << "Srednia pakietowa stopa bledow: " << srednia_stopa_bledow << endl;
		cout << "Maksymalna pakietowa stopa bledow: " << maksymalna_stopa_bledow << endl;
		wyniki_ << "Maksymalna pakietowa stopa bledow: " << maksymalna_stopa_bledow << endl;
		double liczba_retransmisji_ = system_->ZwrocStatLiczbeRetransmisji();
		double srednia_liczba_retransmisji = liczba_retransmisji_ / odebrane_pakiety_w_sieci;
		cout << "Srednia liczba retransmisji: " << srednia_liczba_retransmisji << endl;
		wyniki_ << "Srednia liczba retransmisji: " << srednia_liczba_retransmisji << endl;
		cout << "Przeplywnosc systemu: " << odebrane_pakiety_w_sieci*1000 /(czas_symulacji_-faza_poczatkowa_) << " pakietow/s" << endl;
		wyniki_ << "Przeplywnosc systemu: " << odebrane_pakiety_w_sieci*1000 /( czas_symulacji_-faza_poczatkowa_) << " pakietow/s" << endl;
		double srednie_opoznienie_pakietu = system_->ZwrocOpoznieniePakietowe() / odebrane_pakiety_w_sieci;
		cout << "Srednie opoznienie pakietu: " << srednie_opoznienie_pakietu/1000<< " s" << endl;
		wyniki_ << "Srednie opoznienie pakietu: " << srednie_opoznienie_pakietu/1000  << " s" << endl;
		double srednie_oczekiwanie_pakietow = system_->ZwrocCzasOczekiwania() / nadane_pakiety;
		cout << "Sredni czas oczekiwania pakietu: " << srednie_oczekiwanie_pakietow/1000 << " s" << endl;
		wyniki_ << "Sredni czas oczekiwania pakietu: " << srednie_oczekiwanie_pakietow/1000 << " s" << endl;
		wyniki_.close();
	}

	void Symulator::WyczyscStatystyki()
	{
		system_->UstawOpoznieniePakietowe(0.0);
		system_->UstawCzasOczekiwania(0.0);
		system_->WyzerujLiczbeRetransmisji();
		system_->WyzerujLiczbeOdebranychPakietow();
		system_->WyzerujLiczbeStraconychPakietow();

	}


bool Symulator::PorownajCzasy(double czas_systemowy, double czas_zdarzenia)
{
	if (fabs(czas_systemowy - czas_zdarzenia) < eps_)
	{
		return true;
	}
	else {
		return false;
	}
}

double Symulator::UaktualnijCzas()
{
	double czas = czasy_zdarzen_[0];
	for (int i = 1; i < czasy_zdarzen_.size(); i++) {
		
		if (czasy_zdarzen_[i]< czas && czasy_zdarzen_[i] > system_->ZwrocCzas()) {
			czas = czasy_zdarzen_[i];

		}
	}
	return czas;
}

System * Symulator::ZwrocSystem()
{
	return system_;
}


Symulator::~Symulator()
{
	delete system_;
	delete nowy_pakiet1_;
	delete nowy_pakiet2_;
	delete nowy_pakiet3_;
	delete nowy_pakiet4_;
	delete nowy_pakiet5_;
	delete nowy_pakiet6_;
	delete nowy_pakiet7_;
	delete nowy_pakiet8_;
	delete nowy_pakiet9_;
	delete nowy_pakiet10_;
	delete sprawdz_kanal1_;
	delete sprawdz_kanal2_;
	delete sprawdz_kanal3_;
	delete sprawdz_kanal4_;
	delete sprawdz_kanal5_;
	delete sprawdz_kanal6_;
	delete sprawdz_kanal7_;
	delete sprawdz_kanal8_;
	delete sprawdz_kanal9_;
	delete sprawdz_kanal10_;
	delete start_transmisji1_;
	delete start_transmisji2_;
	delete start_transmisji3_;
	delete start_transmisji4_;
	delete start_transmisji5_;
	delete start_transmisji6_;
	delete start_transmisji7_;
	delete start_transmisji8_;
	delete start_transmisji9_;
	delete start_transmisji10_;
	delete kolizja_;
	delete retransmisja_pakietu1_;
	delete retransmisja_pakietu2_;
	delete retransmisja_pakietu3_;
	delete retransmisja_pakietu4_;
	delete retransmisja_pakietu5_;
	delete retransmisja_pakietu6_;
	delete retransmisja_pakietu7_;
	delete retransmisja_pakietu8_;
	delete retransmisja_pakietu9_;
	delete retransmisja_pakietu10_;
	delete wyslanie_pakietu_;
	delete wyslanie_ack_;
	delete dostarczenie_ack_;
	delete odebranie_pakietu_;

}