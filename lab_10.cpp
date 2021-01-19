#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;


void print_matrix(int** m, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << m[i][j] << " ";
        cout << endl;
    }
}

int** create_matrix(int n){
    int **matrix = new int*[n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new int[n];

    for(int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            matrix[i][j] = rand() % 10;
    }

    return matrix;
}



void update_col(int** m, int* col, int indx){
    m[indx] = col;
}


void delete_matrix(int **m, int n){
    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;
}


int main(){
    srand(2175454);
    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    int **matrix = create_matrix(n);

    print_matrix(matrix, n);

    int * col = new int[n];

    cout << "Столбец: ";
    for (int i = 0; i < n; ++i) {
        col[i] = rand() % 10;
        cout << col[i] << " ";
    }
    cout << endl;

    cout << "Введите индекс столбца: ";
    int indx;
    cin >> indx;

    update_col(matrix, col, indx);

    print_matrix(matrix, n);


    return 0;
}
