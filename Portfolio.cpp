#include "Portfolio.h"
#include <iostream>
#include <memory>
#include <utility>  // for std::move
using namespace std;

void Portfolio::BuyStock(Stock* stockPtr, int quantity)
{
    if (stockPtr == nullptr) {
        cout << "Invalid stock pointer." << endl;
        return;
    }

    double price = stockPtr->GetStockPrice();
    double totalCost = price * quantity;

    if (totalCost > m_balance) {
        cout << "Insufficient funds. Transaction cancelled." << endl;
        return;
    }

    m_balance -= totalCost;  // Fixed the -= operator

    // Create new stock holding using std::unique_ptr
    std::unique_ptr<UserStock> newStock(new UserStock());
    newStock->stockPtr = stockPtr;
    newStock->quantityOwned = quantity;
    newStock->purchasePrice = price;

    m_stockHolding.push_back(std::move(newStock));

    cout << "You've purchased " << quantity << " shares of " 
         << stockPtr->GetStockSymbol() << " at $" << price 
         << " each. Total: $" << totalCost << endl;
}

void Portfolio::SellStock(string symbol, int quantity) 
{
    for (int i = 0; i < m_stockHolding.size(); i++) 
    {
        if (m_stockHolding[i]->stockPtr->GetStockSymbol() == symbol) 
        {
            if (m_stockHolding[i]->quantityOwned < quantity) 
            {
                cout << "You don't have enough shares to sell." << endl;
                return;
            }

            double currentPrice = m_stockHolding[i]->stockPtr->GetStockPrice();
            double saleValue = currentPrice * quantity;
            m_balance += saleValue;

            m_stockHolding[i]->quantityOwned -= quantity;

            cout << "Sold " << quantity << " shares of " << symbol 
                 << " at $" << currentPrice << " each. Gained $" << saleValue << endl;

            if (m_stockHolding[i]->quantityOwned == 0) 
            {
                m_stockHolding.erase(m_stockHolding.begin() + i);
            }
            return;
        }
    }
    cout << "Stock not found in portfolio." << endl;
}

void Portfolio::displayPortfolio() const
{
    cout << "--- Your Portfolio ---" << endl;
    double totalValue = 0.0;  // Moved outside the if-else block

    if (m_stockHolding.empty()) 
    {
        cout << "You don't own any stocks." << endl;
    } 
    else 
    {
        for (int i = 0; i < m_stockHolding.size(); i++) 
        {
            string symbol = m_stockHolding[i]->stockPtr->GetStockSymbol();
            double price = m_stockHolding[i]->stockPtr->GetStockPrice();
            int quantity = m_stockHolding[i]->quantityOwned;
            double value = quantity * price;

            cout << symbol << " | Shares: " << quantity
                 << " | Price: $" << price
                 << " | Value: $" << value << endl;

            totalValue += value;
        }

        cout << "Portfolio Value: $" << totalValue << endl;
    }

    cout << "Cash Balance: $" << m_balance << endl;
    cout << "Total Account Value: $" << (m_balance + totalValue) << endl;
}

// Legacy methods (can be removed if not needed)
void Portfolio::addUserStock(Stock* StockPtr)
{
    if (StockPtr != nullptr) {
        m_stockList.push_back(StockPtr);
    }
}

void Portfolio::displayBoughtStocks()
{
    if (m_stockList.empty()) {
        cout << "No stocks in portfolio." << endl;
        return;
    }
    
    cout << "\nYour Portfolio:" << endl;
    cout << "----------------" << endl;
    for (int i = 0; i < m_stockList.size(); i++) {
        if (m_stockList[i] != nullptr) {
            m_stockList[i]->DisplayStockInfo();
        }
    }
    cout << "----------------" << endl;
}

