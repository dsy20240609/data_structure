#include<stack>
#include<iostream>

using namespace std;

void dfs(stack<int> & s, int &in, int & out, int &res, int n);
int main () {
    int n;
    cin >> n;
    stack<int> s;
    int in= n;
    int out =0;
    int res=0;
    dfs(s,in,out,res,n);
    printf("%d\n", res);
    return res;
}

void dfs(stack<int> & s, int &in,int &out, int &res, int n) {
    if(in > 0) {
      s.push(1);
      in--;
      printf("line 23 %d\n", in);
      dfs(s,in,out,res,n);
      if(!s.empty()) {
        s.pop();
        in++;
      }
    }
    if(!s.empty()) {
        s.pop();
        out++;
        dfs(s,in,out,res,n);
	s.push(1);
	out--;
    }
    if(out == n) {
        res++;
	printf("line 35 %d\n",res);
	return;
    }
 }
// this problem can be solved by recursion , also dynamic programming.
// and this problem can not passed the POJ platform due to run time error.
