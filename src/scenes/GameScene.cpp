#include "GameScene.h"

GameScene::GameScene()
{
    m = new Model(new float[24] {
        -0.5f, -0.5f, 0.0f, 0.0f, // 0
        0.5f, -0.5f, 0.0f, 0.0f, // 1
        0.75f, 0.0f, 0.0f, 0.0f, // 2
        0.5f, 0.5f, 0.0f, 0.0f, // 2
        -0.5f, 0.5f, 0.0f, 0.0f,  // 3
        -0.75f, 0.0f, 0.0f, 0.0f  // 3
    }, 6, new unsigned int[12]{
        1, 2, 3,
        0, 4, 5,
        0, 1, 3,
        0, 4, 3
    }, 12);
    // m = new Model(new float[20] {
    //     -0.5f, -0.5f, 0.0f, 0.0f, // 0
    //     0.5f, -0.5f, 0.0f, 0.0f, // 1
    //     0.5f, 0.5f, 0.0f, 0.0f, // 2
    //     0.0f, 0.75f, 0.0f, 0.0f, // 2
    //     -0.5f, 0.5f, 0.0f, 0.0f,  // 3
    // }, 5);
    // m = new Model(new float[16] {
    //     -0.6f, -0.5f, 0.0f, 0.0f, // 0
    //     0.5f, -0.5f, 1.0f, 0.0f, // 1
    //     0.6f, 0.5f, 1.0f, 1.0f, // 2
    //     -0.5f, 0.5f, 0.0f, 1.0f  // 3
    // });
    texi = new Texture("./res/textures/giordano.jpg");
}

void GameScene::update()
{
	//std::cout << "Hello Game" << std::endl;
}

void GameScene::render(Renderer* renderer)
{
    renderer->renderColor(*m, {1, 0, 1, 1});
}