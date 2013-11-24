#include "iostream"
using namespace std;

struct Student
{
        char model[100];
        char number[100];
        char course[100];
        int grade;
}students[100];

int modelCount = 0;

void list();
void enterStucourse();
void outStucourse();
void enterStugrade(); 
void input(struct Student &student);
int find(char* model);
int fd(char* number);

int main()
{
        int action;
        do{
                cout<<"-----------�˵�-----------"<<endl;
                cout<<"1)�鿴ѧ������"<<endl;
                cout<<"2)ѡ��"<<endl;
                cout<<"3)��ѡ"<<endl;
                cout<<"4)¼���ɼ�"<<endl;
                cout<<"5)�˳�����"<<endl;

                cin>>action;
                switch(action){
                case 1:
                        list();
                        break;
                case 2:
                        enterStucourse();
                        break;
                case 3:
                        outStucourse();
                        break;
                case 4:
                        enterStugrade();
                        break;
                case 5:
                        return 0;
                default:
                        cout<<"�������˴����Ĳ˵��������ѡ����";
                }
        }while(action!=5);
}

void list()
{
        cout<<"-------ѧ������-------"<<endl;
        cout<<"����\t"<<"ѧ��\t"<<"��ѡ�γ�\t"<<"�ɼ�"<<endl;
        if(modelCount>0)
        {
                for(int i=0;i<modelCount;i++)
                {
                        cout <<endl;
                        cout <<students[i].model<<"\t"<<students[i].number<<"\t"<<students[i].course<<"\t"<<students[i].grade<<endl;
                        cout <<endl;
                }
        }
        else
        {
                cout <<endl;
                cout << "ѧ������Ϊ�գ�"<<endl;
                cout <<endl;
        }
        cout<<"-------ѧ������-------"<<endl;
}
void enterStucourse()
{
        struct Student student;
        input(student);

        int i = find(student.model);
        if(i == modelCount)
        {
                strcpy(students[i].model  ,student.model);
                strcpy(students[i].number ,student.number);
                strcpy(students[i].course ,student.course);
                modelCount++;
        }
        else
        {
                strcpy(students[i].course ,student.course);
        }
}

void outStucourse(){
        struct Student student;
        input(student);

        int i = find(student.model);
        if(i == modelCount){
                cout<<"�γ̴���"<<endl;
        }else
        { 
                strcpy(students[i].course ,"��");
        }
}

void enterStugrade(){
        struct Student student;
        int grade;
        char a='a';
        do{
                cout<<"������ѧ�ţ�"<<endl;
                cin>>student.number;
                int i=fd(student.number);
                //cout<<i<<endl;
                if( i==modelCount )
                {
                        cout<<"ѧ�Ŵ�����"<<endl;
                        break;
                }
                cout << "�������ɼ�:"<<endl;
                cin>>grade;
                if(grade<0||grade>100)
                {
                        cout << "�ɼ�������"<<endl; 
                        break;
                }
                students[i].grade=grade;

                cout<<"�Ƿ����������ɼ�?(y/n)"<<endl;
                cin>>a;
        }while(a == 'y');
}

void input(struct Student &student)
{
        
        cout<<"������";
        cin>>student.model;

        cout<<"ѧ�ţ�";
        cin >>student.number;

        cout<<"�γ̣�";
        cin >>student.course;
}

int find(char* model){
        int i;
        for(i=0;i<modelCount;i++){
                if(strcmp(students[i].model,model) == 0){
                        break;
                }
        }
        return i;
}
int fd(char* number){
        int i;
        for(i=0;i<modelCount;i++){
                if( strcmp(students[i].number,number)==0){
                        break;
                }
        }
        return i;
}
