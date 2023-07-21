#include<bits/stdc++.h>
class myHashMap 
{   unordered_map<string,int> mp;
    public:
    myHashMap() 
    {
    }

    void insert(string key, int value) 
    {
         auto it = mp.find(key);
            if(it != mp.end())
                mp[key] = value;
            else
                mp.insert({key, value});
    }

    bool search(string key) 
    {
        if(mp.find(key)!=mp.end()){
            return true;
        }
        return false;
    }

    int get(string key) 
    {   
        auto it=mp.find(key);
        if(it!=mp.end()){
            return it->second; 
        }
        return -1;
    }

    void remove(string key) 
    {
        mp.erase(key);
    }

    int getSize() 
    {
        return mp.size();
    }

    bool isEmpty() 
    { 
        return mp.empty();
    }
};
