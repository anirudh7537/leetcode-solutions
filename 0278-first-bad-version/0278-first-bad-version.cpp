// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        return fBV(1,n);
    }

    int fBV(int s, int e){
        if(s == e)
        return s;

        int mid = s+ (e-s)/2; //(s+e)/2 can be used but if s is larger than int max and e is also greater than s problem occurs so ideal solution to use to find mid is s+ (e-s)/2
        if(isBadVersion(mid))
            return fBV(s, mid);
        else return fBV(mid+1,e);   

    }
};