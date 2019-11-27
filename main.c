#include "roda.h"
#include "corpo.h"
#include "helice.h"

#define DESLOC 5

GLfloat angle, fAspect;

float velHelice = 0;

int rx = 0; 
int ry = 0; 
int rz = 0;

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

// Função callback chamada para fazer o desenho
void Desenha(){

    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    // Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
    // Limpa a janela e o depth buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    DesenhaEixos();

    glRotated(rx, 1, 0, 0);
    glRotated(ry, 0, 1, 0);
    glRotated(rz, 0, 0, 1);

    glPushMatrix();
        glTranslatef(0, -50, 0);
        desenha_roda();
    glPopMatrix();
    
    glRotated(90, 0, 1, 0);
    desenha_corpo();

    glTranslatef(0, 0, 47.5);
    desenha_helice(velHelice);

    glutSwapBuffers();
}


void Inicializa (){

    GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
    GLfloat luzDifusa[4]={0.2,0.2,0.2,1.0};		 // "cor"
    GLfloat luzEspecular[4]={0.1, 0.1, 0.1, 0.1};// "brilho"
    GLfloat posicaoLuz[4]={10000.0, 100000.0, 10000.0, 10000.0};

    // Capacidade de brilho do material
    GLfloat especularidade[4]={0.2,0.2,0.2,0.2};
    GLint especMaterial = 0.5;

    // Especifica que a cor de fundo da janela será preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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
        case 'q':
            rx += 5;
            break;

        case 'a':
            rx -= 5;
            break;

        case 'w':
            ry += 5;
            break;
        
        case 's':
            ry -= 5;
            break;

        case 'e':
            rz += 5;
            break;
        
        case 'd':
            rz -= 5;
            break;

        case 'r':
            velHelice += 5;
            break;

        case 'f':
            velHelice -= 5;
            break;

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
