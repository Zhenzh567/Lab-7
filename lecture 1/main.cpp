#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <locale>

using namespace std;

// ===== ПУНКТ 1: РАБОТА С VECTOR =====

// Функция вывода массива
void printArray(const vector<int>& arr) {
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

// Функция добавления элемента в начало
void addToBegin(vector<int>& arr, int value) {
    arr.insert(arr.begin(), value);
}

// Функция добавления элемента в конец
void addToEnd(vector<int>& arr, int value) {
    arr.push_back(value);
}

// Функция очистки массива
void clearArray(vector<int>& arr) {
    arr.clear();
}

// Функция поиска элемента (возвращает индексы)
vector<size_t> findElement(const vector<int>& arr, int value) {
    vector<size_t> indices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) {
            indices.push_back(i);
        }
    }
    return indices;
}

// Функция вывода индексов
void printIndices(const vector<size_t>& indices) {
    cout << "[";
    for (size_t i = 0; i < indices.size(); ++i) {
        cout << indices[i];
        if (i < indices.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

// Оптимизированная функция проверки треугольного числа
bool isTriangularNumber(int K) {
    // Треугольное число n(n+1)/2 = K
    // Решаем уравнение: n² + n - 2K = 0
    // Дискриминант: D = 1 + 8K
    int discriminant = 1 + 8 * K;
    int sqrt_discriminant = sqrt(discriminant);
    
    // Проверяем, является ли дискриминант полным квадратом
    if (sqrt_discriminant * sqrt_discriminant != discriminant) {
        return false;
    }
    
    // Проверяем, является ли корень целым положительным числом
    return (sqrt_discriminant - 1) % 2 == 0 && (sqrt_discriminant - 1) / 2 > 0;
}

// Функция получения треугольных слагаемых
vector<int> getTriangularTerms(int K) {
    vector<int> terms;
    int n = (sqrt(1 + 8 * K) - 1) / 2;
    
    for (int i = 1; i <= n; ++i) {
        terms.push_back(i);
    }
    
    return terms;
}

// Вариант 5: разбить K на сумму 1+2+3+...=K и добавить слагаемые в конец
void processVariant5(vector<int>& arr) {
    int K;
    cout << "Enter a positive number K: ";
    cin >> K;

    if (K <= 0) {
        cout << "K must be positive!" << endl;
        return;
    }

    // Оптимизированная проверка - сразу определяем, является ли K треугольным числом
    if (!isTriangularNumber(K)) {
        cout << "Number " << K << " cannot be represented as sum 1+2+3+..." << endl;
        return;
    }

    // Получаем слагаемые
    vector<int> terms = getTriangularTerms(K);

    // Выводим разложение
    cout << "Decomposition: ";
    for (size_t i = 0; i < terms.size(); ++i) {
        cout << terms[i];
        if (i < terms.size() - 1) cout << "+";
    }
    cout << " = " << K << endl;

    // Добавляем слагаемые в конец массива
    arr.insert(arr.end(), terms.begin(), terms.end());
    cout << "Array after addition: ";
    printArray(arr);
}

// ===== ПУНКТ 2: РАБОТА С ARRAY  =====


using namespace std;

// Константа для размера массива
const int SIZE = 10;

// Генерация случайного std::array через rand()
array<int, SIZE> generateRandomArray(int min, int max) {
    array<int, SIZE> arr;
    
    // Инициализация генератора случайных чисел
    srand(time(0));
    
    for (int i = 0; i < SIZE; i++) {
        // Генерируем число от min до max включительно
        arr[i] = rand() % (max - min + 1) + min;
    }
    return arr;
}

// Вывод std::array
void printArray(const array<int, SIZE>& arr, const string& message = "") {
    if (!message.empty()) cout << message;
    for (int i = 0; i < SIZE; i++) {
        cout << arr[i];
        if (i < SIZE - 1) cout << ", ";
    }
    cout << endl;
}

// Пузырьковая сортировка по возрастанию
void bubbleSortAsc(array<int, SIZE>& arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start) - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Пузырьковая сортировка по убыванию
void bubbleSortDesc(array<int, SIZE>& arr, int start, int end) {
    for (int i = start; i < end; i++) {
        for (int j = start; j < end - (i - start) - 1; j++) {
            if (arr[j] < arr[j + 1]) {  // Обратное сравнение для убывания
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ
array<int, SIZE> sortHalfAscHalfDescByValue(array<int, SIZE> arr) {
    cout << "Адрес ВНУТРИ функции (значение): " << &arr << endl;
    
    int mid = SIZE / 2;
    
    // Первую половину сортируем по ВОЗРАСТАНИЮ (пузырьковая)
    bubbleSortAsc(arr, 0, mid);
    
    // Вторую половину сортируем по УБЫВАНИЮ (пузырьковая)
    bubbleSortDesc(arr, mid, SIZE);
    
    return arr;
}

// 2. ПЕРЕДАЧА ПО ССЫЛКЕ
void sortHalfAscHalfDescByReference(array<int, SIZE>& arr) {
    cout << "Адрес ВНУТРИ функции (ссылка): " << &arr << endl;
    
    int mid = SIZE / 2;
    
    // Первую половину сортируем по ВОЗРАСТАНИЮ (пузырьковая)
    bubbleSortAsc(arr, 0, mid);
    
    // Вторую половину сортируем по УБЫВАНИЮ (пузырьковая)
    bubbleSortDesc(arr, mid, SIZE);
}

// 3. ПЕРЕДАЧА ПО УКАЗАТЕЛЮ
void sortHalfAscHalfDescByPointer(array<int, SIZE>* arr) {
    cout << "Адрес ВНУТРИ функции (указатель): " << arr << endl;
    
    int mid = SIZE / 2;
    
    // Первую половину сортируем по ВОЗРАСТАНИЮ (пузырьковая)
    bubbleSortAsc(*arr, 0, mid);
    
    // Вторую половину сортируем по УБЫВАНИЮ (пузырьковая)
    bubbleSortDesc(*arr, mid, SIZE);
}

void ShowArrayMenu(){
    array<int, SIZE> originalArray = generateRandomArray(-10, 10);
    
    cout << "=== РАЗДЕЛЬНАЯ СОРТИРОВКА ПОЛОВИН МАССИВА ===" << endl;
    cout << "Первая половина - по возрастанию, вторая - по убыванию" << endl;
    cout << "Используется пузырьковая сортировка" << endl;
    cout << "Размер массива: " << SIZE << " элементов" << endl;
    cout << "Диапазон значений: [-10; 10]" << endl << endl;

    // ТЕСТ 1: Передача по значению
    cout << "1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ:" << endl;
    cout << "=========================================" << endl;
    
    array<int, SIZE> array1 = originalArray;
    printArray(array1, "Исходный массив: ");
    cout << "Адрес СНАРУЖИ функции: " << &array1 << endl;
    
    array<int, SIZE> sorted1 = sortHalfAscHalfDescByValue(array1);
    
    printArray(array1, "Оригинальный массив после функции: ");
    printArray(sorted1, "Возвращенный отсортированный массив: ");
    cout << "Адрес возвращенного массива: " << &sorted1 << endl;
// Показываем половины
    cout << "Первая половина (возрастание): ";
    for (int i = 0; i < SIZE / 2; i++) {
        cout << sorted1[i] << " ";
    }
    cout << endl;
    cout << "Вторая половина (убывание): ";
    for (int i = SIZE / 2; i < SIZE; i++) {
        cout << sorted1[i] << " ";
    }
    cout << endl << endl;

    // ТЕСТ 2: Передача по ссылке
    cout << "2. ПЕРЕДАЧА ПО ССЫЛКЕ:" << endl;
    cout << "=========================================" << endl;
    
    array<int, SIZE> array2 = originalArray;
    printArray(array2, "Исходный массив: ");
    cout << "Адрес СНАРУЖИ функции: " << &array2 << endl;
    
    sortHalfAscHalfDescByReference(array2);
    
    printArray(array2, "Массив после функции: ");
    
    cout << "Первая половина (возрастание): ";
    for (int i = 0; i < SIZE / 2; i++) {
        cout << array2[i] << " ";
    }
    cout << endl;
    cout << "Вторая половина (убывание): ";
    for (int i = SIZE / 2; i < SIZE; i++) {
        cout << array2[i] << " ";
    }
    cout << endl << endl;

    // ТЕСТ 3: Передача по указателю
    cout << "3. ПЕРЕДАЧА ПО УКАЗАТЕЛЮ:" << endl;
    cout << "=========================================" << endl;
    
    array<int, SIZE> array3 = originalArray;
    printArray(array3, "Исходный массив: ");
    cout << "Адрес СНАРУЖИ функции: " << &array3 << endl;
    
    sortHalfAscHalfDescByPointer(&array3);
    
    printArray(array3, "Массив после функции: ");
    
    cout << "Первая половина (возрастание): ";
    for (int i = 0; i < SIZE / 2; i++) {
        cout << array3[i] << " ";
    }
    cout << endl;
    cout << "Вторая половина (убывание): ";
    for (int i = SIZE / 2; i < SIZE; i++) {
        cout << array3[i] << " ";
    }
    cout << endl;

}



// ===== ГЛАВНОЕ МЕНЮ =====


void showVectorMenu() {
    vector<int> arr;
    int choice;

    do {
        cout << "\n=== WORKING WITH VECTOR (PART 1) ===\n";
        cout << "0. Exit to main menu\n";
        cout << "1. View array\n";
        cout << "2. Add element to beginning\n";
        cout << "3. Add element to end\n";
        cout << "4. Clear entire array\n";
        cout << "5. Search element in array\n";
        cout << "6. Variant task (variant 5 - to end)\n";
        cout << "Select action (0-6): ";
        cin >> choice;

        switch (choice) {
            case 0:
                cout << "Return to main menu." << endl;
                break;
            case 1:
                cout << "Current array: ";
                printArray(arr);
                break;
            case 2: {
                int value;
                cout << "Enter value to add to beginning: ";
                cin >> value;
                addToBegin(arr, value);
                cout << "Element added to beginning." << endl;
                break;
            }
            case 3: {
                int value;
                cout << "Enter value to add to end: ";
                cin >> value;
                addToEnd(arr, value);
                cout << "Element added to end." << endl;
                break;
            }
            case 4:
                clearArray(arr);
                cout << "Array cleared." << endl;
                break;
            case 5: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                vector<size_t> indices = findElement(arr, value);
                cout << "Indices of found elements: ";
                printIndices(indices);
                break;
            }
            case 6:
                processVariant5(arr);
                break;
            default:
                cout << "Invalid choice. Try again."<< endl;
        }
    } while (choice != 0);
}




int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int mainChoice;

    do {
        cout << "\n=== MAIN MENU ===\n";
        cout << "1. Part 1 - working with vector\n";
        cout << "2. Part 2 - working with array\n";
        cout << "0. Exit program\n";
        cout << "Select section: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                showVectorMenu();
                break;
            case 2:
                ShowArrayMenu();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (mainChoice != 0);

    return 0;
}
