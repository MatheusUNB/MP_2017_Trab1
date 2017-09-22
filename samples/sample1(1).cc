#include "sample1.h"
#include <string.h>
int soma_string(const char * string_entrada){
	int soma;
	char txt[20];
	strcpy(txt, string_entrada);
	if(strcmp(txt,"\n") == 0)
		soma=0;
	else
		soma=1;		

	return soma;
}
