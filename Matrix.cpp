//
//  Matrix.cpp
//  Honors Project
//
//  Written By: Caroline Lo
//  IDE: Xcode


#include <iostream>

#include "Matrix.h"

using namespace std;

Matrix::Matrix(int r, int c){
    rows = r;
    cols = c;
    table = new Element*[rows]; // array of pointers to arrays
    for (int i = 0; i < rows; i++)
        table[i] = new Element[cols]; // array of elements
}

/*
 The reset function sets unmarks all of the Elements in the table so the Matrix is reusable
 when the user wants to test a different solution.
 */
void Matrix::reset() const{
    for(int r = 0; r < rows; r++)
        for(int c = 0; c < cols; c++)
            table[r][c].undo(); // unmarks the element
}
/*
 The insert function sets a point on the table to the Element given.
 Input:
 - r
 - c
 - val
 */
void Matrix::insert(int r, int c, Element val){
    table[r][c] = val;
}

/*
 The checkEmpty function returns true if the Element at the coordinates are set to '0'
 which is empty and false if it is not.
 Input:
 - r
 - c
 Output:
 - bool
 */
bool Matrix::checkEmpty(int r, int c){
    return table[r][c].getData() == '0';
}

/*
 The visit function returns the Element at the given coordinates and marks the Element
 as visited.
 Input:
 - r
 - c
 Output:
 - Element
 */
Element Matrix::visit(int r, int c){
    table[r][c].setVisit();
    return table[r][c];
}

/*
 The hasVisited function returns true if the Element at the given coordinates are marked
 as visited and false if not.
 Input:
 - r
 - c
 Output:
 - bool
 */
bool Matrix::hasVisited(int r, int c){
    return table[r][c].getVisited() == 1;
}

/*
 The display function prints the array in the order it was stored in the table
 (for testing)
 */
void Matrix::display() const{
    for (int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << table[i][j].getData();
        }
        cout << endl;
    }
}
/*
The Destructor deletes each array the array of pointers was pointing to and then deletes
the table.
 */
Matrix::~Matrix(){
    for (int r = 0; r < rows; r++)
        delete table[r];
    delete[] table;
}


