#include <iostream>

const int m = 3;
const int n = 3;

int diagonalSum(int arr[m][n]) {
    int sum = 0;
    for (int i = 0; i < m; ++i) {
        sum += arr[i][i];          
        sum += arr[i][n - 1 - i];   
    }
    return sum;
}


void rotateClockwise(int arr[m][n]) {
    int temp[m][n];

  
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp[i][j] = arr[j][i];
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            std::swap(temp[i][j], temp[i][n - 1 - j]);
        }
    }


    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    int array[m][n] = {{1, 2, 3},
                       {4, 5, 6},
                       {7, 8, 9}};


    std::cout << "Сумма чисел по диагоналям: " << diagonalSum(array) << std::endl;

    std::cout << "Исходный массив:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    rotateClockwise(array);

    std::cout << "Массив после поворота на 90 градусов по часовой стрелке:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}