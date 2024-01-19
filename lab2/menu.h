#pragma once
#include "taxpayer.h"
#include <string>
#include <iostream>
using std::cout, std::cin, std::endl, std::string;

void MainMenu();

void ShowTaxpayerInfo(const Taxpayer* taxpayer);

void InputField(const string& inputMessage, const int& inputCharacters);

string GetTypeName(const char* letter);

char* InputTIN();

template <typename Type>
Type ValidInput();

void ClearTerminal();
