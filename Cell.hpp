#ifndef CELL_HPP
#define CELL_HPP

class Cell{
    public:
    // position vars

    int x;
    int y;
    
    // index vars

    int col;
    int row;

    // size var
    int size;

    // fill var
    float fill;

    // constructor
    Cell(int x_in, int y_in, int col_in, int row_in, int size_in);
    ~Cell();

    // paint function
    void paint(bool drawOutlines);

    void setFill(float fill_in);
};

#endif