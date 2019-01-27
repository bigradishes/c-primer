#include <iostream>
#include "stocks.h"

int main()
{
	using namespace std;
	stock st;
	char ch;
	unsigned long po;
	cout << "please enter a to add a purchase order, \n"
		<< "p to process a po, or q to quit.\n";

	/* 接受键盘输入 */
	while (cin >> ch && toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!isalpha(ch)) {
			cout << '\a';
			continue;
		}
		/* 添加或者删除 */
		switch (ch) {
		case 'A':
		case 'a':
			cout << "enter a po number to add: ";
			cin >> po;
			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else {
				st.pop(po);
				cout << "PO #" << po << " popped\n";
			}
			break;
		}
		cout << "please enter a to add a purchase order, \n"
		<< "p to process a PO, or Q to quit.\n";
	}
	cout << "bye\n";
	return 0;
}

