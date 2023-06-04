#include <iostream>
#include <stack>

using namespace std;

bool isStackEqual(stack<int>& stack1, stack<int>& stack2) {
    // Jika ukuran stack berbeda, maka tidak mungkin sama
    if (stack1.size() != stack2.size()) {
        return false;
    }

    // Periksa elemen-elemen dalam stack secara berurutan
    while (!stack1.empty()) {
        // Jika elemen pada posisi yang sama berbeda, maka tidak sama
        if (stack1.top() != stack2.top()) {
            return false;
        }
        stack1.pop();
        stack2.pop();
    }

    // Stack sama jika semua elemennya sama
    return true;
}

int main() {
    stack<int> stack1;
    stack<int> stack2;

    // Menambahkan elemen ke stack1
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    // Menambahkan elemen ke stack2
    stack2.push(1);
    stack2.push(2);
    stack2.push(3);

    // Memeriksa apakah stack1 dan stack2 sama
    if (isStackEqual(stack1, stack2)) {
        std::cout << "Kedua stack sama." << std::endl;
    } else {
        std::cout << "Kedua stack tidak sama." << std::endl;
    }

    return 0;
}