#include<iostream>
using namespace std;

/* 请在这里填写答案 */
class Student{
  int no,score;
  public:
  static int count;
  Student(int n,int s):no(n),score(s){
    count ++;
  }
  Student(const Student &d){
    no = d.no+1;
    score = d.score;
    count ++;
  }
  int display(){
    cout<<no<<" ";
    if(score==1){
      cout<<"Pass"<<endl;
    }
    else{
      cout<<"Fail"<<endl;
    }
     
  }
  ~Student(){
    count--;
  }
};
int Student::count=0;


int main(){
    const int size=100;
    int i, N, no, score;
    Student *st[size];
    cin>>N;
    for(i=0; i<N; i++){
        cin>>no;
        if(no>0){
            cin>>score;
            st[i]=new Student(no, score);
        }
        else
            st[i]=new Student(*st[i-1]);
    }
    cout<<Student::count<<" Students"<<endl;
    for(i=0;i<N;i++) st[i]->display();
    for(i=0;i<N;i++) delete st[i];
    return 0;
}