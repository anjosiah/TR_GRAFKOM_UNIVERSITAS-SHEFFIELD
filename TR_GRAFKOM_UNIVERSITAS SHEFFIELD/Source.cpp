#include<Windows.h>
#include<stdlib.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void idle();
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);


bool mouseDown = false;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

float xpos = 0.0f;
float ypos = 0.0f;
float zpos = 0.0f;

int tembokk1 = 0, tembokk2 = 0, atapp = 0, xkelas = 40, xkelasi = 110, zkelas = -18;

int is_depth;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("TR_GRAFKOM_Universitas Sheffield");
	init();
	glutDisplayFunc(tampil);

	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);

	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(0, 0, 0, 0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glViewport(0, 0, 800, 640);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9);
	glLineWidth(6);
}

void tembok()
{
	//tebok depan universitas lt1
	glBegin(GL_QUADS);
	glColor3f(0.57, 0.22, 0.08);
	glVertex3f(-90, 45, 80);
	glVertex3f(-12, 45, 80);
	glVertex3f(-12, 0, 80);
	glVertex3f(-90, 0, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90, 45, 80);
	glVertex3f(12, 45, 80);
	glVertex3f(12, 0, 80);
	glVertex3f(90, 0, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 45, 80);
	glVertex3f(12, 45, 80);
	glVertex3f(12, 33, 80);
	glVertex3f(-12, 33, 80);
	glEnd();

	//tembok kanan
	glBegin(GL_QUADS);
	glVertex3f(90, 45, 80);
	glVertex3f(90, 45, -90);
	glVertex3f(90, 0, -90);
	glVertex3f(90, 0, 80);
	glEnd();

	//tembok kiri
	glBegin(GL_QUADS);
	glVertex3f(-90, 45, 80);
	glVertex3f(-90, 45, -90);
	glVertex3f(-90, 0, -90);
	glVertex3f(-90, 0, 80);
	glEnd();

	//tembok belakang
	glBegin(GL_QUADS);
	glVertex3f(-90, 45, -90);
	glVertex3f(90, 45, -90);
	glVertex3f(90, 0, -90);
	glVertex3f(-90, 0, -90);
	glEnd();

	//tembok kiri
	//miring kiri
	glBegin(GL_QUADS);
	glVertex3f(-90, 0, 80);
	glVertex3f(-110 + 10, 0, 70);
	glVertex3f(-110 + 10, 45, 70);
	glVertex3f(-90, 45, 80);
	glEnd();

	//lurus kiri
	glBegin(GL_QUADS);
	glVertex3f(-110 + 10, 0, 50);
	glVertex3f(-110 + 10, 0, 70);
	glVertex3f(-110 + 10, 45, 70);
	glVertex3f(-110 + 10, 45, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(-90, 0, 40);
	glVertex3f(-110 + 10, 0, 50);
	glVertex3f(-110 + 10, 45, 50);
	glVertex3f(-90, 45, 40);
	glEnd();

	//tembok kanan
	//miring kiri
	glBegin(GL_QUADS);
	glVertex3f(90, 0, 80);
	glVertex3f(110 - 10, 0, 70);
	glVertex3f(110 - 10, 45, 70);
	glVertex3f(90, 45, 80);
	glEnd();

	//lurus kiri
	glBegin(GL_QUADS);
	glVertex3f(110 - 10, 0, 50);
	glVertex3f(110 - 10, 0, 70);
	glVertex3f(110 - 10, 45, 70);
	glVertex3f(110 - 10, 45, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(90, 0, 40);
	glVertex3f(110 - 10, 0, 50);
	glVertex3f(110 - 10, 45, 50);
	glVertex3f(90, 45, 40);
	glEnd();

	//tembok pintu depan
	glBegin(GL_QUADS);
	glColor3f(1, 0.9, 0.9);
	glVertex3f(12, 0, 84);
	glVertex3f(12, 33, 84);
	glVertex3f(12, 33, 70);
	glVertex3f(12, 0, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 0, 84);
	glVertex3f(-12, 33, 84);
	glVertex3f(-12, 33, 70);
	glVertex3f(-12, 0, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 33, 84);
	glVertex3f(12, 33, 84);
	glVertex3f(12, 33, 70);
	glVertex3f(-12, 33, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(16, 0, 84);
	glVertex3f(12, 0, 84);
	glVertex3f(12, 33, 84);
	glVertex3f(16, 33, 84);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-16, 0, 84);
	glVertex3f(-12, 0, 84);
	glVertex3f(-12, 33, 84);
	glVertex3f(-16, 33, 84);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-16, 37, 84);
	glVertex3f(16, 37, 84);
	glVertex3f(16, 33, 84);
	glVertex3f(-16, 33, 84);
	glEnd();

	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_QUADS);
	glVertex3f(-16, 37, 84);
	glVertex3f(16, 37, 84);
	glVertex3f(16, 37, 80);
	glVertex3f(-16, 37, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(16, 37, 84);
	glVertex3f(16, 0, 84);
	glVertex3f(16, 0, 80);
	glVertex3f(16, 37, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-16, 37, 84);
	glVertex3f(-16, 0, 84);
	glVertex3f(-16, 0, 80);
	glVertex3f(-16, 37, 80);
	glEnd();

	//jendela
	int a = 0;
	for (int i = 0; i < 3; i++) {
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex3f(-85 + a, 36, 80.1);
		glVertex3f(-85 + a, 11, 80.1);
		glVertex3f(-70 + a, 11, 80.1);
		glVertex3f(-70 + a, 36, 80.1);
		glEnd();
		int b = 0;
		for (int j = 0; j < 2; j++)
		{
			int c = 0;
			for (int k = 0; k < 2; k++)
			{
				glBegin(GL_QUADS);
				glColor3f(0.6, 0.8, 1);
				glVertex3f(-83 + a + b, 22.5 + c, 80.2);
				glVertex3f(-83 + a + b, 13 + c, 80.2);
				glVertex3f(-78.5 + a + b, 13 + c, 80.2);
				glVertex3f(-78.5 + a + b, 22.5 + c, 80.2);
				glEnd();
				c += 11.5;
			}
			b += 6.5;
		}
		a += 23;
	}

	a = 0;
	for (int i = 0; i < 3; i++) {
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex3f(85 - a, 36, 80.1);
		glVertex3f(85 - a, 11, 80.1);
		glVertex3f(70 - a, 11, 80.1);
		glVertex3f(70 - a, 36, 80.1);
		glEnd();
		int b = 0;
		for (int j = 0; j < 2; j++)
		{
			int c = 0;
			for (int k = 0; k < 2; k++)
			{
				glBegin(GL_QUADS);
				glColor3f(0.6, 0.8, 1);
				glVertex3f(83 - a - b, 22.5 + c, 80.2);
				glVertex3f(83 - a - b, 13 + c, 80.2);
				glVertex3f(78.5 - a - b, 13 + c, 80.2);
				glVertex3f(78.5 - a - b, 22.5 + c, 80.2);
				glEnd();
				c += 11.5;
			}
			b += 6.5;
		}
		a += 23;
	}

}

void lantai1()
{
	//pintu
	glBegin(GL_QUADS);
	glColor4f(0.84, 1, 1, 0.8);
	glVertex3f(-12, 6, 70);
	glVertex3f(0, 6, 70);
	glVertex3f(0, 33, 70);
	glVertex3f(-12, 33, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0, 6, 67);
	glVertex3f(12, 6, 70);
	glVertex3f(12, 33, 70);
	glVertex3f(0, 33, 67);
	glEnd();

	//tangga
	int b = 0, c = 0;
	for (int i = 0; i < 5; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(0.4, 0.4, 0.4);
		glVertex3f(-12, 6 + b, -20 - b);
		glVertex3f(12, 6 + b, -20 - b);
		glVertex3f(12, 9 + b, -20 - b);
		glVertex3f(-12, 9 + b, -20 - b);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(-12, 9 + b, -20 - b);
		glVertex3f(12, 9 + b, -20 - b);
		glVertex3f(12, 9 + b, -23 - b);
		glVertex3f(-12, 9 + b, -23 - b);
		glEnd();

		b += 3;
	}


	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-12, 21, -90);
	glVertex3f(12, 21, -90);
	glVertex3f(12, 21, -35);
	glVertex3f(-12, 21, -35);
	glEnd();

	for (int i = 0; i < 8; i++)
	{
		glBegin(GL_QUADS);
		glColor3f(0.5, 0.5, 0.5);
		glVertex3f(15 + c, 24 + c, -50);
		glVertex3f(12 + c, 24 + c, -50);
		glVertex3f(12 + c, 24 + c, -90);
		glVertex3f(15 + c, 24 + c, -90);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-15 - c, 24 + c, -50);
		glVertex3f(-12 - c, 24 + c, -50);
		glVertex3f(-12 - c, 24 + c, -90);
		glVertex3f(-15 - c, 24 + c, -90);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(0.4, 0.4, 0.4);
		glVertex3f(12 + c, 21 + c, -50);
		glVertex3f(12 + c, 24 + c, -50);
		glVertex3f(12 + c, 24 + c, -90);
		glVertex3f(12 + c, 21 + c, -90);
		glEnd();

		glBegin(GL_QUADS);
		glVertex3f(-12 - c, 21 + c, -50);
		glVertex3f(-12 - c, 24 + c, -50);
		glVertex3f(-12 - c, 24 + c, -90);
		glVertex3f(-12 - c, 21 + c, -90);
		glEnd();

		c += 3;
	}

	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-36, 45, -90);
	glVertex3f(-90, 45, -90);
	glVertex3f(-90, 45, -50);
	glVertex3f(-36, 45, -50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(36, 45, -90);
	glVertex3f(90, 45, -90);
	glVertex3f(90, 45, -50);
	glVertex3f(36, 45, -50);
	glEnd();

	//tembok tangga
	glBegin(GL_QUADS);
	glColor3f(0.57, 0.22, 0.08);
	glVertex3f(12, 45, -50);
	glVertex3f(90, 45, -50);
	glVertex3f(90, 6, -50);
	glVertex3f(12, 6, -50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 45, -50);
	glVertex3f(-90, 45, -50);
	glVertex3f(-90, 6, -50);
	glVertex3f(-12, 6, -50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 45, -50);
	glVertex3f(-12, 45, -20);
	glVertex3f(-12, 6, -20);
	glVertex3f(-12, 6, -50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(12, 45, -50);
	glVertex3f(12, 45, -20);
	glVertex3f(12, 6, -20);
	glVertex3f(12, 6, -50);
	glEnd();
	

}

void tembok2()
{
	//tembok depan lantai 2
	glBegin(GL_QUADS);
	glColor3f(0.57, 0.22, 0.08);
	glVertex3f(90, 45, 80);
	glVertex3f(12, 45, 80);
	glVertex3f(12, 90, 80);
	glVertex3f(90, 90, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-90, 45, 80);
	glVertex3f(-12, 45, 80);
	glVertex3f(-12, 90, 80);
	glVertex3f(-90, 90, 80);
	glEnd();

	//tembok kiri
	glBegin(GL_QUADS);
	glVertex3f(-90, 45, 80);
	glVertex3f(-90, 45, -90);
	glVertex3f(-90, 90, -90);
	glVertex3f(-90, 90, 80);
	glEnd();

	//tembok kanan
	glBegin(GL_QUADS);
	glVertex3f(90, 45, 80);
	glVertex3f(90, 45, -90);
	glVertex3f(90, 90, -90);
	glVertex3f(90, 90, 80);
	glEnd();


	//tembok belakang
	glBegin(GL_QUADS);
	glVertex3f(-90, 45, -90);
	glVertex3f(90, 45, -90);
	glVertex3f(90, 90, -90);
	glVertex3f(-90, 90, -90);
	glEnd();

	//tembok kanan
	//miring kiri
	glBegin(GL_QUADS);
	glVertex3f(-90, 90, 80);
	glVertex3f(-110 + 10, 90, 70);
	glVertex3f(-110 + 10, 45, 70);
	glVertex3f(-90, 45, 80);
	glEnd();

	//lurus kiri
	glBegin(GL_QUADS);
	glVertex3f(-110 + 10, 90, 50);
	glVertex3f(-110 + 10, 90, 70);
	glVertex3f(-110 + 10, 45, 70);
	glVertex3f(-110 + 10, 45, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(-90, 90, 40);
	glVertex3f(-110 + 10, 90, 50);
	glVertex3f(-110 + 10, 45, 50);
	glVertex3f(-90, 45, 40);
	glEnd();

	//tembok kanan
	//miring kiri
	glBegin(GL_QUADS);
	glVertex3f(90, 90, 80);
	glVertex3f(110 - 10, 90, 70);
	glVertex3f(110 - 10, 45, 70);
	glVertex3f(90, 45, 80);
	glEnd();

	//lurus kiri
	glBegin(GL_QUADS);
	glVertex3f(110 - 10, 90, 50);
	glVertex3f(110 - 10, 90, 70);
	glVertex3f(110 - 10, 45, 70);
	glVertex3f(110 - 10, 45, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(90, 90, 40);
	glVertex3f(110 - 10, 90, 50);
	glVertex3f(110 - 10, 45, 50);
	glVertex3f(90, 45, 40);
	glEnd();

	//datar tengah
	glBegin(GL_QUADS);
	glColor4f(0.84, 1, 1, 0.8);
	glVertex3f(-5, 45, 85);
	glVertex3f(5, 45, 85);
	glVertex3f(5, 90, 85);
	glVertex3f(-5, 90, 85);
	glEnd();

	//kiri miring tengah
	glBegin(GL_QUADS);
	glVertex3f(-5, 45, 85);
	glVertex3f(-12, 45, 80);
	glVertex3f(-12, 90, 80);
	glVertex3f(-5, 90, 85);
	glEnd();

	//kanan miring tengah
	glBegin(GL_QUADS);
	glVertex3f(5, 45, 85);
	glVertex3f(12, 45, 80);
	glVertex3f(12, 90, 80);
	glVertex3f(5, 90, 85);
	glEnd();

	//jendela
	int a = 0;
	for (int i = 0; i < 3; i++) {
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex3f(-85 + a, 36 + 50, 80.1);
		glVertex3f(-85 + a, 11 + 40, 80.1);
		glVertex3f(-70 + a, 11 + 40, 80.1);
		glVertex3f(-70 + a, 36 + 50, 80.1);
		glEnd();
		int b = 0;
		for (int j = 0; j < 2; j++)
		{
			int c = 0;
			for (int k = 0; k < 3; k++)
			{
				glBegin(GL_QUADS);
				glColor3f(0.6, 0.8, 1);
				glVertex3f(-83 + a + b, 22.5 + c + 40, 80.2);
				glVertex3f(-83 + a + b, 13 + c + 40, 80.2);
				glVertex3f(-78.5 + a + b, 13 + c + 40, 80.2);
				glVertex3f(-78.5 + a + b, 22.5 + c + 40, 80.2);
				glEnd();
				c += 11.5;
			}
			b += 6.5;
		}
		a += 23;
	}
	a = 0;
	for (int i = 0; i < 3; i++) {
		glColor3f(0.9, 0.9, 0.9);
		glBegin(GL_QUADS);
		glVertex3f(85 - a, 36 + 50, 80.1);
		glVertex3f(85 - a, 11 + 40, 80.1);
		glVertex3f(70 - a, 11 + 40, 80.1);
		glVertex3f(70 - a, 36 + 50, 80.1);
		glEnd();
		int b = 0;
		for (int j = 0; j < 2; j++)
		{
			int c = 0;
			for (int k = 0; k < 3; k++)
			{
				glBegin(GL_QUADS);
				glColor3f(0.6, 0.8, 1);
				glVertex3f(83 - a - b, 22.5 + c + 40, 80.2);
				glVertex3f(83 - a - b, 13 + c + 40, 80.2);
				glVertex3f(78.5 - a - b, 13 + c + 40, 80.2);
				glVertex3f(78.5 - a - b, 22.5 + c + 40, 80.2);
				glEnd();
				c += 11.5;
			}
			b += 6.5;
		}
		a += 23;
	}

}

void lantai2()
{
	//kelas kiri
	glColor3f(0.57, 0.22, 0.08);
	glBegin(GL_QUADS);
	glVertex3f(-20, 45, 80);
	glVertex3f(-20, 45, -20);
	glVertex3f(-20, 90, -20);
	glVertex3f(-20, 90, 80);
	glEnd();

	glBegin(GL_QUADS);//pembatas
	glVertex3f(-90, 45, -20);
	glVertex3f(-20, 45, -20);
	glVertex3f(-20, 90, -20);
	glVertex3f(-90, 90, -20);
	glEnd();

	//tempat sampah
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-27, 45, 75);
	glVertex3f(-22, 45, 75);
	glVertex3f(-21, 55, 75);
	glVertex3f(-28, 55, 75);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-27, 45, 70);
	glVertex3f(-22, 45, 70);
	glVertex3f(-21, 55, 70);
	glVertex3f(-28, 55, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-27, 45, 70);
	glVertex3f(-27, 45, 75);
	glVertex3f(-28, 55, 75);
	glVertex3f(-28, 55, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-22, 45, 70);
	glVertex3f(-22, 45, 75);
	glVertex3f(-21, 55, 75);
	glVertex3f(-21, 55, 70);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.55, 0.55, 0.55);
	glVertex3f(-22, 45.1, 70);
	glVertex3f(-22, 45.1, 75);
	glVertex3f(-27, 45.1, 75);
	glVertex3f(-27, 45.1, 70);
	glEnd();

	//kelas kanan
	glColor3f(0.57, 0.22, 0.08);
	glBegin(GL_QUADS);
	glVertex3f(20, 45, 80);
	glVertex3f(20, 45, -20);
	glVertex3f(20, 90, -20);
	glVertex3f(20, 90, 80);
	glEnd();

	glBegin(GL_QUADS);//pembatas
	glVertex3f(90, 45, -20);
	glVertex3f(20, 45, -20);
	glVertex3f(20, 90, -20);
	glVertex3f(90, 90, -20);
	glEnd();

	//tempat sampah
	glBegin(GL_QUADS);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(27, 45, 75);
	glVertex3f(22, 45, 75);
	glVertex3f(21, 55, 75);
	glVertex3f(28, 55, 75);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(27, 45, 70);
	glVertex3f(22, 45, 70);
	glVertex3f(21, 55, 70);
	glVertex3f(28, 55, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(27, 45, 70);
	glVertex3f(27, 45, 75);
	glVertex3f(28, 55, 75);
	glVertex3f(28, 55, 70);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(22, 45, 70);
	glVertex3f(22, 45, 75);
	glVertex3f(21, 55, 75);
	glVertex3f(21, 55, 70);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.55, 0.55, 0.55);
	glVertex3f(22, 45.1, 70);
	glVertex3f(22, 45.1, 75);
	glVertex3f(27, 45.1, 75);
	glVertex3f(27, 45.1, 70);
	glEnd();

}

void atap()
{
	//dasar atap
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-90, 90, 80);
	glVertex3f(90, 90, 80);
	glVertex3f(90, 90, -90);
	glVertex3f(-90, 90, -90);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.57, 0.22, 0.08);
	glVertex3f(12, 90, 80);
	glVertex3f(-12, 90, 80);
	glVertex3f(-5, 90, 85);
	glVertex3f(5, 90, 85);
	glEnd();

	//tembok kanan
	//miring kiri
	glBegin(GL_QUADS);
	glColor3f(0.57, 0.22, 0.08);
	glVertex3f(90, 90, 80);
	glVertex3f(110 - 10, 90, 70);
	glVertex3f(110 - 10, 110, 70);
	glVertex3f(90, 110, 80);
	glEnd();

	//lurus kiri
	glBegin(GL_QUADS);
	glVertex3f(110 - 10, 90, 50);
	glVertex3f(110 - 10, 90, 70);
	glVertex3f(110 - 10, 110, 70);
	glVertex3f(110 - 10, 110, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(90, 90, 40);
	glVertex3f(110 - 10, 90, 50);
	glVertex3f(110 - 10, 110, 50);
	glVertex3f(90, 110, 40);
	glEnd();

	//lurus tengah
	glBegin(GL_QUADS);
	glVertex3f(90, 90, 80);
	glVertex3f(70, 90, 80);
	glVertex3f(70, 110, 80);
	glVertex3f(90, 110, 80);
	glEnd();

	//miring kanan
	glBegin(GL_QUADS);
	glVertex3f(50 + 10, 90, 70);
	glVertex3f(70, 90, 80);
	glVertex3f(70, 110, 80);
	glVertex3f(50 + 10, 110, 70);
	glEnd();

	//lurus kanan
	glBegin(GL_QUADS);
	glVertex3f(50 + 10, 90, 50);
	glVertex3f(50 + 10, 90, 70);
	glVertex3f(50 + 10, 110, 70);
	glVertex3f(50 + 10, 110, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(50 + 10, 90, 50);
	glVertex3f(70, 90, 40);
	glVertex3f(70, 110, 40);
	glVertex3f(50 + 10, 110, 50);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(90, 90, 40);
	glVertex3f(70, 90, 40);
	glVertex3f(70, 110, 40);
	glVertex3f(90, 110, 40);
	glEnd();

	//penutup atap kanan
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(90, 110, 40);
	glVertex3f(70, 110, 40);
	glVertex3f(50 + 10, 110, 50);
	glVertex3f(50 + 10, 110, 70);
	glVertex3f(70, 110, 80);
	glVertex3f(90, 110, 80);
	glVertex3f(110 - 10, 110, 70);
	glVertex3f(110 - 10, 110, 50);
	glEnd();

	//tembok kiri
	//miring kiri
	glBegin(GL_QUADS);
	glColor3f(0.57, 0.22, 0.08);
	glVertex3f(-90, 90, 80);
	glVertex3f(-110 + 10, 90, 70);
	glVertex3f(-110 + 10, 150, 70);
	glVertex3f(-90, 150, 80);
	glEnd();

	//lurus kiri
	glBegin(GL_QUADS);
	glVertex3f(-110 + 10, 90, 50);
	glVertex3f(-110 + 10, 90, 70);
	glVertex3f(-110 + 10, 150, 70);
	glVertex3f(-110 + 10, 150, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(-90, 90, 40);
	glVertex3f(-110 + 10, 90, 50);
	glVertex3f(-110 + 10, 150, 50);
	glVertex3f(-90, 150, 40);
	glEnd();

	//lurus tengah
	glBegin(GL_QUADS);
	glVertex3f(-90, 90, 80);
	glVertex3f(-70, 90, 80);
	glVertex3f(-70, 150, 80);
	glVertex3f(-90, 150, 80);
	glEnd();

	//miring kanan
	glBegin(GL_QUADS);
	glVertex3f(-50 - 10, 90, 70);
	glVertex3f(-70, 90, 80);
	glVertex3f(-70, 150, 80);
	glVertex3f(-50 - 10, 150, 70);
	glEnd();

	//lurus kanan
	glBegin(GL_QUADS);
	glVertex3f(-50 - 10, 90, 50);
	glVertex3f(-50 - 10, 90, 70);
	glVertex3f(-50 - 10, 150, 70);
	glVertex3f(-50 - 10, 150, 50);
	glEnd();

	//miring belakang
	glBegin(GL_QUADS);
	glVertex3f(-50 - 10, 90, 50);
	glVertex3f(-70, 90, 40);
	glVertex3f(-70, 150, 40);
	glVertex3f(-50 - 10, 150, 50);
	glEnd();

	//lurus ke belakang kanan
	glBegin(GL_QUADS);
	glVertex3f(-70, 90, -90);
	glVertex3f(-70, 90, 40);
	glVertex3f(-70, 150, 40);
	glVertex3f(-70, 150, -90);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-90, 90, -90);
	glVertex3f(-90, 90, 40);
	glVertex3f(-90, 150, 40);
	glVertex3f(-90, 150, -90);
	glEnd();

	//belakang
	glBegin(GL_QUADS);
	glVertex3f(-90, 90, -90);
	glVertex3f(-70, 90, -90);
	glVertex3f(-70, 150, -90);
	glVertex3f(-90, 150, -90);
	glEnd();

	//penutup tembok kiri
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-90, 150, -90);
	glVertex3f(-70, 150, -90);
	glVertex3f(-70, 150, 40);
	glVertex3f(-90, 150, 40);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-90, 150, 40);
	glVertex3f(-70, 150, 40);
	glVertex3f(-50 - 10, 150, 50);
	glVertex3f(-50 - 10, 150, 70);
	glVertex3f(-70, 150, 80);
	glVertex3f(-90, 150, 80);
	glVertex3f(-110 + 10, 150, 70);
	glVertex3f(-110 + 10, 150, 50);
	glEnd();


	glColor3f(0.57, 0.22, 0.08);
	int a = 0;
	for (int i = 0; i < 13; i++) {
		if (i == 5 || i == 6 || i == 7) {

		}
		else {
			glBegin(GL_QUADS);
			glVertex3f(-63 + a, 95, 80);
			glVertex3f(-58 + a, 95, 80);
			glVertex3f(-58 + a, 90, 80);
			glVertex3f(-63 + a, 90, 80);
			glEnd();
		}
		a += 10;
	}

	glBegin(GL_QUADS);
	glVertex3f(-12, 95, 80);
	glVertex3f(-5, 95, 85);
	glVertex3f(-5, 90, 85);
	glVertex3f(-12, 90, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(12, 95, 80);
	glVertex3f(5, 95, 85);
	glVertex3f(5, 90, 85);
	glVertex3f(12, 90, 80);
	glEnd();

	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_QUADS);
	glVertex3f(50, 110, 60);
	glVertex3f(-50, 110, 60);
	glVertex3f(-70, 90, 80);
	glVertex3f(70, 90, 80);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(50, 110, 60);
	glVertex3f(-50, 110, 60);
	glVertex3f(-70, 90, 40);
	glVertex3f(70, 90, 40);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(-70, 90, 40);
	glVertex3f(-70, 90, 80);
	glVertex3f(-50, 110, 60);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(70, 90, 40);
	glVertex3f(70, 90, 80);
	glVertex3f(50, 110, 60);
	glEnd();
}

void lantai()
{
	//alas base program
	glBegin(GL_QUADS);
	glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-150, 0, 100);
	glVertex3f(150, 0, 100);
	glVertex3f(150, 0, -150);
	glVertex3f(-150, 0, -150);
	glEnd();

	//lantai 1
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(12, 6, 80);
	glVertex3f(90, 6, 80);
	glVertex3f(90, 6, -90);
	glVertex3f(12, 6, -90);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 6, 80);
	glVertex3f(-90, 6, 80);
	glVertex3f(-90, 6, -90);
	glVertex3f(-12, 6, -90);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 6, 70);
	glVertex3f(12, 6, 70);
	glVertex3f(12, 6, -90);
	glVertex3f(-12, 6, -90);
	glEnd();

	//tangga pintu depan
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.4, 0.4);
	glVertex3f(-12, 0, 79);
	glVertex3f(12, 0, 79);
	glVertex3f(12, 2, 79);
	glVertex3f(-12, 2, 79);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 4, 76);
	glVertex3f(12, 4, 76);
	glVertex3f(12, 2, 76);
	glVertex3f(-12, 2, 76);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 4, 73);
	glVertex3f(12, 4, 73);
	glVertex3f(12, 6, 73);
	glVertex3f(-12, 6, 73);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-12, 2, 79);
	glVertex3f(12, 2, 79);
	glVertex3f(12, 2, 76);
	glVertex3f(-12, 2, 76);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 4, 73);
	glVertex3f(12, 4, 73);
	glVertex3f(12, 4, 76);
	glVertex3f(-12, 4, 76);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(-12, 6, 73);
	glVertex3f(12, 6, 73);
	glVertex3f(12, 6, 70);
	glVertex3f(-12, 6, 70);
	glEnd();

	//lantai 2
	glBegin(GL_QUADS);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-90, 45, 80);
	glVertex3f(90, 45, 80);
	glVertex3f(90, 45, -50);
	glVertex3f(-90, 45, -50);
	glEnd();

	//lantai depan
	glBegin(GL_QUADS);
	glVertex3f(12, 45, 80);
	glVertex3f(-12, 45, 80);
	glVertex3f(-5, 45, 85);
	glVertex3f(5, 45, 85);
	glEnd();

	//jalan
	glBegin(GL_QUADS);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-150, 0, 130);
	glVertex3f(150, 0, 130);
	glVertex3f(150, 0, 100);
	glVertex3f(-150, 0, 100);
	glEnd();
}

void mejakelas()
{
	//////////////////BARIS 1//////////////////////////////////////////
	//Badan Meja Atas
	glColor3ub(200, 165, 30);
	glBegin(GL_QUADS);
	glVertex3f(82, 58, 15);//kiri belakang
	glVertex3f(82, 58, 25);//kiri depan
	glVertex3f(69, 58, 25);//kanan depan
	glVertex3f(69, 58, 15);//kanan belakang
	glEnd();
	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(82, 55, 15);//kiri belakang
	glVertex3f(82, 55, 25);//kiri depan
	glVertex3f(69, 55, 25);//kanan depan
	glVertex3f(69, 55, 15);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 25);//kiri atas
	glVertex3f(82, 55, 25);//kiri bawah
	glVertex3f(70, 55, 25);//kanan bawah
	glVertex3f(70, 58, 25);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 15);//kiri belakang
	glVertex3f(82, 58, 25);//kanan depan
	glVertex3f(82, 45, 25);//kanan bawah
	glVertex3f(82, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(81, 58, 15);//kiri belakang
	glVertex3f(81, 58, 25);//kanan depan
	glVertex3f(81, 45, 25);//kanan bawah
	glVertex3f(81, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 25);//kiri atas
	glVertex3f(82, 45, 25);//kiri bawah
	glVertex3f(81, 45, 25);//kanan bawah
	glVertex3f(81, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 15);//kiri atas
	glVertex3f(82, 45, 15);//kiri bawah
	glVertex3f(81, 45, 15);//kanan bawah
	glVertex3f(81, 58, 15);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(70, 58, 15);//kiri belakang
	glVertex3f(70, 58, 25);//kanan depan
	glVertex3f(70, 45, 25);//kanan bawah
	glVertex3f(70, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(69, 58, 15);//kiri belakang
	glVertex3f(69, 58, 25);//kanan depan
	glVertex3f(69, 45, 25);//kanan bawah
	glVertex3f(69, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(70, 58, 25);//kiri atas
	glVertex3f(70, 45, 25);//kiri bawah
	glVertex3f(69, 45, 25);//kanan bawah
	glVertex3f(69, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(70, 58, 15);//kiri atas
	glVertex3f(70, 45, 15);//kiri bawah
	glVertex3f(69, 45, 15);//kanan bawah
	glVertex3f(69, 58, 15);//kanan atas
	glEnd();

	//////////////////BARIS 2//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 15);//kiri belakang
	glVertex3f(xkelasi - 82, 58, 25);//kiri depan
	glVertex3f(xkelasi - 69, 58, 25);//kanan depan
	glVertex3f(xkelasi - 69, 58, 15);//kanan belakang
	glEnd();

	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 55, 15);//kiri belakang
	glVertex3f(xkelasi - 82, 55, 25);//kiri depan
	glVertex3f(xkelasi - 69, 55, 25);//kanan depan
	glVertex3f(xkelasi - 69, 55, 15);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 25);//kiri atas
	glVertex3f(xkelasi - 82, 55, 25);//kiri bawah
	glVertex3f(xkelasi - 70, 55, 25);//kanan bawah
	glVertex3f(xkelasi - 70, 58, 25);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 15);//kiri belakang
	glVertex3f(xkelasi - 82, 58, 25);//kanan depan
	glVertex3f(xkelasi - 82, 45, 25);//kanan bawah
	glVertex3f(xkelasi - 82, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 81, 58, 15);//kiri belakang
	glVertex3f(xkelasi - 81, 58, 25);//kanan depan
	glVertex3f(xkelasi - 81, 45, 25);//kanan bawah
	glVertex3f(xkelasi - 81, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 25);//kiri atas
	glVertex3f(xkelasi - 82, 45, 25);//kiri bawah
	glVertex3f(xkelasi - 81, 45, 25);//kanan bawah
	glVertex3f(xkelasi - 81, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 15);//kiri atas
	glVertex3f(xkelasi - 82, 45, 15);//kiri bawah
	glVertex3f(xkelasi - 81, 45, 15);//kanan bawah
	glVertex3f(xkelasi - 81, 58, 15);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 70, 58, 15);//kiri belakang
	glVertex3f(xkelasi - 70, 58, 25);//kanan depan
	glVertex3f(xkelasi - 70, 45, 25);//kanan bawah
	glVertex3f(xkelasi - 70, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 69, 58, 15);//kiri belakang
	glVertex3f(xkelasi - 69, 58, 25);//kanan depan
	glVertex3f(xkelasi - 69, 45, 25);//kanan bawah
	glVertex3f(xkelasi - 69, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 70, 58, 25);//kiri atas
	glVertex3f(xkelasi - 70, 45, 25);//kiri bawah
	glVertex3f(xkelasi - 69, 45, 25);//kanan bawah
	glVertex3f(xkelasi - 69, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 70, 58, 15);//kiri atas
	glVertex3f(xkelasi - 70, 45, 15);//kiri bawah
	glVertex3f(xkelasi - 69, 45, 15);//kanan bawah
	glVertex3f(xkelasi - 69, 58, 15);//kanan atas
	glEnd();

	//////////////////BARIS 3//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(82, 58, 25 + zkelas);//kiri depan
	glVertex3f(69, 58, 25 + zkelas);//kanan depan
	glVertex3f(69, 58, 15 + zkelas);//kanan belakang
	glEnd();
	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(82, 55, 15 + zkelas);//kiri belakang
	glVertex3f(82, 55, 25 + zkelas);//kiri depan
	glVertex3f(69, 55, 25 + zkelas);//kanan depan
	glVertex3f(69, 55, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 25 + zkelas);//kiri atas
	glVertex3f(82, 55, 25 + zkelas);//kiri bawah
	glVertex3f(70, 55, 25 + zkelas);//kanan bawah
	glVertex3f(70, 58, 25 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(82, 58, 25 + zkelas);//kanan depan
	glVertex3f(82, 45, 25 + zkelas);//kanan bawah
	glVertex3f(82, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(81, 58, 15 + zkelas);//kiri belakang
	glVertex3f(81, 58, 25 + zkelas);//kanan depan
	glVertex3f(81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(81, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 25 + zkelas);//kiri atas
	glVertex3f(82, 45, 25 + zkelas);//kiri bawah
	glVertex3f(81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(81, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(82, 58, 15 + zkelas);//kiri atas
	glVertex3f(82, 45, 15 + zkelas);//kiri bawah
	glVertex3f(81, 45, 15 + zkelas);//kanan bawah
	glVertex3f(81, 58, 15 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(70, 58, 15 + zkelas);//kiri belakang
	glVertex3f(70, 58, 25 + zkelas);//kanan depan
	glVertex3f(70, 45, 25 + zkelas);//kanan bawah
	glVertex3f(70, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(69, 58, 15 + zkelas);//kiri belakang
	glVertex3f(69, 58, 25 + zkelas);//kanan depan
	glVertex3f(69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(69, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(70, 58, 25 + zkelas);//kiri atas
	glVertex3f(70, 45, 25 + zkelas);//kiri bawah
	glVertex3f(69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(69, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(70, 58, 15 + zkelas);//kiri atas
	glVertex3f(70, 45, 15 + zkelas);//kiri bawah
	glVertex3f(69, 45, 15 + zkelas);//kanan bawah
	glVertex3f(69, 58, 15 + zkelas);//kanan atas
	glEnd();

	//////////////////BARIS 4//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 82, 58, 25 + zkelas);//kiri depan
	glVertex3f(xkelasi - 69, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 69, 58, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 55, 15 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 82, 55, 25 + zkelas);//kiri depan
	glVertex3f(xkelasi - 69, 55, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 69, 55, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 25 + zkelas);//kiri atas
	glVertex3f(xkelasi - 82, 55, 25 + zkelas);//kiri bawah
	glVertex3f(xkelasi - 70, 55, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 70, 58, 25 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 82, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 82, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 82, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 81, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 81, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 81, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 25 + zkelas);//kiri atas
	glVertex3f(xkelasi - 82, 45, 25 + zkelas);//kiri bawah
	glVertex3f(xkelasi - 81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 81, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 82, 58, 15 + zkelas);//kiri atas
	glVertex3f(xkelasi - 82, 45, 15 + zkelas);//kiri bawah
	glVertex3f(xkelasi - 81, 45, 15 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 81, 58, 15 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kanan
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 70, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 70, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 70, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 70, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 69, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 69, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 69, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 70, 58, 25 + zkelas);//kiri atas
	glVertex3f(xkelasi - 70, 45, 25 + zkelas);//kiri bawah
	glVertex3f(xkelasi - 69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 69, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 70, 58, 15 + zkelas);//kiri atas
	glVertex3f(xkelasi - 70, 45, 15 + zkelas);//kiri bawah
	glVertex3f(xkelasi - 69, 45, 15 + zkelas);//kanan bawah
	glVertex3f(xkelasi - 69, 58, 15 + zkelas);//kanan atas
	glEnd();
	//////////////////BARIS 1//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 15);//kiri belakang
	glVertex3f(-82, 58, 25);//kiri depan
	glVertex3f(-69, 58, 25);//kanan depan
	glVertex3f(-69, 58, 15);//kanan belakang
	glEnd();
	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(-82, 55, 15);//kiri belakang
	glVertex3f(-82, 55, 25);//kiri depan
	glVertex3f(-69, 55, 25);//kanan depan
	glVertex3f(-69, 55, 15);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 25);//kiri atas
	glVertex3f(-82, 55, 25);//kiri bawah
	glVertex3f(-70, 55, 25);//kanan bawah
	glVertex3f(-70, 58, 25);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 15);//kiri belakang
	glVertex3f(-82, 58, 25);//kanan depan
	glVertex3f(-82, 45, 25);//kanan bawah
	glVertex3f(-82, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(-81, 58, 15);//kiri belakang
	glVertex3f(-81, 58, 25);//kanan depan
	glVertex3f(-81, 45, 25);//kanan bawah
	glVertex3f(-81, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 25);//kiri atas
	glVertex3f(-82, 45, 25);//kiri bawah
	glVertex3f(-81, 45, 25);//kanan bawah
	glVertex3f(-81, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 15);//kiri atas
	glVertex3f(-82, 45, 15);//kiri bawah
	glVertex3f(-81, 45, 15);//kanan bawah
	glVertex3f(-81, 58, 15);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(-70, 58, 15);//kiri belakang
	glVertex3f(-70, 58, 25);//kanan depan
	glVertex3f(-70, 45, 25);//kanan bawah
	glVertex3f(-70, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(-69, 58, 15);//kiri belakang
	glVertex3f(-69, 58, 25);//kanan depan
	glVertex3f(-69, 45, 25);//kanan bawah
	glVertex3f(-69, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(-70, 58, 25);//kiri atas
	glVertex3f(-70, 45, 25);//kiri bawah
	glVertex3f(-69, 45, 25);//kanan bawah
	glVertex3f(-69, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(-70, 58, 15);//kiri atas
	glVertex3f(-70, 45, 15);//kiri bawah
	glVertex3f(-69, 45, 15);//kanan bawah
	glVertex3f(-69, 58, 15);//kanan atas
	glEnd();

	//////////////////BARIS 2//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 15);//kiri belakang
	glVertex3f(xkelas - 82, 58, 25);//kiri depan
	glVertex3f(xkelas - 69, 58, 25);//kanan depan
	glVertex3f(xkelas - 69, 58, 15);//kanan belakang
	glEnd();

	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 55, 15);//kiri belakang
	glVertex3f(xkelas - 82, 55, 25);//kiri depan
	glVertex3f(xkelas - 69, 55, 25);//kanan depan
	glVertex3f(xkelas - 69, 55, 15);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 25);//kiri atas
	glVertex3f(xkelas - 82, 55, 25);//kiri bawah
	glVertex3f(xkelas - 70, 55, 25);//kanan bawah
	glVertex3f(xkelas - 70, 58, 25);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 15);//kiri belakang
	glVertex3f(xkelas - 82, 58, 25);//kanan depan
	glVertex3f(xkelas - 82, 45, 25);//kanan bawah
	glVertex3f(xkelas - 82, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 81, 58, 15);//kiri belakang
	glVertex3f(xkelas - 81, 58, 25);//kanan depan
	glVertex3f(xkelas - 81, 45, 25);//kanan bawah
	glVertex3f(xkelas - 81, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 25);//kiri atas
	glVertex3f(xkelas - 82, 45, 25);//kiri bawah
	glVertex3f(xkelas - 81, 45, 25);//kanan bawah
	glVertex3f(xkelas - 81, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 15);//kiri atas
	glVertex3f(xkelas - 82, 45, 15);//kiri bawah
	glVertex3f(xkelas - 81, 45, 15);//kanan bawah
	glVertex3f(xkelas - 81, 58, 15);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 70, 58, 15);//kiri belakang
	glVertex3f(xkelas - 70, 58, 25);//kanan depan
	glVertex3f(xkelas - 70, 45, 25);//kanan bawah
	glVertex3f(xkelas - 70, 45, 15);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 69, 58, 15);//kiri belakang
	glVertex3f(xkelas - 69, 58, 25);//kanan depan
	glVertex3f(xkelas - 69, 45, 25);//kanan bawah
	glVertex3f(xkelas - 69, 45, 15);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 70, 58, 25);//kiri atas
	glVertex3f(xkelas - 70, 45, 25);//kiri bawah
	glVertex3f(xkelas - 69, 45, 25);//kanan bawah
	glVertex3f(xkelas - 69, 58, 25);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 70, 58, 15);//kiri atas
	glVertex3f(xkelas - 70, 45, 15);//kiri bawah
	glVertex3f(xkelas - 69, 45, 15);//kanan bawah
	glVertex3f(xkelas - 69, 58, 15);//kanan atas
	glEnd();

	//////////////////BARIS 3//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(-82, 58, 25 + zkelas);//kiri depan
	glVertex3f(-69, 58, 25 + zkelas);//kanan depan
	glVertex3f(-69, 58, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(-82, 55, 15 + zkelas);//kiri belakang
	glVertex3f(-82, 55, 25 + zkelas);//kiri depan
	glVertex3f(-69, 55, 25 + zkelas);//kanan depan
	glVertex3f(-69, 55, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 25 + zkelas);//kiri atas
	glVertex3f(-82, 55, 25 + zkelas);//kiri bawah
	glVertex3f(-70, 55, 25 + zkelas);//kanan bawah
	glVertex3f(-70, 58, 25 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(-82, 58, 25 + zkelas);//kanan depan
	glVertex3f(-82, 45, 25 + zkelas);//kanan bawah
	glVertex3f(-82, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(-81, 58, 15 + zkelas);//kiri belakang
	glVertex3f(-81, 58, 25 + zkelas);//kanan depan
	glVertex3f(-81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(-81, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 25 + zkelas);//kiri atas
	glVertex3f(-82, 45, 25 + zkelas);//kiri bawah
	glVertex3f(-81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(-81, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(-82, 58, 15 + zkelas);//kiri atas
	glVertex3f(-82, 45, 15 + zkelas);//kiri bawah
	glVertex3f(-81, 45, 15 + zkelas);//kanan bawah
	glVertex3f(-81, 58, 15 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(-70, 58, 15 + zkelas);//kiri belakang
	glVertex3f(-70, 58, 25 + zkelas);//kanan depan
	glVertex3f(-70, 45, 25 + zkelas);//kanan bawah
	glVertex3f(-70, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(-69, 58, 15 + zkelas);//kiri belakang
	glVertex3f(-69, 58, 25 + zkelas);//kanan depan
	glVertex3f(-69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(-69, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(-70, 58, 25 + zkelas);//kiri atas
	glVertex3f(-70, 45, 25 + zkelas);//kiri bawah
	glVertex3f(-69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(-69, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(-70, 58, 15 + zkelas);//kiri atas
	glVertex3f(-70, 45, 15 + zkelas);//kiri bawah
	glVertex3f(-69, 45, 15 + zkelas);//kanan bawah
	glVertex3f(-69, 58, 15 + zkelas);//kanan atas
	glEnd();

	//////////////////BARIS 4//////////////////////////////////////////
	//Badan Meja Atas

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelas - 82, 58, 25 + zkelas);//kiri depan
	glVertex3f(xkelas - 69, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 69, 58, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Bawah

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 55, 15 + zkelas);//kiri belakang
	glVertex3f(xkelas - 82, 55, 25 + zkelas);//kiri depan
	glVertex3f(xkelas - 69, 55, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 69, 55, 15 + zkelas);//kanan belakang
	glEnd();

	//Badan Meja Depan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 25 + zkelas);//kiri atas
	glVertex3f(xkelas - 82, 55, 25 + zkelas);//kiri bawah
	glVertex3f(xkelas - 70, 55, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 70, 58, 25 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelas - 82, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 82, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 82, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 81, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelas - 81, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 81, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 25 + zkelas);//kiri atas
	glVertex3f(xkelas - 82, 45, 25 + zkelas);//kiri bawah
	glVertex3f(xkelas - 81, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 81, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kiri

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 82, 58, 15 + zkelas);//kiri atas
	glVertex3f(xkelas - 82, 45, 15 + zkelas);//kiri bawah
	glVertex3f(xkelas - 81, 45, 15 + zkelas);//kanan bawah
	glVertex3f(xkelas - 81, 58, 15 + zkelas);//kanan atas
	glEnd();

	//Kaki Meja Kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 70, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelas - 70, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 70, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 70, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 69, 58, 15 + zkelas);//kiri belakang
	glVertex3f(xkelas - 69, 58, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 69, 45, 15 + zkelas);//kiri bawah
	glEnd();

	//depan bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 70, 58, 25 + zkelas);//kiri atas
	glVertex3f(xkelas - 70, 45, 25 + zkelas);//kiri bawah
	glVertex3f(xkelas - 69, 45, 25 + zkelas);//kanan bawah
	glVertex3f(xkelas - 69, 58, 25 + zkelas);//kanan atas
	glEnd();

	//belakang bagian 2 kanan

	glBegin(GL_QUADS);
	glVertex3f(xkelas - 70, 58, 15 + zkelas);//kiri atas
	glVertex3f(xkelas - 70, 45, 15 + zkelas);//kiri bawah
	glVertex3f(xkelas - 69, 45, 15 + zkelas);//kanan bawah
	glVertex3f(xkelas - 69, 58, 15 + zkelas);//kanan atas
	glEnd();
}

void kursikelas()
{
	////////////////////////////////////////////////kursi 1
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 55, 10);//kiri belakang
	glVertex3f(78, 55, 25);//kiri depan
	glVertex3f(72, 55, 25);//kanan depan
	glVertex3f(72, 55, 10);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 53, 10);//kiri belakang
	glVertex3f(78, 53, 25);//kiri depan
	glVertex3f(72, 53, 25);//kanan depan
	glVertex3f(72, 53, 10);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 55, 25);//atas kiri
	glVertex3f(72, 55, 25);//atas kanan
	glVertex3f(72, 53, 25);//bawah kanan
	glVertex3f(78, 53, 25);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 55, 25);//atas kiri
	glVertex3f(78, 55, 10);//kiri belakang
	glVertex3f(78, 45, 10);//kanan belakang
	glVertex3f(78, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(79, 55, 25);//atas kiri
	glVertex3f(79, 55, 10);//kiri belakang
	glVertex3f(79, 45, 10);//kiri belakang
	glVertex3f(79, 45, 25);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(79, 55, 25);//atas kiri
	glVertex3f(78, 55, 25);//atas kanan
	glVertex3f(78, 45, 25);//kiri belakang
	glVertex3f(79, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(79, 55, 10);//atas kiri
	glVertex3f(78, 55, 10);//atas kanan
	glVertex3f(78, 45, 10);//kiri belakang
	glVertex3f(79, 45, 10);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(72, 55, 25);//atas kiri
	glVertex3f(72, 55, 10);//kiri belakang
	glVertex3f(72, 45, 10);//kanan belakang
	glVertex3f(72, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(73, 55, 25);//atas kiri
	glVertex3f(73, 55, 10);//kiri belakang
	glVertex3f(73, 45, 10);//kiri belakang
	glVertex3f(73, 45, 25);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(73, 55, 25);//atas kiri
	glVertex3f(72, 55, 25);//atas kanan
	glVertex3f(72, 45, 25);//kiri belakang
	glVertex3f(73, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(73, 55, 10);//atas kiri
	glVertex3f(72, 55, 10);//atas kanan
	glVertex3f(72, 45, 10);//kiri belakang
	glVertex3f(73, 45, 10);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 53, 10);//bawah kiri
	glVertex3f(72, 53, 10);//bawah kanan
	glVertex3f(72, 65, 10);//atas kanan
	glVertex3f(78, 65, 10);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 53, 12);//bawah kiri
	glVertex3f(72, 53, 12);//bawah kanan
	glVertex3f(72, 65, 12);//atas kanan
	glVertex3f(78, 65, 12);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 65, 10);//depan kiri
	glVertex3f(78, 65, 12);//depan kanan
	glVertex3f(72, 65, 12);//belakang kanan
	glVertex3f(72, 65, 10);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 65, 10);//atas kanan
	glVertex3f(78, 53, 10);//bawah kanan
	glVertex3f(78, 53, 12);//bawah kiri
	glVertex3f(78, 65, 12);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(72, 65, 10);//atas kanan
	glVertex3f(72, 53, 10);//bawah kanan
	glVertex3f(72, 53, 12);//bawah kiri
	glVertex3f(72, 65, 12);//atas kiri
	glEnd();

	//////////////////////////////////////////////////kursi 2
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 55, 10);//kiri belakang
	glVertex3f(xkelasi - 78, 55, 25);//kiri depan
	glVertex3f(xkelasi - 72, 55, 25);//kanan depan
	glVertex3f(xkelasi - 72, 55, 10);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 53, 10);//kiri belakang
	glVertex3f(xkelasi - 78, 53, 25);//kiri depan
	glVertex3f(xkelasi - 72, 53, 25);//kanan depan
	glVertex3f(xkelasi - 72, 53, 10);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 55, 25);//atas kiri
	glVertex3f(xkelasi - 72, 55, 25);//atas kanan
	glVertex3f(xkelasi - 72, 53, 25);//bawah kanan
	glVertex3f(xkelasi - 78, 53, 25);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 55, 25);//atas kiri
	glVertex3f(xkelasi - 78, 55, 10);//kiri belakang
	glVertex3f(xkelasi - 78, 45, 10);//kanan belakang
	glVertex3f(xkelasi - 78, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 79, 55, 25);//atas kiri
	glVertex3f(xkelasi - 79, 55, 10);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 10);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 25);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 79, 55, 25);//atas kiri
	glVertex3f(xkelasi - 78, 55, 25);//atas kanan
	glVertex3f(xkelasi - 78, 45, 25);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 79, 55, 10);//atas kiri
	glVertex3f(xkelasi - 78, 55, 10);//atas kanan
	glVertex3f(xkelasi - 78, 45, 10);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 10);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 72, 55, 25);//atas kiri
	glVertex3f(xkelasi - 72, 55, 10);//kiri belakang
	glVertex3f(xkelasi - 72, 45, 10);//kanan belakang
	glVertex3f(xkelasi - 72, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 73, 55, 25);//atas kiri
	glVertex3f(xkelasi - 73, 55, 10);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 10);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 25);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 73, 55, 25);//atas kiri
	glVertex3f(xkelasi - 72, 55, 25);//atas kanan
	glVertex3f(xkelasi - 72, 45, 25);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 73, 55, 10);//atas kiri
	glVertex3f(xkelasi - 72, 55, 10);//atas kanan
	glVertex3f(xkelasi - 72, 45, 10);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 10);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 53, 10);//bawah kiri
	glVertex3f(xkelasi - 72, 53, 10);//bawah kanan
	glVertex3f(xkelasi - 72, 65, 10);//atas kanan
	glVertex3f(xkelasi - 78, 65, 10);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 53, 12);//bawah kiri
	glVertex3f(xkelasi - 72, 53, 12);//bawah kanan
	glVertex3f(xkelasi - 72, 65, 12);//atas kanan
	glVertex3f(xkelasi - 78, 65, 12);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 65, 10);//depan kiri
	glVertex3f(xkelasi - 78, 65, 12);//depan kanan
	glVertex3f(xkelasi - 72, 65, 12);//belakang kanan
	glVertex3f(xkelasi - 72, 65, 10);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 65, 10);//atas kanan
	glVertex3f(xkelasi - 78, 53, 10);//bawah kanan
	glVertex3f(xkelasi - 78, 53, 12);//bawah kiri
	glVertex3f(xkelasi - 78, 65, 12);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 72, 65, 10);//atas kanan
	glVertex3f(xkelasi - 72, 53, 10);//bawah kanan
	glVertex3f(xkelasi - 72, 53, 12);//bawah kiri
	glVertex3f(xkelasi - 72, 65, 12);//atas kiri
	glEnd();

	//////////////////////////////////////////////////kursi 3
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(78, 55, 25 + zkelas);//kiri depan
	glVertex3f(72, 55, 25 + zkelas);//kanan depan
	glVertex3f(72, 55, 10 + zkelas);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 53, 10 + zkelas);//kiri belakang
	glVertex3f(78, 53, 25 + zkelas);//kiri depan
	glVertex3f(72, 53, 25 + zkelas);//kanan depan
	glVertex3f(72, 53, 10 + zkelas);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 55, 25 + zkelas);//atas kiri
	glVertex3f(72, 55, 25 + zkelas);//atas kanan
	glVertex3f(72, 53, 25 + zkelas);//bawah kanan
	glVertex3f(78, 53, 25 + zkelas);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 55, 25 + zkelas);//atas kiri
	glVertex3f(78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(78, 45, 10 + zkelas);//kanan belakang
	glVertex3f(78, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(79, 55, 25 + zkelas);//atas kiri
	glVertex3f(79, 55, 10 + zkelas);//kiri belakang
	glVertex3f(79, 45, 10 + zkelas);//kiri belakang
	glVertex3f(79, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(79, 55, 25 + zkelas);//atas kiri
	glVertex3f(78, 55, 25 + zkelas);//atas kanan
	glVertex3f(78, 45, 25 + zkelas);//kiri belakang
	glVertex3f(79, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(79, 55, 10 + zkelas);//atas kiri
	glVertex3f(78, 55, 10 + zkelas);//atas kanan
	glVertex3f(78, 45, 10 + zkelas);//kiri belakang
	glVertex3f(79, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(72, 55, 25 + zkelas);//atas kiri
	glVertex3f(72, 55, 10 + zkelas);//kiri belakang
	glVertex3f(72, 45, 10 + zkelas);//kanan belakang
	glVertex3f(72, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(73, 55, 25 + zkelas);//atas kiri
	glVertex3f(73, 55, 10 + zkelas);//kiri belakang
	glVertex3f(73, 45, 10 + zkelas);//kiri belakang
	glVertex3f(73, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(73, 55, 25 + zkelas);//atas kiri
	glVertex3f(72, 55, 25 + zkelas);//atas kanan
	glVertex3f(72, 45, 25 + zkelas);//kiri belakang
	glVertex3f(73, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(73, 55, 10 + zkelas);//atas kiri
	glVertex3f(72, 55, 10 + zkelas);//atas kanan
	glVertex3f(72, 45, 10 + zkelas);//kiri belakang
	glVertex3f(73, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 53, 10 + zkelas);//bawah kiri
	glVertex3f(72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(72, 65, 10 + zkelas);//atas kanan
	glVertex3f(78, 65, 10 + zkelas);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(72, 53, 12 + zkelas);//bawah kanan
	glVertex3f(72, 65, 12 + zkelas);//atas kanan
	glVertex3f(78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 65, 10 + zkelas);//depan kiri
	glVertex3f(78, 65, 12 + zkelas);//depan kanan
	glVertex3f(72, 65, 12 + zkelas);//belakang kanan
	glVertex3f(72, 65, 10 + zkelas);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(78, 65, 10 + zkelas);//atas kanan
	glVertex3f(78, 53, 10 + zkelas);//bawah kanan
	glVertex3f(78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(72, 65, 10 + zkelas);//atas kanan
	glVertex3f(72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(72, 53, 12 + zkelas);//bawah kiri
	glVertex3f(72, 65, 12 + zkelas);//atas kiri
	glEnd();

	///////////////////////////////////////////////////kursi 4
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 78, 55, 25 + zkelas);//kiri depan
	glVertex3f(xkelasi - 72, 55, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 72, 55, 10 + zkelas);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 53, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 78, 53, 25 + zkelas);//kiri depan
	glVertex3f(xkelasi - 72, 53, 25 + zkelas);//kanan depan
	glVertex3f(xkelasi - 72, 53, 10 + zkelas);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 72, 55, 25 + zkelas);//atas kanan
	glVertex3f(xkelasi - 72, 53, 25 + zkelas);//bawah kanan
	glVertex3f(xkelasi - 78, 53, 25 + zkelas);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 78, 45, 10 + zkelas);//kanan belakang
	glVertex3f(xkelasi - 78, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 79, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 79, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 79, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 78, 55, 25 + zkelas);//atas kanan
	glVertex3f(xkelasi - 78, 45, 25 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 79, 55, 10 + zkelas);//atas kiri
	glVertex3f(xkelasi - 78, 55, 10 + zkelas);//atas kanan
	glVertex3f(xkelasi - 78, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 79, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 72, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 72, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 72, 45, 10 + zkelas);//kanan belakang
	glVertex3f(xkelasi - 72, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 73, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 73, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 73, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelasi - 72, 55, 25 + zkelas);//atas kanan
	glVertex3f(xkelasi - 72, 45, 25 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 73, 55, 10 + zkelas);//atas kiri
	glVertex3f(xkelasi - 72, 55, 10 + zkelas);//atas kanan
	glVertex3f(xkelasi - 72, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelasi - 73, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 53, 10 + zkelas);//bawah kiri
	glVertex3f(xkelasi - 72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(xkelasi - 72, 65, 10 + zkelas);//atas kanan
	glVertex3f(xkelasi - 78, 65, 10 + zkelas);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(xkelasi - 72, 53, 12 + zkelas);//bawah kanan
	glVertex3f(xkelasi - 72, 65, 12 + zkelas);//atas kanan
	glVertex3f(xkelasi - 78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 65, 10 + zkelas);//depan kiri
	glVertex3f(xkelasi - 78, 65, 12 + zkelas);//depan kanan
	glVertex3f(xkelasi - 72, 65, 12 + zkelas);//belakang kanan
	glVertex3f(xkelasi - 72, 65, 10 + zkelas);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 78, 65, 10 + zkelas);//atas kanan
	glVertex3f(xkelasi - 78, 53, 10 + zkelas);//bawah kanan
	glVertex3f(xkelasi - 78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(xkelasi - 78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelasi - 72, 65, 10 + zkelas);//atas kanan
	glVertex3f(xkelasi - 72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(xkelasi - 72, 53, 12 + zkelas);//bawah kiri
	glVertex3f(xkelasi - 72, 65, 12 + zkelas);//atas kiri
	glEnd();
	////////////////////////////////////////////////kursi 1
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 55, 10);//kiri belakang
	glVertex3f(-78, 55, 25);//kiri depan
	glVertex3f(-72, 55, 25);//kanan depan
	glVertex3f(-72, 55, 10);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 53, 10);//kiri belakang
	glVertex3f(-78, 53, 25);//kiri depan
	glVertex3f(-72, 53, 25);//kanan depan
	glVertex3f(-72, 53, 10);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 55, 25);//atas kiri
	glVertex3f(-72, 55, 25);//atas kanan
	glVertex3f(-72, 53, 25);//bawah kanan
	glVertex3f(-78, 53, 25);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 55, 25);//atas kiri
	glVertex3f(-78, 55, 10);//kiri belakang
	glVertex3f(-78, 45, 10);//kanan belakang
	glVertex3f(-78, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-79, 55, 25);//atas kiri
	glVertex3f(-79, 55, 10);//kiri belakang
	glVertex3f(-79, 45, 10);//kiri belakang
	glVertex3f(-79, 45, 25);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-79, 55, 25);//atas kiri
	glVertex3f(-78, 55, 25);//atas kanan
	glVertex3f(-78, 45, 25);//kiri belakang
	glVertex3f(-79, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-79, 55, 10);//atas kiri
	glVertex3f(-78, 55, 10);//atas kanan
	glVertex3f(-78, 45, 10);//kiri belakang
	glVertex3f(-79, 45, 10);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-72, 55, 25);//atas kiri
	glVertex3f(-72, 55, 10);//kiri belakang
	glVertex3f(-72, 45, 10);//kanan belakang
	glVertex3f(-72, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-73, 55, 25);//atas kiri
	glVertex3f(-73, 55, 10);//kiri belakang
	glVertex3f(-73, 45, 10);//kiri belakang
	glVertex3f(-73, 45, 25);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-73, 55, 25);//atas kiri
	glVertex3f(-72, 55, 25);//atas kanan
	glVertex3f(-72, 45, 25);//kiri belakang
	glVertex3f(-73, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-73, 55, 10);//atas kiri
	glVertex3f(-72, 55, 10);//atas kanan
	glVertex3f(-72, 45, 10);//kiri belakang
	glVertex3f(-73, 45, 10);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 53, 10);//bawah kiri
	glVertex3f(-72, 53, 10);//bawah kanan
	glVertex3f(-72, 65, 10);//atas kanan
	glVertex3f(-78, 65, 10);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 53, 12);//bawah kiri
	glVertex3f(-72, 53, 12);//bawah kanan
	glVertex3f(-72, 65, 12);//atas kanan
	glVertex3f(-78, 65, 12);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 65, 10);//depan kiri
	glVertex3f(-78, 65, 12);//depan kanan
	glVertex3f(-72, 65, 12);//belakang kanan
	glVertex3f(-72, 65, 10);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 65, 10);//atas kanan
	glVertex3f(-78, 53, 10);//bawah kanan
	glVertex3f(-78, 53, 12);//bawah kiri
	glVertex3f(-78, 65, 12);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-72, 65, 10);//atas kanan
	glVertex3f(-72, 53, 10);//bawah kanan
	glVertex3f(-72, 53, 12);//bawah kiri
	glVertex3f(-72, 65, 12);//atas kiri
	glEnd();

	//////////////////////////////////////////////////kursi 2
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 55, 10);//kiri belakang
	glVertex3f(xkelas - 78, 55, 25);//kiri depan
	glVertex3f(xkelas - 72, 55, 25);//kanan depan
	glVertex3f(xkelas - 72, 55, 10);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 53, 10);//kiri belakang
	glVertex3f(xkelas - 78, 53, 25);//kiri depan
	glVertex3f(xkelas - 72, 53, 25);//kanan depan
	glVertex3f(xkelas - 72, 53, 10);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 55, 25);//atas kiri
	glVertex3f(xkelas - 72, 55, 25);//atas kanan
	glVertex3f(xkelas - 72, 53, 25);//bawah kanan
	glVertex3f(xkelas - 78, 53, 25);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 55, 25);//atas kiri
	glVertex3f(xkelas - 78, 55, 10);//kiri belakang
	glVertex3f(xkelas - 78, 45, 10);//kanan belakang
	glVertex3f(xkelas - 78, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 79, 55, 25);//atas kiri
	glVertex3f(xkelas - 79, 55, 10);//kiri belakang
	glVertex3f(xkelas - 79, 45, 10);//kiri belakang
	glVertex3f(xkelas - 79, 45, 25);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 79, 55, 25);//atas kiri
	glVertex3f(xkelas - 78, 55, 25);//atas kanan
	glVertex3f(xkelas - 78, 45, 25);//kiri belakang
	glVertex3f(xkelas - 79, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 79, 55, 10);//atas kiri
	glVertex3f(xkelas - 78, 55, 10);//atas kanan
	glVertex3f(xkelas - 78, 45, 10);//kiri belakang
	glVertex3f(xkelas - 79, 45, 10);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 72, 55, 25);//atas kiri
	glVertex3f(xkelas - 72, 55, 10);//kiri belakang
	glVertex3f(xkelas - 72, 45, 10);//kanan belakang
	glVertex3f(xkelas - 72, 45, 25);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 73, 55, 25);//atas kiri
	glVertex3f(xkelas - 73, 55, 10);//kiri belakang
	glVertex3f(xkelas - 73, 45, 10);//kiri belakang
	glVertex3f(xkelas - 73, 45, 25);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 73, 55, 25);//atas kiri
	glVertex3f(xkelas - 72, 55, 25);//atas kanan
	glVertex3f(xkelas - 72, 45, 25);//kiri belakang
	glVertex3f(xkelas - 73, 45, 25);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 73, 55, 10);//atas kiri
	glVertex3f(xkelas - 72, 55, 10);//atas kanan
	glVertex3f(xkelas - 72, 45, 10);//kiri belakang
	glVertex3f(xkelas - 73, 45, 10);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 53, 10);//bawah kiri
	glVertex3f(xkelas - 72, 53, 10);//bawah kanan
	glVertex3f(xkelas - 72, 65, 10);//atas kanan
	glVertex3f(xkelas - 78, 65, 10);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 53, 12);//bawah kiri
	glVertex3f(xkelas - 72, 53, 12);//bawah kanan
	glVertex3f(xkelas - 72, 65, 12);//atas kanan
	glVertex3f(xkelas - 78, 65, 12);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 65, 10);//depan kiri
	glVertex3f(xkelas - 78, 65, 12);//depan kanan
	glVertex3f(xkelas - 72, 65, 12);//belakang kanan
	glVertex3f(xkelas - 72, 65, 10);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 65, 10);//atas kanan
	glVertex3f(xkelas - 78, 53, 10);//bawah kanan
	glVertex3f(xkelas - 78, 53, 12);//bawah kiri
	glVertex3f(xkelas - 78, 65, 12);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 72, 65, 10);//atas kanan
	glVertex3f(xkelas - 72, 53, 10);//bawah kanan
	glVertex3f(xkelas - 72, 53, 12);//bawah kiri
	glVertex3f(xkelas - 72, 65, 12);//atas kiri
	glEnd();

	//////////////////////////////////////////////////kursi 3
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(-78, 55, 25 + zkelas);//kiri depan
	glVertex3f(-72, 55, 25 + zkelas);//kanan depan
	glVertex3f(-72, 55, 10 + zkelas);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 53, 10 + zkelas);//kiri belakang
	glVertex3f(-78, 53, 25 + zkelas);//kiri depan
	glVertex3f(-72, 53, 25 + zkelas);//kanan depan
	glVertex3f(-72, 53, 10 + zkelas);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 55, 25 + zkelas);//atas kiri
	glVertex3f(-72, 55, 25 + zkelas);//atas kanan
	glVertex3f(-72, 53, 25 + zkelas);//bawah kanan
	glVertex3f(-78, 53, 25 + zkelas);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 55, 25 + zkelas);//atas kiri
	glVertex3f(-78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(-78, 45, 10 + zkelas);//kanan belakang
	glVertex3f(-78, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-79, 55, 25 + zkelas);//atas kiri
	glVertex3f(-79, 55, 10 + zkelas);//kiri belakang
	glVertex3f(-79, 45, 10 + zkelas);//kiri belakang
	glVertex3f(-79, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-79, 55, 25 + zkelas);//atas kiri
	glVertex3f(-78, 55, 25 + zkelas);//atas kanan
	glVertex3f(-78, 45, 25 + zkelas);//kiri belakang
	glVertex3f(-79, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-79, 55, 10 + zkelas);//atas kiri
	glVertex3f(-78, 55, 10 + zkelas);//atas kanan
	glVertex3f(-78, 45, 10 + zkelas);//kiri belakang
	glVertex3f(-79, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-72, 55, 25 + zkelas);//atas kiri
	glVertex3f(-72, 55, 10 + zkelas);//kiri belakang
	glVertex3f(-72, 45, 10 + zkelas);//kanan belakang
	glVertex3f(-72, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-73, 55, 25 + zkelas);//atas kiri
	glVertex3f(-73, 55, 10 + zkelas);//kiri belakang
	glVertex3f(-73, 45, 10 + zkelas);//kiri belakang
	glVertex3f(-73, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-73, 55, 25 + zkelas);//atas kiri
	glVertex3f(-72, 55, 25 + zkelas);//atas kanan
	glVertex3f(-72, 45, 25 + zkelas);//kiri belakang
	glVertex3f(-73, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-73, 55, 10 + zkelas);//atas kiri
	glVertex3f(-72, 55, 10 + zkelas);//atas kanan
	glVertex3f(-72, 45, 10 + zkelas);//kiri belakang
	glVertex3f(-73, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 53, 10 + zkelas);//bawah kiri
	glVertex3f(-72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(-72, 65, 10 + zkelas);//atas kanan
	glVertex3f(-78, 65, 10 + zkelas);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(-72, 53, 12 + zkelas);//bawah kanan
	glVertex3f(-72, 65, 12 + zkelas);//atas kanan
	glVertex3f(-78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 65, 10 + zkelas);//depan kiri
	glVertex3f(-78, 65, 12 + zkelas);//depan kanan
	glVertex3f(-72, 65, 12 + zkelas);//belakang kanan
	glVertex3f(-72, 65, 10 + zkelas);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-78, 65, 10 + zkelas);//atas kanan
	glVertex3f(-78, 53, 10 + zkelas);//bawah kanan
	glVertex3f(-78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(-78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(-72, 65, 10 + zkelas);//atas kanan
	glVertex3f(-72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(-72, 53, 12 + zkelas);//bawah kiri
	glVertex3f(-72, 65, 12 + zkelas);//atas kiri
	glEnd();

	///////////////////////////////////////////////////kursi 4
	//alas duduk atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 78, 55, 25 + zkelas);//kiri depan
	glVertex3f(xkelas - 72, 55, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 72, 55, 10 + zkelas);//kanan belakang
	glEnd();

	//alas duduk bawah
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 53, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 78, 53, 25 + zkelas);//kiri depan
	glVertex3f(xkelas - 72, 53, 25 + zkelas);//kanan depan
	glVertex3f(xkelas - 72, 53, 10 + zkelas);//kanan belakang
	glEnd();

	//cover alas duduk depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 72, 55, 25 + zkelas);//atas kanan
	glVertex3f(xkelas - 72, 53, 25 + zkelas);//bawah kanan
	glVertex3f(xkelas - 78, 53, 25 + zkelas);//bawah kiri
	glEnd();

	//kaki kursi kiri depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 78, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 78, 45, 10 + zkelas);//kanan belakang
	glVertex3f(xkelas - 78, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kiri depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 79, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 79, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 79, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 79, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kiri depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 79, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 78, 55, 25 + zkelas);//atas kanan
	glVertex3f(xkelas - 78, 45, 25 + zkelas);//kiri belakang
	glVertex3f(xkelas - 79, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kiri belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 79, 55, 10 + zkelas);//atas kiri
	glVertex3f(xkelas - 78, 55, 10 + zkelas);//atas kanan
	glVertex3f(xkelas - 78, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 79, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian kanan
	//kaki kursi kanan depan 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 72, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 72, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 72, 45, 10 + zkelas);//kanan belakang
	glVertex3f(xkelas - 72, 45, 25 + zkelas);//atas kanan
	glEnd();

	//kaki kursi kanan depan 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 73, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 73, 55, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 73, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 73, 45, 25 + zkelas);//atas kiri
	glEnd();

	//cover kaki kanan depan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 73, 55, 25 + zkelas);//atas kiri
	glVertex3f(xkelas - 72, 55, 25 + zkelas);//atas kanan
	glVertex3f(xkelas - 72, 45, 25 + zkelas);//kiri belakang
	glVertex3f(xkelas - 73, 45, 25 + zkelas);//kiri belakang
	glEnd();

	//cover kaki kanan belakang
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 73, 55, 10 + zkelas);//atas kiri
	glVertex3f(xkelas - 72, 55, 10 + zkelas);//atas kanan
	glVertex3f(xkelas - 72, 45, 10 + zkelas);//kiri belakang
	glVertex3f(xkelas - 73, 45, 10 + zkelas);//kiri belakang
	glEnd();

	//bagian tegak 1
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 53, 10 + zkelas);//bawah kiri
	glVertex3f(xkelas - 72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(xkelas - 72, 65, 10 + zkelas);//atas kanan
	glVertex3f(xkelas - 78, 65, 10 + zkelas);//atas kiri
	glEnd();

	//bagian tegak 2
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(xkelas - 72, 53, 12 + zkelas);//bawah kanan
	glVertex3f(xkelas - 72, 65, 12 + zkelas);//atas kanan
	glVertex3f(xkelas - 78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak atas
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 65, 10 + zkelas);//depan kiri
	glVertex3f(xkelas - 78, 65, 12 + zkelas);//depan kanan
	glVertex3f(xkelas - 72, 65, 12 + zkelas);//belakang kanan
	glVertex3f(xkelas - 72, 65, 10 + zkelas);//belakang kiri
	glEnd();

	//cover tegak kiri
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 78, 65, 10 + zkelas);//atas kanan
	glVertex3f(xkelas - 78, 53, 10 + zkelas);//bawah kanan
	glVertex3f(xkelas - 78, 53, 12 + zkelas);//bawah kiri
	glVertex3f(xkelas - 78, 65, 12 + zkelas);//atas kiri
	glEnd();

	//cover tegak kanan
	glColor3f(1, 1, 0);
	glBegin(GL_QUADS);
	glVertex3f(xkelas - 72, 65, 10 + zkelas);//atas kanan
	glVertex3f(xkelas - 72, 53, 10 + zkelas);//bawah kanan
	glVertex3f(xkelas - 72, 53, 12 + zkelas);//bawah kiri
	glVertex3f(xkelas - 72, 65, 12 + zkelas);//atas kiri
	glEnd();
}

void papantulis()
{
	int kanan = 110;
	//whiteboard belakang
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(kanan - 80, 80, 79.99);//kiri atas
	glVertex3f(kanan - 30, 80, 79.99);//kiri bawah
	glVertex3f(kanan - 30, 60, 79.99);//kanan bawah
	glVertex3f(kanan - 80, 60, 79.99);//kanan atas
	glEnd();

	//whiteboard depan
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(kanan - 80, 80, 78.99);//kiri atas
	glVertex3f(kanan - 30, 80, 78.99);//kiri bawah
	glVertex3f(kanan - 30, 60, 78.99);//kanan bawah
	glVertex3f(kanan - 80, 60, 78.99);//kanan atas
	glEnd();

	//frame whiteboard atas
	glColor3f(142.0 / 255, 164.0 / 255, 164.0 / 255);
	glBegin(GL_QUADS);
	glVertex3f(kanan - 80, 80, 78.99);//kiri atas
	glVertex3f(kanan - 30, 80, 78.99);//kiri bawah
	glVertex3f(kanan - 30, 80, 79.99);//kiri bawah
	glVertex3f(kanan - 80, 80, 79.99);//kiri atas
	glEnd();

	//frame whiteboard bawah
	glColor3f(142.0 / 255, 164.0 / 255, 164.0 / 255);
	glBegin(GL_QUADS);
	glVertex3f(kanan - 80, 60, 78.99);//kiri atas
	glVertex3f(kanan - 30, 60, 78.99);//kiri bawah
	glVertex3f(kanan - 30, 60, 79.99);//kiri bawah
	glVertex3f(kanan - 80, 60, 79.99);//kiri atas
	glEnd();

	//frame whiteboard kiri
	glColor3f(142.0 / 255, 164.0 / 255, 164.0 / 255);
	glBegin(GL_QUADS);
	glVertex3f(kanan - 80, 80, 79.99);//kiri atas
	glVertex3f(kanan - 80, 80, 78.99);//kiri atas
	glVertex3f(kanan - 30, 80, 79.99);//kiri bawah
	glVertex3f(kanan - 30, 80, 78.99);//kiri bawah
	glEnd();

	//whiteboard belakang
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-80, 80, 79.99);//kiri atas
	glVertex3f(-30, 80, 79.99);//kiri bawah
	glVertex3f(-30, 60, 79.99);//kanan bawah
	glVertex3f(-80, 60, 79.99);//kanan atas
	glEnd();

	//whiteboard depan
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-80, 80, 78.99);//kiri atas
	glVertex3f(-30, 80, 78.99);//kiri bawah
	glVertex3f(-30, 60, 78.99);//kanan bawah
	glVertex3f(-80, 60, 78.99);//kanan atas
	glEnd();

	//frame whiteboard atas
	glColor3f(142.0 / 255, 164.0 / 255, 164.0 / 255);
	glBegin(GL_QUADS);
	glVertex3f(-80, 80, 78.99);//kiri atas
	glVertex3f(-30, 80, 78.99);//kiri bawah
	glVertex3f(-30, 80, 79.99);//kiri bawah
	glVertex3f(-80, 80, 79.99);//kiri atas
	glEnd();

	//frame whiteboard bawah
	glColor3f(142.0 / 255, 164.0 / 255, 164.0 / 255);
	glBegin(GL_QUADS);
	glVertex3f(-80, 60, 78.99);//kiri atas
	glVertex3f(-30, 60, 78.99);//kiri bawah
	glVertex3f(-30, 60, 79.99);//kiri bawah
	glVertex3f(-80, 60, 79.99);//kiri atas
	glEnd();

	//frame whiteboard kiri
	glColor3f(142.0 / 255, 164.0 / 255, 164.0 / 255);
	glBegin(GL_QUADS);
	glVertex3f(-80, 80, 79.99);//kiri atas
	glVertex3f(-80, 80, 78.99);//kiri atas
	glVertex3f(-30, 80, 79.99);//kiri bawah
	glVertex3f(-30, 80, 78.99);//kiri bawah
	glEnd();
}

void mejatengah()
{
	int x = -5, xi = 5, z = 10, zi = -10;
	//bagian depan
	//papan bawah
	glColor3ub(200, 165, 30);
	glBegin(GL_POLYGON);
	glVertex3f(-10, 6.1, 10 + z);//belakang kiri
	glVertex3f(-15, 6.1, 20 + z);//depan kiri
	glVertex3f(15, 6.1, 20 + z);//depan kanan
	glVertex3f(10, 6.1, 10 + z);//belakang kanan
	glEnd();

	//papan atas
	glBegin(GL_POLYGON);
	glVertex3f(-10, 20, 10 + z);//belakang kiri
	glVertex3f(-15, 20, 20 + z);//depan kiri
	glVertex3f(15, 20, 20 + z);//depan kanan
	glVertex3f(10, 20, 10 + z);//belakang kanan
	glEnd();

	//papan tengah belakang
	glBegin(GL_POLYGON);
	glVertex3f(10, 20, 10 + z);//kanan atas
	glVertex3f(-10, 20, 10 + z);//kiri atas
	glVertex3f(-10, 6.1, 10 + z);//kiri bawah
	glVertex3f(10, 6.1, 10 + z);//kiri atas
	glEnd();

	//papan tengah depan
	glBegin(GL_POLYGON);
	glVertex3f(-15, 20, 20 + z);//atas kiri
	glVertex3f(15, 20, 20 + z);//atas kanan
	glVertex3f(15, 6.1, 20 + z);//bawah kanan
	glVertex3f(-15, 6.1, 20 + z);//depan kiri
	glEnd();
	//////////////////////////////////////////////////////////////

	//bagian miring kanan
	//papan miring kanan depan
	glBegin(GL_POLYGON);
	glVertex3f(15, 20, 20 + z);//atas kiri
	glVertex3f(15, 6.1, 20 + z);//bawah kiri
	glVertex3f(35, 6.1, 0 + z);//bawah kanan
	glVertex3f(35, 20, 0 + z);//atas kanan
	glEnd();

	//papan miring kanan belakang
	glBegin(GL_POLYGON);
	glVertex3f(15 + x, 20, 10 + z);//atas kiri
	glVertex3f(15 + x, 6.1, 10 + z);//bawah kiri
	glVertex3f(35 + x, 6.1, -10 + z);//bawah kanan
	glVertex3f(35 + x, 20, -10 + z);//atas kanan
	glEnd();

	//papan penutup atas miring kanan
	glBegin(GL_POLYGON);
	glVertex3f(15, 20, 20 + z);//atas kiri
	glVertex3f(15 + x, 20, 10 + z);//bawah kiri
	glVertex3f(35, 20, 0 + z);//bawah kiri
	glVertex3f(35 + x, 20, -10 + z);//bawah kanan
	glEnd();

	//papan miring kanan tutup
	glBegin(GL_POLYGON);
	glVertex3f(35, 20, 0 + z);//kanan atas
	glVertex3f(35, 6.1, 0 + z);//kanan bawah
	glVertex3f(35 + x, 6.1, -10 + z);//kanan bawah
	glVertex3f(35 + x, 20, -10 + z);//kanan atas
	glEnd();
	/////////////////////////////////////////////////////////////

	//bagian miring kiri
	//papan miring kiri depan
	glBegin(GL_POLYGON);
	glVertex3f(-15, 20, 20 + z);//atas kiri
	glVertex3f(-15, 6.1, 20 + z);//bawah kiri
	glVertex3f(-35, 6.1, 0 + z);//bawah kanan
	glVertex3f(-35, 20, 0 + z);//atas kanan
	glEnd();

	//papan miring kiri belakang
	glBegin(GL_POLYGON);
	glVertex3f(-15 + xi, 20, 10 + z);//atas kiri
	glVertex3f(-15 + xi, 6.1, 10 + z);//bawah kiri
	glVertex3f(-35 + xi, 6.1, -10 + z);//bawah kanan
	glVertex3f(-35 + xi, 20, -10 + z);//atas kanan
	glEnd();

	//papan penutup atas miring kiri
	glBegin(GL_POLYGON);
	glVertex3f(-15, 20, 20 + z);//atas kiri
	glVertex3f(-15 + xi, 20, 10 + z);//bawah kiri
	glVertex3f(-35, 20, 0 + z);//bawah kiri
	glVertex3f(-35 + xi, 20, -10 + z);//bawah kanan
	glEnd();

	//papan miring kanan tutup
	glBegin(GL_POLYGON);
	glVertex3f(-35, 20, 0 + z);//kanan atas
	glVertex3f(-35, 6.1, 0 + z);//kanan bawah
	glVertex3f(-35 + xi, 6.1, -10 + z);//kanan bawah
	glVertex3f(-35 + xi, 20, -10 + z);//kanan atas
	glEnd();
}

void bangku() {
	//bangku
	int c = 0;
	for (int k = 0; k < 4; k++)
	{
		int d = 0;
		for (int l = 0; l < 2; l++)
		{
			//bangku
			glColor3f(1, 0.8, 0.4);
			glBegin(GL_QUADS);
			glVertex3f(89 - d, 13, 75 - c);
			glVertex3f(89 - d, 13, 55 - c);
			glVertex3f(79 - d, 13, 55 - c);
			glVertex3f(79 - d, 13, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(89 - d, 13, 75 - c);
			glVertex3f(89 - d, 13, 55 - c);
			glVertex3f(79 - d, 13, 55 - c);
			glVertex3f(79 - d, 13, 75 - c);
			glEnd();

			glColor3f(1, 1, 0);
			glBegin(GL_QUADS);
			glVertex3f(89 - d, 13, 75 - c);
			glVertex3f(89 - d, 13, 55 - c);
			glVertex3f(89 - d, 12, 55 - c);
			glVertex3f(89 - d, 12, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(79 - d, 13, 75 - c);
			glVertex3f(79 - d, 13, 55 - c);
			glVertex3f(79 - d, 12, 55 - c);
			glVertex3f(79 - d, 12, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(79 - d, 13, 75 - c);
			glVertex3f(79 - d, 13, 55 - c);
			glVertex3f(79 - d, 12, 55 - c);
			glVertex3f(79 - d, 12, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(89 - d, 12, 55 - c);
			glVertex3f(89 - d, 13, 55 - c);
			glVertex3f(79 - d, 13, 55 - c);
			glVertex3f(79 - d, 12, 55 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(89 - d, 12, 75 - c);
			glVertex3f(89 - d, 13, 75 - c);
			glVertex3f(79 - d, 13, 75 - c);
			glVertex3f(79 - d, 12, 75 - c);
			glEnd();
			int a = 0;
			for (int i = 0; i < 2; i++)
			{
				int b = 0;
				for (int j = 0; j < 2; j++)
				{
					glBegin(GL_QUADS);
					glVertex3f(89 - a - d, 14, 75 - b - c);
					glVertex3f(89 - a - d, 6, 75 - b - c);
					glVertex3f(87 - a - d, 6, 75 - b - c);
					glVertex3f(87 - a - d, 14, 75 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(89 - a - d, 14, 73 - b - c);
					glVertex3f(89 - a - d, 6, 73 - b - c);
					glVertex3f(87 - a - d, 6, 73 - b - c);
					glVertex3f(87 - a - d, 14, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(89 - a - d, 14, 75 - b - c);
					glVertex3f(89 - a - d, 6, 75 - b - c);
					glVertex3f(89 - a - d, 6, 73 - b - c);
					glVertex3f(89 - a - d, 14, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(87 - a - d, 14, 75 - b - c);
					glVertex3f(87 - a - d, 6, 75 - b - c);
					glVertex3f(87 - a - d, 6, 73 - b - c);
					glVertex3f(87 - a - d, 14, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(89 - a - d, 6, 73 - b - c);
					glVertex3f(89 - a - d, 6, 75 - b - c);
					glVertex3f(87 - a - d, 6, 75 - b - c);
					glVertex3f(87 - a - d, 6, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(89 - a - d, 14, 73 - b - c);
					glVertex3f(89 - a - d, 14, 75 - b - c);
					glVertex3f(87 - a - d, 14, 75 - b - c);
					glVertex3f(87 - a - d, 14, 73 - b - c);
					glEnd();
					b += 18;
				}
				a += 8;
			}
			d += 25;
		}
		c += 30;
	}

	c = 0;
	for (int k = 0; k < 4; k++)
	{
		int d = 0;
		for (int l = 0; l < 2; l++)
		{
			glColor3f(1, 0.8, 0.4);
			//bangku
			glBegin(GL_QUADS);
			glVertex3f(-89 + d, 13, 75 - c);
			glVertex3f(-89 + d, 13, 55 - c);
			glVertex3f(-79 + d, 13, 55 - c);
			glVertex3f(-79 + d, 13, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-89 + d, 13, 75 - c);
			glVertex3f(-89 + d, 13, 55 - c);
			glVertex3f(-79 + d, 13, 55 - c);
			glVertex3f(-79 + d, 13, 75 - c);
			glEnd();

			glColor3f(1, 1, 0);
			glBegin(GL_QUADS);
			glVertex3f(-89 + d, 13, 75 - c);
			glVertex3f(-89 + d, 13, 55 - c);
			glVertex3f(-89 + d, 12, 55 - c);
			glVertex3f(-89 + d, 12, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-79 + d, 13, 75 - c);
			glVertex3f(-79 + d, 13, 55 - c);
			glVertex3f(-79 + d, 12, 55 - c);
			glVertex3f(-79 + d, 12, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-79 + d, 13, 75 - c);
			glVertex3f(-79 + d, 13, 55 - c);
			glVertex3f(-79 + d, 12, 55 - c);
			glVertex3f(-79 + d, 12, 75 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-89 + d, 12, 55 - c);
			glVertex3f(-89 + d, 13, 55 - c);
			glVertex3f(-79 + d, 13, 55 - c);
			glVertex3f(-79 + d, 12, 55 - c);
			glEnd();

			glBegin(GL_QUADS);
			glVertex3f(-89 + d, 12, 75 - c);
			glVertex3f(-89 + d, 13, 75 - c);
			glVertex3f(-79 + d, 13, 75 - c);
			glVertex3f(-79 + d, 12, 75 - c);
			glEnd();
			int a = 0;
			for (int i = 0; i < 2; i++)
			{
				int b = 0;
				for (int j = 0; j < 2; j++)
				{
					glBegin(GL_QUADS);
					glVertex3f(-89 + a + d, 14, 75 - b - c);
					glVertex3f(-89 + a + d, 6, 75 - b - c);
					glVertex3f(-87 + a + d, 6, 75 - b - c);
					glVertex3f(-87 + a + d, 14, 75 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(-89 + a + d, 14, 73 - b - c);
					glVertex3f(-89 + a + d, 6, 73 - b - c);
					glVertex3f(-87 + a + d, 6, 73 - b - c);
					glVertex3f(-87 + a + d, 14, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(-89 + a + d, 14, 75 - b - c);
					glVertex3f(-89 + a + d, 6, 75 - b - c);
					glVertex3f(-89 + a + d, 6, 73 - b - c);
					glVertex3f(-89 + a + d, 14, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(-87 + a + d, 14, 75 - b - c);
					glVertex3f(-87 + a + d, 6, 75 - b - c);
					glVertex3f(-87 + a + d, 6, 73 - b - c);
					glVertex3f(-87 + a + d, 14, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(-89 + a + d, 6, 73 - b - c);
					glVertex3f(-89 + a + d, 6, 75 - b - c);
					glVertex3f(-87 + a + d, 6, 75 - b - c);
					glVertex3f(-87 + a + d, 6, 73 - b - c);
					glEnd();

					glBegin(GL_QUADS);
					glVertex3f(-89 + a + d, 14, 73 - b - c);
					glVertex3f(-89 + a + d, 14, 75 - b - c);
					glVertex3f(-87 + a + d, 14, 75 - b - c);
					glVertex3f(-87 + a + d, 14, 73 - b - c);
					glEnd();
					b += 18;
				}
				a += 8;
			}
			d += 25;
		}
		c += 30;
	}
}

void teko() {
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glScalef(2, 2, 2);
	glTranslatef(0, 10.5, 12);
	glRotatef(270, 0, 1, 0);
	glutSolidTeapot(1);
	glPopMatrix();
}

void tampil(void)
{
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(xpos, ypos, zpos);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	if (tembokk1 == 0)
	{
		tembok();
	}

	if (tembokk2 == 0)
	{
		tembok2();
	}
	if (atapp == 0)
	{
		atap();
	}
	lantai1();
	lantai2();
	lantai();
	papantulis();
	kursikelas();
	mejakelas();
	mejatengah();
	bangku();
	teko();
	glPushMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void keyboard(unsigned char key, int i, int x)
{
	switch (key)
	{
	case 'w':
	case 'W':
		zpos += 3.0;
		glTranslatef(0, 0, 3);
		break;
	case 'd':
	case 'D':
		xpos += -3.0;
		glTranslatef(-3, 0, 0);
		break;
	case 's':
	case 'S':
		zpos += -3.0;
		glTranslatef(0, 0, -3);
		break;
	case 'a':
	case 'A':
		xpos += 3.0;
		glTranslatef(3, 0, 0);
		break;
	case '1':
		if (tembokk1 == 0) {
			tembokk1 = 1;
		}
		else {
			tembokk1 = 0;
		}
		break;
	case '2':
		if (tembokk2 == 0) {
			tembokk2 = 1;
		}
		else {
			tembokk2 = 0;
		}
		break;
	case '3':
		if (atapp == 0) {
			atapp = 1;
		}
		else {
			atapp = 0;
		}
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		break;
	}
	tampil();
}

void idle()
{

	if (!mouseDown)
	{
		xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	{
		mouseDown = false;
	}
}

void mouseMotion(int x, int y)
{

	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;

		glutPostRedisplay();

	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, lebar / tinggi, 5, 500);
	glTranslatef(0, -5, -350);
	glMatrixMode(GL_MODELVIEW);
}
