#include<iostream>
using namespace std;
class Date
{
    private:
    int year,month,day;
    public:
    Date(int y,int m,int d);
    int isleapyear(void);
    int whichday(void);
    void printday(void);
};
Date::Date(int y,int m,int d)
{
	year=y;
    month=m;
    day=d;
}
int Date:: isleapyear(void)
{
    return ((year%4==0 && year%100!=0) || year%400==0);
}
int Date:: whichday(void)
{
    int m[2][13]={{0,31,28,31,30,31,30,31,31,30,31,30,31},{1,31,29,31,30,31,30,31,31,30,31,30,31}};
    int i=month-1,res=0;
    int flag=isleapyear();
    while(i!=0)
    {
        res+=m[flag][i];
        i--;
    }
    res+=day;
    return res;
}
void Date::printday(void){
  int count;
  Date date(year,month,day);
  count=date.whichday();
  cout<<count;
}
int main(){
  int year,month,day;
  cin>>year>>month>>day;
  Date date(year,month,day);
  date.printday();
  return 0;
}