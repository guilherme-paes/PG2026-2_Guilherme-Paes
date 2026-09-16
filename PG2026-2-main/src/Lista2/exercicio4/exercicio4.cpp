/*
 * Lista 2 - Exercicio 4
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

    // Triangulo magenta centralizado na janela do mundo (perto de 400, 300)
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(400, 220);
        glVertex2d(340, 340);
        glVertex2d(460, 340);
    glEnd();
}

void redimensionar(GLFWwindow* janela, int largura, int altura) {

    int metadeLargura = largura / 2;
    int metadeAltura = altura / 2;
    glViewport(metadeLargura, metadeAltura, metadeLargura, metadeAltura);
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* janela = glfwCreateWindow(800, 600, "Lista 2 - Exercicio 4 - Viewport no Quadrante Superior Direito", nullptr, nullptr);
    if (!janela) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(janela);
    glfwSetFramebufferSizeCallback(janela, redimensionar);

    inicializar();

    // Aplica a viewport inicial com base no tamanho real do framebuffer
    int largura, altura;
    glfwGetFramebufferSize(janela, &largura, &altura);
    redimensionar(janela, largura, altura);

    while (!glfwWindowShouldClose(janela)) {
        desenhar();

        glfwSwapBuffers(janela);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}