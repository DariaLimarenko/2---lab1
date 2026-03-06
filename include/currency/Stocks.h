#pragma once

#include "Currency.h"

namespace currency {

class Stocks : public Currency {
private:
    int lotSize;  // Количество единиц в лоте

public:
    // Конструкторы
    Stocks();
    Stocks(double amount, const std::string& code, int lotSize);

    // Get/Set методы для lotSize
    int getLotSize() const;
    void setLotSize(int lotSize);

    // Переопределение виртуальных методов
    double getMarketValue(double rate) const override;
    void print() const override;

    // Переопределение оператора << (через дружественную функцию)
    friend std::ostream& operator<<(std::ostream& os, const Stocks& stocks);
};

} // namespace currency
