//
// Created by Emil Tsanev on 6.3.2023 г..
//

// Hash table storing integers
#include <vector>

#define HASH_TABLE_CAPACITY 100

using namespace std;

int hash_function(int value)
{
    int index = ((value/7)*4) % HASH_TABLE_CAPACITY;
    return index;
}

class HashTable
{
private:
    vector<vector<int>> hash_array;

public:
    HashTable()
    {
        this->hash_array.resize(HASH_TABLE_CAPACITY);
    }

    bool contains(int value)
    {
        int index_of_value = hash_function(value);

        if (hash_array[index_of_value].empty()) return false;

        if (hash_array[index_of_value][0] == value) return true;
        else
        {
            for (int item : hash_array[index_of_value])
            {
                if (item == value) return true;
            }
        }
        return false;
    }

    void insert(int value)
    {
        if (this->contains(value)) return;
        int index_of_value = hash_function(value);
        hash_array[index_of_value].push_back(value);
    }

    void delete_value(int value)
    {
        if (!this->contains(value)) return;

        int index_of_value = hash_function(value);
        for (auto it = hash_array[index_of_value].begin(); it != hash_array[index_of_value].end(); it++)
        {
            if (*it == value) hash_array[index_of_value].erase(it);
        }
    }
};