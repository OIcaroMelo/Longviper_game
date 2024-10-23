#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/levels.h"
#include "../include/screen.h"

int **mapAloc(int lines, int columns) {
    int **map = (int **) calloc(lines, sizeof(int *));
    if (map == NULL) {
        return NULL; 
    }

    for (int i = 0; i < lines; i++) {
        map[i] = (int *) calloc(columns, sizeof(int));
        if (map[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(map[j]);
            }
            free(map);
            return NULL; 
        }
    }

    return map; 
}

void freeMap(int **collision, int lines) {
    for (int i = 0; i < lines; i++) {
        free(collision[i]); 
    }
    free(collision); 
}

Texture2D **textureAloc(int lines, int columns) {
    Texture2D **texture = (Texture2D **) calloc(lines, sizeof(Texture2D *));
    if (texture == NULL) {
        return NULL; 
    }

    for (int i = 0; i < lines; i++) {
        texture[i] = (Texture2D *) calloc(columns, sizeof(Texture2D));
        if (texture[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(texture[j]);
            }
            free(texture);
            return NULL; 
        }
    }

    return texture; 
}

void freeTexture(Texture2D **texture, int lines, int columns) {
    for (int i=0; i<lines; i++) {
        for(int j=0; j<columns; j++) {
            UnloadTexture(texture[i][j]);
        }
        free(texture[i]);
    }
    free(texture); 
}

int main() {

    int window_Width = 800;
    int window_Height = 800;

    InitWindow(window_Width, window_Height, "Longviper");
    SetTargetFPS(60);

    Image icon = LoadImage("assets/initial.png");

    SetWindowIcon(icon);

    Rectangle button = {100, 500, 250, 100};

    Rectangle button2 = {450, 500, 250, 100};

    Rectangle button3 = {275, 650, 250, 100};

    int textFontSize = 20;
    int playFontSize = 50;
    int how_to_playFontSize = 36;

    Texture2D initial;
    initial = LoadTexture("assets/initial.png");

    Texture2D bricks;
    bricks = LoadTexture("assets/brick.png");

    Texture2D floor;
    floor = LoadTexture("assets/grass-floor.png");

    Cube cube;

    int init_x = 0;
    int init_y = 0;

    int lines = 8;
    int columns = 8;

    Texture2D **body = textureAloc(lines, columns);
    Texture2D current;

    int **collision = mapAloc(lines, columns);
    int **map = mapAloc(lines, columns);

    int screen = 1;
    int flag = 1;
    int level = 1;
    int wait = 0;
    int init = 1;
    int current_form = 0;
    
    char direction = 'K';
    char title[99] = "Longviper";
    char play[99] = "Play";
    char how_to_play[99] = "How to Play";
    char creator[99] = "Created by Icaro Melo";
    char objectives[99] = "Objectives";
    char text1[99] = "You must guide the character to fill all the spaces on the screen with";
    char text2[99] = "its body, except for the spaces with bricks. There are 10 levels.";
    char gameplay[99] = "Gameplay";
    char tip1[99] = "1. Control the character with the arrow keys.";
    char tip2[99] = "2. Press Q to restart the level.";
    char tip3[99] = "3. Press M to return to the menu";
    char tip4[99] = "4. When pressing a directional key, the character will move in";
    char tip5[99] = "   that direction until it hits a wall or the edge of the screen.";
    char back[99] = "Back";
    char to_menu[99] = "to Menu";
    char mesage[99] = "Level 1";
                                  
    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if(screen == 1) {
            freeMap(collision, lines);
            freeMap(map, lines);
            freeTexture(body, lines, columns);
            UnloadTexture(initial);

            body = textureAloc(lines, columns);
            collision = mapAloc(lines, columns);
            map = mapAloc(lines, columns);

            strcpy(mesage, "Level 1");
            level = 1;
            initial = LoadTexture("assets/initial.png");
            setLevel_1(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);

            setMenu(&screen, button, button2, playFontSize, how_to_playFontSize, title, play, how_to_play, creator);
        }
        else if(screen == 2) {
            setHow_to_Play(&screen, button3, playFontSize, textFontSize, playFontSize, objectives, text1, text2, gameplay, tip1, tip2, tip3, tip4, tip5, back);
        }
        else if(screen == 3) {
            if(IsKeyPressed(KEY_M)) {
                screen = 1;
            }

            if(IsKeyPressed(KEY_Q)) {
                freeMap(collision, lines);
                freeMap(map, lines);
                freeTexture(body, lines, columns);
                UnloadTexture(initial);

                body = textureAloc(lines, columns);
                collision = mapAloc(lines, columns);
                map = mapAloc(lines, columns);

                if(level != 10) {
                    initial = LoadTexture("assets/initial.png");
                }
                else {
                    initial = LoadTexture("assets/initial-small.png");
                }
                restart(level, &collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
            }

            if(((IsKeyPressed(KEY_UP) && flag == 1) || direction == 'W') && cube.y > 0) {
                if(collision[(int) ((cube.y - cube.speed)/cube.height)][(int) cube.x/cube.width] == 0) {
                    if(init == 1) {
                        if(level != 10) {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-2.png");
                        }
                        else {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-2-small.png");
                        }
                        init = 0;
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 1;
                    }
                    else if(direction == 'W') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 2;
                    }
                    else if(direction == 'A') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 5;
                    }
                    else if(direction == 'D') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 7;
                    }
                    cube.y -= cube.speed;
                    current_form = 4;
                    direction = 'W';
                    flag = 0;
                }
                else {
                    flag = 1;
                }
                WaitTime(0.005f);
            }
            else if(cube.y == 0) {
                flag = 1;
            }

            if(((IsKeyPressed(KEY_DOWN) && flag == 1) || direction == 'S') && cube.y < GetScreenHeight() - cube.height) {
                if(collision[(int) ((cube.y + cube.speed)/cube.height)][(int) cube.x/cube.width] == 0) {
                    if(init == 1) {
                        if(level != 10) {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-4.png");
                        }
                        else {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-4-small.png");
                        }
                        init = 0;
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 1;
                    }
                    else if(direction == 'S') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 2;
                    }
                    else if(direction == 'A') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 4;
                    }
                    else if(direction == 'D') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 6;
                    }
                    cube.y += cube.speed;
                    current_form = 2;
                    direction = 'S';
                    flag = 0;
                }
                else {
                    flag = 1;
                }
                WaitTime(0.005f);
            }
            else if(cube.y == GetScreenHeight() - cube.height) {
                flag = 1;
            }

            if(((IsKeyPressed(KEY_LEFT) && flag == 1) || direction == 'A') && cube.x > 0) {
                if(collision[(int) cube.y/cube.height][(int) ((cube.x - cube.height)/cube.width)] == 0) {
                    if(init == 1) {
                        if(level != 10) {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-3.png");
                        }
                        else {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-3-small.png");
                        }
                        init = 0;
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 1;
                    }
                    else if(direction == 'A') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 3;
                    }
                    else if(direction == 'W') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 6;
                    }
                    else if(direction == 'S') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 7;
                    }
                    cube.x -= cube.speed;
                    current_form = 1;
                    direction = 'A';
                    flag = 0;
                }
                else {
                    flag = 1;
                }
                WaitTime(0.005f);
            }
            else if(cube.x == 0) {
                flag = 1;
            }

            if(((IsKeyPressed(KEY_RIGHT) && flag == 1) || direction == 'D') && cube.x < GetScreenWidth() - cube.width) {
                if(collision[(int) cube.y/cube.height][(int) ((cube.x + cube.height)/cube.width)] == 0) {
                    if(init == 1) {
                        if(level != 10) {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-1.png");
                        }
                        else {
                            UnloadTexture(initial);
                            initial = LoadTexture("assets/origin-1-small.png");
                        }
                        init = 0;
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 1;
                    }
                    else if(direction == 'D') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 3;
                    }
                    else if(direction == 'W') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 4;
                    }
                    else if(direction == 'S') {
                        collision[(int) cube.y/cube.height][(int) cube.x/cube.width] = 5;
                    }
                    cube.x += cube.speed;
                    current_form = 3;
                    direction = 'D';
                    flag = 0;
                }
                else {
                    flag = 1;
                }
                WaitTime(0.005f);
            }
            else if(cube.x == GetScreenWidth() - cube.width) {
                flag = 1;
            }

            int sum = 0;

            for(int i=0; i<lines; i++) {
                for(int j=0; j<columns; j++) {
                    if(map[i][j] == 1) {
                        DrawTexture(bricks, j * cube.width, i * cube.height, WHITE);
                    }
                    else if(map[i][j] == 0) {
                        DrawTexture(floor, j * cube.width, i * cube.height, WHITE);
                    }
                }
            }

            for(int i=0; i<lines; i++) {
                for(int j=0; j<columns; j++) {
                    if(collision[i][j] > 0) {
                        if(level != 10) {
                            UnloadTexture(body[i][j]);
                            if(collision[i][j] == 2) {
                                body[i][j] = LoadTexture("assets/body-2.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 3) {
                                body[i][j] = LoadTexture("assets/body-1.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 4) {
                                body[i][j] = LoadTexture("assets/corner-1.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 5) {
                                body[i][j] = LoadTexture("assets/corner-2.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 6) {
                                body[i][j] = LoadTexture("assets/corner-4.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 7) {
                                body[i][j] = LoadTexture("assets/corner-3.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                        }
                        else {
                            UnloadTexture(body[i][j]);
                            if(collision[i][j] == 2) {
                                body[i][j] = LoadTexture("assets/body-2-small.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 3) {
                                body[i][j] = LoadTexture("assets/body-1-small.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 4) {
                                body[i][j] = LoadTexture("assets/corner-1-small.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 5) {
                                body[i][j] = LoadTexture("assets/corner-2-small.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 6) {
                                body[i][j] = LoadTexture("assets/corner-4-small.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                            else if(collision[i][j] == 7) {
                                body[i][j] = LoadTexture("assets/corner-3-small.png");
                                DrawTexture(body[i][j], j * cube.width, i * cube.height, WHITE);
                            }
                        }
                        sum++;
                    }
                }
            }

            if(level != 10) {
                if(current_form == 1) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-1.png");
                }
                else if(current_form == 2) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-2.png");
                }
                if(current_form == 3) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-3.png");
                }
                else if(current_form == 4) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-4.png");
                }
            }
            else {
                if(current_form == 1) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-1-small.png");
                }
                else if(current_form == 2) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-2-small.png");
                }
                if(current_form == 3) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-3-small.png");
                }
                else if(current_form == 4) {
                    UnloadTexture(current);
                    current = LoadTexture("assets/current-4-small.png");
                }
            }

            DrawTexture(current, cube.x, cube.y, WHITE);
            DrawTexture(initial, init_x, init_y, WHITE);

            if(sum == (lines * columns) - 1) {

                if(wait == 1) {
                    wait = 0;
                    UnloadTexture(initial);
                    freeTexture(body, lines, columns);
                    body = textureAloc(lines, columns);
                    if(level != 9) {
                        initial = LoadTexture("assets/initial.png");
                    }
                    else {
                        initial = LoadTexture("assets/initial-small.png");
                    }
                    if(level == 1) {
                        strcpy(mesage, "Level 2");
                        setLevel_2(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 2;
                        WaitTime(1.0f);
                    }
                    else if(level == 2) {
                        strcpy(mesage, "Level 3");
                        setLevel_3(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 3;
                        WaitTime(1.0f);
                    }
                    else if(level == 3) {
                        UnloadTexture(floor);
                        floor = LoadTexture("assets/wood-floor.png");
                        strcpy(mesage, "Level 4");
                        setLevel_4(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 4;
                        WaitTime(1.0f);
                    }
                    else if(level == 4) {
                        strcpy(mesage, "Level 5");
                        setLevel_5(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 5;
                        WaitTime(1.0f);
                    }
                    else if(level == 5) {
                        strcpy(mesage, "Level 6");
                        setLevel_6(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 6;
                        WaitTime(1.0f);
                    }
                    else if(level == 6) {
                        strcpy(mesage, "Level 7");
                        setLevel_7(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 7;
                        WaitTime(1.0f);
                    }
                    else if(level == 7) {
                        UnloadTexture(floor);
                        floor = LoadTexture("assets/quartz-floor.png");
                        strcpy(mesage, "Level 8");
                        setLevel_8(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 8;
                        WaitTime(1.0f);
                    }
                    else if(level == 8) {
                        strcpy(mesage, "Level 9");
                        setLevel_9(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 9;
                        WaitTime(1.0f);
                    }
                    else if(level == 9) {
                        strcpy(mesage, "Final Level");

                        freeTexture(body, lines, columns);
                        freeMap(collision, lines);
                        freeMap(map, lines);

                        lines = 16;
                        columns = 16;

                        body = textureAloc(lines, columns);
                        collision = mapAloc(lines, columns);
                        map = mapAloc(lines, columns);

                        setLevel_10(&collision, lines, columns, &map, &cube, &direction, &init_x, &init_y, &init);
                        level = 10;
                        WaitTime(1.0f);
                    }
                    else if(level == 10) {
                        UnloadTexture(floor);
                        floor = LoadTexture("assets/grass-floor.png");

                        strcpy(mesage, "Congratulations!");

                        freeTexture(body, lines, columns);
                        freeMap(collision, lines);
                        freeMap(map, lines);

                        lines = 8;
                        columns = 8;

                        body = textureAloc(lines, columns);
                        collision = mapAloc(lines, columns);
                        map = mapAloc(lines, columns);

                        screen = 4;

                        level = 1;
                        WaitTime(1.0f);
                    }

                }
                else {
                    wait = 1;
                }
            }

            sum = 0;
            DrawText(mesage, 600 + (200 - MeasureText(mesage, 30))/2, 35, 30, BLACK);
        }
        else if(screen == 4) {
            setCongratulations(&screen, button3, 30, 20, mesage, back, to_menu);
        }
        EndDrawing();
    }

    UnloadImage(icon);

    UnloadTexture(initial);
    UnloadTexture(current);
    UnloadTexture(bricks);
    UnloadTexture(floor);

    freeTexture(body, lines, columns);
    freeMap(collision, lines);
    freeMap(map, lines);

    CloseWindow();
    return 0;
}