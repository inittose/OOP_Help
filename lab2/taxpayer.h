#pragma once
#include <cstring>

class Taxpayer
{
private:
    /// <summary>
    /// ИНН (Идентификационный Номер Налогоплательщика)
    /// </summary>
    char* _TIN;

    /// <summary>
    /// Год расчета
    /// </summary>
    int _year;

    /// <summary>
    /// Налогооблагаемый доход (до вычета налога)
    /// </summary>
    double _taxableIncome;

    /// <summary>
    /// Неналогооблагаемый доход
    /// </summary>
    double _nonTaxableIncome;

    /// <summary>
    /// Итог суммы подоходного налога
    /// </summary>
    double _totalIncomeTaxAmount;

    /// <summary>
    /// Итог суммы доходов
    /// </summary>
    double _totalIncomeAmount;

    /// <summary>
    /// Процент подоходного налога
    /// </summary>
    double _incomeTaxPercentage;

public:
    /// <summary>
    /// Селектор для ИНН
    /// </summary>
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

    /// <summary>
    /// Селектор для ИНН
    /// </summary>
    const int& GetYear() const
    {
        return _year;
    }
    void SetYear(const int& year)
    {
        _year = year;
    }

    /// <summary>
    /// Селектор для ИНН
    /// </summary>
    const double& GetTaxableIncome() const
    {
        return _taxableIncome;
    }
    void SetTaxableIncome(const double& taxableIncome)
    {
        _taxableIncome = taxableIncome;
    }

    /// <summary>
    /// Селектор для ИНН
    /// </summary>
    const double& GetNonTaxableIncome() const
    {
        return _nonTaxableIncome;
    }
    void SetNonTaxableIncome(const double& nonTaxableIncome)
    {
        _nonTaxableIncome = nonTaxableIncome;
    }

    /// <summary>
    /// Селектор для ИНН
    /// </summary>
    const double& GetTotalIncomeTaxAmount() const
    {
        return _totalIncomeTaxAmount;
    }
    void SetTotalIncomeTaxAmount(const double& totalIncomeTaxAmount)
    {
        _totalIncomeTaxAmount = totalIncomeTaxAmount;
    }

    /// <summary>
    /// Селектор для ИНН
    /// </summary>
    const double& GetTotalIncomeAmount() const
    {
        return _totalIncomeAmount;
    }
    void SetTotalIncomeAmount(const double& totalIncomeAmount)
    {
        _totalIncomeAmount = totalIncomeAmount;
    }

    /// <summary>
    /// Селектор для ИНН
    /// </summary>
    const double& GetIncomeTaxPercentage() const
    {
        return _incomeTaxPercentage;
    }
    void SetIncomeTaxPercentage(const double& incomeTaxPercentage)
    {
        _incomeTaxPercentage = incomeTaxPercentage;
    }

public:
    /// <summary>
    /// Конструктор
    /// </summary>
    Taxpayer(const char* tin, const int& year, const double &incomeTaxPercentage = 13.3);
    /// <summary>
    /// Деструктор
    /// </summary>
    ~Taxpayer();

    /// <summary>
    /// Добавить статью дохода налогооблагаемого
    /// </summary>
    void AddIncome(const int& income, const bool& taxability);

private:
    /// <summary>
    /// Обновить сумму подоходного налога
    /// </summary>
    void UpdateTaxAmount();
    /// <summary>
    /// Обновить сумму дохода
    /// </summary>
    void UpdateTotalIncomeAmount();
};
