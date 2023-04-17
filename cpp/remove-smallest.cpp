#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>

std::string isReducibleToOne(std::vector<int> arr) {
    while (true) {
        std::vector<int> indices_to_remove;

        for (int i = 1; i < arr.size(); i++) {
            int dif = abs(arr[0] - arr[i]);
            if (dif <= 1) {
                if (arr[i] <= arr[0]) {
                    indices_to_remove.push_back(i);
                } else {
                    indices_to_remove.push_back(0);
                    break; // exit the loop if the first element is smaller than the ith element
                }
            }
        }

        if (indices_to_remove.empty()) {
            break;
        }

        // remove the elements in reverse order to avoid invalidating indices
        std::sort(indices_to_remove.begin(), indices_to_remove.end(), std::greater<int>());
        for (int i : indices_to_remove) {
            arr.erase(arr.begin() + i);
        }
    }

    std::string ans;

    if (arr.size() > 1) {
        ans = "NO";
    } else if (arr.size() == 1) {
        ans = "YES";
    } else {
        throw "Error";
    }

    return ans;
}

int main() {
    int num_tests;
    std::cin >> num_tests;

    for (int i = 0; i < num_tests; i++) {
        int num_elements;
        std::vector<int> test_arr;
        std::cin >> num_elements;
        std::cin.ignore();
        std::string input;

        std::getline(std::cin, input);
        std::istringstream iss(input);

        int elem;
        int tracker = 0;

        while (iss >> elem) {
            test_arr.push_back(elem);
            tracker++;
        }

        if (tracker != num_elements) {
            return 1;
        }

        std::sort(test_arr.begin(), test_arr.end());
        std::string res = isReducibleToOne(test_arr);

        std::cout << res << std::endl;


    }

}