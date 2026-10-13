class Solution {
public:
    int lengthOfLastWord(string s) {
     int len = 0;
      int word = s.size()-1;

       while(word>=0 && s[word] == ' '){
        word--; }
       while(word>=0 && s[word] != ' '){
        len++;
        word--;}
    return len;    
    }
};