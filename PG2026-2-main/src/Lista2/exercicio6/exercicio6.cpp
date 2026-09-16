/*
 * Lista 2 - Exercicio 6
 * Processamento Grafico - OpenGL / CMake / GLFW
 * Guilherme Augusto Paes ---> 2026/2
 */

#include <GLFW/glfw3.h>
#include <vector>

const double XMIN = 0.0;
const double XMAX = 800.0;
const double YMIN = 600.0;
const double YMAX = 0.0;

struct Vertice {
    double x;
    double y;
};

std::vector<Vertice> vertices;

const float cores[][3] = {
    {1.0f, 0.0f, 0.0f}, // vermelho
    {0.0f, 1.0f, 0.0f}, // verde
    {0.0f, 0.0f, 1.0f}, // azul
    {1.0f, 1.0f, 0.0f}, // amarelo
    {1.0f, 0.0f, 1.0f}, // magenta
    {0.0f, 1.0f, 1.0f}  // ciano
};

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

    // Desenha todos os triangulos completos que ja foram criados.
    int quantidadeTriangulos = static_cast<int>(vertices.size()) / 3;

    for (int i = 0; i < quantidadeTriangulos; ++i) {
        int indiceCor = i % 6;

        glColor3f(
            cores[indiceCor][0],
            cores[indiceCor][1],
            cores[indiceCor][2]
        );

        glBegin(GL_TRIANGLES);
            glVertex2d(vertices[i * 3 + 0].x, vertices[i * 3 + 0].y);
            glVertex2d(vertices[i * 3 + 1].x, vertices[i * 3 + 1].y);
            glVertex2d(vertices[i * 3 + 2].x, vertices[i * 3 + 2].y);
        glEnd();
    }

    // Mostra os vertices que ainda nao completaram um triangulo.
    int inicio = quantidadeTriangulos * 3;

    if (inicio < static_cast<int>(vertices.size())) {
        glColor3f(0.0f, 0.0f, 0.0f);
        glPointSize(6.0f);

        glBegin(GL_POINTS);
            for (int i = inicio; i < static_cast<int>(vertices.size()); ++i) {
                glVertex2d(vertices[i].x, vertices[i].y);
            }
        glEnd();
    }
}

void redimensionar(GLFWwindow* janela, int largura, int altura) {
    glViewport(0, 0, largura, altura);
}

void cliqueMouse(GLFWwindow* janela, int botao, int acao, int mods) {
    if (botao != GLFW_MOUSE_BUTTON_LEFT || acao != GLFW_PRESS) {
        return;
    }

    double mouseX;
    double mouseY;
    glfwGetCursorPos(janela, &mouseX, &mouseY);

    int largura;
    int altura;
    glfwGetWindowSize(janela, &largura, &altura);


    double mundoX = XMIN + mouseX * (XMAX - XMIN) / largura;
    double mundoY = YMAX + mouseY * (YMIN - YMAX) / altura;

    vertices.push_back({mundoX, mundoY});
}

int main() {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow* janela = glfwCreateWindow(
        800,
        600,
        "Lista 2 - Exercicio 6 - Triangulos com Mouse",
        nullptr,
        nullptr
    );

    if (!janela) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(janela);

    glfwSetFramebufferSizeCallback(janela, redimensionar);
    glfwSetMouseButtonCallback(janela, cliqueMouse);

    inicializar();

    int largura;
    int altura;
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
