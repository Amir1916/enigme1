#ifndef HEADER_H
#define HEADER_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>

#define SCREEN_W 1280
#define SCREEN_H 720

typedef struct {
    SDL_Surface* surface;
    SDL_Rect rect;
    int active;
} Button;

typedef struct {
    const char* question;
    const char* answerA;
    const char* answerB;
    const char* answerC;
    int correctAnswer;
} Quiz;

typedef struct {
    int x;
    int y;
} SDL_Point;

typedef int GameState;
#define MAIN_MENU 0
#define QUIZ 1

extern Mix_Chunk* hoverSound;
extern Mix_Chunk* clickSound;
extern Mix_Music* bgMusic;
extern GameState currentState;
extern int currentQuizIndex;
extern SDL_Surface* digit_images[10]; // <-- Ajouté pour les chiffres du timer
extern SDL_Surface* sablier_images[4];

// Déclarations des fonctions
void init_SDL();
extern int SDL_PointInRect(const SDL_Point* p, const SDL_Rect* r);
SDL_Surface* load_image(const char* filename);
void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* dest);
void load_assets(SDL_Surface** background, SDL_Surface** quizBtnImg, SDL_Surface** puzzleBtnImg, SDL_Surface** optionA, SDL_Surface** optionB, SDL_Surface** optionC, TTF_Font** font);
void handle_events(int* running, Button buttons[], int buttonCount);
void render(SDL_Surface* screen, SDL_Surface* background, Button buttons[], int buttonCount, TTF_Font* font);
void cleanup(SDL_Surface* background, SDL_Surface* quizBtnImg, SDL_Surface* puzzleBtnImg, SDL_Surface* optionA, SDL_Surface* optionB, SDL_Surface* optionC, TTF_Font* font);
void load_sablier_images();
void free_sablier_images();
void load_digit_images();  // <-- Nouvelle fonction
void free_digit_images();  // <-- Nouvelle fonction
#endif // HEADER_H

