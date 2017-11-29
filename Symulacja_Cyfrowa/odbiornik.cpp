#include"odbiornik.h"

Odbiornik::Odbiornik(int id):id_(id), odebranypakiet_(nullptr){}

Odbiornik::~Odbiornik()
{
}

int Odbiornik::GetID()
{
	return id_;
}

void Odbiornik::SetOdebranyPakiet(Pakiet * zmienna)
{
	odebranypakiet_ = zmienna;
}

Pakiet * Odbiornik::ZwrocOdebranyPakiet()
{
	return odebranypakiet_;
}

void Odbiornik::DodajDoOdebranychPakietow(Pakiet *a)
{
	odebranepakiety_.push_back(a);
}
