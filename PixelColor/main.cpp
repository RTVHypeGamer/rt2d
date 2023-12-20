#include <rt2d/core.h>

#include "PixelColorscene.h"


int main( void )
{
	
	Core core;

	
	std::vector<SuperScene*> scenes;
	scenes.push_back(new PixelColorScene());
	int s = scenes.size();

	
	Player* player = new Player();

	
	for (int i = 0; i < s; i++) {
		scenes[i]->addPlayer(player);
	}

	
	SuperScene* scene = scenes[0];
	int scenecounter = 0;
	int running = 1;
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s-1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s-1; scene->activescene = s-1; }
		scene = scenes[scenecounter];
		core.run(scene);
		core.showFrameRate(5); 
		if (!scene->isRunning()) { running = 0; }
	}
	for (int i = 0; i < s; i++) {
		delete scenes[i];
		scenes[i] = nullptr;
	}
	scenes.clear();
	delete player;

	return 0;
}