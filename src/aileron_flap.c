#include "aileron_flap.h"

void desenha_aileron_flap(float movimentox){

		glPushMatrix();
			
			glTranslatef(0.0,0.0,7.5);
			glRotatef(movimentox, 1.0, 0.0, 0.0);
			glScalef(2.0,1.0,1.0);
			glScalef(7,0.1,0.1);
			glutSolidSphere(1, 10 ,10);
			glScalef(0.143,10,10);
			glTranslatef(0,0,-6.3);

			glScalef(12.0,1.0,12.5);
			glutSolidCube(1.0f);
			glScalef(0.0833,1.0,0.08);
			glScalef(0.5,1.0,1.0);
			
		glPopMatrix();
}