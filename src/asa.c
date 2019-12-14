#include "asa.h"

void desenha_asa(float asax){
    

    glPushMatrix();
	glColor3f(1.0f, 1.0f, 1.0f);
		//asa de baixo

		glScalef(2.0,1.0,1.0);

		glTranslatef(0.0,-20.0,0.0);

		glScalef(45.0f,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.022,1.0,0.066);

		glTranslatef(22,0.0,7.5);
		glScalef(7.5f,0.833,15.0f);
		glutSolidSphere(1, 10 ,10);
		glScalef(0.133,1.2,0.066);

		glTranslatef(-22,0.0,-7.5);
		glTranslatef(0.0,0.0,15.0);
		glTranslatef(-17.75,0.0,0.0);
		glScalef(10.0f,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.1,1.0,0.066);

		glTranslatef(17.75,0.0,0.0);
		glTranslatef(17.75,0.0,0.0);

		glColor3f(1.0,1.0,1.0);
		glScalef(10,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.1,1.0,0.066);


		glTranslatef(-17.75,0.0,0.0);
		glTranslatef(0.0,0.0,-7.5);
		glScalef(13.5,0.1,0.1f);
		glutSolidSphere(1, 10 ,10);
		glScalef(0.074,10.0,10.0);
		

		glTranslatef(0.0,0.0,7.5);
		glScalef(27.0f,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.037,1.0,0.066);

		glTranslatef(-17.75,0.0,0.0);
		glTranslatef(17.75,0.0,0.0);
		glTranslatef(0.0,0.0,-15.0);

		//astes

		//glTranslatef(20,0,0);
		glTranslatef(0.0,10.0,0.0);


		glTranslatef(15,0.0,0.0);
		glScalef(1.0,20.0,1.0);
		glutSolidCube(1.0f);
		glScalef(1.0,0.05,1.0);
		glTranslatef(-15,0.0,0.0);

		glTranslatef(0.0,0.0,15.0);
		glTranslatef(15,0.0,0.0);
		glScalef(1.0,20.0,1.0);
		glutSolidCube(1.0f);
		glScalef(1.0,0.05,1.0);
		glTranslatef(-15,0.0,0.0);
		glTranslatef(0.0,0.0,-15.0);

		glTranslatef(-15,0.0,0.0);
		glScalef(1.0,20.0,1.0);
		glutSolidCube(1.0f);
		glScalef(1.0,0.05,1.0);
		glTranslatef(15,0.0,0.0);

		glTranslatef(0.0,0.0,15.0);
		glTranslatef(-15,0.0,0.0);
		glScalef(1.0,20.0,1.0);
		glutSolidCube(1.0f);
		glScalef(1.0,0.05,1.0);
		glTranslatef(15,0.0,0.0);
		glTranslatef(0.0,0.0,-15.0);


		glTranslatef(0.0,-10.0,0.0);
		//glTranslatef(-20.0,0.0,0.0);

		//asa de cima

		glRotatef(180,1,0,0);
		glTranslatef(0,-40,0);
		glTranslatef(0,0,-15);

		glColor3f(1.0,1.0,1.0);

		glTranslatef(0.0,20.0,0.0);

		glScalef(45.0f,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.022,1.0,0.066);

		glTranslatef(22,0.0,07.5);
		glScalef(7.5f,0.833,15.0f);
		glutSolidSphere(1, 10 ,10);
		glScalef(0.133,1.2,0.066);

		glTranslatef(-22,0.0,-7.5);
		glTranslatef(0.0,0.0,15.0);
		glTranslatef(-17.75,0.0,0.0);
		glScalef(10.0f,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.1,1.0,0.066);

		glTranslatef(17.75,0.0,0.0);
		glTranslatef(17.75,0.0,0.0);

		glColor3f(1.0,1.0,1.0);
		glScalef(10,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.1,1.0,0.066);

		glColor3f(0.0,1.0,0.0);


		glTranslatef(-17.75,0.0,0.0);
		glTranslatef(0.0,0.0,-7.5);
		glRotatef(asax, 1.0, 0.0, 0.0);
		glScalef(13.5,0.1,0.1f);
		glutSolidSphere(1, 10 ,10);
		glScalef(0.074,10.0,10.0);
		

		glTranslatef(0.0,0.0,7.5);
		glColor3f(1.0,0.0,0.0);
		glScalef(27.0f,1.0,15.0f);
		glutSolidCube(1.0f);
		glScalef(0.037,1.0,0.066);
		glRotatef(-asax, 1.0, 0.0, 0.0);
		
		glTranslatef(-17.75,0.0,0.0);
		glTranslatef(17.75,0.0,0.0);

	glPopMatrix();

	// Desenha o teapot com a cor corrente (solid)

	glutSwapBuffers();
}