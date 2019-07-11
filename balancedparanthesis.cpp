#include <bits/stdc++.h>
using namespace std;
// Complete the isBalanced function below.
string isBalanced(string s) {
    stack <char> p;
    string n = "NO", y = "YES";
    int i;
    char x;
    for(i=0;i<s.length();i++)
    {
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
        {
            p.push(s[i]);
            continue;
        }
        if(p.empty())
        return n;
        switch(s[i])
        {
            case ')': x=p.top();
                      p.pop();
                      if(x=='[' || x=='{')
                      return n; 
                      break;
            case ']': x=p.top();
                      p.pop();
                      if(x=='(' || x=='{')
                      return n;
                      break;
            case '}': x=p.top();
                      p.pop();
                      if(x=='(' || x=='[')
                      return n;
                      break;
        }
    }

return y;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

