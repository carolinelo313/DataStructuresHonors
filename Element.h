//
//  Element.h
//  Honors Project
//
//  Written By: Caroline Lo
//  IDE: Xcode

#ifndef Element_h
#define Element_h

class Element{
    private:
    char data;
    int visited; //Tracks if element was counted

    public:
    Element(){
        data = 0;
        visited = 0;
    };
    Element(char d){
        data = d;
        visited = 0;
    };
    
    //getters
    char getData(){ return data; };
    int getVisited(){ return visited; };
    
    //setters
    void setData(char val){ data = val; };
    void setVisit(){ visited = 1; }; // adds the visited mark
    
    // removes the visited mark to reset the matrix
    void undo(){ visited = 0; };
};

#endif /* Element_h */
