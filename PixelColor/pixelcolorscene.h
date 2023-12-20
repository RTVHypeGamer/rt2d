#ifndef PIXELCOLORSCENE_H
#define PIXELCOLORSCENE_H

#include <vector>
#include <rt2d/timer.h>
#include "superscene.h"
#include "gridentity.h"

class PixelColorScene: public SuperScene
{
public:
	PixelColorScene();
	virtual ~PixelColorScene();

	virtual void update(float deltaTime);

private:
	GridEntity* grid;

	int gridwidth;
	int gridheight;
	int cellwidth;
	int cellheight;
};

#endif
