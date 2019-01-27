#include "stocks.h"

stock::stock()
{
	top = 0;
}

bool stock::isempty()const
{
	return top == 0;
}

bool stock::isfull()const
{
	return top == MAX;
}

bool stock::push(const Item &item)
{
	if (top < MAX) {
		items[top++] = item;
		return true;
	} else
		return false;
}

bool stock::pop(Item &item)
{
	if (top > 0) {
		item = items[--top];
		return true;
	} else
		return false;
}

