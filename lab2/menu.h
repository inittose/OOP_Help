#pragma once
#include "taxpayer.h"
#include <string>
#include <iostream>
using std::cout, std::cin, std::endl, std::string;

/// <summary>
/// Главное меню
/// </summary>
void MainMenu();

/// <summary>
/// Вывести информацию о налогоплательщике
/// </summary>
/// <param name="taxpayer">Налогоплательщик</param>
void ShowTaxpayerInfo(const Taxpayer* taxpayer);

/// <summary>
/// Создать символы ввода
/// </summary>
/// <param name="inputMessage">Сообщение до символов ввода</param>
/// <param name="inputCharacters">Количество символов ввода</param>
void InputField(const string& inputMessage, const int& inputCharacters);

/// <summary>
/// Взять наименование типа
/// </summary>
/// <param name="letter">название типа переменной (typeid().name)</param>
/// <returns>Полное наименование типа</returns>
string GetTypeName(const char* letter);

/// <summary>
/// Ввод ИНН
/// </summary>
/// <returns>строчка ИНН</returns>
char* InputTIN();

/// <summary>
/// Ввод с валидацией
/// </summary>
/// <typeparam name="Type">Любой базовый тип переменной</typeparam>
/// <returns>Значение переменной</returns>
template <typename Type>
Type ValidInput();

/// <summary>
/// Очистить консоль
/// </summary>
void ClearTerminal();
