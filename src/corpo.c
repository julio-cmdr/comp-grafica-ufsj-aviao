#include "corpo.h"
#include "math.h"

void desenha_corpo(){

    glPushMatrix();
        glRotatef(180, 0, 1, 0);
        
        glColor3f(1, 0, 0);    
        glScalef(0.5f, 1.0f, 1.0f);
        glTranslatef(0, 0, -47.5);
        gluDisk(gluNewQuadric(), 0, 8, 32, 32);

        glColor3f(1, 1, 1);    

        gluCylinder(gluNewQuadric(), 8, 20, 30, 32, 32);
        glTranslatef(0, 0, 30);
        
        gluCylinder(gluNewQuadric(), 20, 20, 35, 32, 32);
        glTranslatef(0, 0, 35);
        
        gluCylinder(gluNewQuadric(), 20, 15, 40, 32, 32);
        glTranslatef(0, 0, 40);
        
        gluCylinder(gluNewQuadric(), 15, 15, 30, 32, 32);
        glTranslatef(0, 0, 30);
        
        gluDisk(gluNewQuadric(), 0, 15, 32, 32);
    glPopMatrix();

}
