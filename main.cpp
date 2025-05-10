#include <iostream>
#include <string>
#include <cstdlib>

#include "Exchange.h"
using namespace std;

void mainMenu(Exchange& exchange);

int main()
{
    Exchange exchange;
    mainMenu(exchange);
    return 0;
}

void mainMenu(Exchange& exchange)
{
    bool gameRunning = true;
    while (gameRunning)
    {
        cout << "---StockSim Main Menu---" << endl;
        cout << "1. Load stock list from file" << endl;
        cout << "2. Display all stocks" << endl;
        cout << "3. Search for stock by symbol" << endl;
        cout << "4. Sort stocks by price" << endl;
        cout << "5. Simulate price changes" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        if (choice < 1 || choice > 6)
        {
            cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
            continue;
        }

        switch (choice)
        {
            case 1: {
                string filename;
                cout << "Enter a filename: ";
                cin >> filename;
                exchange.LoadStocklist(filename);
                break;
            }

            case 2:
                exchange.DisplayStocks();
                break;

            case 3: {
                string symbol;
                cout << "Enter a symbol: ";
                cin >> symbol;
                exchange.SearchStock(symbol);
                break;
            }

            case 4:
                exchange.SortByPrice(true);
                break;

            case 5:
                exchange.PriceChanges();
                break;

            case 6:
                cout << "StockSim closed. Goodbye!" << endl;
                gameRunning = false;
                break;
        }
    }
}
