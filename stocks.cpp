#include <iostream>
#include <cstring>
#include "stocks.h"

/* 默认构造函数 */
stock::stock()
{
	std::cout << "bft ===================================.\n";
	std::cout << "default constructor called.\n";
	std::strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

stock::stock(const char *co, int n, double pr)
{
	std::cout << "bft --------------------------------.\n";
	std::cout << "constructor using " << co << " called.\n";
	std::strncpy(company, co, 29);
	company[29] = '\0';

	if (n < 0)
	{
		std::cerr << "number of shares can't be negative; "
			<< company << "shares set to 0.\n";
		shares = 0;
	} else
		shares = n;
	share_val = pr;
	set_tot();
}

stock::~stock()
{
	std::cout << "bye, " << company << "!\n";
}

void stock::buy(int num, double price)
{
	if (num < 0) {
		std::cerr << "number of shares purchased can't be negative. "
			<< "transaction is aborted.\n";
	} else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void stock::sell(int num, double price)
{
	using std::cerr;
	if (num < 0) {
		cerr << "number of shares sold can't be negative. "
			<< "transaction is aborted.\n";
	} else if (num > shares) {
		cerr << "you can't sell more than you hanve! "
			<< "transaction is aborted.\n";
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void stock::update(double price)
{
	share_val = price;
	set_tot();
}

void stock::show()
{
	using std::cout;
	using std::endl;
	cout << "company: " << company
		<< " shares: " << shares << endl
		<< " share price: $" << share_val
		<< " total worth: $" << total_val << endl;
}

