#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ifstream myfile("numbers.txt");
    vector<int> numbers;
    int num;

    if (myfile.is_open()) {
        while (myfile >> num) {
            numbers.push_back(num);
        }
        myfile.close();

        sort(numbers.begin(), numbers.end(), greater<int>());

        ofstream outFile("sorted_numbers.txt");
        for (const int &n : numbers) {
            outFile << n << endl;
        }
        outFile.close();

        cout << "Numbers sorted in descending order and written to sorted_numbers.txt" << endl;
    } else {
        cout << "Unable to open file" << endl;
    }

    return 0;
}