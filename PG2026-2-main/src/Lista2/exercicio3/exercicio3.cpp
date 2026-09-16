/*
 * Lista 2 - Exercicio 3
 * Processamento Grafico - OpenGL / CMake / GLFW
 * Guilherme Augusto Paes ---> 2026/2
 */


#include <GLFW/glfw3.h>

const double XMIN = 0.0;
const double XMAX = 800.0;
const double YMIN = 600.0;
const double YMAX = 0.0;

void inicializar() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // fundo branco

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(XMIN, XMAX, YMIN, YMAX, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Retangulo vermelho: y entre 50 e 120 -> perto do TOPO da tela
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2d(50, 50);
        glVertex2d(150, 50);
        glVertex2d(150, 120);
        glVertex2d(50, 120);
    glEnd();

    // Retangulo azul: y entre 450 e 550 -> perto da BASE da tela
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
        glVertex2d(600, 450);
        glVertex2d(750, 450);
        glVertex2d(750, 550);
        glVertex2d(600, 550);
    glEnd();

    // Triangulo verde: perto do centro (400, 300)
    glColor3f(0.0, 0.6, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(400, 250);
        glVertex2d(350, 350);
        glVertex2d(450, 350);
    glEnd();
}

void redimensionar(GLFWwindow* janela, int largura, int altura) {
    glViewport(0, 0, largura, altura);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* janela = glfwCreateWindow(800, 600, "Lista 2 - Exercicio 3 - Posicionando Objetos", nullptr, nullptr);
    if (!janela) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(janela);
    glfwSetFramebufferSizeCallback(janela, redimensionar);

    inicializar();

    while (!glfwWindowShouldClose(janela)) {
        desenhar();

        glfwSwapBuffers(janela);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}