#pragma once

void CreateStaticEntity(CH::Application* app, std::string spriteName, int posX, int posY, int sizeX, int sizeY);
void CreateCamera(CH::Application* app, CH::Entity* playerEntity);
CH::Entity* CreatePlayer(CH::Application* app);
