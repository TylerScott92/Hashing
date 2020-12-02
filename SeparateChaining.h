/*
    Tyler Scott
    Project 5
    *****************************
    SeparateChaining
    - Insertion method changed to count reads with global "read" int
    - Second class has altered hashing function called otherHash (uses DJB2 hashing algorithm)

*/

#ifndef HASHINGB_SEPARATECHAINING_H
#define HASHINGB_SEPARATECHAINING_H

// If this produces errors, go into CMakeLists.txt and change
// the CMAKE_CXX_STANDARD from 14 to 17.
#if __cplusplus < 17
#include <experimental/optional>
using std::experimental::optional;
using std::experimental::nullopt;
using std::experimental::make_optional;
#else
#include <optional>
using std::optional;
using std::nullopt;
using std::make_optional;
#endif

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::function;
using std::string;
using std::vector;

template<typename Hashable>
class SeparateChaining {
private:

    int reads = 0;

    vector<vector<Hashable>> table;
    unsigned long tableSize;

    // The function to get the key from the object
    function<string(Hashable)> getKey;

    // Hash function
    unsigned long hornerHash(string key) {
        unsigned long hashVal = 0;
        for (char &letter : key) {
            hashVal = hashVal * 37 + letter;

        }
        return hashVal % tableSize;
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

public:
    // Constructor
    SeparateChaining(unsigned long tableSize, function<string(Hashable)> getKey) {
        this->tableSize = nextPrime(tableSize);
        this->getKey = getKey;
        // Make sure the vector has room for tableSize number of elements
        // This will create an empty vector at each index
        table.resize(this->tableSize);
    }

    // insert
    void insert(Hashable item) {
        // Get the key from the item
        string key = getKey(item);
        // Hash the key to get an index
        unsigned long index = hornerHash(key);
        if (!find(key)) {
            // Put the item at that index in the table
            reads += 1;
            table[index].push_back(item);

        }
        reads += 2;
    }

    // find
    // Return type is optional<Hashable> because if we find the item,
    // we return it; otherwise we return nullopt.
    optional<Hashable> find(string key) {
        unsigned long index = hornerHash(key);
        // Loop through the items stored at the index
        for (int i = 0; i < table[index].size(); ++i) {
            // Check that the object is the one we're looking for
            if (key == getKey(table[index][i])) {
                // We found the object
                return table[index][i];
            }
        }
        // We did not find the object
        return nullopt;
    }

    // delete
    optional<Hashable> remove(string key) {
        unsigned long index = hornerHash(key);
        // Loop through the items stored at the index
        for (int i = 0; i < table[index].size(); ++i) {
            // Check that the object is the one we're looking for
            if (key == getKey(table[index][i])) {
                // We found the object. Delete it.
                Hashable returnObject = table[index][i];
                // Use the vector erase method to remove the item.
                table[index].erase(table[index].begin() + i);
                return returnObject;
            }
        }
        // We did not find the object
        return nullopt;
    }

    // printTable
    void printTable() const {
        for (unsigned long i = 0; i < table.size(); ++i) {
            cout << i << ": ";
            // Loop through the items stored at the index
            for (int j = 0; j < table[i].size(); ++j) {
                // Use an * to access the value and print it
                cout << table[i][j] << ", ";
            }
            cout << endl;
        }
    }

    int getReads() {
        return reads;
    }
};

template<typename Hashable>
class SeparateChainingOtherHash {
private:

    int reads = 0;

    vector<vector<Hashable>> table;
    unsigned long tableSize;

    // The function to get the key from the object
    function<string(Hashable)> getKey;

    // DJB2 hash function
    unsigned long otherHash(string key) {
        unsigned long hashVal = 5381;
        for (char &letter : key) {
            hashVal = ((hashVal << 5) + hashVal) + letter;

        }
        return hashVal % tableSize;
    }

    // Find the next prime number
    int nextPrime(int n) {
        if (n % 2 == 0) {
            ++n;
        }
        bool prime = false;
        while (!prime) {
            prime = true;
            for (int i = 3; i * i <= n; i += 2) {
                if (n % i == 0) {
                    prime = false;
                }
            }
            n += 2;
        }
        return (n-2);
    }

public:
    // Constructor
    SeparateChainingOtherHash(unsigned long tableSize, function<string(Hashable)> getKey) {
        this->tableSize = nextPrime(tableSize);
        this->getKey = getKey;
        // Make sure the vector has room for tableSize number of elements
        // This will create an empty vector at each index
        table.resize(this->tableSize);
    }

    // insert
    void insert(Hashable item) {
        // Get the key from the item
        string key = getKey(item);
        // Hash the key to get an index
        unsigned long index = otherHash(key);
        if (!find(key)) {
            // Put the item at that index in the table
            reads += 1;
            table[index].push_back(item);

        }
        reads += 2;
    }

    // find
    // Return type is optional<Hashable> because if we find the item,
    // we return it; otherwise we return nullopt.
    optional<Hashable> find(string key) {
        unsigned long index = otherHash(key);
        // Loop through the items stored at the index
        for (int i = 0; i < table[index].size(); ++i) {
            // Check that the object is the one we're looking for
            if (key == getKey(table[index][i])) {
                // We found the object
                return table[index][i];
            }
        }
        // We did not find the object
        return nullopt;
    }

    // delete
    optional<Hashable> remove(string key) {
        unsigned long index = otherHash(key);
        // Loop through the items stored at the index
        for (int i = 0; i < table[index].size(); ++i) {
            // Check that the object is the one we're looking for
            if (key == getKey(table[index][i])) {
                // We found the object. Delete it.
                Hashable returnObject = table[index][i];
                // Use the vector erase method to remove the item.
                table[index].erase(table[index].begin() + i);
                return returnObject;
            }
        }
        // We did not find the object
        return nullopt;
    }

    // printTable
    void printTable() const {
        for (unsigned long i = 0; i < table.size(); ++i) {
            cout << i << ": ";
            // Loop through the items stored at the index
            for (int j = 0; j < table[i].size(); ++j) {
                // Use an * to access the value and print it
                cout << table[i][j] << ", ";
            }
            cout << endl;
        }
    }

    int getReads() {
        return reads;
    }
};

#endif //HASHINGB_SEPARATECHAINING_H
