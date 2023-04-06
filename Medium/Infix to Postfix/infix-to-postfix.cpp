//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char opr){
        switch (opr){
            case '+' : return 1;
            case '-' : return 1;
            case '*' : return 2;
            case '/' : return 2;
            case '^' : return 3;
            default : return -1;
        }
    }
    bool isOperator(char c){
        return c=='+' || c=='-' || c=='^' || c== '*' || c=='/'; 
    }
    string infixToPostfix(string infix) {
        // Your code here
        string postfix= "";
        stack<char> stk;
        for(int i=0;i<infix.length();i++){
            if( isalnum(infix[i])){
                postfix.push_back(infix[i]);
            }
            else if( infix[i]=='(')
                stk.push('(');
            else if(infix[i]==')'){
                while(stk.top()!='(')
                {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            else if(isOperator(infix[i])){
                while(!stk.empty() && precedence(infix[i])<= precedence(stk.top())){
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.push(infix[i]);
            }
        }
        while(!stk.empty()){
            postfix.push_back(stk.top());
            stk.pop();
        }
        return postfix;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends