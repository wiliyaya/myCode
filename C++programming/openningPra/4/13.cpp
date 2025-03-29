#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin >> n >> t;
    struct Building {
        int x;
        int a;
    };
    vector<Building> buildings(n);
    for(int i=0;i<n;i++) cin >> buildings[i].x >> buildings[i].a;
    
    vector<long long> candidates;
    for(int i=0;i<n;i++){
        long long C1 = 2LL * buildings[i].x - buildings[i].a - t;
        long long C2 = 2LL * buildings[i].x + buildings[i].a + t;
        candidates.push_back(C1);
        candidates.push_back(C2);
    }
    
    set<long long> validCs;
    for(auto C : candidates){
        bool valid = true;
        for(int j=0; j<n; j++){
            long long left_new = C - t;
            long long right_new = C + t;
            long long left_exist = 2LL * buildings[j].x - buildings[j].a;
            long long right_exist = 2LL * buildings[j].x + buildings[j].a;

            if(!(right_new <= left_exist || left_new >= right_exist)){
                valid = false;
                break;
            }
        }
        if(valid){
            validCs.insert(C);
        }
    }
    
    cout << validCs.size();
}