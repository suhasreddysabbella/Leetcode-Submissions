class NumArray {
public:
    vector<int> segtree;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        segtree.resize(4*n);
        build(0,0,n-1,nums);
    }
    void build(int idx,int low,int high,vector<int>& nums){
        if(low==high){
            segtree[idx]=nums[low];
            return;
        }
        int mid=(low+high)/2;
        build(2*idx+1,low,mid,nums);
        build(2*idx+2,mid+1,high,nums);
        segtree[idx]=segtree[2*idx+1]+segtree[2*idx+2];
    }
    void updatehelper(int idx,int low,int high,int i,int val){
        if(low==high){
            segtree[idx]=val;
            return;
        }
        int mid=(low+high)/2;
        if(i<=mid){
            updatehelper(2*idx+1,low,mid,i,val);
        }
        else{
            updatehelper(2*idx+2,mid+1,high,i,val);
        }
        segtree[idx]=segtree[2*idx+1]+segtree[2*idx+2];
    }
    void update(int index, int val) {
        updatehelper(0,0,n-1,index,val);
    }
    int query(int idx,int low,int high,int l,int r){
        if(high<l || low>r){
            return 0;
        }
        if(low>=l && high <=r){
            return segtree[idx];
        }
        int mid=(low+high)/2;
        int left=query(2*idx+1,low,mid,l,r);
        int right=query(2*idx+2,mid+1,high,l,r);
        return left+right;
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */