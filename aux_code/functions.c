#include "inc.h"

// removes all trash info that comes before the sorted numbers
void remove_dates_parenthesis(char *s[], char *out[]){
	unsigned long i;
	int index;

	unsigned long sz = (strlen(*s)+1);
	char *buff = (char*)malloc(sz * sizeof(char));

	strcpy(buff, *s);

	index = 0;
	for(i = 17; i < strlen(buff); i++)
		(*out)[index++] = buff[i];
	
	free(buff);
}

// just for simplicity
void fix_text(FILE** lottery_ok, char *s[], char *out[]){
	remove_dates_parenthesis(s, out);
	fprintf(*lottery_ok, "%s", *out);
}