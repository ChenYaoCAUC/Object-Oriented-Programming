#include <iostream>
#include<stdio.h>
#include <string>
using namespace std ;

class Person {
protected:
     string name;
     int age;
public:
     Person();	  
     Person (string p_name, int p_age){name=p_name;age=p_age;};
     void display () {cout<<name<<" :"<<age<<endl;}
};

class student:public Person
{
	int ID;//学号
	float cpp_score;//cpp上机成绩
	float cpp_count;//cpp上机考勤
	float cpp_grade;//cpp总评成绩
public:
	student();
	student(string p_name,int p_ID,int p_age,float score,float count):Person(p_name,p_age)
	{
		ID=p_ID;cpp_score=score;cpp_count=count;
	}
	void print(){
		cpp_grade = cpp_score * 0.9 + cpp_count * 2;
		cout<<ID<<" "<<name<<" ";
		printf("%.1f\n",cpp_grade);
	}
};
int main()
{
	string name;
	int age,ID;
	float score,c;
	cin>>name>>ID>>age>>score>>c;
	while(name!="0"){

		student s(name,ID,age,score,c); 
		s.print();
		cin>>name>>ID>>age>>score>>c;	
	}
	return 0;
} 