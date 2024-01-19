#include "taxpayer.h"
#include <iostream>
using std::cout, std::endl;
Taxpayer::Taxpayer(const char* tin, const int& year, const double& incomeTaxPercentage)
{
    int tinLenth = strlen(tin);
    _TIN = new char[tinLenth + 1];
    _TIN[tinLenth] = '\0';
    strcpy(_TIN, tin);
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

void Taxpayer::UpdateTaxAmount()
{
    _totalIncomeTaxAmount = _taxableIncome * _incomeTaxPercentage / 100.0;
}

void Taxpayer::UpdateTotalIncomeAmount()
{
    _totalIncomeAmount = _taxableIncome + _nonTaxableIncome - _totalIncomeTaxAmount;
}

void Taxpayer::AddIncome(const int& income, const bool& taxability)
{
    if (taxability)
    {
        _taxableIncome += income;
        UpdateTaxAmount();
    }
    else
    {
        _nonTaxableIncome += income;
    }
    UpdateTotalIncomeAmount();
}
