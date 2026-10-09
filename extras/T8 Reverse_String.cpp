#include <iostream>
using namespace std;

void reverseString(string& str) {
    int start = 0;
    int end = str.length() - 1;

    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main() {
    string input_string = "Hello, World!";
    reverseString(input_string);

    cout << "The reversed string is: " << input_string << endl;
    return 0;
}

