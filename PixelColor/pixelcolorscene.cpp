#include "PixelColorscene.h"

PixelColorScene::PixelColorScene() : SuperScene()
{
	text[0]->message("Move the camera with W, A, S, D");
	gridwidth = 512;
	gridheight = 256;
	cellwidth = 64;
	cellheight = 64;

	grid = new GridEntity();
	grid->addGrid("assets/pixelcoloer.tga", 8, 8, gridwidth, gridheight, cellwidth, cellheight);

	layers[0]->addChild(grid);

	int counter = 0;
	for (int x=0; x<gridwidth; x++) {
		for (int y=0; y<gridheight ; y++) {
			grid->spritebatch()[counter]->frame(rand()%16);
			counter++;
		}
	}

}


PixelColorScene::~PixelColorScene()
{
	layers[0]->removeChild(grid);
	delete grid;
}

void PixelColorScene::update(float deltaTime)
{
	SuperScene::update(deltaTime);
	SuperScene::Camera(deltaTime);

	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH/2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT/2;

	std::vector<Sprite*> spritebatch = grid->spritebatch();
	int counter = 0;
	for (int x=0; x<gridwidth; x++) {
		for (int y=0; y<gridheight ; y++) {
			Point2 pos = spritebatch[counter]->spriteposition;

			int halfwidth = cellwidth/2;
			int halfheight = cellheight/2;
			int left = pos.x - halfwidth;
			int right = pos.x + halfwidth;
			int top = pos.y - halfheight;
			int bottom = pos.y + halfheight;

			if ( mousex > left && mousex < right && mousey > top && mousey < bottom ) {
				spritebatch[counter]->color.a = 192;
				if (input()->getMouseDown( 0 )) {
					spritebatch[counter]->frame(rand()%16);
				}
			} else {
				spritebatch[counter]->color.a = 255;
			}
			counter++;
		}
	}
}