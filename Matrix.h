//
//  Matrix.h
//  Honors Project
//
// Written By: Caroline Lo
// IDE: Xcode 

#ifndef Matrix_h
#define Matrix_h

#include "Element.h"

class Matrix
{
private:
    Element **table; //doubly pointer array
    int rows;
    int cols;
    
public:
    
    Matrix(int r, int c); //constructor
    ~Matrix(); //destructor
    
    //getters
    int getRows(){ return rows; };
    int getCols(){ return cols; };
    
    void insert(int r, int c, Element val);
    bool checkEmpty(int r, int c);
    Element visit(int r, int c);
    bool hasVisited(int r, int c);
    
    void reset() const;
    void display() const;
    
};

#endif /* Matrix_h */
