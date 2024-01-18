#include "menu.h"

void MainMenu()
{
    char* menuMessage = "Choose one of the actions\n1 - Add income\nq - exit\n";
    char* tin = InputTIN();
    int year;
    cout << "Enter year: ";
    year = ValidInput<int>();
    while (year <= 1999 || year > 2024)
    {
        cout << "Enter correct year (2000 - 2024): ";
        year = ValidInput<int>();
    }
    Taxpayer* taxpayer = new Taxpayer(tin, year);
    

    delete taxpayer;
    delete tin;
}

void ShowTaxpayerInfo(const Taxpayer& taxpayer)
{
    cout << "TIN: " << taxpayer.GetTIN() << "";
}

char* InputTIN()
{
    char* enterMessage = "\t   **********\rEnter TIN: ";
    cout << enterMessage;
    char* tin = new char(11);
    tin[10] = '\0';
    int counter;
    char peek = cin.get();
    for (counter = 0; counter < 10 && peek != '\n'; counter++)
    {
        cout << peek << endl;
        tin[counter] = peek;
        peek = cin.get();
    }

    while (counter < 9)
    {
        cout << "\t\t\t\t\t    **********\rEnter correct TIN number (9 or 10 numbers): ";
        peek = cin.get();
        for (counter = 0; counter < 10 && peek != '\n'; counter++)
        {
            tin[counter] = peek;
            peek = cin.get();
        }
    }

    return tin;
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