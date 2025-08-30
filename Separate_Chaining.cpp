#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int key;
    int value;
    Node *next;

    Node(int k, int v)
    {
        key = k;
        value = v;
        next = NULL;
    }
};

class HashTable{
public:
    Node *Htable[10] = {NULL};

    int hashFunction(int key)
    {
        return key % 10;
    }

    void insert(int key, int value)
    {
        int index = hashFunction(key);
        Node *newNode = new Node(key, value);

        if (Htable[index] == NULL)
        {
            Htable[index] = newNode;
        }
        else
        {
            Node *temp = Htable[index];
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void search(int key)
    {
        Node *temp = Htable[hashFunction(key)];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                cout << "Found: " << temp->key << " -> " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found." << endl;
    }

    void display()
    {
        cout << "\nHash Table:\n";
        for (int i = 0; i < 10; i++)
        {
            cout << i << ": ";
            Node *temp = Htable[i];
            while (temp != NULL)
            {
                cout << "[" << temp->key << " -> " << temp->value << "] --> ";
   
   
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main()
{
    HashTable h;
    h.insert(5, 85);
    h.insert(26, 36);
    h.insert(42, 888);
    h.insert(15, 5758);
    h.insert(36, 588);

    h.display();

    h.search(26);
}