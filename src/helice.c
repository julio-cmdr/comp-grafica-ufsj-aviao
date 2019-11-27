#include "helice.h"

void desenha_helice(float giro){
    

    glPushMatrix();
        glRotatef(giro, 0, 0, 1);
        glScalef(0.5, 0.5, 0.5);

        glColor3f(1.0f, 0.0f, 0.0f);
        
        // centro
        gluDisk(gluNewQuadric(), 0, 5, 100, 100);
        gluCylinder(gluNewQuadric(), 5, 3, 5, 100, 100);
        glTranslatef(0.0f, 0.0f, 5.0f);
        gluDisk(gluNewQuadric(), 0, 3, 100, 100);

        glTranslatef(-24.0f, 0.0f, 0.0f);
        glScalef(6, 1, 1);
        
        // hélice esquerda
        gluCylinder(gluNewQuadric(), 4, 4, 1, 100, 100);        
        glColor3f(1.0f, 1.0f, 1.0f);
        gluDisk(gluNewQuadric(), 0, 4, 100, 100);
        glTranslatef(0.0f, 0.0f, 1.0f);
        gluDisk(gluNewQuadric(), 0, 4, 100, 100);

        glTranslatef(8.0f, 0.0f, -1.0f);
        
        // hélice direita
        glColor3f(1.0f, 0.0f, 0.0f);
        gluCylinder(gluNewQuadric(), 4, 4, 1, 100, 100);        
        glColor3f(1.0f, 1.0f, 1.0f);
        gluDisk(gluNewQuadric(), 0, 4, 100, 100);
        glTranslatef(0.0f, 0.0f, 1.0f);
        gluDisk(gluNewQuadric(), 0, 4, 100, 100);
        
    glPopMatrix();
}