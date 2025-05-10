#include "Exchange.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <fstream>
using namespace std;

Exchange::Exchange()
{
    srand(time(0));
}

void Exchange::LoadStocklist(string filename)
{
    string symbol;
    double price;

    ifstream inputstream(filename);
    if (!inputstream)
    {
        cout << "The stock exchange is not open!" << endl;
        return;
    }

    while (inputstream >> symbol >> price)
    {
        m_stockList.push_back(Stock(symbol, price));
        cout << symbol << " $" << price << endl;
    }
    inputstream.close();
}

void Exchange::DisplayStocks() const
{
    for (int i = 0; i < m_stockList.size(); i++)
    {
        m_stockList[i].DisplayStockInfo();
    }
}

void Exchange::SearchStock(string symbol)
{
    bool found = false;
    for (int i = 0; i < m_stockList.size(); i++)
    {
        if (m_stockList[i].GetStockSymbol() == symbol)
        {
            m_stockList[i].DisplayStockInfo();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Stock not found." << endl;
    }
}

void Exchange::SortByPrice(bool isAscending)
{
    for (int i = 0; i < m_stockList.size() - 1; i++)
    {
        for (int j = 0; j < m_stockList.size() - i - 1; j++)
        {
            double price1 = m_stockList[j].GetStockPrice();
            double price2 = m_stockList[j + 1].GetStockPrice();

            if ((isAscending && price1 > price2) || (!isAscending && price1 < price2))
            {
                Stock temp = m_stockList[j];
                m_stockList[j] = m_stockList[j + 1];
                m_stockList[j + 1] = temp;
            }
        }
    }
    cout << "Stocks sorted by price (" << (isAscending ? "ascending" : "descending") << ")." << endl;
}

void Exchange::PriceChanges()
{
    for (int i = 0; i < m_stockList.size(); i++)
    {
        double oldPrice = m_stockList[i].GetStockPrice();
        double changePercent = (rand() % 1001 - 500) / 10000.0; // Random change between -5% and +5%
        double newPrice = oldPrice * (1 + changePercent);
        m_stockList[i].UpdateStockPrice(newPrice);
    }
}

void Exchange::StockBySymbol(string symbol)
{
    bool found = false;
    for (int i = 0; i < m_stockList.size(); i++)
    {
        if (m_stockList[i].GetStockSymbol() == symbol)
        {
            m_stockList[i].DisplayStockInfo();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Stock not found." << endl;
    }
}