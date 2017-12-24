#include <stdio.h>
#include <stdlib.h>
/*
mine: -1
otherwise number touching
*/

typedef struct grid{
	int rows;
	int cols;
	int ** mat;
} Grid;

Grid * newGrid(int r, int c){
	Grid * g = malloc(sizeof(Grid));
	g->rows = r;
	g->cols = c;
	g->mat = malloc(sizeof(int *)*r);
	int i;
	for (i=0;i<r;i++)
		g->mat[i] = malloc(sizeof(int)*c);
	return g;
}

void freeGrid(Grid * g){
	int i;
	for (i=0;i<g->rows;i++)
		free(g->mat[i]);
	free(g->mat);
	free(g);
}

void printGrid(Grid * g){
	int i,j;
	for (i=0;i<g->rows;i++){
		for(j=0;j<g->cols;j++){
			if (g->mat[i][j]==0){
				printf("[ ]");
			}else if(g->mat[i][j]==-1){
				printf("[*]");
			}else{
				printf("[%d]",g->mat[i][j]);
			}
		}
		printf("\n");
	}
}

void clearGrid(Grid * g){
	int i,j;
	for (i=0;i<g->rows;i++){
		for (j=0;j<g->cols;j++)
			g->mat[i][j] = 0;
	}
}

void addMines(Grid * g, int num){
	if ((g->rows*g->cols) < num){
		printf("Number of mines bigger than board\n");
		return;
	}
	int i,j;
	while (num){
		i = rand() % g->rows;
		j = rand() % g->cols;
		if (g->mat[i][j]==0){
			g->mat[i][j] = -1;
			num--;
		}
	}
}

void propagateMines(Grid * g);

int main(){
	Grid * g = newGrid(5,5);
	printGrid(g);
	clearGrid(g);
	addMines(g,5);
	printGrid(g);
	freeGrid(g);
	return 0;
}
