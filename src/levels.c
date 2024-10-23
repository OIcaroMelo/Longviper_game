#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h.>
#include "../include/levels.h"

void setLevel_1(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 0;
    cube->y = 0;
    cube->width = 100;
    cube->height = 100;
    cube->speed = 100;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;
    
    *direction = 'K';

    int initValue[8][8] = {{0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 1, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {1, 1, 1, 1, 1, 1, 0, 0},
                           {1, 0, 0, 0, 0, 0, 0, 0},
                           {1, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_2(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 300;
    cube->y = 200;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 0, 1, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 1, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 1},
                           {0, 1, 0, 0, 1, 1, 0, 1},
                           {0, 1, 1, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 1, 1, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_3(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 300;
    cube->y = 300;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 1, 1, 0, 0, 0, 0},
                           {0, 0, 1, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 1, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0},
                           {1, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_4(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 500;
    cube->y = 300;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 1, 0, 0, 0, 1, 1},
                           {0, 0, 0, 0, 1, 0, 0, 1},
                           {0, 1, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 1, 0, 0, 0, 1},
                           {1, 0, 0, 1, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 1},
                           {1, 0, 0, 0, 0, 0, 0, 1},
                           {1, 1, 1, 1, 1, 1, 1, 1}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_5(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 500;
    cube->y = 500;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{1, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 1, 1, 0, 0},
                           {0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_6(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 700;
    cube->y = 700;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 1, 1, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_7(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 0;
    cube->y = 0;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 1, 0, 0},
                           {0, 0, 0, 1, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_8(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 300;
    cube->y = 300;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 0, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 1, 1, 0, 0, 1, 0},
                           {0, 0, 0, 0, 0, 1, 1, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_9(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 0;
    cube->y = 700;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 1, 0, 0, 0, 0, 1},
                           {0, 0, 0, 0, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0}};

    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void setLevel_10(int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    cube->x = 500;
    cube->y = 200;
    cube->width = 50;
    cube->height = 50;
    cube->speed = 50;

    *init_x = cube->x;
    *init_y = cube->y;
    *init = 1;

    *direction = 'K';

    int initValue[16][16] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
                             {0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1},
                             {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1},
                             {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                             {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
                             {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                             {0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1},
                             {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
                             {0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1},
                             {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1},
                             {0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1},
                             {0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
                           
    for(int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            (*collision)[i][j] = initValue[i][j];
            (*map)[i][j] = initValue[i][j];
        }
    }
}

void restart(int level, int ***collision, int lines, int columns, int ***map, Cube *cube, char *direction, int *init_x, int *init_y, int *init) {
    if(level == 1) {
        setLevel_1(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 2) {
        setLevel_2(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 3) {
        setLevel_3(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 4) {
        setLevel_4(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 5) {
        setLevel_5(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 6) {
        setLevel_6(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 7) {
        setLevel_7(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 8) {
        setLevel_8(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 9) {
        setLevel_9(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
    else if(level == 10) {
        setLevel_10(&(*collision), lines, columns, &(*map), &(*cube), &(*direction), &(*init_x), &(*init_y), &(*init));
    }
}
