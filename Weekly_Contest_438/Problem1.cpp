
// 3461. Check If Digits Are Equal in String After Operations I
// Leetcode : https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/
class Solution {
    public:
        bool isPalindrome(string s,int n){
            for(int i=0;i<n/2;i++){
                if(s[i]!=s[n-i-1]){
                    return false;
                }
            }
            return true;
        }
        bool hasSameDigits(string s) {
            int n = s.length();
            if(isPalindrome(s,n)){
                return true;
            }
            
            while(n!=2){
                for(int i=0;i<n-1;i++){
                   int digit = (s[i]-'0' + s[i+1]-'0')%10;
                    s[i] = char(digit+'0');
                }
                n--;
                if(isPalindrome(s,n)){
                     return true;  
                }
            }
            return false;
        }
    };