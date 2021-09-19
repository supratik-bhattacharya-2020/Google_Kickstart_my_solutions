#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int T;
    int case_id = 1;
    cin>>T;
    while(T--){
        ll n;
        cin>>n;
        string houses;
        cin>>houses;
        ll ans = 0;
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        for(ll i = 0;i<n;i++){
            if(houses[i]=='0'){
                if(i==0){
                    prefix[i]= INT_MAX;
                }
                else{
                    if(prefix[i-1]==INT_MAX){
                        prefix[i]= INT_MAX;
                    }
                    else{
                        prefix[i] = 1+prefix[i-1];
                    }
                }
            }
        }
        for(ll i = n-1;i>=0;i--){
            if(houses[i]=='0'){
                if(i==n-1){
                    suffix[i]= INT_MAX;
                }
                else{
                    if(suffix[i+1]==INT_MAX){
                        suffix[i]= INT_MAX;
                    }
                    else{
                        suffix[i] = 1+suffix[i+1];
                    }
                }
            }
        }
        for(ll i = 0;i<n;i++){
            ans+= min(prefix[i],suffix[i]);
        }
        cout<<"Case #"<<case_id<<": "<<ans;
        case_id++;
        cout<<endl;
    }
    return 0;
}
