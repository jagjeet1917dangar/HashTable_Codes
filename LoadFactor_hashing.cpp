#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    int *table;
    int size;
    int count;
    double loadFactorThreshold;


    int hashFunction(int key) {
        return key % size;
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
    HashTable(int s, double threshold = 0.7) {
        size = nextPrime(s);
        count = 0;
        loadFactorThreshold = threshold;
        table = new int[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;  
        }
    }

    void insert(int key) {
        double loadFactor = (double)(count + 1) / size;
        if (loadFactor > loadFactorThreshold) {
            cout << "Load factor exceeded (" << loadFactor << "), rehashing...\n";
            rehash();
        }

        int index = hashFunction(key);

       
        while (table[index] != -1) {
            index = (index + 1) % size;
        }

        table[index] = key;
        count++;
    }

    void display() {
        cout << "\nHash Table (size = " << size << ", count = " << count
             << ", load factor = " << (double)count / size << "):\n";
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht(5, 0.7);

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
