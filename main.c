#include <stdio.h>




int main(int argc, char**argv) {

    char *str_to_obfuscate = NULL;

    for (argc--, argv++; argc > 0; argc--, argv++)
	{

		if (strcmp(*argv, "-file") == 0)
			{
			argc--;
			if (argc < 1) goto usage;
			filetohash = *++argv;
			}
		else if (strcmp(*argv, "-str") == 0)
			{
			argc--;
			if (argc < 1) goto usage;
			str_to_obfuscate = *++argv;
			}
		else if (strcmp(*argv, "-out") == 0)
			{
			argc--;
			if (argc < 1) goto usage;
			fileout = *++argv;
			}
		else if (strcmp(*argv, "-tsaurl") == 0)
			{
			argc--;
			if (argc < 1) goto usage;
			TSAurl = *++argv;
			}
		else if (strcmp(*argv, "-policy") == 0)
			{
			argc--;
			if (argc < 1) goto usage;
			policy = *++argv;
			}

		else
			goto usage;

	}

if (string_to_int(str_to_obfuscate) > 0)
   goto clean_up:

usage:

printf("(c) DIRECTORATE-GENERAL RESEARCH & INNOVATION ver 1.0 February 2022\n"
"Author Antonio Perez Caballero\n"
"usage: token_obfuscation -str\n"
);

clean_up:

exit 0;

}

//
// convert string char to array int
//
int string_to_int(char *string[]){

    int i=0;
    while(string[i]!=NULL){


    }
}

//
// create check sum 
//
int create_check_sum(){

}

