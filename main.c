#include "roda.h"
#include "corpo.h"
#include "helice.h"
#include "asa.h"
#include "aileron_flap.h"
#include <GL/glut.h>
#include <stdio.h>
#include <string.h>

#define DESLOC 5

GLfloat angle, fAspect;
float leme=0,flapdx=0,flapex=0,ailerondx=0,aileronex=0;

float velHelice = 0;

float rx = 0; 
float ry = 0; 
float rz = 0;

void DesenhaEixos(){
    glBegin(GL_LINES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(10.0f,0.0f,0.0f);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,10.0f,0.0f);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,10.0f);
    glEnd();
}


void escreveTexto() {
	glPushMatrix();
	glTranslatef(-170.0f, 110.0f, 0.0f);
	char *string = strdup("Eixos:   X->(Q,E) Y->(A,D) Z->(S,W)\0");
	int w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(0.0, 0.0);
	glColor3f(1.0, 0., 0.0);
	int len = strlen(string);
	for (int i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
	glTranslatef(-2.0f, -10.0f, 0.0f);
	string = strdup("Leme:   I, O\0");
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(0.0, 0.0);
	len = strlen(string);
	for (int i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
    
	glTranslatef(-2.0f, -10.0f, 0.0f);
	string = strdup("Flap:  Esq->(H,B) Dir->(J,N)\0");
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(0.0, 0.0);
	len = strlen(string);
	for (int i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}

	glTranslatef(-2.0f, -10.0f, 0.0f);
	string = strdup("Aileron:   Esq->(G,V) Dir->(K,M)\0");
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(0.0, 0.0);
	len = strlen(string);
	for (int i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}
	glTranslatef(-2.0f, -10.0f, 0.0f);
	string = strdup("Helice: R,F\0");
	w = glutBitmapLength(GLUT_BITMAP_8_BY_13, string);
	glRasterPos2f(0.0, 0.0);
	len = strlen(string);
	for (int i = 0; i < len; i++) {
    	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
	}

	glPopMatrix();
}

// Função callback chamada para fazer o desenho
void Desenha(){

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    // Especifica posição do observador e do alvo
    gluLookAt(300,80,200, 0,0,0, 0,1,0);
    // Limpa a janela e o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    escreveTexto();

    DesenhaEixos();

    glRotated(rx, 1, 0, 0);
    glRotated(ry, 0, 1, 0);
    glRotated(rz, 0, 0, 1);

    glPushMatrix();
        glColor3f(1,1,1);
        //glTranslatef(0,0,3);
        //perna1
        glRotatef(-25,1,0,0);
        glutSolidSphere(1, 10 ,10);
        glTranslatef(0,-25,0);

        glScalef(1,50,1);
        glutSolidCube(1.0f);
        glScalef(1,0.02,1);
        glTranslatef(0,25,0);
        glRotatef(25,1,0,0);
        //glTranslatef(0,0,-6);
        //perna2
        glRotatef(25,1,0,0);
        glutSolidSphere(1, 10 ,10);
        glTranslatef(0,-25,0);

        glScalef(1,50,1);
        glutSolidCube(1.0f);
        glScalef(1,0.02,1);
        glTranslatef(0,25,0);
        glRotatef(-25,1,0,0);
        //glTranslatef(0,0,3);
        //rodas
        glTranslatef(0, -45, 0);
        glTranslatef(0,0,22);
        desenha_roda();
        glTranslatef(0, 0, -44 );
        desenha_roda();
        glTranslatef(0,0 ,22);
        glTranslatef(0,45,0);

        //roda traseira
        glTranslatef(-80,0,0);
        glColor3f(1,1,1);
       // glTranslatef(0,-25,0);
        glRotatef(-40,0,0,1);
        glutSolidSphere(1, 10 ,10);
        glTranslatef(0,-20,0);

        glScalef(1,20,1);
        glutSolidCube(1.0f);
        glScalef(1,0.05,1);
        
        glTranslatef(0,-10,0);
        glTranslatef(0,0,2);
        desenha_roda();
        glTranslatef(0,0,-4);
        desenha_roda();

    glPopMatrix();
    
    glRotated(90, 0, 1, 0);
    desenha_corpo(leme);

    glTranslatef(50.0,0.0,0.0);
    glTranslatef(0.0,10.0,0.0);
    desenha_asa();  
    glTranslatef(-50.0,0.0,0.0);

    glTranslatef(0.0,-10.0,0.0);

    glTranslatef(0, 0, 47.5);
    desenha_helice(velHelice);
    glTranslatef(0, 0, -47.5);
    

    glTranslatef(0.0,10.0,0.0);
    glTranslatef(-63,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    desenha_aileron_flap(aileronex);
    glColor3f(1.0,0.0,0.0);
    glTranslatef(26,0,0);
    desenha_aileron_flap(flapex);
    glColor3f(1.0,1.0,1.0);
    glTranslatef(63,0.0,0.0);

    glTranslatef(37,0,0);
    //glTranslatef(63,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    desenha_aileron_flap(ailerondx);
    glColor3f(1.0,0.0,0.0);
    glTranslatef(-26,0,0);
    desenha_aileron_flap(flapdx);
    glColor3f(1.0,1.0,1.0);
    //glTranslatef(-63,0.0,0.0);
    glTranslatef(0.0,-10.0,0.0);
    

     
    

    glutSwapBuffers();
}


void Inicializa (){

    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor"
    GLfloat luzEspecular[4]={0.1, 0.1, 0.1, 0.1};// "brilho"
    GLfloat posicaoLuz[4]={10000.0, 100000.0, 10000.0, 10000.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={0.2,0.2,0.2,0.2};
    GLint especMaterial = 0.5;

    // Especifica que a cor de fundo da janela será preta
    glClearColor(0.529f, 0.8078f, 0.921f, 1.0f);

    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Define a refletância do material
    glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);

    angle = 45;
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void){
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();
    // Especifica a projeção perspectiva
    gluPerspective(angle,fAspect,0.4,500);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h){
    // Para previnir uma divisão por zero
    if (h == 0)
        h = 1;
    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
    // Calcula a correção de aspecto
    fAspect = (GLfloat)w/(GLfloat)h;
    // Corrige o aspecto especificando novamente o volume de visualização
    EspecificaParametrosVisualizacao();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN)   // Zoom-in
            if (angle >= 10)
                angle -= DESLOC;

    if (button == GLUT_RIGHT_BUTTON)
        if (state == GLUT_DOWN)   // Zoom-out
            if (angle <= 130)
                angle += DESLOC;

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

void GerenciaTeclado(unsigned char key, int x, int y) {
    switch(key){
        case 'e':
            rx ++;
            break;

        case 'q':
            rx --;
            break;

        case 'a':
            ry ++;
            break;
        
        case 'd':
            ry --;
            break;

        case 'w':
            rz ++;
            break;
        
        case 's':
            rz --;
            break;

        case 'r':
            velHelice += 5;
            break;

        case 'f':
            velHelice -= 5;
            break;
        
        case 'i': {
            if(leme < 45)
			    leme++;
			break;
        }

		case 'o': {
            if(leme > -45)
			    leme--;
			break;
        }
        case 'h': {
            if(flapex < 20)
			    flapex++;
			break;
        }
		case 'b': {
			if(flapex > -20)
                flapex--;
			break;
        }
        case 'g': {
			if(aileronex < 20)
                aileronex++;
			break;
        }
		case 'v': {
			if(aileronex > -20)
                aileronex--;
			break;
        }
        case 'j': {
            if(flapdx < 20)
			    flapdx++;
			break;
        }
		case 'n': {
			if(flapdx > -20)
                flapdx--;
			break;
        }
        case 'k': {
            if(ailerondx < 20)
			    ailerondx++;
			break;
        }
		case 'm': {
            if(ailerondx > -20)
			    ailerondx--;
			break;
        }

        case 27:
            exit(0);
        default:
            break;
    }
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("Visualizacao 3D");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutMouseFunc(GerenciaMouse);
    glutKeyboardFunc(GerenciaTeclado);
    Inicializa();
    glutMainLoop();
}
