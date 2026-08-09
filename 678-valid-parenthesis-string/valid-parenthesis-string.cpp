class Solution {
public:

    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> t(n+1, vector<bool>(n+1, false));

        // t[i][open] = can s[i...n-1] be valid
        // when 'open' brackets are currently open?

        t[n][0] = true;

        for(int i = n-1; i >= 0; i--) {

            for(int open = 0; open <= n; open++) {

                bool isValid = false;

                if(s[i] == '*') {

                    // '*' -> '('
                    if(open < n)
                        isValid |= t[i+1][open+1];

                    // '*' -> ')'
                    if(open > 0)
                        isValid |= t[i+1][open-1];

                    // '*' -> empty
                    isValid |= t[i+1][open];
                }

                else if(s[i] == '(') {

                    // '(' -> increase open
                    if(open < n)
                        isValid |= t[i+1][open+1];
                }

                else {
                    // ')' -> decrease open
                    if(open > 0)
                        isValid |= t[i+1][open-1];
                }

                t[i][open] = isValid;
            }
        }

        return t[0][0];
    }
};
/* Recursion methord
bool solve (int i,int open,string s,int n){
        if(i==n) return open ==0;
        bool isValid = false;

        if(s[i]=='('){
            isValid = solve(i+1,open+1,s,n);
        }
        else if(s[i]=='*'){
            isValid |= solve(i+1,open+1,s,n);
            isValid |= solve(i+1,open,s,n);
            if(open>0) isValid |= solve(i+1,open-1,s,n);
        }
        else{
            if(open>0) isValid |= solve(i+1,open-1,s,n);
        }
        return isValid;
    }

    bool checkValidString(string s) {
        
        int n = s.size();

        return solve(0,0,s,n);
    }
    */
/*
class Solution {
public:
    



    bool checkValidString(string s) {
        int n = s.size();
        char p = '0';
        int starcnt=0;
        int cnt =0;
        for(int i =0;i<n;i++){
            if(s[i]=='*'){
                starcnt++;
                if(i>0 && i<n-1 && s[i-1]=='(' && s[i+1] ==')') p='c';
                else if (i>0 && s[i-1]=='('||s[i+1]=='(') p='l';
                else if(i<n-1 && s[i+1]==')' || s[i-1]==')') p ='r';
            }
            else if(s[i]=='('){
                cnt++;
            }
            else cnt--;
        }
        if(cnt==0)return true;
        if(cnt<0){
            if(( p=='c' || p=='l') && cnt==-1){
                return true;
            }
        }
        else{
            if((p=='c'|| p=='r') && cnt ==1){
                return true;
            }
        }
        return false;
    }
};
*/