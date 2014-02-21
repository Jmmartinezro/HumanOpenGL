#include <iostream>
#include <math.h>
#include "human.h"

const int PRECISION = 20;

const float ARM_UP_RADIUS = 0.3;
const float ARM_HEIGHT = 1.5;
const float FOREARM_RADIUS = 0.5;
//const float CODE_RADIUS=0.5;
const float FOREARM_DOWN_RADIUS = 0.6;
const float FOREARM_UP_RADIUS = 0.4;
const float FOREARM_HEIGHT = 2;
const float HEAD_RADIUS = 1;
const float HIP_RADIUS = 0.5;
const float HIP_HEIGHT = 3;
const float KNEE_RADIUS = 0.7;
const float SHIN_UP_RADIUS = 0.6;
const float SHIN_DOWN_RADIUS = 0.45;
const float SHIN_HEIGHT = 2;
const float SHOULDER_ANGLE = 25;
const float SHOULDER_DISTANCE = 2;
const float SHOULDER_RADIUS = 0.6;
const float THIGH_HEIGHT = 1.8;
const float THIGH_DOWN_RADIUS = 0.6;
const float THIGH_UP_RADIUS = 0.8;
const float TORSO_DOWN_RADIUS = 2;
const float TORSO_UP_RADIUS = 1.5;
const float TORSO_HEIGHT = 4;

GLUquadricObj *quadratic;

using namespace std;

void Human::draw() {
    glPushMatrix();
    {
        drawUpperTorso();
        drawLowerTorso();
    }
    glPopMatrix();
}

void Human::drawUpperTorso() {
    drawTorso();
    glPushMatrix();
    {
        glTranslatef(0.0, 0.25, 0.0);
        drawNeck();
        glPushMatrix();
        {
            glTranslatef(0.0, 0.9, 0.0);
            drawHead();
        }
        glPopMatrix();
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(SHOULDER_DISTANCE, -SHOULDER_RADIUS, 0.0);
        drawFullArm(SHOULDER_ANGLE);
    }
    glPopMatrix();
    glPushMatrix();
    {
        glTranslatef(-SHOULDER_DISTANCE, -SHOULDER_RADIUS, 0.0);
        drawFullArm(-SHOULDER_ANGLE);
    }
    glPopMatrix();
}

void Human::drawLowerTorso() {
    glPushMatrix();
    {
        glTranslatef(-1.5, -4.5, 0.0);
        drawHip();
        glPushMatrix();
        {
            glTranslatef(2.2, -HIP_RADIUS, 0.0);
            drawFullLeg();
        }
        glPopMatrix();
        glPushMatrix();
        {
            glTranslatef(0.7, -HIP_RADIUS, 0.0);
            drawFullLeg();
        }
        glPopMatrix();
    }
    glPopMatrix();
}

void Human::drawHip() {
    glPushMatrix();
    {
        glRotatef(90, 0, 1, 0);
        glColor3f(0.0f, 0.0f, 0.6f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, HIP_RADIUS, HIP_RADIUS, HIP_HEIGHT, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawTorso() {
    glPushMatrix();
    {
        glRotatef(90, 1, 0, 0);
        glColor3f(1.0f, 0.0f, 0.0f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, TORSO_DOWN_RADIUS, TORSO_UP_RADIUS, TORSO_HEIGHT, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawHead() {
    glPushMatrix();
    {
        glColor3f(1.0f, 0.64f, 0.52f);
        glutSolidSphere(HEAD_RADIUS, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawNeck() {
    glPushMatrix();
    {
        glRotatef(90, 1, 0, 0);
        glColor3f(1.0f, 0.64f, 0.52f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, 0.40f, 0.40f, 0.30, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawShoulder() {
    glPushMatrix();
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        glutSolidSphere(SHOULDER_RADIUS, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawForearm() {
    glPushMatrix();
    {
        glRotatef(90, 1, 0, 0);
        glColor3f(1.0f, 0.64f, 0.52f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, FOREARM_DOWN_RADIUS, FOREARM_UP_RADIUS, FOREARM_HEIGHT, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawElbow() {
    glPushMatrix();
    {
        glColor3f(1.0f, 0.64f, 0.52f);
        glutSolidSphere(FOREARM_RADIUS, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawArm() {
    glPushMatrix();
    {
        glRotatef(90, 1, 0, 0);
        glColor3f(1.0f, 0.64f, 0.52f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, FOREARM_RADIUS, ARM_UP_RADIUS, ARM_HEIGHT, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawHand() {
    glPushMatrix();
    {
        glColor3f(1.0f, 0.64f, 0.52f);
        glutSolidSphere(SHOULDER_RADIUS, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawFullArm(float angleShoulder) {
    glPushMatrix();
    {
        drawShoulder();
        glRotatef(angleShoulder, 0, 0, 1);
        glPushMatrix();
        {
            drawForearm();
            glPushMatrix();
            {
                glTranslatef(0.0, -2.0, 0.0);
                drawElbow();
                glPushMatrix();
                {
                    drawArm();
                    glPushMatrix();
                    {
                        glTranslatef(0.0, -2.1, 0.0);
                        drawHand();
                    }
                    glPopMatrix();
                }
                glPopMatrix();
            }
            glPopMatrix();
        }
        glPopMatrix();
    }
    glPopMatrix();
}

void Human::drawFullLeg() {
    glPushMatrix();
    {
        drawThigh();
        glPushMatrix();
        {
            glTranslatef(0.0, -2.2, 0.0);
            drawKnee();
            glPushMatrix();
            {
                glTranslatef(0.0, -0.4, 0.0);
                drawShin();
                glPushMatrix();
                {
                    glTranslatef(0.0, -2.2, 0.5);
                    drawFoot();
                }
                glPopMatrix();
            }
            glPopMatrix();
        }
        glPopMatrix();

    }
    glPopMatrix();
}

void Human::drawThigh() {
    glPushMatrix();
    {
        glRotatef(90, 1, 0, 0);
        glColor3f(0.0f, 0.0f, 0.6f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, THIGH_UP_RADIUS, THIGH_DOWN_RADIUS, TORSO_HEIGHT, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawKnee() {
    glPushMatrix();
    {
        glColor3f(0.0f, 0.0f, 0.6f);
        glutSolidSphere(KNEE_RADIUS, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawShin() {
    glPushMatrix();
    {
        glRotatef(90, 1, 0, 0);
        glColor3f(0.0f, 0.0f, 0.6f);
        quadratic = gluNewQuadric();
        gluCylinder(quadratic, SHIN_UP_RADIUS, SHIN_DOWN_RADIUS, SHIN_HEIGHT, PRECISION, PRECISION);
    }
    glPopMatrix();
}

void Human::drawFoot() {
    glPushMatrix();
    {
        glColor3f(0.8, 0.8, 0.8);
        glScalef(0.4, 0.5, 1.5);
        glutSolidCube(1);
    }
    glPopMatrix();
}
