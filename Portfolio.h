#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Stock.h"
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Portfolio {
    public:
        Portfolio() : m_balance(10000.0) {}  // Initialize with $10,000
        ~Portfolio() = default;

        // Stock management
        void BuyStock(Stock* stockPtr, int quantity);
        void SellStock(string symbol, int quantity);
        void displayPortfolio() const;

        // Legacy methods (can be removed if not needed)
        void addUserStock(Stock* StockPtr);
        void displayBoughtStocks();

    private:
        struct UserStock {
            Stock* stockPtr;
            int quantityOwned;
            double purchasePrice;
        };

        double m_balance;
        vector<unique_ptr<UserStock>> m_stockHolding;
        vector<Stock*> m_stockList;  // Legacy member (can be removed if not needed)
};

#endif