#include <raylib.h>
#include "game.hpp"
#include <string>

std::string FromatWithLeadZeros(int number, int width){
    std::string numberText = std::to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = std::string(leadingZeros,'0') + numberText;
} 

int main()
{ 

    Color grey = {29,29,27,255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50;
    int windowWidth= 750;
    int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2*offset, "C++ Space Invaders");

    InitAudioDevice();

    Font font = LoadFontEx("Font/monogram.ttf",64,0,0);

    Texture2D spaceshipImage = LoadTexture("Graphics/spaceship.png");

    SetTargetFPS(60);

    Game game;


    while (WindowShouldClose() == false)
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        game.Update();
        BeginDrawing();
        ClearBackground(grey);
        DrawRectangleRoundedLines({10, 10, 780, 780}, 0.188f, 20, 2, yellow);
        DrawLineEx({25,730},{775,730},3,yellow);
        if(game.run){
            DrawTextEx(font, "LEVEL SABKE NIKALNGE",{570, 740},17,2,yellow);
        }else{
            DrawTextEx(font, "TUMSE NA HOPAYEGA",{570, 740},17,2,yellow);
        }

        float x = 50.0;
        for(int i=0; i<game.lives; i++){
            DrawTextureV(spaceshipImage,{x, 754}, WHITE);
            x += 50;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34,2,  yellow);
        std::string scoreText = FromatWithLeadZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        game.Draw();
        EndDrawing();

    } 
    CloseWindow();
    CloseAudioDevice();

    return 0;
}