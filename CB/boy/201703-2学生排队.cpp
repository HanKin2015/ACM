#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<cmath>
using namespace std;

int n, m;
vector<int> ret;
void solve(vector<vector<double> > &);


inline bool isZero(double d){
    return abs(d) < 1e-6;
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;// m * n matrix
    vector<vector<double> > mat(m, vector<double>(n + 1));
    ret = vector<int>(n);
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            cin >> mat[i][j];
        }
    }
    solve(mat);
    return 0;
}

void swap2Row(vector<vector<double> >& mat, int i, int j){
    for(int k = 0; k < mat[i].size(); k++){
        swap(mat[i][k], mat[j][k]);
    }
}

void display(vector<vector<double> > & mat){
    cout << endl;
    for(int i = 0; i < m ; i++){
        for(int j = 0; j <= n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void solve(vector<vector<double> > & mat){
    // 处理出上三角矩阵
    for(int i = 0; i < n; i++){
        bool flag = false;
        for(int j = i; j < m; j++){
            if(!isZero(mat[j][i])){
                swap2Row(mat, j, i);
                flag = true;
                break;
            }
        }

        if(!flag){
            cout << "Many solutions" << endl;
            return;
        }

        for(int j = i + 1; j < m; j++){
            double t = mat[j][i] / mat[i][i];
            for(int k = i; k <= n; k++){
                mat[j][k] -= mat[i][k] * t;
            }
        }

        //display(mat);
    }

    for(int i = 0; i < m; i++){
        bool allZero = true;
        for(int j = 0; j < n; j++){
            if(!isZero(mat[i][j])){
                allZero = false;
                break;
            }
        }
        if(allZero && !isZero(mat[i][n])){
            cout << "No solutions" << endl;
            return;
        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            mat[i][n] -= mat[i][j] * ret[j];
            mat[i][j] = 0;
        }
        ret[i] = int(mat[i][n] / mat[i][i] + 0.5);
    }

    for(int i = 0; i < ret.size(); i++){
        cout << ret[i] << endl;
    }
}

