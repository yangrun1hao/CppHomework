#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct Student{
      char id[20];
      int score;
        }
Students[1000];
int count=0;
void setScore(int &count);
void addStudent();
void deleteStudent();
void quitCourse();
int find(char * id);
void selectCourse();
void list();
void input(struct Student &student);
void setAll();
int main(){
    int action;
    do{
       cout<<"------------输入数字选择所需操作-------------"<<endl;
       cout<<"1> 查看学生名单"<<endl;
       cout<<"2> 选课"<<endl;
       cout<<"3> 退选"<<endl;
       cout<<"4> 录入成绩 "<<endl;
       cout<<"5> 退出系统  "<<endl;
       cin>>action;
       if(cin.fail()){
                       cin.clear();
                       cin.sync();
                     }
        switch (action)
               {
                    case 1:
                          list();
                          break;
                    case 2:
                        selectCourse();
                        break;
                    case 3:
                        quitCourse();
                        break;
                    case 4:       
                        setScore(count);
                        break;
                    case 5:  
                        return 0;
                        default:
                        cout<<"您的输入有误，请输入正确的数字"<<endl;
                }
        }
while(1);
}
void list(){
        cout<<"--------------学生信息------------------"<<endl;
        cout<<"\t学号\t\t\t成绩\t"<<endl;
        for(int i=0;i<count;i++)
            cout<<Students[i].id<<"\t"<<Students[i].score<<endl;
            cout<<"--------------学生信息------------------\n"<<endl;
}
void selectCourse(){
        int action;
        do{
                cout<<"--------------------选课系统-------------------"<<endl;
                cout<<"------------输入数字选择所需操作-------------"<<endl;
                cout<<"1>添加学号  "<<endl;
                cout<<"2>退出选课系统  "<<endl; 
                cin>>action;
                if(cin.fail())
                     {
                         cin.clear();
                         cin.sync();
                         cout<<"您的输入有误，请输入正确的数字"<<endl;
                     }
                switch(action)
               {
                case 1:
                        addStudent();
                        break;
                case 2:
                        break;
                default:
                        cout<<"您的输入有误，请重新选择"<<endl;
                }
        }
while (action!=2);
}
void addStudent()
{
        struct Student student;
        input(student);
        int i=find(student.id);
        if(i==count)
        {
            strcpy(Students[count].id,student.id);
            count++;
        }
        else
        {
            cout<<"该生已存在,请重新输入"<<endl;
        }
}
void input(struct Student &student)
{
    cout<<"请输入学生学号："<<endl;
    cin>>student.id;
}
int find(char *id)
{
        int i;
        for(i=0;i<count;i++)
                if(strcmp(Students[i].id,id)==0)
                        break;
       return i;
}
void setScore(int &count)
{
        int action;
        char id[20];
        int score=0;
        do
        {
            cout<<"-----------------成绩录入系统-----------------"<<endl;
            cout<<"------------输入数字选择所需操作-------------"<<endl；
            cout<<"1>成绩录入                          "<<endl;
            cout<<"2>退出录入系统                    "<<endl;
            cin>>action;
                 if(cin.fail())
                     {
                         cin.clear();
                         cin.sync();
                     }
                switch(action)
                {
                  case 1:
                        setAll();
                        break;
                  case 2:
                        break;
                  default:
                        cout<<"您的输入有误，请重新选择"<<endl;
                }
        }
while(action!=2);
}
void setAll()
{
    char c;
    struct Student student;
    input(student)；
    int k=find(student.id);
    if(k==count)
            cout<<"您输入的学号不存在，请重新输入"<<endl;
    else
    {
         for(k=0;k<count;k++)
     {
        int flag=0;
        cout<<"请输入学号为："<<Students[k].id<<"的学生的分数："<<endl;
        cin>>student.score;
        Students[k].score=student.score;
             if(k==count/2-1)
            {
               do
                 {
                    cout<<"已录入一半学生，是否继续录入？(Y/N)"<<endl;
                    cin>>c;
                    if(cin.fail())
                     {
                        cin.clear();
                        cin.sync();
                        cout<<"请输入Y/N"<<endl;
                    }
                    if(c=='Y')
                    {
                        ++k;
                        if(k==count)
                        { 
                             cout<<"所有学生成绩录入完毕！"<<endl;
                             flag=1;
                             break;
                        }
                        cout<<"请输入学号为："<<Students[k].id<<"的学生的分数："<<endl;
                        cin>>student.score;
                        Students[k].score=student.score;
                    }
                    if(c=='N')
                    {
                        flag=1;
                        cout<<"退出录入成功！"<<endl;
                        break;
                    }
            }
while(c!='N');
             if(flag=1||k==count)
                  break;
        }
    }
    }
}
void quitCourse()
{
        int action;
        char id[20];
        int i;
       do
{
                cout<<"--------------------退课系统-------------------"<<endl;
                cout<<"------------输入数字选择所需操作-------------"<<endl;
                cout<<"1>删除学号                        "<<endl;
                cout<<"2>退出选课系统                     "<<endl;
                cin>>action;
                 if(cin.fail())
                     {
                         cin.clear();
                         cin.sync();
                     }
                switch(action)
                {
                case 1:
                        deleteStudent();
                        break;
                case 2:
                        break;
                default:
                        cout<<"您的输入有误，请重新选择"<<endl;
                }
        }
while (action!=2);
}
void deleteStudent()
{
    struct Student student;
    input(student);
    int j=find(student.id);
    if(j==count)
        cout<<"您输入的学号不存在，请重新输入"<<endl;
    else
    {
        for(int i=j;i<count;i++)
        {
            Students[i]=Students[i+1];
        }
        count--;
        cout<<"退课成功！"<<endl;
    }
}
