//
// Created by Lisa Dion on 9/2/20.
//

#ifndef LECTURERA_LECTURER_H
#define LECTURERA_LECTURER_H

#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

/*
 * Lecturer class
 */

class Lecturer {
private:
    std::string name;
    int class1;
    int class2;
    int class3;
    std::string office;

public:
    // Constructors
    Lecturer() {
        name = "Jane Doe";
        class1 = class2 = class3 = 0;
        office = "Innovation E220";
    }

    Lecturer(std::string name,
            int class1,
            int class2,
            int class3,
            std::string office) {
        this->name = name;
        // validate the class values that are input as parameters
        setClass1(class1);
        setClass2(class2);
        setClass3(class3);
        this->office = office;
    }

    // Getters
    // use const to specify that the method won't modify the object
    std::string getName() const {
        return name;
    }

    int getClass1() const {
        return class1;
    }

    int getClass2() const {
        return class2;
    }

    int getClass3() const {
        return class3;
    }

    std::string getOffice() const {
        return office;
    }

    // Setters
    void setName(std::string name) {
        this->name = name;
    }

    void setClass1(int class1) {
        // check value
        if (class1 < 0) {
            this->class1 = 0;
        } else {
            this->class1 = class1;
        }
    }

    void setClass2(int class2) {
        // check value
        if (class2 < 0) {
            this->class2 = 0;
        } else {
            this->class2 = class2;
        }
    }

    void setClass3(int class3) {
        // check value
        if (class3 < 0) {
            this->class3 = 0;
        } else {
            this->class3 = class3;
        }
    }

    // Overloaded Operators
    friend std::ostream& operator << (std::ostream& outs, const Lecturer &lec) {
        outs << lec.name;
        return outs;
    }

    friend bool operator == (const Lecturer &lhs, const Lecturer &rhs) {
        // Use the unique field to determine if the two objects are equal
        return lhs.name == rhs.name;
    }

};

// A global function is declared outside the scope of the class
// An ampersand & means that the vector is being passed by reference
void getLecturersFromFile(std::string filename, std::vector<Lecturer> &lecturers) {
    // Read lecturers in from file
    std::ifstream fIn;
    fIn.open("../" + filename);

    std::string header = "";
    if (fIn) {
        // Use getline with two arguments to read a line from the file
        getline(fIn, header);
    }

    std::string name = "", office = "";
    int class1 = 0, class2 = 0, class3 = 0;
    char comma = ',';
    // Syntax for creating Lecturer objects
    //Lecturer lec;
    //Lecturer lec2("Name", 1, 2, 3, "Office");

    // while the file stream is in a good state and
    // we are not at the end-of-file
    while (fIn && fIn.peek() != EOF) {
        // Read in the name
        // Use getline with three arguments to specify stop character
        getline(fIn, name, ',');

        // Read class 1
        fIn >> class1 >> comma;

        // Read class 2
        fIn >> class2;
        // Check to see if the file input stream broke
        if (!fIn) {
            // There was no class 2
            // Set a default value for class 2
            class2 = 0;
            // Clear the stream so we can continue reading from the file
            fIn.clear();
        }
        fIn >> comma;

        // Read class 3
        fIn >> class3;
        // Check to see if the file input stream broke
        if (!fIn) {
            // There was no class 3
            // Set a default value for class 3
            class3 = 0;
            // Clear the stream so we can continue reading from the file
            fIn.clear();
        }
        fIn >> comma;

        // Read office
        getline(fIn, office);

        // Create a Lecturer object and add it to the vector
        lecturers.push_back(Lecturer(name, class1, class2, class3, office));
    }

    fIn.close();

}

#endif //LECTURERA_LECTURER_H
