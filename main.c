#include <raylib.h>
#include "raylib.h"

typedef struct {
    Vector2 position;
    Texture2D texture;

    float speed;
    float scale;
}PLAYER;

int main(void){

    //Window
    const int screenWidth= 1280;
    const int screenHeight= 720;

    InitWindow(screenWidth, screenHeight, "Gunslinger");
    SetTargetFPS(60);

    //Player
    PLAYER player= {0};
    player.texture= LoadTexture("assets/player.png");
    player.position= (Vector2){
        screenWidth/2.0f,
        screenWidth/2.0f};
    player.speed= 250.0f;
    player.scale= 0.10f;

    //Main Game Loop
    while(!WindowShouldClose()){
        float dT= GetFrameTime();

        //Inputs
        if (IsKeyDown(KEY_E)){
                    player.position.y -= player.speed*dT;}
        if (IsKeyDown(KEY_D)){
                    player.position.y += player.speed*dT;}
        if (IsKeyDown(KEY_S)){
                    player.position.x -= player.speed*dT;}
        if (IsKeyDown(KEY_F)){
                    player.position.x += player.speed*dT;}

        //Draw Loop
        BeginDrawing();
        ClearBackground(BLACK);

        DrawTextureEx(player.texture, player.position, 0.0f, player.scale, WHITE);
        EndDrawing();
        }

        //Cleanup
        UnloadTexture(player.texture);
        CloseWindow();
        return 0;
}
