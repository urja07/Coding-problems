#include<iostream>
using namespace std;
char rotatestring(string ,char ,int );
int main()
{
	string s,t;
	int q,m,j,k,n,i;
	char d;
	cin>>s;
	cin>>q;
	n=s.length();
	k=0;
	for(j=0;j<q;j++)
	{   cin>>d;
		cin>>m;
		t[k]=rotatestring(s,d,m);
		k++;
    }  
    for(k=0;k<n;i++)
    cout<<t[i];
}
char rotatestring(string s,char d,int m)
{ int n,i;
  char p;
  n=s.length();
  string a;
	if(d=='R'|| d== 'r')
	{
		for(i=0;i<n;i++)
		{
			a[(i+m)%n]=s[i];
		}
	}
	if(d=='L'|| d=='l')
	{
		for(i=0;i<n;i++)
		{
	     	a[i]=s[(i+m)%n]	;
		}
	}
	for(i=0;i<n;i++)
	p=a[0];
	return p;
	
}
