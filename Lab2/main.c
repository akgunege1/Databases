#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void terscevir(char *str){
int i;
int j;
int temp;

for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
{
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

}


int main()
{
	char str[] = "Teknoloji";
	terscevir(str);
	printf("Ters çevrilen metin: %s", str);
	return 0;
}

