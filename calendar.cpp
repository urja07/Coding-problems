#include<iostream>
#include<stdio.h>
using namespace std;
int determineleapyear(int year);
int monthcode[]={-1,0,3,3,6,1,4,6,2,5,0,3,5};
int days_in_month[]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
  {
    " ","January","February","March","April","May","June","July","August","September","October","November","December"
  };
int yearcode(int year)
{
    if(year>=1600 && year<=1699)
        return 6;
    else if(year>=1700 && year<=1799)
        return 4;
    else if(year>=1800 && year<=1899)
        return 2;
    else if(year>=1900 && year<=1999)
        return 0;
    else
        return 6;
}
int lasttwodigit(int year)
{
    return year%100;
}
int determineleapyear(int year)
{
    return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
}
int determinedaycode(int year,int month)
{

  int d1,d2,p;
  p=lasttwodigit(year);
  d1= p+p/4+monthcode[month]+yearcode(year)+1;
  d2=d1%7;
  if (determineleapyear(year))
  {
      if(d2==0)
        d2=7;
      else
        d2=d2-1;
  }
  return d2;
}
void calendar(int year, int month, int daycode)
{
    int day;
    cout<<months[month]<<" "<<year;
    cout<<"\n\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n";
    for (day = 1; day <= 1 + daycode * 5; day++)
    {
        cout<<" ";
    }
    //Print all the dates for one month
    for (day = 1; day <= days_in_month[month]; day++)
    {
        printf("%2d",day);

        //Is day before Sat? Else start next line Sun.
        if ((day + daycode) % 7 > 0)
            cout<<"   ";
        else
            cout<<"\n ";
    }

}
int main() {
  int daycode, month, year;

   cout<<"Enter the month[1-12]: ";
   cin>>month;
   cout<<"Enter the year[1600-2099]: ";
   cin>>year;
   daycode = determinedaycode(year,month);
   calendar(year, month, daycode);
   cout<<"\n";
   return 0;
}
