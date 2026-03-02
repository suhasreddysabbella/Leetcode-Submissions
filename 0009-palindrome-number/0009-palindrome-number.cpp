class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        vector<int> z;
        while (x>0){
            z.push_back(x%10);
            x=x/10;
        }
        int j=z.size()-1;
        long long w=0;
        for (int i=0;i<z.size();i++){
            w=w+z[i]*(pow(10,j));
            j--;
        }
        if (w==y){
            return true;
        }
        else{
            return false;
        }
    }
};