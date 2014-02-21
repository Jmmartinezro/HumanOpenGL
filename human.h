#ifndef _Human_
#define _Human_

#include "renderable.h"
#ifndef __APPLE__
#include <GL/glut.h>
#else
#include <GLUT/glut.h>
#endif

class Human : public Renderable {
public:
    void draw();

private:
    void drawArm();
    void drawElbow();
    void drawFoot();
    void drawForearm();
    void drawFullArm(float angleShoulder);
    void drawFullLeg();
    void drawHand();
    void drawHead();
    void drawHip();
    void drawKnee();
    void drawNeck();
    void drawLowerTorso();
    void drawUpperTorso();
    void drawShin();
    void drawShoulder();
    void drawThigh();
    void drawTorso();
};

#endif

