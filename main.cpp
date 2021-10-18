#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

#define LINHAS 15
#define COLUNAS 18
#define BLOCOS LINHAS * COLUNAS

struct Bloco {
	int x;
	int y;
	int comp;
	int alt;
};

float mapa[LINHAS][COLUNAS];

void desenharBloco(int x, int y, int alt, int comp);
void display();
void timer(int t);
int colisao(float Ax, float Ay, float Bx, float By, float Acomp, float Bcomp, float Aalt, float Balt);
void carregarMapa();

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);

	// Criar uma janela
	glutInitWindowSize(800, 600);
	glutCreateWindow("X-Men Atividade Computacao Grafica (OpenGL)");

	// definir a função de callback de display
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);

	// Laço principal do OpenGL.
	glutMainLoop();

	return 0;
}

void timer(int t) {
	glutPostRedisplay();
	glutTimerFunc(60, timer, 0);
}

void desenharBloco(int x, int y, int alt, int comp) {
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + comp, y);
	glVertex2f(x + comp, y + alt);
	glVertex2f(x, y + alt);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT); // Limpa o Buffer
	glClearColor(0, 0, 0, 1);     // Mudar a cor do fundo
	glViewport(0, 0, 800, 600);   // Define a area que vamos trabalhar
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0f, 800.0f, 0.0f, 600.0f); // Estabelece a Janela de Seleção

	// RENDERIZAÇÃO
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix(); // Inicializa a Matriz

	// Carregar Mapa e os Blocos
	carregarMapa();
	Bloco blocos[BLOCOS];
	for (int i = 0, x = 0, y = 0; i < BLOCOS; i++, x += 44)
	{
		if (x != 0 && x % 792 == 0) {
			y += 40;
			x = 0;
		}

		blocos[i].x = x;
		blocos[i].y = y;
		blocos[i].comp = 44;
		blocos[i].alt = 40;
	}

	// Desenhar Blocos na Tela
	for (int i = 0; i < BLOCOS; i++)
	{
		Bloco bloco = blocos[i];
		int x = bloco.x / 44;
		int y = bloco.y / 40;
		int result = mapa[y][x];

		if (result == 1) {
			glColor4ub(231, 231, 73, 255);
			desenharBloco(bloco.x, bloco.y, bloco.alt, bloco.comp);
		}
		else if (result == 2) {
			glColor4ub(166, 96, 32, 255);
			desenharBloco(bloco.x, bloco.y, bloco.alt, bloco.comp);
		}
		else if (result == 3) {
			glColor4ub(227, 110, 109, 255);
			desenharBloco(bloco.x, bloco.y, bloco.alt, bloco.comp);
		}
	}

	glPopMatrix();     // Fecha a Matriz
	glutSwapBuffers(); // Caso utilize animação
}

// return 1 se não colidiu, 0 se colidiu
int colisao(float Ax, float Ay, float Bx, float By, float Acomp, float Bcomp, float Aalt, float Balt) {
	if (Ay + Aalt < By) return 1;
	else if (Ay > By + Balt) return 1;
	else if (Ax + Acomp < Bx) return 1;
	else if (Ax > Bx + Bcomp) return 1;

	return 0;

}

void carregarMapa() {
	for (int coluna = 0; coluna < COLUNAS; coluna++)
	{
		mapa[0][coluna] = 1;
		mapa[14][coluna] = 1;
	}

	for (int linha = 0; linha < LINHAS; linha++)
	{
		mapa[linha][0] = 1;
		mapa[linha][17] = 1;
	}

	// 1 Linha
	mapa[1][2] = 1;
	mapa[1][5] = 1;
	mapa[1][6] = 1;
	mapa[1][10] = 1;
	mapa[1][11] = 1;

	// 2 Linha
	mapa[2][3] = 1;
	mapa[2][8] = 1;
	mapa[2][13] = 1;
	mapa[2][14] = 1;
	mapa[2][15] = 1;

	// 3 Linha
	mapa[3][1] = 1;
	mapa[3][3] = 1;
	mapa[3][5] = 1;
	mapa[3][6] = 1;
	mapa[3][9] = 1;
	mapa[3][10] = 1;
	mapa[3][11] = 1;
	mapa[3][12] = 1;

	// 4 Linha
	mapa[4][1] = 1;
	mapa[4][3] = 1;
	mapa[4][7] = 1;
	mapa[4][9] = 1;
	mapa[4][13] = 1;
	mapa[4][15] = 1;
	mapa[4][16] = 1;

	// 5 Linha
	mapa[5][4] = 1;
	mapa[5][5] = 1;
	mapa[5][7] = 1;
	mapa[5][8] = 1;
	mapa[5][9] = 1;
	mapa[5][11] = 1;
	mapa[5][13] = 1;

	// 6 Linha
	mapa[6][2] = 1;
	mapa[6][4] = 1;
	mapa[6][7] = 1;
	mapa[6][11] = 1;
	mapa[6][13] = 1;
	mapa[6][15] = 1;

	// 7 Linha
	mapa[7][1] = 1;
	mapa[7][2] = 1;
	mapa[7][4] = 1;
	mapa[7][6] = 1;
	mapa[7][7] = 1;
	mapa[7][9] = 1;
	mapa[7][10] = 1;
	mapa[7][14] = 1;

	// 8 Linha
	mapa[8][4] = 1;
	mapa[8][7] = 1;
	mapa[8][8] = 1;
	mapa[8][9] = 1;
	mapa[8][11] = 1;
	mapa[8][12] = 1;
	mapa[8][14] = 1;
	mapa[8][16] = 1;

	// 9 Linha
	mapa[9][2] = 1;
	mapa[9][3] = 1;
	mapa[9][5] = 1;
	mapa[9][12] = 1;
	mapa[9][14] = 1;

	// 10 Linha
	mapa[10][2] = 1;
	mapa[10][5] = 1;
	mapa[10][7] = 1;
	mapa[10][8] = 1;
	mapa[10][9] = 1;
	mapa[10][10] = 1;
	mapa[10][14] = 1;
	mapa[10][15] = 1;

	// 11 Linha
	mapa[11][3] = 1;
	mapa[11][6] = 1;
	mapa[11][11] = 1;
	mapa[11][13] = 1;

	// 12 Linha
	mapa[12][1] = 1;
	mapa[12][3] = 1;
	mapa[12][4] = 1;
	mapa[12][8] = 1;
	mapa[12][9] = 1;
	mapa[12][11] = 1;
	mapa[12][12] = 1;
	mapa[12][15] = 1;

	// 13 Linha
	mapa[13][6] = 1;
	mapa[13][7] = 1;
	mapa[13][14] = 1;

	// Jogador
	mapa[1][1] = 2;

	// Chegada
	mapa[6][8] = 3;
	mapa[7][8] = 3;
}
