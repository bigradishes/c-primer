#include <iostream>
#include "stocks.h"

const int STKS = 4;

int main()
{
	using std::cout;
	using std::ios_base;

	/* 类数组 */
	stock stocks[STKS] = {
		stock("nanosmart", 12, 20.0),
		stock("boffo objects", 200, 2.0),
		stock("monolithic obelisks", 130, 3.25),
		stock("fleep enterprises", 60, 6.5)
	};

	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "stock holdings:\n";

	int st;
	for (st = 0; st < STKS; st++)
		stocks[st].show();

	stock top = stocks[0];
	for (st = 1; st < STKS; st++)
		top = top.topval(stocks[st]);
	cout << "\nMost valuable holding:\n";
	top.show();

#if 0
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	/* 默认构造函数 */
	stock stock33;
	cout << "using constructors to create new objects.\n";
	/* 构造函数 */
	stock stock1("nanosmart", 12,20.0);
	stock1.show();
	/* 构造函数 */
	stock stock2 = stock("boffo objects", 2, 2.0);
	stock2.show();

	cout << "assigning stock1 to stock2: \n";
	stock2 = stock1;
	cout << "listing stock1 and stock2: \n";
	stock1.show();
	stock2.show();

	cout << "using a constructor to reset an object.\n";
	stock1 = stock("nifty foods", 10, 50.0);
	cout << "revised stock1: \n";
	stock1.show();
	cout << "done.\n";
#endif
	return 0;
}
