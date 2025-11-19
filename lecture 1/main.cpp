#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>

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

// Вариант 5: разбить K на сумму 1+2+3+...=K и добавить слагаемые в конец
void processVariant5(vector<int>& arr) {
    int K;
    cout << "Enter a positive number K: ";
    cin >> K;

    if (K <= 0) {
        cout << "K must be positive!" << endl;
        return;
    }

    vector<int> terms;
    int sum = 0;
    int n = 1;

    // Находим последовательность 1+2+3+... пока сумма <= K
    while (sum + n <= K) {
        terms.push_back(n);
        sum += n;
        ++n;
    }

    // Если сумма равна K, добавляем слагаемые
    if (sum == K) {
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
    } else {
        cout << "Number " << K << " cannot be represented as sum 1+2+3+..." << endl;
    }
}


 

// ===== ПУНКТ 2: РАБОТА С ARRAY =====

const size_t ARRAY_SIZE = 10;

// Функция удаления чётных чисел (передача по значению)
array<int, ARRAY_SIZE> removeEvenByValue(array<int, ARRAY_SIZE> arr) {
    array<int, ARRAY_SIZE> result = {};
    size_t index = 0;

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] % 2 != 0) { //нечётное число
            result[index] = arr[i];
            index++;
        }
    }

    // Заполняем оставшиеся элементы нулями
    while (index < ARRAY_SIZE) {
        result[index] = 0;
        index++;
    }

    cout << "In function (by value): ";
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (result[i] != 0) cout << result[i] << " ";
    }
    cout << endl;

    return result;
}

// Функция удаления чётных чисел (передача по ссылке)
void removeEvenByReference(array<int, ARRAY_SIZE>& arr) {
    size_t writeIndex = 0;

    for (size_t readIndex = 0; readIndex < ARRAY_SIZE; ++readIndex) {
        if (arr[readIndex] % 2 != 0) { // нечётное число
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    // Заполняем оставшиеся элементы нулями
    while (writeIndex < ARRAY_SIZE) {
        arr[writeIndex] = 0;
        writeIndex++;
    }

    cout << "In function (by reference): ";
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] != 0) cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция удаления чётных чисел (передача по указателю)
void removeEvenByPointer(array<int, ARRAY_SIZE>* arrPtr) {
    size_t writeIndex = 0;

    for (size_t readIndex = 0; readIndex < ARRAY_SIZE; ++readIndex) {
        if ((*arrPtr)[readIndex] % 2 != 0) { // нечётное число
            (*arrPtr)[writeIndex] = (*arrPtr)[readIndex];
            writeIndex++;
        }
    }

    // Заполняем оставшиеся элементы нулями
    while (writeIndex < ARRAY_SIZE) {
        (*arrPtr)[writeIndex] = 0;
        writeIndex++;
    }

    cout << "In function (by pointer): ";
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if ((*arrPtr)[i] != 0) cout << (*arrPtr)[i] << " ";
    }
    cout << endl;
}

// Функция вывода array
void printStdArray(const array<int, ARRAY_SIZE>& arr) {
    cout << "[";
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        cout << arr[i];
        if (i < ARRAY_SIZE - 1) cout << " ";
    }
    cout << "]" << endl;
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

void showArrayMenu() {
    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-10, 10);

    // Создание и заполнение массива случайными числами
    array<int, ARRAY_SIZE> myArray;
    
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }

    cout << "Original array: ";
    printStdArray(myArray);

    // Демонстрация передачи по значению
    cout << "\n--- Passing by VALUE ---" << endl;
    cout << "Original array before call: ";
    printStdArray(myArray);
    array<int, ARRAY_SIZE> resultByValue = removeEvenByValue(myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);
    cout << "Function result: ";
    printStdArray(resultByValue);

    // Восстанавливаем массив для следующего теста
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }
    cout << "\nRestored array: ";
    printStdArray(myArray);

    // Демонстрация передачи по ссылке
    cout << "\n--- Passing by REFERENCE ---" << endl;
    cout << "Original array before call: ";
    printStdArray(myArray);
    removeEvenByReference(myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);

    // Восстанавливаем массив для следующего теста
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }
    cout << "\nRestored array: ";
    printStdArray(myArray);

    // Демонстрация передачи по указателю
    cout << "\n--- Passing by POINTER ---" << endl;
    cout << "Original array before call: ";
    printStdArray(myArray);
    removeEvenByPointer(&myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);
}

int main() {
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
                showArrayMenu();
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
#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>

using namespace std;

// Функция проверки треугольного числа
bool isTriangularNumber(long long K) {
    if (K <= 0) return false;

    long long calc_num = 8 * K + 1;
    long long t = static_cast<long long>(sqrt(calc_num));

    return t * t == calc_num;
}

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

// Вариант 5: разбить K на сумму 1+2+3+...=K и добавить слагаемые в конец
void processVariant5(vector<int>& arr) {
    int K;
    cout << "Enter a positive number K: ";
    cin >> K;

    if (K <= 0) {
        cout << "K must be positive!" << endl;
        return;
    }

    // Сначала проверяем, является ли число треугольным
    if (!isTriangularNumber(K)) {
        cout << "Number " << K << " is not triangular!" << endl;
        return;
    }

    vector<int> terms;
    int sum = 0;
    int n = 1;

    // Находим последовательность 1+2+3+... пока сумма <= K
    while (sum + n <= K) {
        terms.push_back(n);
        sum += n;
        ++n;
    }

    // Если сумма равна K, добавляем слагаемые
    if (sum == K) {
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
    else {
        cout << "Number " << K << " cannot be represented as sum 1+2+3+..." << endl;
    }
}




// ===== ПУНКТ 2: РАБОТА С ARRAY =====

const size_t ARRAY_SIZE = 10;

/// Функция вывода array с учётом реального размера
void printStdArray(const array<int, ARRAY_SIZE>& arr) {
    cout << "[";
    bool first = true;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] % 2 != 0) { // выводим только нечётные числа
            if (!first) {
                cout << " ";
            }
            cout << arr[i];
            first = false;
        }
    }
    cout << "]" << endl;
}

// Функция удаления чётных чисел (передача по значению)
array<int, ARRAY_SIZE> removeEvenByValue(array<int, ARRAY_SIZE> arr) {
    array<int, ARRAY_SIZE> result = {};
    size_t index = 0;

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] % 2 != 0) { // нечётное число
            result[index] = arr[i];
            index++;
        }
    }

    // Заполняем оставшиеся элементы нулями для корректного отображения
    for (size_t i = index; i < ARRAY_SIZE; ++i) {
        result[i] = 0;
    }

    return result;
}

// Функция удаления чётных чисел (передача по ссылке)
void removeEvenByReference(array<int, ARRAY_SIZE>& arr) {
    size_t writeIndex = 0;

    for (size_t readIndex = 0; readIndex < ARRAY_SIZE; ++readIndex) {
        if (arr[readIndex] % 2 != 0) { // нечётное число
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    // Заполняем оставшиеся элементы нулями для корректного отображения
    for (size_t i = writeIndex; i < ARRAY_SIZE; ++i) {
        arr[i] = 0;
    }
}

// Функция удаления чётных чисел (передача по указателю)
void removeEvenByPointer(array<int, ARRAY_SIZE>* arrPtr) {
    size_t writeIndex = 0;

    for (size_t readIndex = 0; readIndex < ARRAY_SIZE; ++readIndex) {
        if ((*arrPtr)[readIndex] % 2 != 0) { // нечётное число
            (*arrPtr)[writeIndex] = (*arrPtr)[readIndex];
            writeIndex++;
        }
    }

    // Заполняем оставшиеся элементы нулями для корректного отображения
    for (size_t i = writeIndex; i < ARRAY_SIZE; ++i) {
        (*arrPtr)[i] = 0;
    }
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
            cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);
}

void showArrayMenu() {
    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(-10, 10);

    // Создание и заполнение массива случайными числами
    array<int, ARRAY_SIZE> myArray;

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }

    cout << "Original array: ";
    printStdArray(myArray);

    // Демонстрация передачи по значению
    cout << "\n--- Passing by VALUE ---" << endl;
    cout << "Original array before call: ";
    printStdArray(myArray);
    array<int, ARRAY_SIZE> resultByValue = removeEvenByValue(myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);
    cout << "Function result: ";
    printStdArray(resultByValue);

    // Восстанавливаем массив для следующего теста
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }
    cout << "\nRestored array: ";
    printStdArray(myArray);

    // Демонстрация передачи по ссылке
    cout << "\n--- Passing by REFERENCE ---" << endl;
    cout << "Original array before call: ";
    printStdArray(myArray);
    removeEvenByReference(myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);

    // Восстанавливаем массив для следующего теста
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }
    cout << "\nRestored array: ";
    printStdArray(myArray);

    // Демонстрация передачи по указателю
    cout << "\n--- Passing by POINTER ---" << endl;
    cout << "Original array before call: ";
    printStdArray(myArray);
    removeEvenByPointer(&myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);
}

int main() {
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
            showArrayMenu();
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






        







