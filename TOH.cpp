#include <iostream>
#include<math.h>
using namespace std;

void TOH(int n, char sour, char temp, char des){
	int steps=0;
    if (n == 1) {
        cout << "Move Disk " << n << " from " << sour << " to " << des << endl;
        return;
    }

    TOH(n - 1, sour, des, temp);
    cout << "Move Disk " << n << " from " << sour << " to " << des << endl;
    TOH(n - 1, temp, sour, des);
}

int main()
{
    int n;

    cout << "Enter no. of disks:";
    cin >> n;
    int steps=pow(2,n)-1;
    cout<< "for " <<n<< " disks we have " <<steps<< " steps. " <<endl;
    TOH(n, 'A', 'B', 'C');

    return 0;
}
