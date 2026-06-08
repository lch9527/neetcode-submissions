class KthLargest {
public:
    std::vector<int> Narray;
    int kth;

    KthLargest(int k, vector<int>& nums) {
        kth = k;
        Narray = nums;
    }
    
    int add(int val) {
        Narray.push_back(val);
        std::sort(Narray.begin(),Narray.end(),std::greater<int>());
        return Narray[kth-1]; 
    }
};
