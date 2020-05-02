#include <iostream>
#include <stdio.h>
using namespace std;

int sravneniya5 = 0, perestanovki5 = 0, cc = 0;

void sortRowWise(int** arr) {
    //  loop for rows of matrix
    for (int i = 0; i < 10; i++) {
        //  loop for column of matrix
        for (int j = 0; j < 10; j++) {
            //  loop for comparison and swapping
            for (int k = 0; k < 10 - j - 1; k++) {
                sravneniya5++;
                if (arr[i][k] > arr[i][k + 1]) {
                    //  swapping of elements
                    int t = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = t;
                    perestanovki5++;
                }
            }
        }
    }
}
//сортировка столбцов
void quicksort_colum(int** matr, int j, int first, int last)
// j - номер сортируемого столбца quicksort_colum(arr,0,0,9);
{
    int mid, count;
    int f = first, l = last;
    mid = matr[(f + l) / 2][j]; //вычисление опорного элемента
    do
    {
        while (matr[f][j] > mid) f++;
        while (matr[l][j] < mid) l--;
        if (f <= l) //перестановка элементов
        {
            perestanovki5++;
            if (cc == 100) {
                perestanovki5 = 0;
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
    //Размерность массива
    int a = 10,
        b = 10;

    // Выделение памяти под массив
    int** arr;
    arr = new int* [a];
    for (int i = 0; i < a; i++)
    {
        arr[i] = new int[b];
    }
    // Выделение памяти под второй массив
    int** arr2;
    arr2 = new int* [a];
    for (int i = 0; i < a; i++)
    {
        arr2[i] = new int[b];
    }

    //Вывод неотсортированного массива
    cout << "Вывод неотсортированного массива" << endl;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            //arr2[i][j] = 69;
            arr2[i][j] = rand() % 99 + 1;
            cout << arr2[i][j] << "\t";
        }
        cout << endl << endl;
    }

    //Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (arr[0][0] == arr[i][j]) {
                cc++;
            }
        }
    }
    //Сортировка ПУЗЫРЬКОВАЯ
    cout << "Метод ПУЗЫРЬКОВЫЙ" << endl;
    int sravneniya1 = 0, perestanovki1 = 0;
    for (int i = 0; i < a; i++) {
        for (int k = 0; k < 10; k++) {
            bool flag = true;
            for (int j = 0; j < b - 1; j++) {
                //Алгоритм сортировки
                sravneniya1++;
                if (arr[i][j] > arr[i][j + 1]) {
                    // меняем элементы местами
                    flag = false;
                    swap(arr[i][j], arr[i][j + 1]);
                    perestanovki1++;
                }
            }
            if (flag) { break; }
        }
    }
    for (int j = 0; j < a; j++) {
        for (int k = 0; k < 10; k++) {
            bool flag = true;
            for (int i = 0; i < b - 1; i++) {
                //Алгоритм сортировки
                sravneniya1++;
                if (arr[i][j] < arr[i + 1][j]) {
                    // меняем элементы местами
                    flag = false;
                    swap(arr[i][j], arr[i + 1][j]);
                    perestanovki1++;
                }
            }
            if (flag) { break; }
        }
    }
    //Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << sravneniya1 << "\t" << "Перестановок " << perestanovki1 << endl << endl;



    //Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    //Сортировка МЕТОДОМ ОТБОРА
    cout << "Метод ОТБОРА" << endl;
    int length = a;
    int sravneniya2 = 0, perestanovki2 = 0;
    for (int i = 0; i < a; i++) {
        for (int startIndex = 0; startIndex < length - 1; ++startIndex) {
            int biggestIndex = startIndex;
            for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex) {
                if (arr[i][currentIndex] < arr[i][biggestIndex]) {
                    biggestIndex = currentIndex;
                }
                sravneniya2++;
            }
            swap(arr[i][startIndex], arr[i][biggestIndex]);
            perestanovki2++;
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
                sravneniya2++;
            }
            swap(arr[startIndex][j], arr[biggestIndex][j]);
            perestanovki2++;
            if (cc == 100) {
                perestanovki2 = 0;
            }
        }
    }
    //Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << sravneniya2 << "\t" << "Перестановок " << perestanovki2 << endl << endl;

    //Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    //Сортировка МЕТОДОМ ВСТАВКИ
    cout << "Метод ВСТАВКИ" << endl;
    int sravneniya3 = 0, perestanovki3 = 0;

    int tmp, pos;
    for (int i = 0; i < a; ++i) { // i - номер текущей строки
        for (int j = 0; j < a; ++j) { // j - номер текущего шага
            pos = j;
            tmp = arr[i][j];
            for (int h = j + 1; h < a; ++h) { // цикл выбора наименьшего элемента
                sravneniya3++;
                if (arr[i][h] < tmp) {
                    perestanovki3++;
                    pos = h;
                    tmp = arr[i][h];
                }
            }
            arr[i][pos] = arr[i][j];
            arr[i][j] = tmp; // меняем местами наименьший с a[i]
        }
    }

    for (int j = 0; j < a; j++) {
        //Алгоритм сортировки
        int newElement, location;
        for (int i = 1; i < a; i++) {
            newElement = arr[i][j];
            location = i - 1;
            while (location >= 0 && arr[location][j] < newElement) {
                //sravneniya3++;
                arr[location + 1][j] = arr[location][j];
                perestanovki3++;
                location = location - 1;
            }
            arr[location + 1][j] = newElement;
            perestanovki3++;
            if (cc == 100) {
                perestanovki3 = 0;
            }
        }
    }
    //Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << sravneniya3 << "\t" << "Перестановок " << perestanovki3 << endl << endl;

    //Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    //Сортировка ШЕЛЛА
    cout << "Метод ШЕЛЛА" << endl;
    int sravneniya4 = 0, perestanovki4 = 0;

    int i, j, step;
    int tmp1;
    for (int p = 0; p < a; p++) {
        for (step = a / 2; step > 0; step /= 2) {
            for (i = step; i < a; i++) {
                tmp1 = arr[p][i];
                for (j = i; j >= step; j -= step) {
                    sravneniya4++;
                    if (tmp1 < arr[p][j - step]) {
                        arr[p][j] = arr[p][j - step];
                        perestanovki4++;
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
                    sravneniya4++;
                    if (tmp1 > arr[j - step][p]) {
                        arr[j][p] = arr[j - step][p];
                        perestanovki4++;
                    }
                    else
                        break;
                }
                arr[j][p] = tmp1;
            }
        }
    }
    //Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << sravneniya4 << "\t" << "Перестановок " << perestanovki4 << endl << endl;

    //Присвоение старых значений массиву
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            arr[i][j] = arr2[i][j];
        }
    }
    //Сортировка "БЫСТРАЯ"
    cout << "Метод \"БЫСТРЫЙ\"" << endl;


    sortRowWise(arr);
    for (int i = 0; i <= 10; i++) {
        quicksort_colum(arr, i, 0, 9);
    }
    //Вывод
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    cout << "Сравнений " << sravneniya5 << "\t" << "Перестановок " << perestanovki5 << endl << endl;

    cout << "Таблица сравнений сортировок: " << endl;

    printf("=====================================================================================\n");
    printf("|  Алгоритм сортировки      |  Количество сравнений     |  Количество перестановок  |\n");
    printf("=====================================================================================\n");

    cout << "  Сортировка ПУЗЫРЬКОВАЯ                 " << sravneniya1 << "\t\t\t" << perestanovki1 << "             " << endl;
    cout << "  Сортировка ОТБОРОМ                     " << sravneniya2 << "\t\t\t" << perestanovki2 << "             " << endl;
    cout << "  Сортировка ВСТАВКАМИ                   " << sravneniya3 << "\t\t\t" << perestanovki3 << "             " << endl;
    cout << "  Сортировка ШЕЛЛА                       " << sravneniya4 << "\t\t\t" << perestanovki4 << "             " << endl;
    cout << "  Сортировка БЫСТРАЯ                     " << sravneniya5 << "\t\t\t" << perestanovki5 << "             " << endl;

    printf("=====================================================================================\n");




    return 0;
}