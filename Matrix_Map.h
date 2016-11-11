
#ifndef MATRIX_MAP_H
#define MATRIX_MAP_H
/*
    0   :   Ground
    1   :   Box
    2   :   Item
    3   :   Bomb
    4   :   Explosion
    5   :   Wall
*/
class Matrix_Map
{
    public:
    Matrix_Map();

    void draw_graphics();

    int get_element(int row, int col);
    void set_element(int row, int col, int new_value);
    int get_rows();
    int get_columns();

    private:
    void initialize_map();
    // Data
    private:
    int max_rows;
    int max_cols;
    int our_map[19][25] = {{0}};
};

#endif