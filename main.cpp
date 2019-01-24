#include <iostream>
#include "stocks.h"

int main()
{
	using std::cout;
	using std::ios_base;
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
	return 0;
}
