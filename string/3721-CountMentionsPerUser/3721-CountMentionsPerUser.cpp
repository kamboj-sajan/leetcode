// Last updated: 19/08/2026, 15:26:05
// class Solution {
// public:
//     using info=tuple<int, char, string>; //(timestamp, kind, users)
//     static void print(auto& X){
//         for(auto& x: X){
//             auto& [t, k, s]=x;
//             cout<<t<<"|"<<k<<"|"<<s<<endl;
//         }
//     }
//     static void data_proc(vector<string>& event, vector<info>& X){
//         int t=stoi(event[1]);
//         char k=event[0]=="MESSAGE"?'M':'A';
//         if (k=='A') X.emplace_back(t+60, '1', event[2]);
//         X.emplace_back(t, k, event[2]);
//     }
//     static vector<int> countMentions(int n, vector<vector<string>>& events) {
//         vector<int> freq(n, 0);
//         vector<info> X;
//         X.reserve(n*3);
//         for (auto& e: events)
//             data_proc(e, X);
//         sort(X.begin(), X.end());
//     //    print(X);
//         bitset<100> online;
//         online.set();// all bits set 1
//     //    cout<<online<<endl;
//         for(auto& x: X){
//             auto& [t, k, s]=x;
//             if (k!='M'){
//                 int user=stoi(s);
//                 online.flip(user);
//             }
//             else{
//                 if (s=="ALL") 
//                     for_each(freq.begin(), freq.end(), [](int& x){
//                         return ++x;});
//                 else if(s=="HERE"){
//         //            cout<<online<<endl;
//                     for(int i=0; i<n; i++)
//                         freq[i]+=online[i];
//                 }
//                 else{
//                     stringstream ss(s);
//                     char c;
//                     int user;
//                     while(ss>>c>>c>>user)
//                         freq[user]++;
//                 }
//             }
//         }
//         return freq;
//     }
// };

class Solution {
public:
    int stoi(string s){
        int x = 0;
        for(auto c : s){
            x = x * 10 + (c - '0');
        }
        return x;
    }
    int extract_id(string s){
        return stoi(s.substr(2));
    }
    const int OFFLINE = 0;
    const int MESSAGE = 1;
    struct EVENT{
        int type;
        int time;
        bool flag_all;
        bool flag_here;
        vector<int> ids;
        EVENT(){
            flag_all  = false;
            flag_here = false;
        }
    };
    
    vector<EVENT> convert(vector<vector<string> > events){
        vector<EVENT> EVENTS;
        for(auto event : events){
            EVENT new_event;
            string type   = event[0];
            int timestamp = stoi(event[1]);
            new_event.time = timestamp;
            if(type == "OFFLINE"){
                new_event.type = OFFLINE;
                new_event.ids  = {stoi(event[2])};
                EVENTS.push_back(new_event);
                continue;
            }
            new_event.type = MESSAGE;

            if(event[2] == "ALL"){
                new_event.flag_all  = true;
                EVENTS.push_back(new_event);
                continue;
            }
            if(event[2] == "HERE"){
                new_event.flag_here = true;
                EVENTS.push_back(new_event);
                continue;
            }
            vector<string> stringids = {""};
            for(auto c : event[2]){
                if(c == ' '){
                    stringids.push_back("");
                    continue;
                }
                stringids.back() += c;
            }
            vector<int> ids;
            for(auto stringid : stringids){
                ids.push_back(extract_id(stringid));
            }
            new_event.ids = ids;
            EVENTS.push_back(new_event);
        }
        return EVENTS;
    }
    
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = numberOfUsers;
        vector<int> mentions(n, 0);
        
        vector<EVENT> EVENTS = convert(events);
        int all_count  = 0;
        int here_count = 0;
        unordered_map<int, int> here_at;
        
        for(auto event : EVENTS){
            if(event.type == MESSAGE){
                if(event.flag_all){
                    all_count += 1;
                    continue;
                }
                if(!event.flag_here){
                    for(auto id : event.ids){
                        mentions[id] += 1;
                    }
                    continue;
                }
                here_count += 1;
                here_at[event.time] += 1;
            }
        }
        for(int i = 0; i < n; i ++){
            mentions[i] += all_count;
            mentions[i] += here_count;
        }
        for(auto event : EVENTS){
            if(event.type == MESSAGE) continue;
            int id = event.ids[0];
            for(int i = event.time; i < event.time + 60; i += 1){
                mentions[id] -= here_at[i];
            }
        }
        return mentions;
    }
};