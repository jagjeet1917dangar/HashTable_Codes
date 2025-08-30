#include <iostream>
using namespace std;

class LinearHashtable
{
    int *table;
    int size;
    int count;

public:
    LinearHashtable(int s)
    {
        size = s;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = -1;
        }
    }

    int HashFunction(int key){
        int i=0;
        while(i<size && table[(key+i) % size] != -1){
            i++;
        }
        return (key+i) % size;
    }

    void insert(int key)
    {
        if (count == size)
        {
            rehash();
        }
        int index = HashFunction(key);
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

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << " --> " << table[i] << endl;
        }
    }
    };

    int main(){
    LinearHashtable ht(5);
    ht.insert(10);  
    ht.insert(20);
    ht.insert(15);
    ht.insert(25);
    ht.insert(2);
    ht.insert(33);

    ht.display();
    }

    