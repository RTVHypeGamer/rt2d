#include "superscene.h"

int SuperScene::activescene = 0;

SuperScene::SuperScene() : Scene()
{
	player = nullptr;
	top_layer = 7; // 8 layers (0-7)

	for (unsigned int i = 0; i <= top_layer; i++) {
		GridEntity* layer = new GridEntity();
		layers.push_back(layer);
		this->addChild(layer);
	}

	for (unsigned int i = 0; i < 16; i++) {
		Text* line = new Text();
		line->scale = Point2(0.5f, 0.5f);

		text.push_back(line);
		layers[top_layer]->addChild(line);
	}
}


SuperScene::~SuperScene()
{
	int ls = layers.size();
	for (int i=0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = nullptr;
	}
	layers.clear();

	int ts = text.size();
	for (int i=0; i<ts; i++) {
		this->removeChild(text[i]);
		delete text[i];
		text[i] = nullptr;
	}
	text.clear();
}

// must be explicitly called from subclass
void SuperScene::update(float deltaTime)
{
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
	if (input()->getKeyUp(KeyCode::LeftBracket)) {
		activescene--;
	}
	if (input()->getKeyUp(KeyCode::RightBracket)) {
		activescene++;
	}
	for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) {
		if (input()->getMouseUp( i )) {
			
		}
		if (input()->getMouseDown( i )) {
			
			player->mouseclicks++;
		}
	}

	Point2 cam_pos = Point2(camera()->position.x, camera()->position.y);

	unsigned int s = text.size();
	for (unsigned int i = 0; i < s; i++) {
		text[i]->position = Point2(cam_pos.x + 50 - SWIDTH/2, cam_pos.y + 50 + (30*i) - SHEIGHT/2);
	}
}

void SuperScene::Camera(float deltaTime)
{
	float speed = 600.0f;

	Point2 right = Point2(1, 0);
	Point2 up = Point2(0, 1);

	Vector2 direction = Vector2(0,0);

	if (input()->getKey(KeyCode::Up)) {
		direction -= up;
	}
	if (input()->getKey(KeyCode::Down)) {
		direction += up;
	}
	if (input()->getKey(KeyCode::Right)) {
		direction += right;
	}
	if (input()->getKey(KeyCode::Left)) {
		direction -= right;
	}
	direction.normalize();
	direction *= deltaTime * speed;
	camera()->position += direction;
}
