#include "currency/Stocks.h"

namespace currency {

// Конструктор по умолчанию
Stocks::Stocks() : Currency(), lotSize(1) {}

// Конструктор с параметрами
Stocks::Stocks(double amount, const std::string& code, int lotSize) 
    : Currency(amount, code), lotSize(lotSize) {
    if (lotSize <= 0) {
        throw std::invalid_argument("Lot size must be positive");
    }
}

// Get метод для lotSize
int Stocks::getLotSize() const {
    return lotSize;
}

// Set метод для lotSize
void Stocks::setLotSize(int lotSize) {
    if (lotSize <= 0) {
        throw std::invalid_argument("Lot size must be positive");
    }
    this->lotSize = lotSize;
}

// Переопределение метода получения рыночной стоимости
// Для акций стоимость = сумма * курс * размер лота
double Stocks::getMarketValue(double rate) const {
    return amount * rate * lotSize;
}

// Переопределение метода вывода
void Stocks::print() const {
    std::cout << "=== Stocks Information ===" << std::endl;
    std::cout << "Formatted per unit: " << format() << std::endl;
    std::cout << "Code: " << code << std::endl;
    std::cout << "Amount per unit: " << std::fixed << std::setprecision(2) << amount << std::endl;
    std::cout << "Lot size: " << lotSize << " units" << std::endl;
    std::cout << "Total value: " << getSymbol(code) << (amount * lotSize) << std::endl;
    std::cout << "Symbol: " << getSymbol(code) << std::endl;
    std::cout << "==========================" << std::endl;
}

// Переопределение оператора <<
std::ostream& operator<<(std::ostream& os, const Stocks& stocks) {
    os << stocks.format() << " × " << stocks.lotSize << " lots (" << stocks.code << ")";
    return os;
}

} // namespace currency
