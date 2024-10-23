#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h.>
#include "../include/screen.h"

void setMenu(int *screen, Rectangle button, Rectangle button2, int playFontSize, int how_to_playFontSize, char *title, char *play, char *how_to_play, char *creator) {
    Vector2 mousePosition = GetMousePosition();
    bool buttonHovered = CheckCollisionPointRec(mousePosition, button);
    bool buttonHovered2 = CheckCollisionPointRec(mousePosition, button2);
    bool buttonPressed = false;
    bool button2Pressed = false;

    if (buttonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        buttonPressed = true;
    }
    if (buttonHovered2 && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        button2Pressed = true;
    }

    if (buttonHovered) {
        playFontSize = 100;
        DrawRectangleRec(button, ORANGE);
    } 
    else {
        playFontSize = 50;
        DrawRectangleRec(button, ORANGE);
    }
    if (buttonHovered2) {
        how_to_playFontSize = 60;
        DrawRectangleRec(button2, ORANGE);
    } 
    else {
        how_to_playFontSize = 36;
        DrawRectangleRec(button2, ORANGE);
    }

    int titleWidth = MeasureText(title, 100);
    int playWidth = MeasureText(play, playFontSize);
    int how_to_playWidth = MeasureText(how_to_play, how_to_playFontSize);
    int creatorWidth = MeasureText(creator, 20);

    ClearBackground(ORANGE);
    DrawText(title, (GetScreenWidth() - titleWidth)/2, 200, 100, DARKGRAY);
    DrawText(play, button.x + (button.width - playWidth)/2, button.y + (button.height - playFontSize)/2, playFontSize, BLACK);
    DrawText(how_to_play, button2.x + (button2.width - how_to_playWidth)/2, button2.y + (button2.height - how_to_playFontSize)/2, how_to_playFontSize, BLACK);
    DrawText(creator, (GetScreenWidth() - creatorWidth)/2, 750, 20, BLACK);

    if (buttonPressed) {
        buttonPressed = false;
        (*screen) = 3;
    }
    if (button2Pressed) {
        button2Pressed = false;
        (*screen) = 2;
    }
}

void setHow_to_Play(int *screen, Rectangle button, int objectivesFontSize, int textFontSize, int backFontSize, char *objectives, char *text1, char *text2, char *gameplay, char *tip1, char *tip2, char *tip3, char *tip4, char *tip5, char *back) {
    Vector2 mousePosition = GetMousePosition();
    bool buttonHovered = CheckCollisionPointRec(mousePosition, button);
    bool buttonPressed = false;

    if (buttonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        buttonPressed = true;
    }

    if (buttonHovered) {
        backFontSize = 75;
        DrawRectangleRec(button, ORANGE);
    } 
    else {
        backFontSize = 50;
        DrawRectangleRec(button, ORANGE);
    }
    
    int objectivesWidth = MeasureText(objectives, objectivesFontSize);
    int textWidth = MeasureText(text1, textFontSize);
    int text2Width = MeasureText(text2, textFontSize);
    int gameplayWidth = MeasureText(gameplay, objectivesFontSize);
    int tipWidth = MeasureText(tip4, textFontSize);
    int backWidth = MeasureText(back, backFontSize);

    ClearBackground(ORANGE);
    DrawText(objectives, (GetScreenWidth() - objectivesWidth)/2, 100, objectivesFontSize, BLACK);
    DrawText(text1, (GetScreenWidth() - textWidth)/2, 200, textFontSize, BLACK);
    DrawText(text2, (GetScreenWidth() - text2Width)/2, 230, textFontSize, BLACK);
    DrawText(gameplay, (GetScreenWidth() - gameplayWidth)/2, 300, objectivesFontSize, BLACK);
    DrawText(tip1, (GetScreenWidth() - tipWidth)/2, 400, textFontSize, BLACK);
    DrawText(tip2, (GetScreenWidth() - tipWidth)/2, 430, textFontSize, BLACK);
    DrawText(tip3, (GetScreenWidth() - tipWidth)/2, 460, textFontSize, BLACK);
    DrawText(tip4, (GetScreenWidth() - tipWidth)/2, 490, textFontSize, BLACK);
    DrawText(tip5, (GetScreenWidth() - tipWidth)/2, 520, textFontSize, BLACK);
    DrawText(back, button.x + (button.width - backWidth)/2, button.y + (button.height - backFontSize)/2, backFontSize, BLACK);

    if (buttonPressed) {
        buttonPressed = false;
        (*screen) = 1;
    }
}

void setCongratulations(int *screen, Rectangle button, int backFontSize, int to_menuFontSize, char *congratulations, char *back, char *to_menu) {
    Vector2 mousePosition = GetMousePosition();
    bool buttonHovered = CheckCollisionPointRec(mousePosition, button);
    bool buttonPressed = false;

    if (buttonHovered && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        buttonPressed = true;
    }

    if (buttonHovered) {
        backFontSize = 60;
        to_menuFontSize = 40;
        DrawRectangleRec(button, ORANGE);
    } 
    else {
        backFontSize = 30;
        to_menuFontSize = 20;
        DrawRectangleRec(button, ORANGE);
    }

    int congratulationsWidth = MeasureText(congratulations, 50);
    int backWidth = MeasureText(back, backFontSize);
    int to_menuWidth = MeasureText(to_menu, to_menuFontSize);

    ClearBackground(ORANGE);
    DrawText(congratulations, (GetScreenWidth() - congratulationsWidth)/2, 300, 50, BLACK);
    DrawText(back, button.x + (button.width - backWidth)/2, button.y + (button.height - (backFontSize + to_menuFontSize))/2, backFontSize, BLACK);
    DrawText(to_menu, button.x + (button.width - to_menuWidth)/2, button.y + (button.height - (backFontSize + to_menuFontSize))/2 + backFontSize, to_menuFontSize, BLACK);

    if (buttonPressed) {
        buttonPressed = false;
        (*screen) = 1;
    }
}
