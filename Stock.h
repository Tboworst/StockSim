#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;

//define the stock class
class Stock {
    public:
    Stock(string symbol, double price);

    //getter for stock symbol
    string GetStockSymbol() const;
    //getter for stock price 
    double GetStockPrice () const;

    // update stock price
    void UpdateStockPrice(double newPrice);

    //will dispaly the stock symbol and price 
    void DisplayStockInfo() const;

    
    private:
    string m_stockSymbol;
    double m_stockPrice;
};

#endif
