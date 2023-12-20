#ifndef SUPERSCENE_H
#define SUPERSCENE_H

#include <vector>
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "gridentity.h"

struct Player
{
	int mouseclicks = 0;
};

class SuperScene: public Scene
{
public:
	SuperScene();
	virtual ~SuperScene();

	// must be explicitly called from subclass
	virtual void update(float deltaTime);
	void addPlayer(Player* p) { player = p; };

	static int activescene;

protected:
	unsigned int top_layer;
	std::vector<GridEntity*> layers;
	std::vector<Text*> text;
	Player* player;
	void Camera(float deltaTime);

private:
};

#endif
