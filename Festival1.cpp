#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct mystruct{
  bool operator()(const pair<int,pair<int,int>>&p1,const pair<int,pair<int,int>>&p2){
      return p1.first > p2.first;
  }  
};
int main(){
    int T;
    cin>>T;
    int case_id = 1;
    int D,N,K;
    while(T--){
        cin>>D>>N>>K;
        ll ans = 0;
        vector<pair<int,pair<int,int>>> v;
        int h,s,e;
        for(int i = 0;i<N;i++){
            cin>>h>>s>>e;
            v.push_back({h,{s,e}});
        }
        sort(v.begin(),v.end(),mystruct());
        for(int day = 1;day<=D;day++){
            ll candidate_ans = 0;
            int taken = 0;
            for(int i = 0;i<N;i++){
                if(taken==K)
                    break;
                else{
                    if(v[i].second.first<=day&&day<=v[i].second.second){
                        taken++;
                        candidate_ans += v[i].first;
                    }   
                }
            }
            
            ans = max(ans,candidate_ans);   
        }
        cout<<"Case #"<<case_id<<": "<<ans;
        case_id++;
        cout<<endl;
    }    
    return 0;
}

