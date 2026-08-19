// Last updated: 19/08/2026, 15:51:38
// class Solution {
// public:
//     int sumFourDivisors(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i=0; i<n; ++i){
//             int cnt = 0;
//             int sum2 = 0;
//             for(int j=1; j<=sqrt(nums[i]); ++j){
//                 if(nums[i]%j ==0){
//                     sum2 += j;
//                     cnt++;
//                     if(j != nums[i]/j){
//                         cnt++;
//                         sum2 += (nums[i]/j);
//                     }
//                 }
//             }
//             if(cnt == 4)sum += sum2;
//         }
//         return sum;
//     }
// };

// class Solution {
// public:
//     int sumFourDivisors(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for(int i=0; i<n; ++i){
//             int cnt = 0;
//             int sum2 = 0;
//             for(int j=1; j * j<= nums[i]; ++j){
//                 if(nums[i]%j ==0){
//                     sum2 += j;
//                     cnt++;
//                     if(j != nums[i]/j){
//                         cnt++;
//                         sum2 += (nums[i]/j);
//                     }
//                 }
//             }
//             if(cnt == 4)sum += sum2;
//         }
//         return sum;
//     }
// };

// constexpr int MX = 100'001;
// int divisor_num[MX];
// int divisor_sum[MX];

// int init = [] {
//     for (int i = 1; i < MX; i++) {
//         for (int j = i; j < MX; j += i) { 
//             divisor_num[j]++; 
//             divisor_sum[j] += i;
//         }
//     }
//     return 0;
// }();

// class Solution {
// public:
//     int sumFourDivisors(vector<int>& nums) {
//         int ans = 0;
//         for (int x : nums) {
//             if (divisor_num[x] == 4) {
//                 ans += divisor_sum[x];
//             }
//         }
//         return ans;
//     }
// };

// const int N=316;
// bitset<N+1> isPrime=0;
// vector<int> prime;
// int Div4[100001];

// class Solution {
// public:
//     static void Sieve(){ 
//         if (isPrime[2]) return ; 
//         isPrime.set(); 
//         memset(Div4, -1, sizeof(Div4)); 
//         isPrime[0]=isPrime[1]=0; 
//         Div4[0]=Div4[1]=0; 
//         int Nsqrt=sqrt(N-1); 
//         for(int p=2; p<=Nsqrt; p+=1+(p&1)){ 
//             if (isPrime[p]){ 
//                 Div4[p]=0;// prime has only 2 divisors 
//                 prime.push_back(p); 
//                 for(int i=p*p; i<N; i+=p) 
//                     isPrime[i]=0; 
//             } 
//         } 
//         for(int i=Nsqrt+((Nsqrt&1)==0); i<N; i+=2){ 
//             if (isPrime[i]) 
//                 prime.push_back(i); 
//         } 
//     }

//     static int sum4Div(int x){
//         if (Div4[x]!=-1) return Div4[x];
//         int y=x, sum=1+x, cntPF=0, xsqrt=sqrt(x);
//         for(int p: prime){
//             if (p>xsqrt) break;
//             if (y%p) continue;
//             int e=0;
//             while(y%p==0){
//                 y/=p;
//                 e++;
//             }
//             cntPF++;

//             if (e==3 && y==1 && cntPF==1)
//                 return Div4[x]=1+p+p*p+p*p*p;

//             if (e>1) return Div4[x]=0;
//             sum+=p;
//         }
//         if (y>1){
//             cntPF++;
//             sum+=y;
//         }
//         return Div4[x]=(cntPF==2)?sum:0;
//     }

//     static int sumFourDivisors(vector<int>& nums) {
//         Sieve();
//         int ans=0;
//         for(int x: nums)
//             ans+=sum4Div(x);
//         return ans;
//     }
// };

int prime[]={2, 3, 5, 7, 11, 13, 17, 17, 19, 23, 29, 31, 37, 41, 43,
 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
  127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 
  193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 
  269, 271, 277, 281, 283, 293, 307, 311, 313 };
int Div4[100001];

class Solution {
public:
    static int sum4Div(int x){
        if (Div4[x]!=-1) return Div4[x];
        int y=x, sum=1+x, cntPF=0, xsqrt=sqrt(x);
        for(int p: prime){
            if (p>xsqrt) break;
            if (y%p) continue;
            int e=0;
            while(y%p==0){
                y/=p;
                e++;
            }
            cntPF++;
            if (y==1 && cntPF==1){
                if (e==1)  return 0;
                if (e==3)  return Div4[x]=1+p+p*p+p*p*p;
            }
            if (e>1) return Div4[x]=0;
            sum+=p;
        }
        if (y>1){
            cntPF++;
            sum+=y;
        }
        return Div4[x]=(cntPF==2)?sum:0;
    }

    static int sumFourDivisors(vector<int>& nums) {
        if (Div4[0]==0) memset(Div4, -1, sizeof(Div4));
        int ans=0;
        for(int x: nums)
            ans+=sum4Div(x);
        return ans;
    }
};