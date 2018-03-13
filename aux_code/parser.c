#include "inc.h"

FILE *lottery_trash = NULL;
FILE *lottery_ok = NULL;

int main(void){
	lottery_trash = fopen("../db/db_no_tags.txt", "r");
	lottery_ok = fopen("../db/db_only_numbers.txt", "w");

	char *buff = (char*)malloc(256 * sizeof(char)),
		 *out = (char*)malloc(256 * sizeof(char));

	size_t sz = 256;
	while(!feof(lottery_trash)){
		getline(&buff, &sz, lottery_trash);
		fix_text(&lottery_ok, &buff, &out); // copies all correctly to a new file
	}

	free(buff);
	free(out);

	fclose(lottery_trash);
	fclose(lottery_ok);

	return 0;
}
