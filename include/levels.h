#ifndef LEVELS_H
#define LEVELS_H

typedef struct {
    float x, y;
    int width, height;
    float speed;
} Cube;

void setLevel_1(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_2(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_3(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_4(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_5(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_6(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_7(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_8(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_9(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void setLevel_10(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

void restart(int level, int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init);

#endif 
