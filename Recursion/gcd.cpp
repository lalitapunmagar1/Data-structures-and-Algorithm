#include <iostream>
using namespace std;

int gcd(int n1, int n2);
int main(){
   int n1, n2;
   cout << "Enter two positive integers: ";
   cin >> n1 >> n2;
   cout << "The GCD(HCF) of " << n1 << " and " << n2 << " is: " <<gcd(n1, n2);
   return 0;
}
int gcd(int n1, int n2){
	if(n1==0||n2==0){
		return 0;	
	}else if(n1==n2){
		return n1;
	}else if(n1>n2){
		return gcd(n1-n2,n2);
	}else{
		return gcd(n1,n2-n1);
	}
}
