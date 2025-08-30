#include <iostream>
using namespace std;

class NormalHashtable
{
    int *table;
    int size;
    int count;

public:
    NormalHashtable(int s)
    {
        size = s;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }


int HashFunction(int key, int size)
{
    return key % size;
}

int insert(int key)
{
    if (count == size)
    {
        rehash();
    }
    int index = HashFunction(key, size);
    table[index] = key;
    count++;
}

void rehash()
{
    int oldSize = size;
    size = 2 * size;
    int *oldTable = table;

    table = new int[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
    }

    count = 0;
    for (int i = 0; i < oldSize; i++)
    {
        if (oldTable[i] != -1)
        {
            insert(oldTable[i]);
        }
    }

    delete[] oldTable;
}

void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> " << table[i] << endl;
        }
    }
};

int main() {
    NormalHashtable h(3);  
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);  
    h.insert(50);

    h.display();
    return 0;
}
