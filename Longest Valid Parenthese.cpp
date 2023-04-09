#include <iostream>
using namespace std;
#include <stack>
int delimiterMatching( string S) {
    stack<char> buffer;
    int Valid = 0;
    for (int i = 0; i < S.size(); ++i) {
        if (S[i] == '(' || S[i] == '{' || S[i] == '[') {
            buffer.push(S[i]);
        }
        else if (S[i] == '/' && S[i + 1] == '*') {
            buffer.push(S[i]);
        }
        else if (S[i] == ')' || S[i] == '}' || S[i] == ']') {
            if (buffer.empty()) {
                continue;
            }
            else {
                //for comparing { and [
                if ((int) buffer.top() == (int) (S[i] - 2)) {
                    buffer.pop();
                    Valid += 2;
                }
                    //for comparing (
                else if ((int) buffer.top() == (int) (S[i] - 1)) {
                    buffer.pop();
                    Valid += 2;
                }
            }
        }
        else if (S[i] == '*' && S[i + 1] == '/') {
            if ((int) buffer.top() == (int) (S[i + 1]) && !buffer.empty()) {
                buffer.pop();
                Valid += 2;
            }

        } else continue;

    }

    return Valid;

}

int main()
{
string input = ")()())";
cout << delimiterMatching(input) << endl;
string input2 = "(()";
cout << delimiterMatching(input2) << endl;

    return 0;
}