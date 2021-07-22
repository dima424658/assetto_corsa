#pragma once

class Game
{
// void __userpurge Game::Game(@<ecx>, __m128 a2@<xmm1>, std::wstring name, VideoSettings *videoSettings);
void Game::~Game();
Game *Game::`vector deleting destructor'(unsigned int a2);
void Game::deleteGameObjectRec(GameObject *go);
void Game::onIdle();
void Game::render(GameObject *o, float dt);
void Game::renderAudio(GameObject *o, float dt);
void Game::renderHUD(GameObject *o, float dt);
void Game::renderHUDOnDemand(float dt);
void Game::run();
void Game::shutdown();
void Game::shutdownObject(GameObject *o);
void Game::update(GameObject *o, float dt);

};