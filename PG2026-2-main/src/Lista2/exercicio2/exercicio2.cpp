/*
 * Lista 2 - Exercicio 2
 * Processamento Grafico - OpenGL / CMake / GLFW
 * Guilherme Augusto Paes ---> 2026/2
 */


#include <GLFW/glfw3.h>

// Limites da janela do mundo (window/ortho)
const double XMIN = 0.0;
const double XMAX = 800.0;
const double YMIN = 600.0;
const double YMAX = 0.0;

void inicializar() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // fundo branco

    // Projecao ortografica 2D = a "janela do mundo"
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(XMIN, XMAX, YMIN, YMAX, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    // Eixos desenhados apenas para conferir visualmente os limites da janela
    glBegin(GL_LINES);
        glVertex2d(XMIN, 0.0);
        glVertex2d(XMAX, 0.0);
        glVertex2d(0.0, YMIN);
        glVertex2d(0.0, YMAX);
    glEnd();
}

void redimensionar(GLFWwindow* janela, int largura, int altura) {
    // Mantem a viewport ocupando toda a janela (device)
    glViewport(0, 0, largura, altura);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    // Janela criada em 800x600 para casar 1:1 com os limites da janela do mundo
    GLFWwindow* janela = glfwCreateWindow(800, 600, "Lista 2 - Exercicio 2 - Janela do Mundo (Ortho)", nullptr, nullptr);
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