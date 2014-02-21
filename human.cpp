#include <iostream>
#include "human.h"
#include "cylinder.h"

const float HEIGHT_TORSO = 4;
const float RADIUS_HEAD = 1;
const float RADIUS_TORSO = 1;
const float RADIUS_ARM = 0.5;

float ElbowJointAngle = 0;
float WristJointAngle = 0;
float FingerJointAngle = 0;

using namespace std;

void Human::draw() {
    //drawImmediate();
}

void Human::drawTorso() {
    Cylinder cylinder(HEIGHT_TORSO, RADIUS_TORSO);
    cylinder.draw();
}

void Human::drawHead() {
    glPushMatrix();
    glTranslatef(0, 0, HEIGHT_TORSO / 2 + RADIUS_HEAD);
    glutSolidSphere(1, 50, 50);
    glPopMatrix();

}

void Human::drawRightUpperArm() {
    Cylinder cylinder(HEIGHT_TORSO, RADIUS_ARM);
    cylinder.draw();
}

//==================== 1. Immediate method ===================================
// immediate definition of individual vertex properties

void Human::drawImmediate() {
    glPushMatrix();
    {
        drawTorso();
        drawHead();

        //Drawing the right arm
        glPushMatrix();
        {

            glTranslatef(RADIUS_TORSO, RADIUS_TORSO, 0);
            //glRotatef(90,1,1,/*HEIGHT_TORSO/2*/0);
            drawRightUpperArm();
            glPopMatrix();
        }

        //Drawing the left arm
        glPushMatrix();
        {

            glTranslatef(-RADIUS_TORSO, -RADIUS_TORSO, 0);
            //glRotatef(90,1,1,/*HEIGHT_TORSO/2*/0);
            drawRightUpperArm();
            glPopMatrix();
        }

        //Drawing the left leg
        glPushMatrix();
        {

            glTranslatef(RADIUS_ARM / 2, RADIUS_ARM / 2, -HEIGHT_TORSO);
            drawRightUpperArm();
            glPopMatrix();
        }

        //Drawing the right leg
        glPushMatrix();
        {

            glTranslatef(-RADIUS_ARM / 2, -RADIUS_ARM / 2, -HEIGHT_TORSO);
            drawRightUpperArm();
            glPopMatrix();
        }
    }
    glPopMatrix();
}