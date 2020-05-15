#include <iostream>
#include <stdio.h>

using namespace std;

double s5 = 0, p5 = 0, set = 0;

// Размер массива
int a = 10;

void sortRowWise(int** arr) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a - j - 1; k++) {
                s5++;
                if (arr[i][k] > arr[i][k + 1]) {
                    
                    int t = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = t;
                    p5++;

                }
            }
        }
    }
}

void quicksort_colum(int** matr, int j, int first, int last) {
    int mid, count;
    int f = first, l = last;
    mid = matr[(f + l) / 2][j]; 
    do
    {
        while (matr[f][j] > mid) f++;
        while (matr[l][j] < mid) l--;
        if (f <= l) 
        {
            p5++;
            if (set == 100) {
                p5 = 0;
            }
            count = matr[f][j];
            matr[f][j] = matr[l][j];
            matr[l][j] = count;
            f++;
            l--;
        }
    } while (f < l);

    if (first < l) quicksort_colum(matr, j, first, l);
    if (f < last) quicksort_colum(matr, j, f, last);
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Выделение памяти под массив
    int** arr;
    arr = new int* [a];
    for (int i = 0; i < a; i++)
    {
        arr[i] = new int[a];
    }

    // Выделение памяти под второй массив
    int** arr2;
    arr2 = new int* [a];
    for (int i = 0; i < a; i++)
    {
        arr2[i] = new int[a];
    }

    //Вывод неотсортированного массива
    cout << "Вывод неотсортированного массива" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            arr2[i][j] = rand() % 99 + 1;
            cout << arr2[i][j] << "\t";
        }
        cout << endl << endl;
    }

    // Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            arr[i][j] = arr2[i][j];
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (arr[0][0] == arr[i][j]) {
                set++;
            }
        }
    }



    // Сортировка ПУЗЫРЬКОВАЯ
    cout << "Метод ПУЗЫРЬКОВЫЙ" << endl;
    double s1 = 0, p1 = 0;
    for (int i = 0; i < a; i++) {
        for (int k = 0; k < a; k++) {
            bool flag = true;
            for (int j = 0; j < a - 1; j++) {

                // Алгоритм сортировки
                s1++;
                if (arr[i][j] > arr[i][j + 1]) {

                    // Меняем элементы местами
                    flag = false;
                    swap(arr[i][j], arr[i][j + 1]);
                    p1++;
                }
            }
            if (flag) { break; }
        }
    }

    for (int j = 0; j < a; j++) {
        for (int k = 0; k < a; k++) {
            bool flag = true;
            for (int i = 0; i < a - 1; i++) {

                // Алгоритм сортировки
                s1++;
                if (arr[i][j] < arr[i + 1][j]) {

                    // Меняем элементы местами
                    flag = false;
                    swap(arr[i][j], arr[i + 1][j]);
                    p1++;
                }
            }
            if (flag) { break; }
        }
    }

   // Вывод
   for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << s1 << "\t" << "Перестановок " << p1 << endl << endl;



    // Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            arr[i][j] = arr2[i][j];
        }
    }



    // Сортировка МЕТОДОМ ОТБОРА
    cout << "Метод ОТБОРА" << endl;
    int length = a;
    double s2 = 0, p2 = 0;
    for (int i = 0; i < a; i++) {
        for (int startIndex = 0; startIndex < length - 1; ++startIndex) {
            int biggestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
                if (arr[i][currentIndex] < arr[i][biggestIndex]) {
                    biggestIndex = currentIndex;
                }
                s2++;
            }
            swap(arr[i][startIndex], arr[i][biggestIndex]);
            p2++;
        }
    }

    length = a;

    for (int j = 0; j < a; j++) {
        for (int startIndex = 0; startIndex < length - 1; ++startIndex) {
            int biggestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
                if (arr[currentIndex][j] > arr[biggestIndex][j]) {
                    biggestIndex = currentIndex;
                }
                s2++;
            }
            swap(arr[startIndex][j], arr[biggestIndex][j]);
            p2++;
            if (set == 100) {
                p2 = 0;
            }
        }
    }

    // Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << s2 << "\t" << "Перестановок " << p2 << endl << endl;



    // Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            arr[i][j] = arr2[i][j];
        }
    }



    // Сортировка МЕТОДОМ ВСТАВКИ
    cout << "Метод ВСТАВКИ" << endl;
    double s3 = 0, p3 = 0;

    int tmp, pos;
    for (int i = 0; i < a; ++i) { 
        for (int j = 0; j < a; ++j) { 
            pos = j;
            tmp = arr[i][j];
            for (int h = j + 1; h < a; ++h) { 
                s3++;
                if (arr[i][h] < tmp) {
                    p3++;
                    pos = h;
                    tmp = arr[i][h];
                }
            }
            arr[i][pos] = arr[i][j];
            arr[i][j] = tmp; 
        }
    }

    for (int j = 0; j < a; j++) {
        int newElement, location;
        for (int i = 1; i < a; i++) {
            newElement = arr[i][j];
            location = i - 1;
            while (location >= 0 && arr[location][j] < newElement) {
                arr[location + 1][j] = arr[location][j];
                p3++;
                location = location - 1;
            }
            arr[location + 1][j] = newElement;
            p3++;
            if (set == 100) {
                p3 = 0;
            }
        }
    }

    // Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << s3 << "\t" << "Перестановок " << p3 << endl << endl;



    // Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            arr[i][j] = arr2[i][j];
        }
    }



    // Сортировка ШЕЛЛА
    cout << "Метод ШЕЛЛА" << endl;
    double s4 = 0, p4 = 0;

    int i, j, step;
    int tmp1;
    for (int p = 0; p < a; p++) {
        for (step = a / 2; step > 0; step /= 2) {
            for (i = step; i < a; i++) {
                tmp1 = arr[p][i];
                for (j = i; j >= step; j -= step) {
                    s4++;
                    if (tmp1 < arr[p][j - step]) {
                        arr[p][j] = arr[p][j - step];
                        p4++;
                    }
                    else
                        break;
                }
                arr[p][j] = tmp1;
            }
        }
    }

    for (int p = 0; p < a; p++) {
        for (step = a / 2; step > 0; step /= 2) {
            for (i = step; i < a; i++) {
                tmp1 = arr[i][p];
                for (j = i; j >= step; j -= step) {
                    s4++;
                    if (tmp1 > arr[j - step][p]) {
                        arr[j][p] = arr[j - step][p];
                        p4++;
                    }
                    else
                        break;
                }
                arr[j][p] = tmp1;
            }
        }
    }

    // Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << s4 << "\t" << "Перестановок " << p4 << endl << endl;



    // Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            arr[i][j] = arr2[i][j];
        }
    }



    // Сортировка БЫСТРАЯ
    cout << "Метод БЫСТРЫЙ" << endl;

    sortRowWise(arr);
    for (int i = 0; i <= a; i++) {
        quicksort_colum(arr, i, 0, a-1);
    }

    // Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << s5 << "\t" << "Перестановок " << p5 << endl << endl;





    cout << "Таблица сравнений сортировок: " << endl;

    printf("=====================================================================================\n");
    printf("|  Алгоритм сортировки      |  Количество сравнений     |  Количество перестановок  |\n");
    printf("=====================================================================================\n");

    cout << "  Сортировка ПУЗЫРЬКОВАЯ                 " << s1 << "\t\t\t\t" << p1 << "             " << endl;
    cout << "  Сортировка ОТБОРОМ                     " << s2 << "\t\t\t\t" << p2 << "             " << endl;
    cout << "  Сортировка ВСТАВКАМИ                   " << s3 << "\t\t\t\t" << p3 << "             " << endl;
    cout << "  Сортировка ШЕЛЛА                       " << s4 << "\t\t\t\t" << p4 << "             " << endl;
    cout << "  Сортировка БЫСТРАЯ                     " << s5 << "\t\t\t\t" << p5 << "             " << endl;

    printf("=====================================================================================\n");





    return 0;
}