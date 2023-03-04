#include <iostream>
#include <map>

using namespace std;

map<string, int> cows;
int main(){
    int n;
    cin >> n;
    while (n--) {
        string name;
        int milk_prod;
        cin >> name >> milk_prod;
        cows[name] += milk_prod;
    }
    int min_m = INT16_MAX;
    if (cows.size() < 7){
        min_m = 0;
    } else {
        for (auto& cow : cows){
            min_m = min(min_m, cow.second);
        }
    }
    string ans = "";
    int sec_min = INT16_MAX, cnt = 0;
    for (auto cow : cows){
        if (cow.second > min_m && cow.second < sec_min){
            sec_min = cow.second;
            ans = cow.first;
            cnt = 1;
        } else if (cow.second == sec_min){
            cnt++; 
        }

    }
    if (cnt == 1) cout << ans << '\n';
    else cout << "Tie\n";
    // for (auto cow : cows){
    //     cout << cow.first << " " << cow.second << "\n";
    // }
}