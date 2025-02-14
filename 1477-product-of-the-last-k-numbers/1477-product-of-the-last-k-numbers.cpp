class ProductOfNumbers {
private:
    vector<int> prefix_prod;
public:
    ProductOfNumbers() {

    }
    
    void add(int num) {
        if(prefix_prod.empty()){
            prefix_prod.push_back(num);
        }
        else{
            if(prefix_prod.back() == 0){
                prefix_prod.push_back(num);
            }
            else{
                prefix_prod.push_back(num * prefix_prod.back());
            }
        }
        
        if(num == 0){
            prefix_prod.clear();
        }
    }
    
    int getProduct(int k) {
        int n = prefix_prod.size();

        if (k > n) return 0;
        if (n == k) return prefix_prod[n-1];

        int elemToDiv = prefix_prod[n-k-1];
        return (elemToDiv != 0) ? (prefix_prod[n-1] / elemToDiv) : prefix_prod[n-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */