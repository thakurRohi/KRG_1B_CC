#include <iostream>
#include <vector>
using namespace std;

int countDifferentBitsPair(int a, int b) {
    return __builtin_popcount(a ^ b); 
}

long long sumOfDifferentBits(vector<int>& arr) {
    int n = arr.size();
    long long total = 0;


    for (int i = 0; i < 32; i++) {
        long long countSetBits = 0;

        for (int num : arr) {
            if (num & (1 << i)) {
                countSetBits++;
            }
        }

        total += countSetBits * (n - countSetBits);
    }


    return total * 2;
}

int main() {
    vector<int> arr = {1, 3, 5};

    cout << sumOfDifferentBits(arr) << endl;

    return 0;
}
