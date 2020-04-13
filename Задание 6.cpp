#include <iostream>
#include <stdio.h>

using namespace std;

template<class T>
void quickSortR(T* a, long N) {
    // На входе - массив a[], a[N] - его последний элемент.

    long j = N, i = 0;            // поставить указатели на исходные места
    T temp, p;

    p = a[N >> 1];                // центральный элемент

    // процедура разделения
    do {
        while (a[i] < p) {
            i++;
        }
        while (a[j] > p) {
            j--;
        }

        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
        }
    } while (i <= j);

    // рекурсивные вызовы, если есть, что сортировать
    if (j > 0) quickSortR(a, j);
    if (N > i) quickSortR(a + i, N - i);
}
template<class T>
int quickSortRf(T* a, long N, int n) {
    // На входе - массив a[], a[N] - его последний элемент.
    int counter = 0;
    int counter2 = 0;
    long j = N, i = 0;            // поставить указатели на исходные места
    T temp, p;

    p = a[N >> 1];                // центральный элемент

    // процедура разделения
    do {
        while (a[i] < p) {
            i++;
            counter++;
        }
        while (a[j] > p) {
            j--;
            counter++;
        }

        if (i <= j) {
            temp = a[i]; a[i] = a[j]; a[j] = temp;
            i++; j--;
            counter2++;
        }
    } while (i <= j);

    // рекурсивные вызовы, если есть, что сортировать
    if (j > 0) quickSortR(a, j);
    if (N > i) quickSortR(a + i, N - i);
    if (n == 1) return counter;
    if (n == 2) return counter2;
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
    for (int i = 0; i < a; i++) {
        //Алгоритм сортировки
        int newElement, location;
        for (int j = 1; j < a; j++) {
            newElement = arr[i][j];
            location = j - 1;
            while (location >= 0 && arr[i][location] < newElement) {
                sravneniya3++;
                arr[i][location + 1] = arr[i][location];
                perestanovki3++;
                location = location - 1;
            }
            arr[i][location + 1] = newElement;
            perestanovki3++;
        }
    }
    for (int j = 0; j < a; j++) {
        //Алгоритм сортировки
        int newElement, location;
        for (int i = 1; i < a; i++) {
            newElement = arr[i][j];
            location = i - 1;
            while (location >= 0 && arr[location][j] < newElement) {
                sravneniya3++;
                arr[location + 1][j] = arr[location][j];
                perestanovki3++;
                location = location - 1;
            }
            arr[location + 1][j] = newElement;
            perestanovki3++;
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
    for (int i = 0; i < a; i++) {
        //Алгоритм сортировки
        int step = a / 2;
        while (step > 0) {
            for (int f = 0; f < (a - step); f++) {
                int j = f;
                while (j >= 0 && arr[i][j] < arr[i][j + step]) {
                    sravneniya4++;
                    int temp = arr[i][j];
                    arr[i][j] = arr[i][j + step];
                    arr[i][j + step] = temp;
                    perestanovki4++;
                    j--;
                }
                if (j < 0 && arr[i][j] >= arr[i][j + step]) sravneniya4++;
            }
            step = step / 2;
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
    int sravneniya5 = 0, perestanovki5 = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            //Алгоритм сортировки
            quickSortR(arr2, 9);
            //cout << arr[i][j] << "\t";
        }
        cout << endl << endl;
    }
    sravneniya5 = quickSortRf(arr2, 9, 1);
    perestanovki5 = quickSortRf(arr2, 9, 2);
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

    cout << "  Сортировка ПУЗЫРЬКОВАЯ                 " << sravneniya1 << "                         " << perestanovki1 << "             " << endl;
    cout << "  Сортировка ОТБОРОМ                     " << sravneniya2 << "                         " << perestanovki2 << "             " << endl;
    cout << "  Сортировка ВСТАВКАМИ                   " << sravneniya3 << "                         " << perestanovki3 << "             " << endl;
    cout << "  Сортировка ШЕЛЛА                       " << sravneniya4 << "                         " << sravneniya4 << "             " << endl;
    cout << "  Сортировка БЫСТРАЯ                     " << sravneniya5 << "                         " << sravneniya5 << "             " << endl;

    printf("=====================================================================================\n");




    return 0;
}


