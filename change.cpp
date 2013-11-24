#include<iostream>
using namespace std;
float change(float x)
{
       float y;
       y=5*(x-32)/9;
       return y;
}
int main()
{
   float c,f;
   cout<<"请输入华氏温度f=";
   cin>>f;
   c=change(f);
   cout<<"对应的摄氏温度c="<<c<<endl;
   return 0;
}
