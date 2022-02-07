#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int string_to_int(char *string, int *str_len);
int create_check_sum(char *string, int check_sum, int str_len);

// ./a.out -str 

int main(int argc, char**argv) {

    char *str_to_obfuscate = NULL;
	int str_len=0;

    printf("argument numbers: %d\n", argc);

	if (argc == 1)
	{
	
	   goto usage;
	}

    for (argc--, argv++; argc > 0; argc--, argv++)
	{

		if (strcmp(*argv, "-str") == 0)
			{
			argc--;
			str_to_obfuscate = *++argv;
			}
		else
			goto usage;

	}


int check_sum=string_to_int(str_to_obfuscate, &str_len);
printf("\nstring len: %d\n", str_len);
if ( check_sum > 0)
{
	create_check_sum(str_to_obfuscate, check_sum, str_len);
    goto clean_up;
}

usage:

printf("(c) Vivaldi-Spring LTD ver 1.0 February 2022\n"
"Author Antonio Perez Caballero\n"
"usage: token_obfuscation -str token or password \n"
);

clean_up:

return 0;

}

//
// convert string char to array int
//
int string_to_int(char *string, int *str_len){

    int i=*str_len;
	int check_sum=0;
    while(*(string+i) != 0){

       printf("%d",*(string+i));
       printf(" ");
	   check_sum += *(string+i);
       i++;

    }

	*str_len=i;

return check_sum;
}

//
// create check sum 
//
int create_check_sum(char *string, int check_sum, int str_len){

	int *t;
	int lazo=0;
	int val_token=0;
	char string_tocheck[str_len + 1];

	printf("\ncheck sum: %d\n", check_sum);
	printf("str_len: %d\n", str_len);
	printf("%s\n", string);

	t = (int*) malloc( str_len+1 * sizeof(int));
	//string_tocheck =  (char *) malloc( (str_len + 1) * sizeof(char));

	if (t ==NULL)// if empty array
	{
    	printf("\nError! Memory not allocated \n");
    	return 0;
	}

	val_token=check_sum;

	while(lazo < (str_len)){

		t[lazo]=val_token;
		val_token=val_token - *(string+lazo);
		lazo++;
	}
	t[lazo+1]=0;

	lazo=0;
	while(lazo < (str_len)){
		printf("%d %c\n", t[lazo], (char) t[lazo]-t[lazo+1]);
		lazo++;

	}

	int i=0;
	while ( i < str_len ) {

  	*(string_tocheck+i)= (char)(t[i]-t[i+1]);
	  i++;

	}

	string_tocheck[str_len]='\0';

	printf("%s\n", string_tocheck);
    free(t);
	//free(string_tocheck);

    return 1;
}

