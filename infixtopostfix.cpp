#include<iostream>
#include<stack>
using namespace std;
int prec(char c)
{
	if(c == '^')
	return 2;
	else if(c == '*' || c == '/' || c == '%')
	return 1;
	else if(c == '+' || c == '-')
	return 0;
	else
	return -1;
}

void infixToPostfix(string s)
{
	stack<char> st;
	st.push('X');
	int len=s.length();
	string new_string;
	for(int i=0;i<len;i++)
	{

		if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
		{
		    new_string+=s[i];
        }

		else if(s[i] == '(')
        {
            st.push('(');
        }
		else if(s[i] == ')')
		{
			while(st.top() != 'X' && st.top() != '(')
			{
				char c = st.top();
				st.pop();
                new_string += c;
			}
			if(st.top() == '(')
			{
				char c = st.top();
				st.pop();
			}
		}

		else{
			while(st.top() != 'X' && prec(s[i])<= prec(st.top()))
			{
				char c = st.top();
				st.pop();
				new_string+=c;
			}
			st.push(s[i]);
		}

	}

	while(st.top() != 'X')
	{
		char c = st.top();
		st.pop();
		new_string += c;
	}

	cout<<new_string<<endl;

}

int main()
{
	string exp;
	cout<<"Enter String input = ";
	getline(cin,exp);
	infixToPostfix(exp);
	return 0;
}

