#include "currency/Currency.h"
#include "currency/Stocks.h"
#include <iostream>
#include <vector>

using namespace currency;

// Полиморфная функция для демонстрации
void demonstratePolymorphism(Currency* obj, double rate, const std::string& name) {
    std::cout << "--- Демонстрация для " << name << " ---" << std::endl;
    std::cout << "Объект: " << *obj << std::endl;
    std::cout << "Рыночная стоимость по курсу " << rate << ": " 
              << obj->getMarketValue(rate) << std::endl;
    obj->print();
    std::cout << std::endl;
}

int main() {
    std::cout << "=== Лабораторная работа №2: Наследование и полиморфизм ===\n" << std::endl;
    
    // 1. Создание объектов
    std::cout << "1. Создание объектов:" << std::endl;
    
    Currency usd(100.50, "USD");
    Stocks appleStocks(175.25, "USD", 10);  // 10 акций по $175.25
    
    std::cout << "   Currency объект: " << usd << std::endl;
    std::cout << "   Stocks объект:   " << appleStocks << std::endl;
    std::cout << std::endl;
    
    // 2. Демонстрация работы с базовым классом
    std::cout << "2. Демонстрация работы с базовым классом Currency:" << std::endl;
    demonstratePolymorphism(&usd, 1.2, "Currency");
    
    // 3. Демонстрация работы с производным классом Stocks
    std::cout << "3. Демонстрация работы с производным классом Stocks:" << std::endl;
    demonstratePolymorphism(&appleStocks, 1.2, "Stocks");
    
    // 4. Демонстрация полиморфного поведения через вектор
    std::cout << "4. Демонстрация полиморфного поведения через вектор:" << std::endl;
    
    std::vector<Currency*> assets;
    assets.push_back(&usd);
    assets.push_back(&appleStocks);
    
    double eurRate = 0.92;
    
    for (size_t i = 0; i < assets.size(); ++i) {
        std::cout << "Актив " << i+1 << ": " << *assets[i] << std::endl;
        std::cout << "   Рыночная стоимость (EUR, курс " << eurRate << "): " 
                  << assets[i]->getMarketValue(eurRate) << std::endl;
    }
    
    // 5. Демонстрация специфических методов Stocks
    std::cout << "\n5. Специфические методы Stocks:" << std::endl;
    std::cout << "   Lot size: " << appleStocks.getLotSize() << std::endl;
    
    appleStocks.setLotSize(20);
    std::cout << "   После изменения lot size на 20: " << appleStocks << std::endl;
    std::cout << "   Рыночная стоимость: " << appleStocks.getMarketValue(1.2) << std::endl;
    
    // 6. Проверка обработки исключений
    std::cout << "\n6. Проверка обработки исключений:" << std::endl;
    try {
        Stocks invalidStocks(100.0, "USD", -5);
    } catch (const std::exception& e) {
        std::cout << "   Ошибка при создании: " << e.what() << std::endl;
    }
    
    try {
        appleStocks.setLotSize(0);
    } catch (const std::exception& e) {
        std::cout << "   Ошибка при установке: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== Лабораторная работа №2 успешно завершена ===" << std::endl;
    
    return 0;
}
