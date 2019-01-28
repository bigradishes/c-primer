#ifndef STOCK1_H_
#define STOCK1_H_

#include <string>

class stock
{
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	void set_tot() {total_val = shares * share_val; }
public:
	/* 默认构造函数 */
	stock();
	/* 构造函数 */
	stock(const char *co, int n = 0, double pr = 0.0);
	/* 析构函数 */
	~stock();
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	void show();
	const stock &topval(const stock &s) const;
};
#endif
