// This approach gives Accurate ans with two loops
// both running greedy algo, from left to right and right to left


#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkValidString(string s){
    int i = 0;
    stack<char> st;

    while(i<s.size())
    {
        if (s[i]==')')
        {
            // int top = st.top();
            if (st.empty())
            {
                return false;
            }
            else if (st.top() == '*' || st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else{
            st.push(s[i]);
        }
        i++;
    }

    i = s.size();
    while (!st.empty())
    {
        st.pop();
    }
    

    while(i>=0)
    {
        if (s[i]=='(')
        {
            if (st.empty())
            {
                return false;
            }
            else if (st.top() == '*' || st.top() == ')')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else{
            st.push(s[i]);
        }
        i--;
    }
    
    return true;
}

int main() {

    string s = "";
    cout << "Enter A String of Parenthesis" << endl;
    cin >> s;

    cout << checkValidString(s) << endl;

    return 0;
}