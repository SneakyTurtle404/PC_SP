#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#include "frequencies.h"
#include "transmitters.h"
#define ARGV_FILENAME 1
#define TYPE_FORMAT_TXT ".txt"


/* -------- Help text --------------------- */
	const char s_help[] = 	"Input file name argument is incorrect.\n"
							"Please run the program in the following form:\n"
							"freq.exe \"input_file_name.txt\"\n";
						
/*
 * Maximum length of row in input file
 */
	const int line_size = 50;






/*______________________________________________________________________________________________________
 * Main funkce, nacte hodnoty z konzole a zkontroluje vsechny parametry
 * @param argc: pocet zadanych parametru v konzoli
 * @param argv: pole zadanych parametru
 *______________________________________________________________________________________________________
 */
	int main(int argc, char *argv[]) {

		/* 
		 * Kontrola zadaných parametrù - <filename> zastupuje nazev souboru, ze ktereho nasledne nacteme info o vysilacich
		 */
		if (argc == 2 && strstr(argv[ARGV_FILENAME], TYPE_FORMAT_TXT)){
			char *filename = argv[ARGV_FILENAME];
			
				/* load input file */
		
				load_data(filename, &trans_head, &freqs_head);
				//TODO
				
				
				/* check if loaded succesfuly */
					
					//TODO
					
					
					
		}
		
		
	
	/* creating collision graph */
		//TODO
	
	/* trying to assing non-colliding frequencies */
		//TODO
	/* check if assing succesfuly */
		//TODO
	/* print all trans */
		//TODO
		
		
		
		clear();
		return 0;
	}


/*_________________________________________________________________________________________________
 * Nacteni dat ze souboru 
 * @param filename: nazev souboru
 *_________________________________________________________________________________________________
 */
	int load_data(char *filename , transmitters **trans_head, frequencies **freqs_head){
		FILE *f;
		char line[line_size];
		int ret = 1;
		
		f = fopen(filename, "r");
		
		if (f == NULL) {
			ret = 1;
			printf("%s\n", "ERR#1: Missing argument!");  //Soubor neexistuje / nelze otevrit
			printf("%s", s_help);
			return ret;
		}
		else {	
					
			    printf("%s", "Loading file\n");
			    
					//TODO						
							
				
				printf("%s\n", "File loaded\n");
				
		
			ret = 0;
		}
		
		fclose(f);
		
		return ret;
	}






/*___________________________________
 *	Clears all allocated memory.
 *______________________________________
 */
	void clear(){
		printf("clear\n");
		
		//	free_stack(&m_stack);
			free_transmitters(trans_head);
			free_frequencies(freqs_head);
	}


