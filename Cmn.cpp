# include <iostream>
using namespace std;
int fac(int num)
{
    int sum;
    if(num==1) sum=1;
    else sum=num*fac(num-1);
    return sum;
}
int main()
{
   int n;
   int m;
   double Cnm;
   cout<<"请输入n=";
   cin>>n;
   cout<<"请输入m=";
   cin>>m;
   Cnm=fac(n) /(fac(m)*fac(
n-m));
   cout<<"Cnm="<<Cnm<<endl;
   return 0;
}
