# Stock Market Simulator

A C++ based stock market simulator that allows users to simulate and monitor stock prices in a virtual environment. This project provides a hands-on way to understand stock market mechanics through a command-line interface.

## Features

- Real-time stock price simulation with random price fluctuations
- Stock price monitoring and tracking
- Market exchange simulation
- Interactive command-line interface
- Stock price sorting and searching capabilities
- File-based stock data loading

## Detailed Functionality

The simulator provides the following key features:

1. **Stock Management**
   - Load stock data from text files
   - Display all available stocks
   - Search for specific stocks by symbol
   - Sort stocks by price (ascending/descending)

2. **Price Simulation**
   - Simulate random price changes for stocks
   - Realistic price fluctuation patterns
   - Track price history

3. **User Interface**
   - Interactive menu system
   - Easy-to-use command-line interface
   - Clear display of stock information

## Prerequisites

- C++ compiler (g++ recommended)
- Make build system

## Installation

1. Clone the repository:
```bash
git clone https://github.com/tboworst/StockSim.git
cd StockSim
```

2. Compile the project:
```bash
make
```

## Usage

1. Run the simulator:
```bash
./StockSim
```

2. The program will present you with a menu of options:
   - Load stock list from file
   - Display all stocks
   - Search for stock by symbol
   - Sort stocks by price
   - Simulate price changes
   - Exit

3. The program uses the stock prices from `stock_price.txt` which contains a list of stocks and their initial prices in the format:
```
SYMBOL PRICE
```

For example:
```
AAPL 266.83
TSLA 397.9
GOOGL 325.66
```

## Project Structure

- `main.cpp` - Main program entry point with menu system
- `Stock.h`/`Stock.cpp` - Stock class implementation for individual stock management
- `Portfolio.h`/`Portfolio.cpp` - Portfolio management system
- `Exchange.h`/`Exchange.cpp` - Stock exchange simulation with price management
- `stock_price.txt` - Initial stock prices
- `Makefile` - Build configuration

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgments

- Stock price data is for simulation purposes only
- This is a learning project for understanding stock market mechanics
- Designed to help users understand basic stock market operations 