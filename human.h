#ifndef _Human_
#define _Human_

#include "renderable.h"
#ifndef __APPLE__
	#include <GL/glut.h>
#else
	#include <GLUT/glut.h>
#endif


class Human : public Renderable
{
	public:
		void draw();

	private:
		void drawImmediate();
                void drawHead();
                void drawTorso();
};

#endif

