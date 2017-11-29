#include"generator.h"
#include<fstream>
#include<iostream>
using namespace std;

fstream ziarna_do_pliku("ziarna.txt", ios::out | ios::ate);
fstream histogram_wykladniczy("histogram_wykladniczy.txt", ios::out | ios::ate);
fstream histogram_rownomierny("histogram_rownomierny.txt", ios::out | ios::ate);

Generator::Generator(int id, __int64 ziarno) :id_(id), ziarno_(ziarno), M_(2147483647), A_(16807), Q_(127773), R_(2836), lambda_(0.03) {


}


Generator::~Generator() {}


// Generator równomierny liczb ca³kowitych z zakresu <min, max>
int Generator::GeneratorRownomiernyCalkowity(int id, int min, int max)
{
	return (min + GeneratorRownomiernyRealistyczny(ziarno_)*(max - min));
}

// Generator wyk³adniczy
double Generator::GeneratorWykladniczy()
{
	//cout << -log(Even_generator_real(aktualne_ziarno)) / lambda_<< endl;
	return -log(GeneratorRownomiernyRealistyczny(ziarno_)) / lambda_;
}




// Generator równomierny liczb pseudolosowych z zakresu <0, 1>
double Generator::GeneratorRownomiernyRealistyczny(__int64 &ziarno_) {
	double kernel_ = ziarno_;

	int h_ = kernel_ / Q_;
	kernel_ = A_*(kernel_ - Q_*h_) - R_*h_;
	ziarno_ = kernel_;
	if (kernel_ < 0) {
		kernel_ = kernel_ + M_;
	}

	return kernel_ / M_;
}

//Funkcja, która generuje ziarno
/*
__int64 Generator::Generator_seeds(__int64 ziarno)
{
	int ilosc_iteracji_ = 100000;

	__int64 kernel_ = ziarno;

	for (int i = 0; i < ilosc_iteracji_; i++) {

		__int64 h_ = kernel_ / Q_;
		kernel_ = A_*(kernel_ - Q_*h_) - R_*h_;
		if (kernel_ < 0) {
			kernel_ = kernel_ + M_;
		}
	}
	return kernel_;

}*/

/*

void Generator::ZapiszPlikZZiarnami(__int64 ziarno_)
{
	int przerwa_miedzy_ziarnami = 100000;
	int ile_nadajnikow_ = 10;
	__int64 kernel_;
	__int64 tablica_ziaren[10];
	int ile_symulacji_ = 10;
	for (int k = 0; k < ile_symulacji_;k++)
	{
		ziarna_do_pliku << endl;
		for (int i = 0; i < ile_nadajnikow_;i++)
		{
			for (int j = 0; j < przerwa_miedzy_ziarnami;j++)
			{
				kernel_ = ziarno_;
				int h_ = kernel_ / Q_;
				kernel_ = A_*(kernel_ - Q_*h_) - R_*h_;
				if (kernel_ < 0) {
					kernel_ = kernel_ + M_;
				}
				ziarno_ = kernel_;

			}
			tablica_ziaren[i] = ziarno_;

			ziarna_do_pliku << tablica_ziaren[i] << ' ';

		}
	}

}
*/

// Funkcja zapisuj¹ca do pliku tekstowego wartoœci histogramu dla generatora wykladniczego



/*
void Generator::HistogramWykladniczy(int x)
{
	int tablica_[1000] = { 0 };
	__int64 ziarno_ = Generator_seeds(x);
	//	cout << ziarno_;
	int liczba_ = 0;
	for (int i = 0; i < 100000; i++)
	{
		liczba_ = GeneratorWykladniczy();
		//cout << liczba_;
		if (liczba_ < 1000 && liczba_ >= 0) {
			tablica_[liczba_]++;
		}
	}
	for (int i = 0; i < 1000;i++)
	{
		histogram_wykladniczy << tablica_[i] << ',';
	}
}
*/


// Funkcja zapisuj¹ca do pliku tekstowego wartoœci histogramu dla generatora równomiernego

/*
void Generator::HistogramRownomierny(int x)
{
	int tablica_[1000] = { 0 };
	__int64 liczba_ = Generator_seeds(x);

	for (int i = 0; i < 100000; i++)
	{

		tablica_[GeneratorRownomiernyCalkowity(1, liczba_, 0, 999)]++;
	}
	for (int i = 0; i < 1000; i++)
	{
		histogram_rownomierny << tablica_[i] << ',';
	}
} */



