#include <iostream>

using namespace std;
int fan(int n){
	
	if(n==0)
	return 1;
	else 
	return 7+fan(n-2);}
	//fan (4) = 15
	//return 7+8 =15
	//return 8
	//return 1
int main()
{
	cout << fan(4) << endl;
	return 0;
}
