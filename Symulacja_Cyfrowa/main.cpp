#include<iostream>
#include"pakiet.h"
#include"nadajnik.h"
#include"kanaltransmisyjny.h"
#include"odbiornik.h"
#include"generator.h"
#include"utworzeniepakietu.h"
#include"system.h"
#include"starttransmisji.h"
#include"wyslaniepakietu.h"
#include"odebraniepakietu.h"
#include <windows.h>
#include"symulator.h"
using namespace std;

int main() {
	int czas_symulacji_ = 1500;
	__int64 ziarna_[30];
	__int64 ziarno = 117;
	__int64 zmienna = ziarno;
	int liczba_symulacji_ = 19;
	int ilosc = 10;
	int flaga;
	int flaga2;
	double faza_poczatkowa;

	cout << "Czy chcesz wyswietlac logi??" << endl;
	cout << "0 -> Nie   ------  1 -> Tak" << endl;
	cin >> flaga;
	
    cout << "Chcesz wlaczyc tryb ciagly czy tryb krokowy?? " << endl;
	cout << "0 -> Ciagly   ------  1 -> Krokowy" << endl;
	cin >> flaga2;
	
	cout << "Podaj koniec fazy poczatkowej: [Ustalona jako 550 ms] " << endl;
	cin >> faza_poczatkowa;


	for (int i = 0; i < liczba_symulacji_; i++) {
		for (int j = 0; j < 30; j++) {
			for (int k = 0; k < 100000; k++) {
				zmienna = (16807 * zmienna) % 2147483647;
			}
			ziarna_[j] = zmienna;
		}
		cout << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
		cout << "-----------NR SYMULACJI " << i << "-------------" << endl;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		Symulator * symulator = new Symulator(10, ziarna_, flaga, flaga2,faza_poczatkowa, i, czas_symulacji_);
		symulator->Symuluj();
		cout << endl;
		symulator->Statystyki(i);
		delete symulator;
			
	}
		




	system("pause");

	return 0;


}