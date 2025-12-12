//
//  CIS 22C
//
//  This project reads a matrix from a file and prints all of the objects (groups of adjacent
//  nodes) and their areas. It has a iterative and recursive option for the solution.
//
//  main.cpp
//  Honors Project
//
//  Written By: Caroline Lo
//  IDE: Xcode

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

#include "Matrix.h"
#include "StackADT.h"

using namespace std;

Matrix buildMatrix(string filename);
void menuManager(Matrix& mat);

int validCoord(int x, int y, int n, int m);

int objectFinder(int n, int m, Matrix& mat1, int x, int y);
void iterativeSolution(Matrix& mat1, int numRow, int numCol);

int recurTraverse(Matrix& mat, int r, int c);
void recursiveSolution(Matrix& mat1, int numRow, int numCol);


int main(int argc, const char * argv[]) {
    string filename;
    cout << "Enter input file's name: ";
    getline(cin, filename);
    
    Matrix mat = buildMatrix(filename);
    
    menuManager(mat);
    
    return 0;
    
}

/*
 The menuManager function prints the options for user input and can run the iterative
 and recursive solutions. It stops running the program when the user enters "Quit".
 Input:
 - mat
 */
void menuManager(Matrix& mat){
    cout << "Menu options:" << endl;
    cout << "______________________" << endl;
    cout << "I - Iterative Solution" << endl;
    cout << "R - Recursive Solution" << endl;
    cout << "Quit - stop\n" << endl;
    string in;
    cin >> in;
    
    //allows for lowercase
    for(char &c: in){
          c = (char)toupper(c);
    }
    
    // runs until user enters "quit"
    while (in != "QUIT"){
        if(in == "I"){
            iterativeSolution(mat, mat.getRows(), mat.getCols());
        }else if(in == "R"){
            recursiveSolution(mat, mat.getRows(), mat.getCols());
        }else{
            cout << "Invalid Input" << endl;
            cout << "I - Iterative Solution" << endl;
            cout << "R - Recursive Solution" << endl;
            cout << "Quit - stop" << endl;
        }
        cout << endl;
        cin >> in;
        for(char &c: in){
              c = (char)toupper(c);
        }
        mat.reset(); // allows for different solution
    }
}

/*
 The buildMatrix function uses the data from the file to create a Matrix and the
 insert data into it. It returns the completed Matrix.
 Input:
 - filename
 Output:
 - Matrix (has data)
 */
Matrix buildMatrix(string filename){
    ifstream inputFile(filename);

    if(!inputFile) // checks for errors
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Reading data from \"" << filename << "\"" << endl;
    string line;
    getline(inputFile, line);
    stringstream in(line);
    
    // making matrix
    int row, col;
    in >> row;
    in >> col;
    Matrix table = Matrix(row, col);
    
    int r = 0;
    
    //assigning each element
    while (getline(inputFile, line))
    {
        for(int c = 0; c < col; c++){
            table.insert(r, c, Element(line.at(c)));
        }
        r++;
    }
    
    inputFile.close();
    
    return table;
}

//Iterative Solution
/*
 The validCoord function makes sure the x and y are not out of bounds. It returns 0 if
 it is invalid and 1 if it is.
 Input:
 - x
 - y
 - n
 - m
 Output
 - int
 */
int validCoord(int x, int y, int n, int m)
{
 
    if (x < 0 || y < 0) {
        return 0;
    }
    if (x >= n || y >= m) {
        return 0;
    }
    return 1;
}
/*
 The objectFinder function finds the total area of an object using a stack. It pushes the
 starting node into the stack and when a valid neighbor is found, it is added to the stack.
 The function pops the node and repeats the proccess with the next node on the stack. It
 continues until the stack is empty which means there are no more neighbors to add.
 Input:
 - n (row size)
 - m (col size)
 - mat1
 - x (row)
 - y (col)
 Output:
 - int (area)
 */
int objectFinder(int n, int m, Matrix& mat1, int x, int y)
{
   // total area
   int counter = 0;
 
    //coordinates so stack works with 2D array
    struct point{
        int x;
        int y;
    };
    
   Stack<point> *obj = new Stack<point>;
  
  //Push the first coordinates into the stack
  obj->push((point){x, y});
  counter++;

  // Mark the element
  mat1.visit(x, y);

 // Until stack is empty
  while (!obj->isEmpty()) {

       // Extract coordinates of object in stack
       point coord = obj->pop();
       int rowVal = coord.x;
       int colVal = coord.y;
       
       // Look down
       if(validCoord(rowVal + 1, colVal, n, m) && !mat1.hasVisited(rowVal + 1, colVal) && !mat1.checkEmpty(rowVal + 1, colVal)){
           obj->push((point){rowVal + 1, colVal});
           mat1.visit(rowVal + 1, colVal);
          counter++;
       }
         
       // Look up
       if(validCoord(rowVal - 1, colVal, n, m) && !mat1.hasVisited(rowVal - 1, colVal) && !mat1.checkEmpty(rowVal - 1, colVal)){
           obj->push((point){rowVal - 1, colVal});
           mat1.visit(rowVal - 1, colVal);
          counter++;
       }
         
       // Look to the right
       if(validCoord(rowVal, colVal + 1, n, m) && !mat1.hasVisited(rowVal, colVal + 1) && !mat1.checkEmpty(rowVal, colVal + 1)){
           obj->push((point){rowVal, colVal + 1});
           mat1.visit(rowVal, colVal + 1);
          counter++;
       }
         
       // Look to the left
       if(validCoord(rowVal, colVal - 1, n, m) && !mat1.hasVisited(rowVal, colVal - 1) && !mat1.checkEmpty(rowVal, colVal - 1)){
          obj->push((point){rowVal, colVal - 1});
          mat1.visit(rowVal, colVal - 1);
          counter++;
       }
    }
    return counter;
}

/*
 The iterativeSolution function traverses the matrix and when it finds a nonempty, unmarked
 element, it calls the objectFinder function to find the area.
 Input:
 - mat1
 - numRow
 - numCol
 */
void iterativeSolution(Matrix& mat1, int numRow, int numCol){
     
     int objCounter = 0;
     int area = 0;
     
     for(int k = 1; k < numRow - 1; k++){
          for(int l = 1; l < numCol - 1; l++){
            //when a nonempty, unmarked node is found, call the function to find the area
             if(!mat1.checkEmpty(k, l) && !mat1.hasVisited(k, l)){
             area = objectFinder(numRow, numCol, mat1, k, l);
             //after whole area found, increment the objCounter
             objCounter ++;
             cout << "Object " << objCounter << ": ";
             cout << area << endl;
           }
        }
     }
}


/*
 The recurTraverse function checks the up, right, down, then left nodes. If all of
 the neighbors are visited/empty/out of bounds -> base case, add 1 to the area.
 Otherwise recursive call to the valid neighbors, add 1 to area + sum from other calls.
 Input:
 - mat
 - r (row)
 - c (col)
 Output
 - int (area)
 */
int recurTraverse(Matrix &mat, int r, int c){
    //track if no neighbors are called recursivly
    bool validNeighbors = false;
    //mark current
    mat.visit(r, c);
    //count area
    int sum = 1;
    
    //check up
    if(validCoord(r - 1, c, mat.getRows(), mat.getCols()) && !mat.hasVisited(r - 1, c) && !mat.checkEmpty(r - 1, c)){
        sum += recurTraverse(mat, r - 1, c);
        validNeighbors = true;
    }
    
    //check right
    if(validCoord(r, c + 1, mat.getRows(), mat.getCols()) && !mat.hasVisited(r, c + 1) && !mat.checkEmpty(r, c + 1)){
        sum += recurTraverse(mat, r, c + 1);
        validNeighbors = true;
    }
    
    //check down
    if(validCoord(r + 1, c, mat.getRows(), mat.getCols()) && !mat.hasVisited(r + 1, c) && !mat.checkEmpty(r + 1, c)){
        sum += recurTraverse(mat, r + 1, c);
        validNeighbors = true;
    }
    
    //check left
    if(validCoord(r, c - 1, mat.getRows(), mat.getCols()) && !mat.hasVisited(r, c - 1) && !mat.checkEmpty(r, c - 1)){
        sum += recurTraverse(mat, r, c - 1);
        validNeighbors = true;
    }
    
    //base case, all adjecent cells are all empty, visited, or have invalid coordinates
    if(!validNeighbors){
        return 1;
    }else{
        // recursive case, return total connected cells visited so far
        return sum;
    }
}

/*
 The recursiveSolution function traverses the matrix and when it finds a nonempty, unmarked
 element, it calls the recurTraverse function to find the area.
 Input:
 - mat1
 - numRow
 - numCol
 */
void recursiveSolution(Matrix& mat1, int numRow, int numCol){
     
     int objCounter = 0;
     int area = 0;
     
     for(int k = 1; k < numRow - 1; k++){
          for(int l = 1; l < numCol - 1; l++){
            //when a nonempty, nonmarked node is found, call the function to find the area
             if(!mat1.checkEmpty(k, l) && !mat1.hasVisited(k, l)){
                 area = recurTraverse(mat1, k, l);
                 //after whole area found, increment the objCounter
                 objCounter++;
                 cout << "Object " << objCounter << ": ";
                 cout << area << endl;
             }
          }
     }
}
