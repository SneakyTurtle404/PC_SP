#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transmitters.h"
#include "frequencies.h" 
#include "stack.h" 

/*______________________________________________________________________________________________________
 *	Frees all memory allocated for list of transmitters
 *	@param first: pointer to the first element in this list.
 *______________________________________________________________________________________________________
 */
void free_transmitters(transmitters *first){
	transmitters *temp;
	transmitters *pom;
	
	pom = first;
	while(pom != NULL ){
		temp = pom;
		pom = pom->next;
		free(temp->transmitter);
		free(temp);
	}
	first = NULL;
	
	printf("%s", "\n transmitters cleared\n");
	
}


/*______________________________________________________________________________________________________
 * Frees all memory allocated to list of frequencies
 * 	@param first: pointer to the first element in this list.
 *______________________________________________________________________________________________________
 */
void free_frequencies(frequencies *first){
	frequencies *temp;
	frequencies *pom;
	
	pom = first;
	while(pom != NULL ){
		temp = pom;
		pom = pom->next;
		free(temp->frequency);
		free(temp);
	}
	first = NULL;
	
	printf("%s", "\n frequencies cleared\n");
	
}


 
/*______________________________________________________________________________________________________
 * Frees all memory allocated to list of stack
 * 	@param s: 
 * _____________________________________________________________________________________________________
 */
int free_stack(stack **s){
	if(!(*s))return RET_ERR; //nelze uvolnit neco, co uz uvlneno bzlo a neexistuje
	
	free((*s)->data);  //uvolneni celeho bloku dat
	free(*s);
	*s = NULL; // indikuje, ze zasobnik neexistuje a byl zrusen
	
		printf("%s", "stack cleared\n");
}
