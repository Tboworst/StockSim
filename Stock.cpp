#include "Stock.h"
#include <iostream>
using namespace std;

Stock::Stock(string symbol, double price): m_stockSymbol(symbol), m_stockPrice(price) {}

string Stock::GetStockSymbol() const 
{
    return m_stockSymbol;
}

double Stock::GetStockPrice() const 
{
    return m_stockPrice;
}

void Stock::UpdateStockPrice(double newPrice) 
{
    m_stockPrice = newPrice;
}

void Stock::DisplayStockInfo() const 
{
    cout << m_stockSymbol << ": $" << m_stockPrice << endl;
}
