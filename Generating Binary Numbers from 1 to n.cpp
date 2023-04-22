#include <iostream> 
#include "Queue.cpp"
using namespace std;

void generateBinaryNumbers(int n) {
    Queue<std::string> q;
    q.enqueue("1"); // Start with "1" as the first binary number

    for (int i = 0; i < n; i++) {
        std::string curr = q.First();
        std::cout << curr << " "; // Print the current binary number
        q.dequeue();

        // Generate the next binary numbers by appending "0" and "1" to the current binary number
        q.enqueue(curr + "0");
        q.enqueue(curr + "1");
    }
}

int main() {
    int n;
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Binary numbers from 1 to " << n << ": ";
    generateBinaryNumbers(n);
    
    return 0;
}