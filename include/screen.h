#ifndef SCREEN_H
#define SCREEN_H

void setMenu(int *screen, Rectangle button, Rectangle button2, int playFontSize, int how_to_playFontSize, char *title, char *play, char *how_to_play, char *creator);

void setHow_to_Play(int *screen, Rectangle button, int objectivesFontSize, int textFontSize, int backFontSize, char *objectives, char *text1, char *text2, char *gameplay, char *tip1, char *tip2, char *tip3, char *tip4, char *tip5, char *back);

void setCongratulations(int *screen, Rectangle button, int backFontSize, int to_menuFontSize, char *congratulations, char *back, char *to_menu);

#endif