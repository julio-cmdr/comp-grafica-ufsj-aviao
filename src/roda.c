#include "roda.h"

void desenha_roda(){
    glColor3f(0.2f, 0.2f, 0.2f);
    glutSolidTorus(1.5f, 6.0f, 32, 32);   //pneu
    glColor3f(1.0f, 0.0f, 0.0f);    

    glPushMatrix();
        glTranslatef(0.0f, 0.0f, 1.0f);        
        gluDisk(gluNewQuadric(), 0, 5, 20, 20);
        glTranslatef(0.0f, 0.0f, -2.0f);
        gluDisk(gluNewQuadric(), 0, 5, 20, 20);
    glPopMatrix();
}