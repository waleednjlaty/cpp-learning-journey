#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	
	
	srand(time(0));
	
	char reb = 'y';
	
	while (reb =='y'){
		int rnd;
		int x;
		system("cls");
		rnd= rand()%10+1;
	cout<<"Enter a namber (0~10)"<<endl;
	cin>> x;
    if(rnd==x)
cout<<"pass"<<endl;
else 
cout<<"good lock try agein\n the namber is "<<rnd<<endl;

cout<<"do you play agein? (y/n) "<<endl;
cin>>reb;
}


while (reb!='n'&&reb!='y'){
cout<<"Wrong entry \nEnter agein !!!"<<endl;
cout<<"do you play agein? (y/n) "<<endl;
cin>>reb;

}
while(cin.fail()){
cin.clear();
cin.ignore(1000,'\n');
cout<<"Wrong entry \nEnter agein !!!"<<endl;
cout<<"do you play agein? (y/n) "<<endl;
cin>>reb;

}
cout<<"by waleed thank you "<<endl;
	return 0;
}
