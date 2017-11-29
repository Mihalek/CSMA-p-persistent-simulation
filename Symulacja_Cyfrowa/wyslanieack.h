
#include "system.h"

class WyslanieAck {
private:
	System *system_;
	double czas;
public:
	WyslanieAck(System*);
	void Wykonaj(bool flaga);
	double ZwrocCzas();
	void UstawCzas(double);



};

