#include <bits/stdc++.h>
using namespace std;


class LRUCache
{
    private:
        list<pair<int,int>>l;
        unordered_map<int,list<pair<int,int>>::iterator>umap;
        int size;

    public:
        LRUCache(int cap)
    {
        size = cap;
    }
    
    int get(int key)
    {
        if(umap.find(key) == umap.end()) return -1;
        l.splice(l.begin(),l,umap[key]);
        return umap[key]->second;
    }
    
    void set(int key, int value)
    {
        if(umap.find(key) != umap.end()){
            l.splice(l.begin(),l,umap[key]);
            umap[key]->second = value;
            return;
        }
        
        if(l.size() == size){
            auto d_key = l.back().first;
            l.pop_back();
            umap.erase(d_key);
        }
            l.push_front({key,value});
            umap[key] = l.begin();
    }
};

 main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
}
