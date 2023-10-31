#include<bits/stdc++.h>
//#include<stack>
using namespace std;

string preTopost(string expression){
    int len = expression.size();
    reverse(expression.begin(),expression.end());
    stack <string>s;
    string ans;
    for(int i=0; i<len; i++){
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/'){
            string str1 = s.top();
            s.pop();
            string str2 = s.top();
            s.pop();
            ans = str1;
            //ans.push_back(str1);
            ans += str2;
            //ans.push_back(str2);
            ans += expression[i];
            //ans.push_back(expression[i]);
            s.push(ans); 
        }
        else{
            s.push(string(1,expression[i]));
        }
    }
    return ans;
}


int main(){
    string exp = "*-A/BC-/AKL";
    cout << preTopost(exp); //sir logic dekhlen pushback pe kuch masla aarha ig uski waja se chal nh rha ye
    // basically we will reverse the prefix string. then we will take characters 1 by 1.
    // if that character is operand we will push in stack. If the character is operator we will pop
    // the stack two times. then push them back in the answer string. repeat until whole expression is complete
    




    return 0;
}

