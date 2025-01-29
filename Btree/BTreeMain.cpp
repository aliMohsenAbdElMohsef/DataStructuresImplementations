#include <iostream>
#include "BtreeImplementation.cpp"
using namespace std;

int main()
{
    // Construct a BTree of order 3, which stores int data
    BTree<int, 3> t1;
    t1.Insert(1);
    t1.Insert(5);
    t1.Insert(0);
    t1.Insert(4);
    t1.Insert(3);
    t1.Insert(2);
    t1.Print(); // Expected Output:
    /*
    1,4
     0
     2,3
     5
    */

    BTree<char, 5> t; // Construct a BTree of order 5, which stores char data
    t.Insert('G');
    t.Insert('I');
    t.Insert('B');
    t.Insert('J');
    t.Insert('C');
    t.Insert('A');
    t.Insert('K');
    t.Insert('E');
    t.Insert('D');
    t.Insert('S');
    t.Insert('T');
    t.Insert('R');
    t.Insert('L');
    t.Insert('F');
    t.Insert('H');
    t.Insert('M');
    t.Insert('N');
    t.Insert('P');
    t.Insert('Q');
    t.Print(); // Expected Output:
    /*
    K
     C,G
      A,B
      D,E,F
      H,I,J
     N,R
      L,M
      P,Q
      S,T
    */
    // test from midterms and finals on BTree
    // BTree<int, 5> t2; // Construct a BTree of order 5, which stores char data
    // t2.Insert(8);
    // t2.Insert(3);
    // t2.Insert(2);
    // t2.Insert(1);
    // t2.Insert(7);
    // t2.Insert(9);
    // t2.Insert(5);
    // t2.Insert(6);
    // t2.Insert(4);
    // t2.Insert(0);
    // t2.Print();

    // BTree<int, 5> t2; // Construct a BTree of order 5, which stores char data
    // t2.Insert(1);
    // t2.Insert(6);
    // t2.Insert(7);
    // t2.Insert(8);
    // t2.Insert(2);
    // t2.Insert(0);
    // t2.Insert(4);
    // t2.Insert(3);
    // t2.Insert(5);
    // t2.Insert(9);
    // t2.Print();
    return 0;
}
