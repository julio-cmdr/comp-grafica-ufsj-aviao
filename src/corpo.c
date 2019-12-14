#include "corpo.h"
#include "math.h"

void desenha_corpo(float cauday){

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

        gluCylinder(gluNewQuadric(), 15, 5, 20, 32, 32);
        glTranslatef(0, 0, 20);
		gluCylinder(gluNewQuadric(), 5, 1, 1, 32, 32);

		//glColor3f(0.0f, 0.0f, 1.0f);
		glRotatef(25, 1.0, 0.0, 0.0);
		glTranslatef(0.0,4.0,0.0);
		glScalef(0.5f, 5.0f, 2.0f);
		glutSolidCube(4.0f);
		glScalef(5.0f, 0.25, 0.5f);
		


		glRotatef(-20, 1.0, 0.0, 0.0);
		glTranslatef(0.0,7.0,4.1);
		glScalef(0.5,1.0,2.6);
		glutSolidCube(4.0f);
		glScalef(2.0,1.0,0.38);
		glTranslatef(0.0,-7.0,-4.1);
		glRotatef(20, 1.0, 0.0, 0.0);


		glTranslatef(0.0,0.0,5.0);
		
		
		glColor3f(1.0f, 1.0f, 1.0f);
		glTranslatef(0.0,6.0,0.0);
		glScalef(0.5,1.0,1.0);
		glutSolidCube(4.0f);
		glScalef(2.0,1.0,1.0);
		glTranslatef(0.0,-6.0,0.0);
		glTranslatef(0.0,-6.0,0.0);
		glScalef(0.5,1.0,1.0);
		glutSolidCube(4.0f);
		glScalef(2.0,1.0,1.0);
		glTranslatef(0.0, 6, 0.0);

		

		glTranslatef(0.0,0.0,-2.0);
		glRotatef(cauday, 0.0,1.0,0.0);
		glScalef(0.1,0.1,0.1);
		glutSolidSphere(1, 10 ,10);
		glScalef(10,10,10);
		glTranslatef(0.0,0.0,2.0);
		glColor3f(1.0,0.0,0.0);
		glScalef(0.5f, 2.0f, 1.0f);
		glutSolidCube(4.0f);	
		glScalef(2.0f,0.5f,1.0f);
		glRotatef(-cauday, 0.0,1.0,0.0);

		glRotatef(-25, 1.0, 0.0, 0.0);
        
        //gluDisk(gluNewQuadric(), 0, 15, 32, 32);
    glPopMatrix();

}
