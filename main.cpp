#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Function prototypes
void task1();
void task2();
void task3();
void task4();
void print3DArray(double*** arr, int depth, int rows, int cols);

int main() {
    // Initialize random seed
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    int choice;
    do {
        std::cout << "\n================ PRACTICAL WORK 16 ================\n";
        std::cout << "1 - Task 1: Dynamic memory for primitive types\n";
        std::cout << "2 - Task 2: Reference to double via pointer\n";
        std::cout << "3 - Task 3: 1D dynamic array (reverse indices)\n";
        std::cout << "4 - Task 4: 3D dynamic array (random float)\n";
        std::cout << "0 - Exit\n";
        std::cout << "Choose task: ";
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
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

// === TASK 1 ===
void task1() {
    std::cout << "[Task 1] Memory allocation for primitive types\n";
    
    // Allocating memory
    int* pInt = new int;
    char* pChar = new char;
    float* pFloat = new float;
    bool* pBool = new bool;

    // Input data
    std::cout << "Enter an integer (int): ";
    std::cin >> *pInt;
    std::cout << "Enter a character (char): ";
    std::cin >> *pChar;
    std::cout << "Enter a float number (float): ";
    std::cin >> *pFloat;
    std::cout << "Enter a boolean (0 - false, 1 - true): ";
    std::cin >> *pBool;

    // Output data
    std::cout << "\nValues from dynamic memory:\n";
    std::cout << "int: " << *pInt << "\n";
    std::cout << "char: " << *pChar << "\n";
    std::cout << "float: " << *pFloat << "\n";
    std::cout << "bool: " << std::boolalpha << *pBool << "\n";

    // Free memory
    delete pInt;
    delete pChar;
    delete pFloat;
    delete pBool;
    
    std::cout << "Memory successfully freed.\n";
}

// === TASK 2 ===
void task2() {
    std::cout << "[Task 2] Reference to double via pointer\n";
    
    // Allocate memory for double
    double* pDouble = new double;
    
    // Create reference linked to dereferenced pointer
    double& refDouble = *pDouble;

    // Input via reference
    std::cout << "Enter double value via reference: ";
    std::cin >> refDouble;

    // Output via reference
    std::cout << "Value via reference: " << refDouble << "\n";

    // Delete memory via original pointer
    delete pDouble;
    
    std::cout << "Memory successfully freed.\n";
}

// === TASK 3 ===
void task3() {
    std::cout << "[Task 3] Dynamic 1D integer array\n";
    
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Array size must be greater than 0!\n";
        return;
    }

    // Allocate 1D array
    int* arr = new int[size];

    // Fill array with indices in reverse order
    for (int i = 0; i < size; i++) {
        arr[i] = size - 1 - i;
    }

    // Print array in a separate loop
    std::cout << "Array elements (reverse indices):\n";
    for (int i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << "\n";
    }

    // Delete dynamic array
    delete[] arr;
    
    std::cout << "Dynamic array deleted from memory.\n";
}

// === TASK 4 ===
void task4() {
    std::cout << "[Task 4] Dynamic 3D array of floats\n";
    
    int depth = 2, rows = 3, cols = 3; // Fixed small sizes for clean output
    std::cout << "Creating 3D array of size " << depth << "x" << rows << "x" << cols << "\n";

    // 1. Memory allocation for 3D array
    double*** array3D = new double**[depth];
    for (int i = 0; i < depth; i++) {
        array3D[i] = new double*[rows];
        for (int j = 0; j < rows; j++) {
            array3D[i][j] = new double[cols];
        }
    }

    // 2. Fill with random floats (from 0.0 to 99.9)
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                array3D[i][j][k] = (rand() % 1000) / 10.0;
            }
        }
    }

    // 3. Call print function
    std::cout << "\nCalling function to display 3D array:\n";
    print3DArray(array3D, depth, rows, cols);

    // 4. Delete 3D array from memory (reverse order)
    for (int i = 0; i < depth; i++) {
        for (int j = 0; j < rows; j++) {
            delete[] array3D[i][j]; // Delete columns
        }
        delete[] array3D[i]; // Delete rows
    }
    delete[] array3D; // Delete depth

    std::cout << "3D array successfully deleted from memory.\n";
}

// Separate function to print 3D array
void print3DArray(double*** arr, int depth, int rows, int cols) {
    for (int i = 0; i < depth; i++) {
        std::cout << "Block (Layer) " << i << ":\n";
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                std::cout << arr[i][j][k] << "\t";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}
