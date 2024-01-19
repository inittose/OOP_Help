#include "taxpayer.h"
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

Taxpayer::Taxpayer( const char* tin, const int& year, const double& taxableIncome,
                    const double& nonTaxableIncome, const double& incomeTaxPercentage)
{
    int tinLenth = strlen(tin);
    _TIN = new char[tinLenth + 1];
    _TIN[tinLenth] = '\0';
    strcpy(_TIN, tin);
    _year = year;
    _incomeTaxPercentage = incomeTaxPercentage;
    _taxableIncome = taxableIncome;
    _nonTaxableIncome = nonTaxableIncome;
    _totalIncomeTaxAmount = 0;
    _totalIncomeAmount = 0;
    UpdateTaxAmount();
    UpdateTotalIncomeAmount();
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

void Taxpayer::AddIncome(const double& income, const bool& taxability)
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

void Taxpayer::AddIncomeAfterTax(const double& incomeAfterTax)
{
    _taxableIncome += incomeAfterTax / (1 - _incomeTaxPercentage / 100);
    UpdateTaxAmount();
    UpdateTotalIncomeAmount();
}

istream& operator>>(istream& os, Taxpayer& taxpayer)
{
    int incomeAfterTax;
    os >> incomeAfterTax;
    taxpayer.AddIncomeAfterTax(incomeAfterTax);
    return os;
}

void operator+=(double& sum, const Taxpayer& taxpayer)
{
    sum += taxpayer._totalIncomeTaxAmount;
}