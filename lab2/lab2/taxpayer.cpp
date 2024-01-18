#include "taxpayer.h"

Taxpayer::Taxpayer(const char* tin, const int& year, const double& incomeTaxPercentage)
{
	_TIN = new char(std::strlen(tin));
	std::strcpy(_TIN, tin);
	_year = year;
	_incomeTaxPercentage = incomeTaxPercentage;
	_taxableIncome = 0;
	_nonTaxableIncome = 0;
	_totalIncomeTaxAmount = 0;
	_totalIncomeAmount = 0;
}

Taxpayer::~Taxpayer()
{
	delete _TIN;
}

