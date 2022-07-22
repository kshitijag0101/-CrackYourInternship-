class NestedIterator {
    vector<int> res;
    int i=0;
public:
    void flatten(vector<NestedInteger> &nestedList){
        for(int i=0;i<nestedList.size();i++){
            if(nestedList[i].isInteger()){
                res.push_back(nestedList[i].getInteger());
            }
            else{
                flatten(nestedList[i].getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    int next() {
        int ans=res.at(i);
        i++;
        return ans;
    }
    
    bool hasNext() {
        if(i<res.size()){
            return true;
        }
        else{
            return false;
        }
    }
};