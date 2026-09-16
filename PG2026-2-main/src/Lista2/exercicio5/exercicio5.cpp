/*
 * Lista 2 - Exercicio 5
 * Processamento Grafico - OpenGL / CMake / GLFW
 * Guilherme Augusto Paes ---> 2026/2
 */


#include <GLFW/glfw3.h>

// Limites da janela do mundo (window/ortho) - mesma camera dos exercicios anteriores
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

void desenharCena() {
    glColor3f(1.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
        glVertex2d(400, 220);
        glVertex2d(340, 340);
        glVertex2d(460, 340);
    glEnd();
}

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);

    int largura, altura;
    glfwGetFramebufferSize(glfwGetCurrentContext(), &largura, &altura);

    int metadeLargura = largura / 2;
    int metadeAltura = altura / 2;

    // Quadrante superior esquerdo
    glViewport(0, metadeAltura, metadeLargura, metadeAltura);
    desenharCena();

    // Quadrante superior direito
    glViewport(metadeLargura, metadeAltura, metadeLargura, metadeAltura);
    desenharCena();

    // Quadrante inferior esquerdo
    glViewport(0, 0, metadeLargura, metadeAltura);
    desenharCena();

    // Quadrante inferior direito
    glViewport(metadeLargura, 0, metadeLargura, metadeAltura);
    desenharCena();
}

void redimensionar(GLFWwindow* janela, int largura, int altura) {

}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* janela = glfwCreateWindow(800, 600, "Lista 2 - Exercicio 5 - Cena nos 4 Quadrantes", nullptr, nullptr);
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
