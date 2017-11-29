#ifndef GENERATOR_H_
#define GENERATOR_H_
#include<cmath>

// Klasa reprezentujaca generator liczb pseudolosowych, zostal uzyty generator z wykladu


class Generator {
private:
	const int M_, A_, Q_, R_;
	int id_;
	double lambda_;
	__int64 ziarno_;

public:
	Generator(int id, __int64 ziarno);
	~Generator();
	double GeneratorRownomiernyRealistyczny(__int64&);  // Generator Rownomierny Realistyczny
	int GeneratorRownomiernyCalkowity(int id, int, int); //Generator Rownomierny Calkowity
	double GeneratorWykladniczy();  //Generator Wykladniczny	



	/*
	__int64 Generator_seeds(__int64); // Funkcja Generujaca Ziarna
	void ZapiszPlikZZiarnami(__int64);	// Funkcja Zapisujaca Ziarna Do pliku
	void HistogramWykladniczy(int);  // Funkcja Generujaca Histogram Wykladniczy
	void HistogramRownomierny(int); // Funkcja Generujaca Histogram Rownomierny
	*/
};


#endif GENERATOR_H_#pragma once
