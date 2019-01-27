#ifndef STOCK1_H_
#define STOCK1_H_

typedef unsigned long Item;

class stock
{
private:
	enum {MAX = 10};
	Item items[MAX];
	int top;
public:
	/* 默认构造函数 */
	stock();
	bool isempty()const;
	bool isfull()const;
	bool push(const Item &item);
	bool pop(Item &item);
};
#endif