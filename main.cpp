#include <iostream>
#include <algorithm>

void reverse_array(int arr[], size_t start, size_t end) {
    while (start < end) {
        int temp{arr[start]};
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void fill_array_from_string(int *array, const std::string &string) {
    for (size_t i{}; i < string.size(); ++i) {
        array[i] = static_cast<int>(static_cast<unsigned>(string.at(i))) - 48;
    }
}

void
array_addition(const int *first_array, const size_t &first_size, const int *second_array, const size_t &second_size,
               int **sum_array) {
    int *resized_array{nullptr};
    if (first_size < second_size) {
        resized_array = new int[second_size]{};
        for (size_t i{}; i < first_size; ++i) {
            resized_array[i] = first_array[i];
            first_array = resized_array;
        }
    } else if (second_size < first_size) {
        resized_array = new int[first_size]{};
        for (size_t i{}; i < second_size; ++i) {
            resized_array[i] = second_array[i];
            second_array = resized_array;
        }
    }

    // Print the arrays for debug purposes
    std::cout << std::endl;
    for (size_t i{}; i < first_size; ++i) {
        std::cout << first_array[i];
    }
    std::cout << std::endl;
    for (size_t i{}; i < second_size; ++i) {
        std::cout << second_array[i];
    }

    std::string result;
    int carry{};
    for (size_t i{}; i < (first_size > second_size ? first_size : second_size) * 2; ++i) {
        int subtotal{(first_array[i]) + (second_array[i]) + carry};
        int subanswer{subtotal % 10};
        carry = subtotal / 10;
        result += (subanswer);
        std::cout << std::endl;
        std::cout << subtotal;
    }
    if (carry == 1)
        result += '1';

    sum_array = new int *[result.size()]{};
    for (size_t i{}; i < result.size(); ++i) {
        *sum_array[i] = static_cast<int>(static_cast<unsigned>(result.at(i))) - 48;
    }

    reverse_array(*sum_array, 0, result.size());
//    delete[] sum_array;
}


/**
 * EXAMPLE ALGORITH from INTERNET
 * @param num1 First string representing a number
 * @param num2 Second string representing a number
 * @return Resulting string number from addition algorithm
 */
std::string PaperPencilAlgorithm(std::string num1, std::string num2) {
    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());
    if (num1.size() < num2.size())
        num1.resize(num2.size(), '0');
    else if (num2.size() < num1.size())
        num2.resize(num1.size(), '0');
    std::string result;

    int carry = 0;
    for (size_t i = 0; i < num1.size(); ++i) {
        int subtotal = (num1[i] - '0') + (num2[i] - '0') + carry;
        int subanswer = subtotal % 10;
        carry = subtotal / 10;
        result += (subanswer + '0');
    }
    if (carry == 1)
        result += '1';
    std::reverse(result.begin(), result.end());
    return result;
}

/**
 * Displays prompts and output (taken from internet)
 */
void Display() {
    std::cout << "Paper and Pencil Algorithm Addition" << std::endl;
    std::string num1, num2;
    std::cout << "Enter num 1: " << std::endl;
    std::cin >> num1;
    std::cout << "Enter num 2: " << std::endl;
    std::cin >> num2;
    std::cout << "Addition is : " + PaperPencilAlgorithm(num1, num2) << std::endl;
//    system("pause");
//    system("CLS");

    std::cout << "Want to add 2 more numbers? (Y/n)" << std::endl;
    char c;
    std::cin >> c;

    if (c == 'Y') {
//        system("CLS");
        Display();
    }
}

int main() {

    std::string entered_number;
    std::cout << "Enter a number: ";
    std::cin >> entered_number;

    size_t first_size{entered_number.size()};
    int *first_array{new int[entered_number.size()]{}};
    fill_array_from_string(first_array, entered_number);

    std::cout << std::endl;
    std::cout << "Enter a second number: ";
    std::cin >> entered_number;

//    Display();

    size_t second_size{entered_number.size()};
    int *second_array{new int[entered_number.size()]{}};
    fill_array_from_string(second_array, entered_number);

    // Print the arrays for debug purposes
    for (size_t i{}; i < first_size; ++i) {
        std::cout << first_array[i];
    }
    std::cout << std::endl;
    for (size_t i{}; i < second_size; ++i) {
        std::cout << second_array[i];
    }

    int *sum_array{};
    reverse_array(first_array, 0, first_size - 1);
    reverse_array(second_array, 0, second_size - 1);
    array_addition(first_array, first_size, second_array, second_size, &sum_array);

    delete[] first_array;
    delete[] second_array;

    return 0;
}
