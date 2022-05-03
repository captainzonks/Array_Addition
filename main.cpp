/////////////////////
// Matthew Barham
// 2022-05-02
///////////////////////////////////////////////////////////////////
// Array Adding
//
// Takes input of two large numbers from the user and creates arrays
// of integers representing both with each array value as a digit.
// Then adds the two arrays together to create a sum array before printing.
//
///////////////////////////////////////////////////////////////////

#include <iostream>
#include <algorithm>

/**
 * Simple array reversal algorithm.
 * @param arr The array.
 * @param start The first index to begin with sorting.
 * @param end The last index to end the sorting.
 */
void reverse_array(int arr[], size_t start, size_t end) {
    while (start < end) {
        int temp{arr[start]};
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

/**
 * Creates an array from integer values in a passed string and then redirects the provided pointer to its location.
 * @param array Integer pointer will point to new array.
 * @param string String of integer values to fill the new array.
 */
void fill_array_from_string(int **array, const std::string &string) {
    int *new_array = new int[string.size()];
    for (size_t i{}; i < string.size(); ++i) {
        new_array[i] = static_cast<int>(static_cast<unsigned>(string.at(i))) - 48;
    }
    *array = new_array;
}

/**
 * Adds two large decimal numbers together which are held as values in an array, with each array index
 * being a single digit. The algorithm is a simple paper-and-pencil method of addition.
 * @param first_array The first number to be summed.
 * @param first_size The size of the first array.
 * @param second_array The second number to be summed.
 * @param second_size The size of the second array.
 */
void sum_arrays(const int *first_array, size_t first_size, const int *second_array, size_t second_size) {
    size_t sum_array_size{(first_size > second_size ? first_size + 1 : second_size + 1)};
    int *sum = new int[sum_array_size]{};

    int carry{}, length_counter{};
    int i{}, j{}, k{}; // declare outside loop to use later.

    for (i = static_cast<int>(first_size - 1), j = static_cast<int>(second_size - 1), k =
            static_cast<int>(sum_array_size) - 1; (i >= 0) && (j >= 0); i--, j--) {
        int temp;
        temp = first_array[i] + second_array[j] + carry;
        carry = 0;
        k = std::max(i, j);
        sum[k--] = temp % 10;
        length_counter++;

        // Carry for next digit?
        if (temp > 9) {
            carry = 1;
        }
    }

    // Only one of the next two loops will do anything.
    // Add on the numbers that are left over
    for (; i >= 0; i--) {
        sum[k--] = first_array[i] + carry;
        carry = 0;
        length_counter++;
    }
    for (; j >= 0; j--) {
        sum[k--] = second_array[j] + carry;
        carry = 0;
        length_counter++;
    }

    std::cout << "The sum of your two numbers is: ";
    for (size_t num{}; num < length_counter; ++num) {
        std::cout << sum[num];
    }

    delete[] sum;
}

int main() {

    bool keep_going{true};
    while (keep_going) {
        std::string entered_number;
        std::cout << "Enter a number: ";
        std::cin >> entered_number;

        size_t first_size{entered_number.size()};
        int *first_array{nullptr};
        fill_array_from_string(&first_array, entered_number);

        std::cout << "Enter a second number: ";
        std::cin >> entered_number;

        size_t second_size{entered_number.size()};
        int *second_array{nullptr};
        fill_array_from_string(&second_array, entered_number);

        sum_arrays(first_array, first_size, second_array, second_size);

        delete[] first_array;
        delete[] second_array;

        std::cout << "\nWould you like to add more arrays? (Y or N): ";
        char answer{};
        std::cin >> answer;
        switch (std::tolower(answer)) {
            case 'y':
                keep_going = true;
                break;
            case 'n':
                keep_going = false;
                break;
            default:
                std::cout << "Invalid input. Let's keep going." << std::endl;
                break;
        }
    }

    return 0;
}
