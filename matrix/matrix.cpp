#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > square_matrix(int n){
    vector<vector<int> > matrix(n, vector<int>(n, 0));
    int iter = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrix[i][j] = iter;
            iter++;
        }
    }
    return matrix;
}

void print_ordered_square_matrix(vector<vector<int> > matrix){
    int n = matrix.size();
    int j = n - 1;

    for (int i = n*n - 1; i >= 0; i--){
        int current = matrix[j][i%n];
        cout << "M[" << j << "][" << i%n << "] = " << current << endl;
        if (i % n == 0) j--; 
    }

    return;
}

int main(){
    int n;
    cout << "Tamaño de la matriz: "; cin >> n;
    vector<vector<int> > matrix = square_matrix(n);
    print_ordered_square_matrix(matrix);
    return 0;
}
