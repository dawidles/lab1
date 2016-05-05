#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);
void drawCharSquare(char **square, int n);

int main(int argc, char **argv)
{
	int n=atoi(argv[1]);
	srand(argc==3?atoi(argv[2]):time(NULL));
	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	char **square = new char *[n*n];

	for (int i=0; i<n*n; i++){
		square[i] = new char[n*n];
		square[i/n][i%n] = char(rand()%26 + 97); // lub 'a' + rand()%('z'-'a' +1); prosilbym o informacje, ktory zapis bedzie "poprawniejszy"
	}
	
	return square;
}

void drawCharSquare(char **square, int n)
{
	for(int i=0; i<n*n; i++){
		printf("%c ", square[i/n][i%n]);
			if ((i%n) == (n-1)) printf("\n");
		}
}