#include <iostream>
#include "human.h"
#include "cylinder.h"

int head_torso=2;

using namespace std;

void Human::draw() {
    glPushMatrix();
    drawImmediate();
    glTranslatef(-2, 0, 0);
    glPopMatrix();
}


void Human::drawTorso(){
    Cylinder cylinder(head_torso,1);
    cylinder.draw();
}

void Human::drawHead(){
    glutSolidSphere(1,50,50);
}

//==================== 1. Immediate method ===================================
// immediate definition of individual vertex properties

void Human::drawImmediate() {
    //Hierarchical Modeling Opengl
    glPushMatrix();
        //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glColor3d(1,0,0); 
        //glTranslatef(10,0,0);
        glRotatef(45,0,0,1);
        drawTorso();
        glPushMatrix();
                glTranslatef(0,0,head_torso);
                glRotatef(45,0,0,1);
                //glRotatef(45,1,0,0);
                drawHead();
        glPopMatrix();
        glPushMatrix();
                //glTranslate(...);
                //glRotate(...);
                //left_upper_leg();
        glPopMatrix();
    glPopMatrix();
}



