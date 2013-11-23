# include <iostream>
using namespace std;
double func(double x, double y)
{
    double z;
    if (y==1)
         z=x;
    else
         z=x*func(x,y-1);
    return z;
}
int main()
{
   double x;
   double y;
   double z;

   cout<<"请输入x=";
   cin>>x;
   cout<<"请输入y=";
   cin>>y;
   z=func(x,y);
   cout<<"z="<<z<<endl;
}
