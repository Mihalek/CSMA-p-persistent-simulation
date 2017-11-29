#include "kanaltransmisyjny.h"

void KanalTransmisyjny::DodajPakiet(Pakiet * dodawany_pakiet_)
{
	kanal_.push_back(dodawany_pakiet_);

}

int KanalTransmisyjny::IloscPakietowWKanale()
{
	return kanal_.size();
}


bool KanalTransmisyjny::CzyJestPusty() {
	if (kanal_.empty()) {
		return true;
	}
	else {
		return false;
	}


}

Pakiet * KanalTransmisyjny::PobierzPakiet()
{
		return kanal_.front();
	
}

void KanalTransmisyjny::UsunPakiet(Pakiet* pakiet) {
	for (int i = 0; i < IloscPakietowWKanale(); i++)
	{
		if (kanal_[i] == pakiet)
		{
			kanal_.erase(kanal_.begin() + i);
			cout << "usunieto pakiet z nadajnika " << pakiet->GetNadawca() << endl;

			return;
		}
	}
}

void KanalTransmisyjny::UsunPakiety()
{
	kanal_.clear();

}






