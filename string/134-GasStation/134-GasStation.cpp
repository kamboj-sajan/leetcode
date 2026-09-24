// Last updated: 25/09/2026, 01:24:06
// // class Solution {
// // public:
// //     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
// //        int n = gas.size();
// //        gas.insert(gas.end(),gas.begin(),gas.end());
// //        cost.insert(cost.end(),cost.begin(),cost.end());
// //        for(int i=0; i<n; i++){
// //           if(gas[i] < cost[i])continue;
// //           else{
// //              int g = gas[i];
// //              bool a = true;
// //              for(int j=i; j<i+n; j++){
// //                 if(g >= cost[j]){
// //                     g -= cost[j];
// //                     g += gas[j+1];
// //                 }else{
// //                     a = false;
// //                     break;
// //                 }
// //              }
// //              if(a == true)return i;
// //           }
// //        }
// //        return -1;
// //     }
// // };

// // class Solution {
// // public:
// //     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
// //         int n = gas.size();
// //         for(int i = 0; i < n; i++) {
// //             if(gas[i] < cost[i])
// //                 continue;
// //             int g = gas[i];
// //             bool possible = true;
// //             for(int j = 0; j < n; j++) {
// //                 int curr = (i + j) % n;
// //                 if(g < cost[curr]) {
// //                     possible = false;
// //                     break;
// //                 }
// //                 g -= cost[curr];
// //                 int next = (curr + 1) % n;
// //                 g += gas[next];
// //             }
// //             if(possible)
// //                 return i;
// //         }
// //         return -1;
// //     }
// // };

// class Solution {
// public:
//     int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
//         int n = gas.size();
//         int tot = 0;
//         int tank = 0;
//         int start = 0;
//         for(int i=0; i<n; i++){
//            int d= gas[i] - cost[i];
//            tank += d;
//            tot += d;
//            if(tank < 0){
//             tank = 0;
//             start = i+1;
//            }
//         }
//         return (tot >= 0) ? start : -1;
//     }
// };

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totGas = 0;
        int totCost = 0;

        for(int val:gas){
            totGas += val;
        }

        for(int val:cost){
            totCost += val;
        }

        if (totCost>totGas){
            return -1;
        }

        int start = 0, currGas = 0;

        for(int i=0;i<gas.size();i++){
            currGas+=(gas[i]-cost[i]);
            if (currGas<0) {
                start = i+1;
                currGas = 0;
            }
        }

        return start;
    }
};