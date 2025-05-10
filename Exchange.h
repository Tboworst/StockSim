#ifndef EXCHANGE_H
#define EXCHANGE_H

#include "Stock.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

//Define the exchaneg class
class Exchange {
    public:
    Exchange();
        // loads stocks from a file into the stock list
    void LoadStocklist(string filename);

    // function that will display the stocks
    void DisplayStocks() const;

    //tearches for a stock by symbol
    void SearchStock(string symbol);
    
    // this will be sorted by price from descending from largest to smallest
    void SortByPrice(bool isAscending);

    // this function's goal is to loop through the stocks that we will pass while it does so it will modify the prices eithe down or up by a certain amoutn 
    void PriceChanges();
    // 
    void StockBySymbol(string symbol);

    private:
    vector <Stock> m_stockList;
};

#endif