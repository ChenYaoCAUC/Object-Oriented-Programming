#include<iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */


class Student{
  public:
  string num,name;
  public:
   static float max;
  Student(string numm,string namee):num(numm),name(namee){}
  virtual void display()=0;
};
float Student::max=0;
class GroupA:public Student{
  int s1,s2;
  public:
  GroupA(string num,string name,int ss1,int ss2):Student(num,name),s1(ss1),s2(ss2){
    if((s1+s2)/2>=Student::max){
      Student::max=(s1+s2)/2;
    }
  }
  void display(){
    if((s1+s2)/2==Student::max){
     cout<<num<<" "<<name<<endl; 
    }
  }
};
class GroupB:public Student{
  int s1,s2;
  string gs;
  public:
  GroupB(string num,string name,int ss1,int ss2,string ggs):Student(num,name),s1(ss1),s2(ss2){
  	gs=ggs;
    if((s1+s2)/2>=max){
      max=(s1+s2)/2;
    }
}
    void display(){
      if(((s1+s2)/2==Student::max)||((s1+s2)/2>=0.7*max&&gs="A"){
        cout<<num<<" "<<name<<endl;
      }
    }
};
class GroupC:public Student{
  int s1,s2,s3,s4,s5;
  public:
  GroupC(string num,string name,int ss1,int ss2,int ss3,int ss4,int ss5):Student(num,name),s1(ss1),s2(ss2),s3(ss3),s4(ss4),s5(ss5){
    
  }
  void display(){
    if((s1+s2+s3+s4+s5)/5>=0.9*max){
      cout<<num<<" "<<name<<endl;
    }
  }
};
int main()
{
    const int Size=50;
    string num, name;
    int i,ty,s1,s2,s3,s4,s5;
    char gs;
    Student *pS[Size];
    int count=0;
    for(i=0;i<Size;i++){
        cin>>ty;
        if(ty==0) break;
        cin>>num>>name>>s1>>s2;
        switch(ty){
             case 1:pS[count++]=new GroupA(num, name, s1, s2); break;
             case 2:cin>>gs; pS[count++]=new GroupB(num, name, s1,s2, gs); break;
             case 3:cin>>s3>>s4>>s5; pS[count++]=new GroupC(num, name, s1,s2,s3,s4,s5); break;
        }			
    }
    for(i=0;i<count;i++) {
        pS[i]->display();
        delete pS[i];
    }
    return 0;
}
