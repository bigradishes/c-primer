#include <iostream>
#include "stocks.h"

int main()
{
	using std::cout;
	using std::endl;

	/* 默认构造函数 */
	Time planning;
	/* 构造函数 */
	Time coding(2, 40);
	Time fixing(5, 55);
	Time total;

	cout << "planning time = ";
	planning.Show();
	cout << endl;

	cout << "coding time = ";
	coding.Show();
	cout << endl;

	cout << "fixing time = ";
	fixing.Show();
	cout << endl;

	total = coding.Sum(fixing);
	cout << "coding.Sum(fixing) = ";
	total.Show();
	cout << endl;

	return 0;
}