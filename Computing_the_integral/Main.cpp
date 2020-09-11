#include<stdio.h> //библиотека для ввода-вывода
#include<conio.h> //библиотека для консольного ввода-вывода
#include<math.h>
#include<windows.h> //библиотека, использующаяся для рисования примитивов
#include<locale.h> //библиотека, которая используется для задач связанных с локализацией 
#include<string.h> //библиотека, содержащая функции для работы с нуль-терминированными строками и различными функциями работы с памятью
#include<stdlib.h> //библиотека,содержащая в себе функции, занимающиеся выделением памяти, контроль процесса выполнения программы, преобразования типов
#include<glut.h> //предназначена для создания/манипуляции окон, вывода графики
#include<Gl/gl.h>
#include<GL/glu.h>
#define eps 0.001 //директива постановки 

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput, scrn);
}

void Circle(HWND hW, int xCenter, int yCenter, int radius, COLORREF borderColor, COLORREF fillColor)
{
	HDC hDC1 = GetDC(hW);
	HPEN hPen = CreatePen(PS_SOLID, 1, borderColor);
	HPEN hOldPen = (HPEN)SelectObject(hDC1, hPen);
	HBRUSH hBrush = CreateSolidBrush(fillColor);
	HBRUSH hOldBrush = (HBRUSH)SelectObject(hDC1, hBrush);

	Ellipse(hDC1, xCenter - radius, yCenter - radius, xCenter + radius, yCenter + radius);

	SelectObject(hDC1, hOldPen);
	DeleteObject(hPen);
	SelectObject(hDC1, hOldBrush);
	DeleteObject(hBrush);
	ReleaseDC(hW, hDC1);
}
void Picture(HWND hW, int dx, int dy, int mode)
{
	COLORREF border = RGB(255, 255, 0), fill = RGB(127, 127, 0), line = RGB(0, 255, 0), black = RGB(0, 0, 0);
	if (!mode)
		border = fill = line = black;
	int x0 = 150, y0 = 150, r = 110;

	Circle(hW, x0 + dx, y0 + dy, r, border, fill);
}
void zastavka()
{
	system("color 0f");
	HWND hW = GetConsoleWindow();
	int step = -1;
	Sleep(1000);

	for (;; ++step)
	{
		Picture(hW, 5 * step, 0, 1);
		Sleep(70);
		Picture(hW, 5 * step, 0, 0);
		if (step > 100)
			break;
	}
	system("pause");
	system("color f0");
}
void information() // Сведения об авторе
{
	printf("\n");
	printf("          ---------------------------------------------------------\n");
	printf("             Расчетно-графическая работа по программированию\n");
	printf("          ---------------------------------------------------------\n");
	printf("\n");
	printf("   Выполнил студент Факультета информационных технологий и компьютерных систем\n");
	printf("\n");
	printf("           Кафедры Фундаментальной информатики и информационных технологий\n");
	printf("\n");
	printf("                             Группы ФИТ-181\n");
	printf("\n");
	printf("                         Бегалко Илья Алексеевич\n");
	printf("\n");
	printf("          ---------------------------------------------------------\n");
	_getch();
}
void table()
{
	setlocale(LC_ALL, "RUS");
	double xmas[20], F1mas[20], F2mas[20];
	float maxF1 = -1, maxF2 = -1, minF1 = 10000, minF2 = 2;
	float F1, F2, x, dx, a = 1, b = 2, max1, min1, max2, min2;
	int i = 0, n = 16;
	dx = fabs(b - a) / (n - 1);
	x = a;
	printf("________________________________\n");
	printf("|I  |       X|      F1|      F2|\n");
	printf("|---|--------|--------|--------|\n");

	for (i = 0; i < n; i++)
	{
		F2 = pow((x - 1), 3);
		F1 = 1 + pow(2, (x + 5));
		xmas[i] = x, F1mas[i] = F1, F2mas[i] = F2;
		printf("|%3d|%8.4f|%8.4f|%8.4f|\n", i + 1, xmas[i], F1mas[i], F2mas[i]);
		x = x + dx;
		if (maxF1 < F1mas[i])
		{
			maxF1 = F1mas[i];
		}

		if (maxF2 < F2mas[i])
		{
			maxF2 = F2mas[i];
		}

		if (minF1 > F1mas[i])
		{
			minF1 = F1mas[i];
		}

		if (minF2 > F2mas[i])
		{
			minF2 = F2mas[i];
		}
	}
	printf("________________________________\n");

	printf("maxF1= %8.4f\n", maxF1);
	printf("maxF2 = %8.4f\n", maxF2);
	printf("minF1 = %8.4f\n", minF1);
	printf("minF2 = %8.4f\n", minF2);
	_getch();
	_getch();
}
void graphik()
{
	double x;

	printf("\n                                   y\n");
	printf("\n \n \n \n \n \n \n \n \n \n \n \n                                                             x\n");
	printf("\n \n          F1=1 + pow(2, (x + 5))");
	printf("\n \n          F2=pow((x - 1)");

	HDC hDC = GetDC(GetConsoleWindow());
	HPEN Pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hDC, Pen);
	for (x = -10.0f; x <= 10.0f; x += 0.01f)
	{
		MoveToEx(hDC, 110, 180, NULL);
		LineTo(hDC, 550, 180);
		MoveToEx(hDC, 320, 20, NULL);
		LineTo(hDC, 320, 270);
	}
	HPEN NewPen = CreatePen(PS_SOLID, 2, RGB(243, 34, 123));
	SelectObject(hDC, NewPen);

	for (x = -10.0f; x <= 10.0f; x += 0.01f)
	{
		MoveToEx(hDC, 20 * x + 450, -20 * 4 * (1 + pow(2, (x + 5))) + 260, NULL);
		LineTo(hDC, 20 * x + 450, -20 * 4 * (1 + pow(2, (x + 5))) + 260);

	}

	HPEN New2Pen = CreatePen(PS_SOLID, 2, RGB(136, 200, 000));
	SelectObject(hDC, New2Pen);

	for (x = -10.0f; x <= 10.0f; x += 0.01f)
	{
		MoveToEx(hDC, 20 * x + 320, -20 * (pow((x - 1), 3)) + 180, NULL);
		LineTo(hDC, 20 * x + 320, -20 * (pow((x - 1), 3)) + 180);
	}
	_getch();
	_getch();
}

float integral(float x)
{
	return sqrt(pow(x, 2) + 3);
}
void integral()
{
	setlocale(LC_ALL, "rus");
	float S = 0.0;
	int a = 0, b = 0, N = 1;
	int j = 0;
	printf("Проинтегрировать функцию f(x) = sqrt(pow(x,2)+3) : \n");
	printf("Введите a,b и количество шагов N:\n");
	scanf_s("%d", &a);
	scanf_s("%d", &b);
	scanf_s("%d", &N);
	float k = (fabs(b - a) / N) * 1.0;
	for (float i = a + k; j < N; i += k) {
		S += ((integral(i) + integral(i - k)) / 2.0 * k);
		j++;
	}
	printf("Определенный интеграл по правилу прямоугольников равен %lf\n", S);
	printf("\n");
	S = 0.0;
	for (double i = a + k; i < b; i += k) {
		S += integral(i);
	}
	S += (integral(a) + integral(b)) / 2.0;
	S *= k;
	printf("Определенный интеграл по правилу трапеции  равен %lf\n", S);
	_getch();
	_getch();
}

double f(double x)
{
	return pow(x, 2) - log(x + 1) + sin(x) - 2;
}
int uravnenie()
{
	setlocale(LC_ALL, "RUS");
	int n = 0;
	double a, b, c;
	printf("Введите A = ");
	scanf_s("%lf", &a);
	printf("Введите B = ");
	scanf_s("%lf", &b);
	do
	{
		c = (a + b) / 2;
		if (f(a) * f(c) <= 0)
		{
			b = c;
		}
		else {
			a = c;
		}
		n++;
	} while (fabs(f(c)) >= eps);
	printf("C = ");
	printf("%lf\n", c);
	printf("N = ");
	printf("%d\n", n);

	_getch();
	_getch();

	return 0;
}

void menu()
{
	int N;
	int i;
	system("cls");
	for (i = 1; i < 21; i++)
	{

		gotoxy(22, i);
		printf("|");
		gotoxy(52, i);
		printf("|");
	}
	for (i = 1; i < 30; i++)
	{
		gotoxy(22 + i, 1);
		printf("=");
		gotoxy(35, 2);
		printf("МЕНЮ");
		gotoxy(22 + i, 3);
		printf("_");
		gotoxy(22 + i, 20);
		printf("=");
	}
	{
		gotoxy(24, 5); printf("1) Заставка");
		gotoxy(24, 7); printf("2) Информация об авторе");
		gotoxy(24, 9); printf("3)   Таблица");
		gotoxy(24, 11); printf("4)   Построение графика");
		gotoxy(24, 13); printf("5)  Вычисление уравнения");
		gotoxy(24, 15); printf("6)  Вычисление интеграла");
		gotoxy(24, 17); printf("7)  ВЫХОД");
		gotoxy(24, 19); printf("ВВЕДИ НОМЕР ПУНКТА: ");

		scanf_s("%d", &N);
		switch (N)
		{
		case 1:
		{
			system("cls");
			zastavka();
			break;
		}
		case 2:
		{
			system("cls");
			information();
			break;
		}
		case 3:
		{
			system("cls");
			table();
			break;
		}
		case 4:
		{
			system("cls");
			graphik();
			break;
		}
		case 5:
		{
			system("cls");
			uravnenie();
			break;
		}
		case 6:
		{
			system("cls");
			integral();
			break;
		}
		case 7:
		{
			system("cls");
			exit(1);
			break;
		}

		}
		menu();
		_getch();
		_getch();
	}

}


int main(int argc, char** argv)
{
	system("mode con cols=80 lines=25");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)((15 << 4) | 0));
	setlocale(LC_ALL, "RUS");
	menu();
	_getch();
	_getch();
}