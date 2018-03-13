#include <stdio.h>
#include <stdlib.h>

#define NUMBERS 6
#define RAFFLES 2427
#define POSS 61

void fill_up_matrix(FILE *f, int ***m){
	int n1,n2,n3,n4,n5,n6;
	int row = 0, column = 0;

	while(!feof(f)){
		fscanf(f,"%d%d%d%d%d%d",&n1,&n2,&n3,&n4,&n5,&n6);
		// printf("%d %d %d %d %d %d\n",n1,n2,n3,n4,n5,n6);
		
		if(column == 6) column = 0;
		
		(*m)[row][column++] = n1;
		(*m)[row][column++] = n2;
		(*m)[row][column++] = n3;
		(*m)[row][column++] = n4;
		(*m)[row][column++] = n5;
		(*m)[row][column++] = n6;
		
		row++;
	}
}

int main(void){
	FILE *lottery_data = NULL;

	lottery_data = fopen("db/db_only_numbers.txt", "r");

	int **lottery = NULL;

	lottery = (int**)malloc(RAFFLES * sizeof(int*));
	for(int i = 0; i < RAFFLES; i++)
		lottery[i] = (int*)malloc(NUMBERS * sizeof(int));

	// stores data
	fill_up_matrix(lottery_data, &lottery);

	// analysis by position [1..6]
	int pos[NUMBERS][POSS] = {0};

	int x = 0;
	for(int i = 0; i < RAFFLES; i++){
		for(int j = 0; j < NUMBERS; j++){
			pos[0][lottery[i][j]]++;
		}
	}


	for(int i = 0; i < RAFFLES; i++){
		for(int j = 0; j < NUMBERS; j++){
			printf("%d ", lottery[i][j]);
		}
		printf("\n");
	}


	for(int i = 0; i < RAFFLES; i++)
		free(lottery[i]);
	free(lottery);

	return 0;
}