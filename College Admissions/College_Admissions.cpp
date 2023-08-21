#include<bits/stdc++.h>
using namespace std;


int main(){
    int tc; cin >> tc;
    while(tc--) {
        int n_col, n_stu; cin >> n_col >> n_stu;
        int id_rank_col[n_col+1];
        for(int i = 1; i<= n_col; i++) {cin >> id_rank_col[i];}
        int id_rank_stu[n_stu+1];
        for(int i = 1; i<=n_stu;i++) {cin >> id_rank_stu[i];}
        vector<vector<int>> stu_col_pref(n_stu+1);
        for(int i = 1; i<=n_stu; i++) {
            int temp; int x;
            cin >> temp;
            for(int j = 0; j<temp; j++) {
                cin >> x;
                stu_col_pref[id_rank_stu[i]].push_back(id_rank_col[x]);
            }
            sort(stu_col_pref[id_rank_stu[i]].begin(), stu_col_pref[id_rank_stu[i]].end());
        }
        vector<int> col_occ(n_col+1,-1);
        for(int i = 1; i<= n_stu; i++) {
            for(int col: stu_col_pref[i]) {
                if(col_occ[col] == -1) {
                    col_occ[col] = i;
                    break;
                }
            }
        }
        //rank of chef is id_rank_stu[1]
        int rank_col = -1;
        for(int i = 1;i<= n_col;i++) {
            if(col_occ[i] == id_rank_stu[1]) {
                rank_col = i;
                break;
            }
        }
        if(rank_col == -1) {cout << 0 << endl;}
        else {
            for(int i = 1; i<= n_col; i++) {
                if (id_rank_col[i] == rank_col) {
                    cout << i << endl;
                    break;
                }
            }
        }
    }
}
