#include <QCoreApplication>
#include <iostream>
#include <cstring>

class stock
{
private:
    char company[30];
    int shares;
    double share_val;
    double total_val;
    void set_tot(){ total_val = shares * share_val;}
public:
    void acquire(const char *co, int n, double pr);
    void buy(int num,double price);
    void sell(int num, double price);
    void update(double price);
    void show();
    stock(const char *co, int n = 0, double pr = 0.0);
};

stock::stock()
{
	std::strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

stock::stock(const char * co, int n, double pr)
{
	std::strncpy(company, co, 29);
	company[29] = '\0';

	if (n < 0) {
		std::cerr << "number of shares can't be negative;"
			<< company << " shares set to 0.\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

void stock::acquire(const char *co, int n, double pr)
{
    std:strncpy(company, co, 29);
    company[29] = '\0';
    if (n < 0)
    {
        std::cerr << "number of shares can't be negative. "
                 << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void stock::buy(int num, double price)
{
    if (num < 0)
    {
        std::cerr << "number of shares purchased can't be negative. "
                  << "transaction is aborted.\n";
    }
    else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void stock::sell(int num, double price)
{
    using std::cerr;
    if (num < 0) {
        cerr << "number of shares sold can't be negative."
             << "transaction is aborbed.\n";
    } else if (num > shares) {
        cerr << "you can't sell more than you have! "
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
         << " tobal worth: $" << total_val << endl;
}

int main(int argc, char *argv[])
{
    using std::cout;
    using std::ios_base;
    stock food = stock("world cabbage", 250, 1.25);
    stock garment("furry mason", 50, 2.5);
    stock garment1 = stock("furry mason", 50, 2.5);
    stock *pstock = new stock("electroshock games", 18, 19.0);
    stock stock1;
    stock1.acquire("nanosmart", 20, 12.50);
    cout.setf(ios_base::fixed);
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    stock1.show();
    stock1.buy(15, 18.25);
    stock1.show();
    stock1.sell(400, 20.00);
    stock1.show();
    delete pstock;
    return 0;
    //QCoreApplication a(argc, argv);

    //return a.exec();
}
