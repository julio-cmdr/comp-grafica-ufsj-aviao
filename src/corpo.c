#include "corpo.h"

void desenha_corpo(){
    glPushMatrix();
        glScalef(0.37f, 1.0f, 1.0f);

        gluCylinder(gluNewQuadric(), 10, 20, 40, 32, 32);    
        glTranslatef(0, 0, 40);
        gluCylinder(gluNewQuadric(), 20, 20, 70, 32, 32);
        glTranslatef(0, 0, 70);
        gluCylinder(gluNewQuadric(), 20, 15, 30, 32, 32);
        glTranslatef(0, 0, 30);

        // uso de vários cones para fechar a traseira do avião
        float raio_inicial = 15;
        float comprimento = 0.8;
        float fechamento = 1;

        while(raio_inicial > 0){
            gluCylinder(gluNewQuadric(), raio_inicial, raio_inicial-fechamento, comprimento, 32, 32);

            if(raio_inicial == fechamento)
                break;
            
            if((raio_inicial - fechamento) > 0){
                raio_inicial -= fechamento;
                fechamento *= 1.1;
                glTranslatef(0, 0, comprimento);
            }else{
                fechamento = raio_inicial;
                comprimento = comprimento/2;
            }
            
        }
    glPopMatrix();
}