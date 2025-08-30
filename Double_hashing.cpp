#include <iostream>
#include <vector>
using namespace std;

class DoubleHashing {
    int *table;
    int size;
    int count;


    int h1(int key) {
        return key % size;
    }

    
    int h2(int key) {
        return 1 + (key % (size - 1));
    }

    
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    
    int nextPrime(int n) {
        while (!isPrime(n)) n++;
        return n;
    }

    
    void rehash() {
        int oldSize = size;
        int *oldTable = table;

        size = nextPrime(size * 2);
        table = new int[size];
        count = 0;

        for (int i = 0; i < size; i++) {
            table[i] = -1;
        }

        
        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != -1) {
                insert(oldTable[i]);
            }
        }

        delete[] oldTable;
    }

public:
    DoubleHashing(int s) {
        size = nextPrime(s);
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;  
        }
    }

    
    void insert(int key) {
        if (count == size) {
            cout << "Table full! Rehashing..." << endl;
            rehash();
        }

        int index = h1(key);
        int step = h2(key);
        int i = 0;

        while (table[(index + i * step) % size] != -1) {
            i++;
        }

        table[(index + i * step) % size] = key;
        count++;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << table[i] << endl;
        }
    }
};

int main() {
    DoubleHashing ht(5); 

    
    ht.insert(50);
    ht.insert(700);
    ht.insert(76);
    ht.insert(85);
    ht.insert(92);
    ht.insert(73);
    ht.insert(101);

    ht.display();

    return 0;
}
