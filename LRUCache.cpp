#include "LRUCache.h"
using namespace std;

/*

VER README PARA VER EXPLICACION

*/

int main() {

    LRUCache lruc(3, LRU);
    //LRUCache lruc(3, FIFO);
    lruc.insertKeyValuePair('b', 2);
    lruc.insertKeyValuePair('a', 1);
    lruc.insertKeyValuePair('c', 3);

	//lruc.print();
	//lruc.print_val();

    pair <char, int> test = lruc.getMostRecentKey();
    cout << "Test 1 = " << endl;
    cout << test.second << endl; // 3

    test = lruc.getValueFromKey('a');
	//lruc.print();
	//lruc.print_val();

    cout << "Test 2 = " << endl;
    cout << test.second << endl; // 1

    lruc.insertKeyValuePair('d', 4);

    //lruc.print();
	//lruc.print_val();

    test = lruc.getValueFromKey('b');

    cout << "Test 3 = " << endl;
    cout << test.second << endl; // 0

	//lruc.print();
	//lruc.print_val();

    lruc.insertKeyValuePair('a', 5);

    test = lruc.getValueFromKey('a');
    cout << "Test 4 = " << endl;
    cout << test.second << endl; // 5

    //lruc.print();
	//lruc.print_val();
    
    return 0;
};