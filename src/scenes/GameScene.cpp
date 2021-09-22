#include "GameScene.h"

GameScene::GameScene()
{
	//Renderer::init();
    GameScene::m = new Model(new float[16] {
        -0.5f, -0.5f, 0.0f, 0.0f, // 0
            0.5f, -0.5f, 1.0f, 0.0f, // 1
            0.5f, 0.5f, 1.0f, 1.0f, // 2
        -0.5f, 0.5f, 0.0f, 1.0f  // 3
    });
    texi = new Texture("ressources/textures/shiat.png");
}

void GameScene::update()
{
	//std::cout << "Hello Game" << std::endl;
    Renderer::renderTest(*m, *texi);
}

void GameScene::render()
{

}