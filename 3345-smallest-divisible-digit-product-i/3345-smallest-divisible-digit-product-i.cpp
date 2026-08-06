class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int prod = 1;
            int temp = n;
            while(temp>0){
                int lastdigit = temp%10;
                prod *= lastdigit;
                temp = temp/10;

            }
            if(prod%t == 0){
                return n;}
                n++;
            
        }
        return true;
    }
};