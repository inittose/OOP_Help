#include "menu.h"

void MainMenu()
{
    string menuMessage = "Choose one of the actions:\n1 - Add income\nq - exit\nYour choice: ";
    char* tin = InputTIN();
    int year;
    InputField("Enter year: ", 4);
    year = ValidInput<int>();
    while (year <= 1999 || year > 2024)
    {
        InputField("Enter correct year (2000 - 2024): ", 4);
        year = ValidInput<int>();
    }
    Taxpayer* taxpayer = new Taxpayer(tin, 2000);
    cout << endl;

    char mode = '\0';
    while (mode != 'q')
    {
        ClearTerminal();
        ShowTaxpayerInfo(taxpayer);
        cout << menuMessage;
        mode = ValidInput<char>();
        while (mode != '1' && mode != 'q')
        {
            cout << "Enter correct action: ";
            mode = ValidInput<char>();
        }
        if (mode == '1')
        {
            cout << "Enter the number of income: ";
            int income = ValidInput<int>();
            cout << "Enter whether it is taxable (0 - No): ";
            bool taxability = ValidInput<bool>();
            taxpayer->AddIncome(income, taxability);
        }
    }

    delete taxpayer;
    delete tin;
}

void ShowTaxpayerInfo(const Taxpayer* taxpayer)
{
    cout << "TIN: " << taxpayer->GetTIN() << "\nYear: " << taxpayer->GetYear()
         << "\nIncome tax percentage: " << taxpayer->GetIncomeTaxPercentage()
         << "\nTaxable income: " << taxpayer->GetTaxableIncome()
         << "\nNon taxable income: " << taxpayer->GetNonTaxableIncome()
         << "\nTotal income tax amount: " << taxpayer->GetTotalIncomeTaxAmount()
         << "\nTotal income amount: " << taxpayer->GetTotalIncomeAmount() << endl;
}

char* InputTIN()
{
    InputField("Enter TIN: ", 10);
    char* tin = new char[11];
    int counter;
    char peek = cin.get();
    for (counter = 0; counter < 10 && isdigit(peek); counter++)
    {
        tin[counter] = peek;
        peek = cin.get();
    }
    if (peek != '\n')
    {
        while (cin.get() != '\n');
    }

    while (counter < 9)
    {
        InputField("Enter correct TIN number (9 or 10 numbers): ", 10);
        peek = cin.get();
        for (counter = 0; counter < 10 && isdigit(peek); counter++)
        {
            tin[counter] = peek;
            peek = cin.get();
        }
        if (peek != '\n')
        {
            while (cin.get() != '\n');
        }
    }
    tin[counter] = '\0';

    return tin;
}

void InputField(const string& inputMessage, const int& inputCharacters)
{
    cout << inputMessage;
    for (int i = 0; i < inputCharacters; i++)
    {
        cout << "*";
    }
    cout << "\r" << inputMessage;
}

string GetTypeName(const char* letter)
{
    switch (*letter)
    {
    case 'c':
        return "char";
    case 'i':
        return "integer";
    case 'f':
        return "float";
    case 'd':
        return "double";
    case 'N':
        return "string";
    default:
        return string("UNKNOWN_TYPE (") + letter + string(")");
    }
}

template <typename Type>
Type ValidInput()
{
    Type variable;
    cin >> variable;
    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter correct " << GetTypeName(typeid(variable).name()) << " value: ";
        cin >> variable;
    }
    return variable;
}

void ClearTerminal()
{
    if (system("cls"))
    {
        system("clear");
    }
}
