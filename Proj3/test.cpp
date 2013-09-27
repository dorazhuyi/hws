#include <iostream>
#include "sequence2.h"

using namespace std;

using namespace main_savitch_4;

int main()
{
	sequence original;

	original.attach(1);
	for(size_t i=2; i<2*original.DEFAULT_CAPACITY;i++)
		original.attach(i);
/*
	cout << "used: " << original.size() << endl;
	cout << "is_item():" << original.is_item() << endl;

	sequence copy2(original);
	cout << "copied."<<endl;
*/
/*
	original.start();
	cout << "move to start." << endl;
	original.advance();
	cout << "move to second." << endl;
*/

	while(original.is_item())
		original.advance();
	cout << "original size: " << original.size() << endl;
	cout << "original is_item(): " << original.is_item() << endl;

	sequence copy2;
	copy2 = original;
	original.start();
	original.advance();
	original.remove_current();
	cout << copy2.size() << endl;
	cout << copy2.is_item() << endl;

	cout << "Nothing wrong." << endl;

	return 0;
}
