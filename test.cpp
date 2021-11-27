////SkyWalker///
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fir(i, a, b) for(int i=a;i<b;i++)
#define rfir(i, a, b) for(int i=a;i>=b;i--)
#define vi vector<int>
#define pii pair<int, int>
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define mod 1000000007
#define fast                  \
ios_base::sync_with_stdio(0); \
cin.tie(0);                   \
cout.tie(0);
#define tests                 \
int tt;                       \
cin>>tt; while(tt--)
using namespace std;

/*
const int N = 1e6+1;
bool arr[N];
void process(){
   arr[0]=arr[1]=false;
   fir(i, 2, N)arr[i]=true;

   for(int i=2; i*i<=N; i++){
       if(arr[i]==true){
           for(int j=i*i; j<N; j+=i){
           arr[j]=false;
           }
       }
   }
}
*/
/****************************/


int cnt = 0;
void recur(int n){
    cnt++;
    n=n/2;
    if(n)recur(n);
}
int main()
{
    recur(100);
    cout<<cnt<<endl;

return 0;
}