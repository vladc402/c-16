#include <iostream>
#include <cstdlib> // Для функцій rand() та srand()
#include <ctime>   // Для функції time()

// Прототипи функцій для завдань
void task1();
void task2();
void task3();
void task4();
void print3DArray(double*** arr, int depth, int rows, int cols);

int main() {
    // Ініціалізація генератора випадкових чисел поточним часом
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    int choice;
    do {
        std::cout << "\n================ PRACTICAL WORK 16 ================\n";
        std::cout << "1 - Завдання 1: Динамічна пам'ять для примітивних типів\n";
        std::cout << "2 - Завдання 2: Посилання на double через вказівник\n";
        std::cout << "3 - Завдання 3: Одновимірний динамічний масив (зворотні індекси)\n";
        std::cout << "4 - Завдання 4: Тривимірний динамічний масив\n";
        std::cout << "0 - Вихід з програми\n";
        std::cout << "Оберіть завдання: ";
        std::cin >> choice;
        std::cout << "---------------------------------------------------\n";

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 0:
                std::cout << "Вихід з програми. До побачення!\n";
                break;
            default:
                std::cout << "Невірний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}

// === ЗАВДАННЯ 1 ===
void task1() {
    std::cout << "[Завдання 1] Виділення пам'яті для примітивних типів\n";
    
    // Виділяємо пам'ять
    int* pInt = new int;
    char* pChar = new char;
    float* pFloat = new float;
    bool* pBool = new bool;

    // Введення даних
    std::cout << "Введіть ціле число (int): ";
    std::cin >> *pInt;
    std::cout << "Введіть символ (char): ";
    std::cin >> *pChar;
    std::cout << "Введіть число з плаваючою крапкою (float): ";
    std::cin >> *pFloat;
    std::cout << "Введіть логічне значення (0 - false, 1 - true): ";
    std::cin >> *pBool;

    // Виведення даних
    std::cout << "\nВведені значення з динамічної пам'яті:\n";
    std::cout << "int: " << *pInt << "\n";
    std::cout << "char: " << *pChar << "\n";
    std::cout << "float: " << *pFloat << "\n";
    std::cout << "bool: " << std::boolalpha << *pBool << "\n";

    // Звільнення пам'яті
    delete pInt;
    delete pChar;
    delete pFloat;
    delete pBool;
    
    std::cout << "Пам'ять успішно звільнено.\n";
}

// === ЗАВДАННЯ 2 ===
void task2() {
    std::cout << "[Завдання 2] Посилання на double через вказівник\n";
    
    // Виділяємо пам'ять для double
    double* pDouble = new double;
    
    // Створюємо посилання, яке зв'язуємо з розіменованим вказівником
    double& refDouble = *pDouble;

    // Введення через посилання
    std::cout << "Введіть значення типу double через посилання: ";
    std::cin >> refDouble;

    // Виведення через посилання
    std::cout << "Значення змінної через посилання: " << refDouble << "\n";

    // Видалення пам'яті (через оригінальний вказівник)
    delete pDouble;
    
    std::cout << "Пам'ять успішно звільнено.\n";
}

// === ЗАВДАННЯ 3 ===
void task3() {
    std::cout << "[Завдання 3] Динамічний масив цілих чисел\n";
    
    int size;
    std::cout << "Введіть розмір масиву: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Розмір масиву має бути більшим за 0!\n";
        return;
    }

    // Створення динамічного масиву
    int* arr = new int[size];

    // Заповнення значеннями (індекси у зворотному порядку)
    for (int i = 0; i < size; i++) {
        arr[i] = size - 1 - i;
    }

    // Виведення масиву в окремому циклі
    std::cout << "Елементи масиву (зворотні індекси):\n";
    for (int i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    // Видалення динамічного масиву
    delete[] arr;
    
    std::cout << "Динамічний масив видалено з пам'яті.\n";
}

// === ЗАВДАННЯ 4 ===
void task4() {
    std::cout << "[Завдання 4] Тривимірний динамічний масив\n";
    
    int depth = 2, rows = 3, cols = 3; // Фіксовані невеликі розміри для зручності виведення
    std::cout << "Створення масиву розміром " << depth << "x" << rows << "x" << cols << "\n";

    // 1. Виділення пам'яті для 3D масиву
    double*** array3D = new double**[depth];
    for (int i = 0; i < depth; i++) {
        array3D[i] = new double*[rows];
        for (int j = 0; j < rows; j++) {
            array3D[i][j] = new double[cols];
        }
    }

    // 2. Заповнення випадковими числами з плаваючою крапкою (від 0.0 до 99.9)
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                array3D[i][j][k] = (rand() % 1000) / 10.0;
            }
        }
    }

    // 3. Виклик функції виведення масиву
    std::cout << "\nВиклик функції для виведення тривимірного масиву:\n";
    print3DArray(array3D, depth, rows, cols);

    // 4. Видалення масиву з пам'яті (у зворотному порядку)
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] array3D[i][j]; // Видаляємо рядки (стовпці)
        }
        delete[] array3D[i]; // Видаляємо матриці
    }
    delete[] array3D; // Видаляємо масив матриць

    std::cout << "Тривимірний масив повністю видалено з пам'яті.\n";
}

// Окрема функція для виведення 3D масиву
void print3DArray(double*** arr, int depth, int rows, int cols) {
    for (int i = 0; i < depth; i++) {
        std::cout << "Зріз (Блок) " << i << ":\n";
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                std::cout << arr[i][j][k] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
