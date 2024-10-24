#include <GL/glut.h>
#include <cmath>

// Variáveis de controle de tempo e cor
int dia = 1;
GLfloat corCeuDia[] = { 0.53f, 0.81f, 0.92f }; // Azul claro
GLfloat corCeuNoite[] = { 0.05f, 0.05f, 0.2f }; // Azul escuro
GLfloat corAtualCeu[3];

// Função para desenhar o cenário
void DesenhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Céu
    glColor3fv(corAtualCeu);
    glBegin(GL_QUADS); // Usar GL_QUADS em vez de GL_POLYGON
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Chão
    glColor3f(0.0f, 0.5f, 0.0f); // Verde
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.3f);
    glVertex2f(1.0f, -0.3f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();

    // Casa
    glColor3f(0.6f, 0.4f, 0.12f); // Marrom
    glBegin(GL_QUADS);
    glVertex2f(-0.3f, -0.3f);
    glVertex2f(0.3f, -0.3f);
    glVertex2f(0.3f, 0.2f);
    glVertex2f(-0.3f, 0.2f);
    glEnd();

    // Telhado
    glColor3f(0.8f, 0.0f, 0.0f); // Vermelho
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.35f, 0.2f);
    glVertex2f(0.35f, 0.2f);
    glVertex2f(0.0f, 0.5f);
    glEnd();

    // Sol (aparece somente de dia)
    if (dia) {
        glColor3f(1.0f, 1.0f, 0.0f); // Amarelo
        glBegin(GL_POLYGON);
        for (int i = 0; i < 20; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(20);
            float dx = 0.1f * cosf(theta);
            float dy = 0.1f * sinf(theta);
            glVertex2f(dx + 0.7f, dy + 0.7f);
        }
        glEnd();
    }

    // Lua e estrelas (aparecem somente à noite)
    if (!dia) {
        glColor3f(1.0f, 1.0f, 1.0f); // Branco para estrelas
        for (float i = -0.8f; i < 1.0f; i += 0.4f) {
            glBegin(GL_POINTS);
            glVertex2f(i, 0.8f);
            glVertex2f(i + 0.2f, 0.9f);
            glEnd();
        }

        // Lua
        glColor3f(1.0f, 1.0f, 0.8f); // Amarelado
        glBegin(GL_POLYGON);
        for (int i = 0; i < 20; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(20);
            float dx = 0.1f * cosf(theta);
            float dy = 0.1f * sinf(theta);
            glVertex2f(dx - 0.7f, dy + 0.7f);
        }
        glEnd();
    }

    glutSwapBuffers();
}

// Função de troca de cor
void TrocaCor(int valor) {
    dia = !dia;
    if (dia) {
        for (int i = 0; i < 3; i++) {
            corAtualCeu[i] = corCeuDia[i];
        }
    }
    else {
        for (int i = 0; i < 3; i++) {
            corAtualCeu[i] = corCeuNoite[i];
        }
    }
    glClearColor(corAtualCeu[0], corAtualCeu[1], corAtualCeu[2], 1.0f); // Atualiza a cor de fundo
    glutPostRedisplay(); // Redesenha a cena com as novas cores
    glutTimerFunc(5000, TrocaCor, 0); // Chama novamente após 5 segundos
}

// Função de inicialização
void Inicializa() {
    for (int i = 0; i < 3; i++) {
        corAtualCeu[i] = corCeuDia[i]; // Define a cor inicial do céu como dia
    }
    glClearColor(corAtualCeu[0], corAtualCeu[1], corAtualCeu[2], 1.0f); // Cor inicial do céu
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Projeção ortogonal 2D
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Alternância Dia e Noite");

    Inicializa();
    glutDisplayFunc(DesenhaCena);
    glutTimerFunc(5000, TrocaCor, 0); // Inicia a alternância de cores a cada 5 segundos

    glutMainLoop(); // Inicia o loop principal
    return 0;
}