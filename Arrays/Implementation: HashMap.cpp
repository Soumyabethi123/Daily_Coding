#include<bits/stdc++.h>

class myHashMap 

{

    public:
        vector<string>keys;
        vector<int>val;


    void insert(string key, int value) 
    {
        // Write your code here.
        for(int i=0; i<keys.size(); i++){

            if(keys[i]==key)
            {
                val[i]=value;
                return;
            }
        }

        keys.push_back(key);
        val.push_back(value);
    }

    bool search(string key) 
    {
        // Write your code here.

        for(int i=0; i<keys.size(); i++){

            if(key==keys[i]){

                return true;
            }
        }

        return false;
    }

    int get(string key) 
    {
        // Write your code here.
        for(int i=0; i<keys.size(); i++){

            if(key==keys[i]){

                return val[i];
            }
        }

        return -1;
    }

    void remove(string key) 
    {
        // Write your code here.
        int i=0;
        while(i<keys.size()){

            if(keys[i]==key){

                keys.erase(keys.begin()+i);
                val.erase(val.begin()+i);
            }

            i++;
        }
    }

    int getSize() 
    {
        // Write your code here.
        return keys.size();
    }

    bool isEmpty() 
    { 
        // Write your code here.
        if(keys.size()==0){

            return true;
        }

        return false;
    }
};
