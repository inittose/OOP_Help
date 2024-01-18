#pragma once
#include <cstring>

class Taxpayer
{
private:
    char* _TIN;
    int _year;
    double _taxableIncome;
    double _nonTaxableIncome;
    double _totalIncomeTaxAmount;
    double _totalIncomeAmount;
    double _incomeTaxPercentage;

public:
    const char* GetTIN() const
    {
        return _TIN;
    }
    void SetTIN(const char* tin)
    {
        delete _TIN;
        _TIN = new char(strlen(tin));
        strcpy(_TIN, tin);
    }

    const int& GetYear() const
    {
        return _year;
    }
    void SetYear(const int& year)
    {
        _year = year;
    }

    const double& GetTaxableIncome() const
    {
        return _taxableIncome;
    }
    void SetTaxableIncome(const double& taxableIncome)
    {
        _taxableIncome = taxableIncome;
    }

    const double& GetNonTaxableIncome() const
    {
        return _nonTaxableIncome;
    }
    void SetNonTaxableIncome(const double& nonTaxableIncome)
    {
        _nonTaxableIncome = nonTaxableIncome;
    }

    const double& GetTotalIncomeTaxAmount() const
    {
        return _totalIncomeTaxAmount;
    }
    void SetTotalIncomeTaxAmount(const double& totalIncomeTaxAmount)
    {
        _totalIncomeTaxAmount = totalIncomeTaxAmount;
    }

    const double& GetTotalIncomeAmount() const
    {
        return _totalIncomeAmount;
    }
    void SetTotalIncomeAmount(const double& totalIncomeAmount)
    {
        _totalIncomeAmount = totalIncomeAmount;
    }

    const double& GetIncomeTaxPercentage() const
    {
        return _incomeTaxPercentage;
    }
    void SetIncomeTaxPercentage(const double& incomeTaxPercentage)
    {
        _incomeTaxPercentage = incomeTaxPercentage;
    }

public:
    Taxpayer(const char* tin, const int& year, const double &incomeTaxPercentage = 13.3);
    ~Taxpayer();
};
