class NumArray {
public:
    vector<int>bit;
    vector<int>nums;
    int n;
    NumArray(vector<int>& arr) {
        nums=arr;
        n=arr.size();
        bit.resize(n+1,0);
        for(int i=0;i<n;i++){
            add(i+1,arr[i]);
        }
    }
    void add(int idx,int val){
        while(idx<=n){
            bit[idx]+=val;
            idx+=(idx &-idx);
        }
    }
    int prefixsum(int idx){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-=(idx & -idx);
        }
        return sum;
    }
    int sumRange(int left, int right) {
        return prefixsum(right+1) - prefixsum(left);   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */