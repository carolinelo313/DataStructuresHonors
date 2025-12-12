//#include <iostream>
//using namespace std;
//
////================================================================================================
////================================================================================================
////================================================================================================
//class Element{
//   
//   private:
//   char value;
//   int processed;
//   
//   public:
//   Element(){
//      value = 0;
//      processed = 0;
//  }
//
//   void setContent(char cellValue){ value = cellValue; }
//   void setProcessed(int num1){ processed = num1; }
//   char getContent(){ return value; }
//   int getProcessed(){ return processed; }
//};
////================================================================================================
////================================================================================================
////================================================================================================
//#include "StackADT.h"
//class Matrix{
//
//   private:
//   Element* matArray;
//   int rows;
//   int cols;
//
//   public:
//   Matrix(int nRows, int nCols){
//   matArray = new Element[nRows * nCols];
//   rows = nRows;
//   cols = nCols;
//   }
//
//   void setInput(int r, int c, Element input){
//      matArray[(r * cols) + c] = input;
//   }
//
//   Element getInput(int r, int c){
//      return matArray[(r * cols) + c];
//   }
//   
//};
////================================================================================================
////================================================================================================
////================================================================================================
//
////Iterative Solution
//int validCoord(int x, int y, int n, int m)
//{
// 
//    if (x < 0 || y < 0) {
//        return 0;
//    }
//    if (x >= n || y >= m) {
//        return 0;
//    }
//    return 1;
//}
//
//
//int objectFinder(int n, int m, Matrix& mat1, int x, int y, int& objCounter)
//{
//   int counter = 0;
// 
//   Stack<int> *obj = new Stack<int>;
//   
//   //If the element is 0, do not count it
//   if(mat1.getInput(x, y).getContent() == '0'){
//      return 0;
//   }
//      
//   //If the element is not zero, and it hasn't been processed, count it
//   if(mat1.getInput(x, y).getProcessed() == 0){
//   
//      //We found another object so increment
//      objCounter++;
//  
//      //Push the coordinates into the stack
//      obj->push((x * m) + y);
//      counter++;
//   
//      //Set as processed
//      Element temp;
//      temp = mat1.getInput(x, y);
//      temp.setProcessed(1);
//      mat1.setInput(x, y, temp);
//      
//  
//     // Until stack is emppty
//     while (!obj->isEmpty()) {
// 
//       // Extrat coordinates of object in stack
//       int coord = obj->peek();
//       int rowVal = coord / m;
//       int colVal = coord % m;
//    
//       // Popping top object in stack
//       obj->pop();
//       Element temporary;
//       
//       // Look down
//       if(validCoord(rowVal + 1, colVal, n, m) && mat1.getInput(rowVal + 1, colVal).getProcessed() == 0 && mat1.getInput(rowVal + 1, colVal).getContent() != '0'){
//          obj->push((rowVal + 1) * m + colVal);
//          temporary = mat1.getInput(rowVal + 1, colVal);
//          temporary.setProcessed(1);
//          mat1.setInput(rowVal + 1, colVal, temporary);
//          counter++;
//       }
//       // Look up
//       if(validCoord(rowVal - 1, colVal, n, m) && mat1.getInput(rowVal - 1, colVal).getProcessed() == 0 && mat1.getInput(rowVal - 1, colVal).getContent() != '0'){
//          obj->push((rowVal - 1) * m + colVal);
//          temporary = mat1.getInput(rowVal - 1, colVal);
//          temporary.setProcessed(1);
//          mat1.setInput(rowVal - 1, colVal, temporary);
//          counter++;
//       }
//       // Lool to the right
//       if(validCoord(rowVal, colVal + 1, n, m) && mat1.getInput(rowVal, colVal + 1).getProcessed() == 0 && mat1.getInput(rowVal, colVal + 1).getContent() != '0'){
//          obj->push((rowVal * m) + (colVal + 1));
//          temporary = mat1.getInput(rowVal, colVal + 1);
//          temporary.setProcessed(1);
//          mat1.setInput(rowVal, colVal + 1, temporary);
//          counter++;
//       }
//       // Look to the left
//       if(validCoord(rowVal, colVal - 1, n, m) && mat1.getInput(rowVal, colVal - 1).getProcessed() == 0 && mat1.getInput(rowVal, colVal - 1).getContent() != '0'){
//          obj->push((rowVal * m) + (colVal - 1));
//          temporary = mat1.getInput(rowVal, colVal - 1);
//          temporary.setProcessed(1);
//          mat1.setInput(rowVal, colVal - 1, temporary);
//          counter++;
//       }
//     }
//   }
//
//   else{
//      return 0;
//   }
//
//return counter;
//}
//
//void iterativeSolution(Matrix mat1, int numRow, int numCol){
//     
//     int objCounter = 0;
//     int walker = 0;
//     
//     for(int k = 1; k < numRow - 1; k++){
//          for(int l = 1; l < numCol - 1; l++){
//             if(mat1.getInput(k, l).getContent() != '0' && mat1.getInput(k, l).getProcessed() == 0){
//             walker = objectFinder(numRow, numCol, mat1, k, l, objCounter);
//             cout << "Object " << objCounter << ": ";
//             cout << walker << endl;
//           }
//        }
//     }
//}
//
