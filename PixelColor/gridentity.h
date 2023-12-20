#ifndef GRIDENTITY_H
#define GRIDENTITY_H

#include <rt2d/entity.h>

class GridEntity: public Entity
{
	public:
		GridEntity();
		virtual ~GridEntity();

		virtual void update(float deltaTime);

	private:
};

#endif
