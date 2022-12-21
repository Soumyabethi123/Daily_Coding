class Solution {
public:

    set<int>s;

    void check(vector<vector<int>>& rooms,int i){

        for(int j=0; j<rooms[i].size(); j++){

            s.insert(rooms[i][j]);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int i=0;
        map<int,int>m;
        check(rooms,i);
        m[i]=1;

        while(true){

        int flag=0;
        for(auto it : s){

            if(m.find(it)==m.end()){

                flag=1;
                check(rooms,it);
                m[it]=1;
            }
        }

        if(flag==0){
            break;
        }

        }

        for(int i=0; i<rooms.size(); i++){

            if(m.find(i)==m.end()){

                return false;
            }
        }
        
        return true;
    }
};
