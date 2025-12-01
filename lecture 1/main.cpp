#pragma execution_character_set("utf-8")

#include <iostream>
#include <vector>
#include <array>
#include <random>
#include <cmath>
#include <cstdlib> 
#include <ctime>
#include <locale>
#include <limits>
#include <windows.h>

using namespace std;

// ===== ПУНКТ 1: РАБОТА С VECTOR =====

void printArray(const vector<int>& arr) {
    if (arr.empty()) {
        cout << "[] (пусто)" << endl;
        return;
    }
    
    cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i];
        if (i < arr.size() - 1) cout << " ";
    }
    cout << "]" << endl;
}

void addToBegin(vector<int>& arr, int value) {
    arr.insert(arr.begin(), value);
}

void addToEnd(vector<int>& arr, int value) {
    arr.push_back(value);
}

void clearArray(vector<int>& arr) {
    arr.clear();
}

vector<size_t> findElement(const vector<int>& arr, int value) {
    vector<size_t> indices;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == value) {
            indices.push_back(i);
        }
    }
    return indices;
}

void printIndices(const vector<size_t>& indices) {
    if (indices.empty()) {
        cout << "[] (не найдено)" << endl;
        return;
    }
    
    cout << "[";
    for (size_t i = 0; i < indices.size(); ++i) {
        cout << indices[i];
        if (i < indices.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

bool isTriangularNumber(int K) {
    if (K <= 0) return false;
    
    long long discriminant = 1 + 8LL * static_cast<long long>(K);
    if (discriminant < 0) return false;
    
    long long sqrt_discriminant = static_cast<long long>(sqrt(static_cast<double>(discriminant)));
    
    if (sqrt_discriminant * sqrt_discriminant != discriminant) {
        return false;
    }
    
    return (sqrt_discriminant - 1) % 2 == 0 && (sqrt_discriminant - 1) / 2 > 0;
}

vector<int> getTriangularTerms(int K) {
    vector<int> terms;
    int n = static_cast<int>((sqrt(1.0 + 8.0 * static_cast<double>(K)) - 1.0) / 2.0);
    
    for (int i = 1; i <= n; ++i) {
        terms.push_back(i);
    }
    
    return terms;
}

void processVariant5(vector<int>& arr) {
    if (arr.empty()) {
        cout << "Массив пуст! Пожалуйста, добавьте элементы сначала." << endl;
        return;
    }
    
    int K;
    cout << "Введите положительное число K: ";
    
    if (!(cin >> K)) {
        cout << "Неверный ввод! Пожалуйста, введите число." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (K <= 0) {
        cout << "K должно быть положительным!" << endl;
        return;
    }

    cout << "\nМассив до обработки: ";
    printArray(arr);

    if (isTriangularNumber(K)) {
        cout << "\nЧисло " << K << " можно представить в виде суммы 1+2+3+..." << endl;
        
        vector<int> terms = getTriangularTerms(K);
        
        cout << "Разложение: ";
        for (size_t i = 0; i < terms.size(); ++i) {
            cout << terms[i];
            if (i < terms.size() - 1) cout << "+";
        }
        cout << " = " << K << endl;

        cout << "Добавляем слагаемые в конец массива..." << endl;
        arr.insert(arr.end(), terms.begin(), terms.end());
        
        cout << "Массив после добавления: ";
        printArray(arr);
    } else {
        cout << "\nЧисло " << K << " НЕЛЬЗЯ представить в виде суммы 1+2+3+..." << endl;
        cout << "Дублируем элементы на четных позициях (индексы 0, 2, 4, ...)..." << endl;
        
        vector<int> newArr;
        for (size_t i = 0; i < arr.size(); ++i) {
            newArr.push_back(arr[i]);
            if (i % 2 == 0) {
                newArr.push_back(arr[i]);
            }
        }
        
        arr = newArr;
        cout << "Массив после дублирования: ";
        printArray(arr);
    }
}

// ===== ПУНКТ 2: РАБОТА С ARRAY =====

const int ARRAY_SIZE = 10;  // Изменили имя с SIZE на ARRAY_SIZE

array<int, ARRAY_SIZE> generateRandomArray(int min, int max) {
    array<int, ARRAY_SIZE> arr;
    
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

void printArray(const array<int, ARRAY_SIZE>& arr, const string& message = "") {
    if (!message.empty()) cout << message;
    cout << "[";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i];
        if (i < ARRAY_SIZE - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// Исправленные функции сортировки - изменили имена параметров
void bubbleSortAsc(array<int, ARRAY_SIZE>& arr, int start_idx, int end_idx) {
    for (int i = start_idx; i < end_idx - 1; i++) {
        int iterations = end_idx - 1 - (i - start_idx);
        for (int j = start_idx; j < iterations; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void bubbleSortDesc(array<int, ARRAY_SIZE>& arr, int start_idx, int end_idx) {
    for (int i = start_idx; i < end_idx - 1; i++) {
        int iterations = end_idx - 1 - (i - start_idx);
        for (int j = start_idx; j < iterations; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

array<int, ARRAY_SIZE> sortHalfAscHalfDescByValue(array<int, ARRAY_SIZE> arr) {
    cout << "Адрес ВНУТРИ функции (по значению): " << &arr << endl;
    
    int mid = ARRAY_SIZE / 2;
    bubbleSortAsc(arr, 0, mid);
    bubbleSortDesc(arr, mid, ARRAY_SIZE);
    
    return arr;
}

void sortHalfAscHalfDescByReference(array<int, ARRAY_SIZE>& arr) {
    cout << "Адрес ВНУТРИ функции (по ссылке): " << &arr << endl;
    
    int mid = ARRAY_SIZE / 2;
    bubbleSortAsc(arr, 0, mid);
    bubbleSortDesc(arr, mid, ARRAY_SIZE);
}

void sortHalfAscHalfDescByPointer(array<int, ARRAY_SIZE>* arr) {
    if (arr == nullptr) return;
    
    cout << "Адрес ВНУТРИ функции (по указателю): " << arr << endl;
    
    int mid = ARRAY_SIZE / 2;
    bubbleSortAsc(*arr, 0, mid);
    bubbleSortDesc(*arr, mid, ARRAY_SIZE);
}

void ShowArrayMenu() {
    array<int, ARRAY_SIZE> originalArray = generateRandomArray(-10, 10);
    
    cout << "\n=== РАЗДЕЛЬНАЯ СОРТИРОВКА ПОЛОВИН МАССИВА ===" << endl;
    cout << "Первая половина - по возрастанию, вторая - по убыванию" << endl;
    cout << "Используется пузырьковая сортировка" << endl;
    cout << "Размер массива: " << ARRAY_SIZE << " элементов" << endl;
    cout << "Диапазон значений: [-10; 10]" << endl << endl;

    // ТЕСТ 1: Передача по значению
    cout << "1. ПЕРЕДАЧА ПО ЗНАЧЕНИЮ:" << endl;
    cout << "=========================================" << endl;
    cout << "Создается копия массива. Оригинальный массив не изменяется." << endl;
    cout << "Функция возвращает новый отсортированный массив." << endl;
    
    array<int, ARRAY_SIZE> array1 = originalArray;
    printArray(array1, "Исходный массив: ");
    cout << "Адрес ВНЕ функции: " << &array1 << endl;
    
    array<int, ARRAY_SIZE> sorted1 = sortHalfAscHalfDescByValue(array1);
    
    printArray(array1, "Оригинальный массив после функции: ");
    printArray(sorted1, "Возвращенный отсортированный массив: ");
    cout << "Адрес возвращенного массива: " << &sorted1 << endl;
    
    cout << "Первая половина (возрастание): [";
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        cout << sorted1[i];
        if (i < ARRAY_SIZE / 2 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << "Вторая половина (убывание): [";
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        cout << sorted1[i];
        if (i < ARRAY_SIZE - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // ТЕСТ 2: Передача по ссылке
    cout << "2. ПЕРЕДАЧА ПО ССЫЛКЕ:" << endl;
    cout << "=========================================" << endl;
    cout << "Работает напрямую с оригинальным массивом. Изменяет его." << endl;
    cout << "Более эффективно для больших массивов (нет копирования)." << endl;
    
    array<int, ARRAY_SIZE> array2 = originalArray;
    printArray(array2, "Исходный массив: ");
    cout << "Адрес ВНЕ функции: " << &array2 << endl;
    
    sortHalfAscHalfDescByReference(array2);
    
    printArray(array2, "Массив после функции: ");
    
    cout << "Первая половина (возрастание): [";
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        cout << array2[i];
        if (i < ARRAY_SIZE / 2 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << "Вторая половина (убывание): [";
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        cout << array2[i];
        if (i < ARRAY_SIZE - 1) cout << ", ";
    }
    cout << "]" << endl << endl;

    // ТЕСТ 3: Передача по указателю
    cout << "3. ПЕРЕДАЧА ПО УКАЗАТЕЛЮ:" << endl;
    cout << "=========================================" << endl;
    cout << "Аналогично передаче по ссылке, но использует синтаксис указателей." << endl;
    cout << "Позволяет проверять на nullptr." << endl;
    
    array<int, ARRAY_SIZE> array3 = originalArray;
    printArray(array3, "Исходный массив: ");
    cout << "Адрес ВНЕ функции: " << &array3 << endl;
    
    sortHalfAscHalfDescByPointer(&array3);
    
    printArray(array3, "Массив после функции: ");
    
    cout << "Первая половина (возрастание): [";
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        cout << array3[i];
        if (i < ARRAY_SIZE / 2 - 1) cout << ", ";
    }
    cout << "]" << endl;
    
    cout << "Вторая половина (убывание): [";
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        cout << array3[i];
        if (i < ARRAY_SIZE - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void showExplanation() {
    cout << "\n=== ПУНКТ 3: ОБЪЯСНЕНИЕ ВЫБОРА РЕАЛИЗАЦИИ ===" << endl;
    cout << "==============================================" << endl;
    
    cout << "\n1. ПОЧЕМУ VECTOR В ПУНКТЕ 1?" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "✓ Динамический размер: может изменяться во время выполнения" << endl;
    cout << "✓ Необходимые операции: вставка в начало, добавление в конец, очистка" << endl;
    cout << "✓ Неизвестен конечный размер на этапе компиляции" << endl;
    cout << "✓ Задание варианта требует добавления переменного числа слагаемых" << endl;
    cout << "✓ Управление памятью происходит автоматически" << endl;
    
    cout << "\n2. ПОЧЕМУ ARRAY В ПУНКТЕ 2?" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "✓ Фиксированный размер: ровно 10 элементов как требуется" << endl;
    cout << "✓ Лучшая производительность для операций с фиксированным размером" << endl;
    cout << "✓ Демонстрирует размерование в стеке (быстрее кучи)" << endl;
    cout << "✓ Показывает разницу между передачей по значению/ссылке/указателю" << endl;
    cout << "✓ Проверка размера на этапе компиляции" << endl;
    
    cout << "\n3. КОГДА ОНИ ВЗАИМОЗАМЕНЯЕМЫ?" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "✓ Когда размер известен на этапе компиляции И не изменяется" << endl;
    cout << "✓ Когда критически важна максимальная производительность" << endl;
    cout << "✓ При работе с устаревшим кодом или библиотеками на C" << endl;
    
    cout << "\n4. КЛЮЧЕВЫЕ РАЗЛИЧИЯ:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "VECTOR:                                 ARRAY:" << endl;
    cout << "- Динамический размер                  - Фиксированный размер" << endl;
    cout << "- Выделение в куче                    - Выделение в стеке" << endl;
    cout << "- Можно изменять размер               - Нельзя изменять размер" << endl;
    cout << "- Немного медленнее                   - Немного быстрее" << endl;
    cout << "- Более гибкий                        - Более предсказуемый" << endl;
    
    cout << "\n5. ВЫВОД И ВЫБОР:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "Выбор между vector и array зависит от требований задачи:" << endl;
    cout << "- Используйте vector, когда размер изменяется или неизвестен заранее" << endl;
    cout << "- Используйте array, когда размер фиксирован и известен на этапе компиляции" << endl;
    cout << "- В данной работе выбор был обусловлен спецификой каждого пункта:" << endl;
    cout << "  * Пункт 1 требует динамических операций → vector" << endl;
    cout << "  * Пункт 2 работает с фиксированным массивом → array" << endl;
}

void showVectorMenu() {
    vector<int> arr;
    int choice;

    do {
        cout << "\n=== РАБОТА С VECTOR (ПУНКТ 1) ===" << endl;
        cout << "Текущий массив: ";
        printArray(arr);
        cout << "Размер: " << arr.size() << " элементов" << endl;
        cout << "0. Выход в главное меню" << endl;
        cout << "1. Просмотр массива" << endl;
        cout << "2. Добавить элемент в начало" << endl;
        cout << "3. Добавить элемент в конец" << endl;
        cout << "4. Очистить весь массив" << endl;
        cout << "5. Поиск элемента в массиве" << endl;
        cout << "6. Задание варианта (вариант 5)" << endl;
        cout << "Выберите действие (0-6): ";
        
        if (!(cin >> choice)) {
            cout << "Неверный ввод! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 0:
                cout << "Возврат в главное меню." << endl;
                break;
            case 1:
                cout << "Текущий массив: ";
                printArray(arr);
                break;
            case 2: {
                int value;
                cout << "Введите значение для добавления в начало: ";
                if (!(cin >> value)) {
                    cout << "Неверный ввод!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                addToBegin(arr, value);
                cout << "Элемент добавлен в начало." << endl;
                cout << "Массив: ";
                printArray(arr);
                break;
            }
            case 3: {
                int value;
                cout << "Введите значение для добавления в конец: ";
                if (!(cin >> value)) {
                    cout << "Неверный ввод!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                addToEnd(arr, value);
                cout << "Элемент добавлен в конец." << endl;
                cout << "Массив: ";
                printArray(arr);
                break;
            }
            case 4:
                clearArray(arr);
                cout << "Массив очищен." << endl;
                break;
            case 5: {
                if (arr.empty()) {
                    cout << "Массив пуст. Нечего искать." << endl;
                    break;
                }
                int value;
                cout << "Введите значение для поиска: ";
                if (!(cin >> value)) {
                    cout << "Неверный ввод!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                vector<size_t> indices = findElement(arr, value);
                cout << "Индексы найденных элементов: ";
                printIndices(indices);
                break;
            }
            case 6:
                processVariant5(arr);
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);
}

int main() {
    // Установка кодировки для Windows
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    
    int mainChoice;

    do {
        cout << "\n=== ГЛАВНОЕ МЕНЮ ===" << endl;
        cout << "1. Пункт 1 - работа с vector" << endl;
        cout << "2. Пункт 2 - работа с array" << endl;
        cout << "3. Пункт 3 - объяснение выбора реализации" << endl;
        cout << "0. Выход из программы" << endl;
        cout << "Выберите раздел: ";
        
        if (!(cin >> mainChoice)) {
            cout << "Неверный ввод! Пожалуйста, введите число." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (mainChoice) {
            case 1:
                showVectorMenu();
                break;
            case 2:
                ShowArrayMenu();
                break;
            case 3:
                showExplanation();
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (mainChoice != 0);

    return 0;
}
