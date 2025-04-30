class NumArray {
public:
    vector<int>arr;
    vector<int>segTree;
    void buildTree(int i, int l, int r, int n){
        if(l==r){
            segTree[i]=arr[l];
            return;
        }
        int mid=l+(r-l)/2;
        buildTree(2*i+1,l,mid,n);
        buildTree(2*i+2,mid+1,r,n);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
    }
    NumArray(vector<int>& nums){
        arr=nums;
        int n=arr.size();
        segTree.resize(4*n);
        buildTree(0,0,n-1,n);
    }
    int f(int start, int end, int i, int l, int r){
        if(end<l || start>r) return 0;
        if(start<=l && end>=r) return segTree[i];
        int mid=l+(r-l)/2;
        return f(start,end,2*i+1,l,mid)+f(start,end,2*i+2,mid+1,r);
    }
    
    int sumRange(int left, int right) {
        int n=arr.size();
        return f(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */