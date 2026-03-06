#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <stdexcept>

namespace currency {

class Currency {
protected:  // Изменено с private на protected для доступа в наследниках
    double amount;
    std::string code;
    
public:
    // Конструкторы
    Currency();
    Currency(double amount, const std::string& code);
    
    // Виртуальный деструктор для полиморфизма
    virtual ~Currency() = default;
    
    // Get методы
    double getAmount() const;
    std::string getCode() const;
    
    // Set методы
    void setAmount(double amount);
    void setCode(const std::string& code);
    
    // Публичные методы
    void convertTo(const std::string& newCode, double rate);
    std::string format() const;
    bool isSameCurrency(const Currency& other) const;
    Currency add(const Currency& other, double rate) const;
    double getAmountInUSD(double usdRate) const;
    void roundToTwoDecimals();
    
    // Виртуальные методы для полиморфизма
    virtual double getMarketValue(double rate) const;
    virtual void print() const;
    
    // Перегрузка операторов
    bool operator==(const Currency& other) const;
    Currency operator+(const Currency& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
    
    // Статический метод
    static std::string getSymbol(const std::string& code);
};

} // namespace currency
