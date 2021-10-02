#include "GameScene.h"

GameScene::GameScene()
{
    GameScene::m = new Model(new float[16] {
        -0.5f, -0.5f, 0.0f, 0.0f, // 0
            0.5f, -0.5f, 1.0f, 0.0f, // 1
            0.5f, 0.5f, 1.0f, 1.0f, // 2
        -0.75f, 0.75f, 0.0f, 1.0f  // 3
    });
    texi = new Texture("./res/textures/giordano.jpg");
}

void GameScene::update()
{
	//std::cout << "Hello Game" << std::endl;
}

void GameScene::render(Renderer* renderer)
{
    renderer->renderColor(*m, {1, 1, 1, 0});
}