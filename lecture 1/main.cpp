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

// ===== ПУНКТ 2: РАБОТА С ARRAY (БЕЗ VECTOR И СТРУКТУР) =====

const size_t ARRAY_SIZE = 10;

// Функция удаления чётных чисел (передача по значению) - возвращаем новый array
array<int, ARRAY_SIZE> removeEvenByValue(array<int, ARRAY_SIZE> arr) {
    array<int, ARRAY_SIZE> result = {};
    size_t resultIndex = 0;

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] % 2 != 0) { // нечётное число
            result[resultIndex] = arr[i];
            resultIndex++;
        }
    }

    cout << "In function (by value): ";
    for (size_t i = 0; i < resultIndex; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return result;
}

// Функция удаления чётных чисел (передача по ссылке) - возвращаем новый array
array<int, ARRAY_SIZE> removeEvenByReference(const array<int, ARRAY_SIZE>& arr) {
    array<int, ARRAY_SIZE> result = {};
    size_t resultIndex = 0;

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] % 2 != 0) { // нечётное число
            result[resultIndex] = arr[i];
            resultIndex++;
        }
    }

    cout << "In function (by reference): ";
    for (size_t i = 0; i < resultIndex; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return result;
}

// Функция удаления чётных чисел (передача по указателю) - возвращаем новый array
array<int, ARRAY_SIZE> removeEvenByPointer(const array<int, ARRAY_SIZE>* arrPtr) {
    array<int, ARRAY_SIZE> result = {};
    size_t resultIndex = 0;

    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if ((*arrPtr)[i] % 2 != 0) { // нечётное число
            result[resultIndex] = (*arrPtr)[i];
            resultIndex++;
        }
    }

    cout << "In function (by pointer): ";
    for (size_t i = 0; i < resultIndex; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return result;
}

// Функция in-place удаления чётных чисел (возвращает новый размер)
size_t removeEvenInPlace(array<int, ARRAY_SIZE>& arr) {
    size_t writeIndex = 0;

    for (size_t readIndex = 0; readIndex < ARRAY_SIZE; ++readIndex) {
        if (arr[readIndex] % 2 != 0) { // нечётное число
            arr[writeIndex] = arr[readIndex];
            writeIndex++;
        }
    }

    // Заполняем оставшиеся элементы специальным значением (например, 0)
    for (size_t i = writeIndex; i < ARRAY_SIZE; ++i) {
        arr[i] = 0;
    }

    return writeIndex; // возвращаем новый размер
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

// Функция вывода array только с значимыми элементами
void printStdArrayMeaningful(const array<int, ARRAY_SIZE>& arr) {
    cout << "[";
    bool first = true;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] != 0) { // считаем 0 как пустой элемент
            if (!first) cout << " ";
            cout << arr[i];
            first = false;
        }
    }
    cout << "]" << endl;
}

// Функция вывода array с указанием размера
void printStdArrayWithSize(const array<int, ARRAY_SIZE>& arr, size_t size) {
    cout << "[";
    for (size_t i = 0; i < size; ++i) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
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
    cout << "Function result (only meaningful elements): ";
    printStdArrayMeaningful(resultByValue);

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
    array<int, ARRAY_SIZE> resultByReference = removeEvenByReference(myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);
    cout << "Function result (only meaningful elements): ";
    printStdArrayMeaningful(resultByReference);

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
    array<int, ARRAY_SIZE> resultByPointer = removeEvenByPointer(&myArray);
    cout << "Original array after call: ";
    printStdArray(myArray);
    cout << "Function result (only meaningful elements): ";
    printStdArrayMeaningful(resultByPointer);

    // Демонстрация in-place удаления
    cout << "\n--- IN-PLACE removal ---" << endl;
    for (size_t i = 0; i < ARRAY_SIZE; ++i) {
        myArray[i] = dis(gen);
    }
    cout << "Original array: ";
    printStdArray(myArray);
    size_t newSize = removeEvenInPlace(myArray);
    cout << "Array after in-place removal: ";
    printStdArrayWithSize(myArray, newSize);
    cout << "New size: " << newSize << endl;
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




