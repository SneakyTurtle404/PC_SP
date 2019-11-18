#include <stdlib.h>
#include <stdio.h>
#include "frequencies.h"

/* _____________________________________________________________________________
 *	Creates and adds new frequency to the end of the list 
 * @param *last: point to the last added element in list of frequencies
 * @param id: id of new frequency that's gonna be created
 * @param value: value of new frequency that's gonna be created
 * return last added element in the list
 * _____________________________________________________________________________
 */
frequencies *add_freq(frequencies *last, int id, int value){
	frequency *newfreq;
	frequencies *newfreqies;
	
	/* creating new frequency */
	newfreq = malloc(sizeof(frequency));
	newfreq->id = id;
	newfreq->value=value;

	/* adding created frequency into the list of frequencies*/	
	newfreqies = malloc(sizeof(frequencies));
	newfreqies->frequency = newfreq;
	newfreqies->next = NULL;
	
	/* if there's an element point last one to the newfreq*/
	if(last){
		last->next = newfreqies;
	}
	
	/* if there's nothing yet -> newfreq is the first(&&last)*/
	
	return newfreqies;
	
}


/* _____________________________________________________________________________
 *	Prints one frequency to the output
 *  @param *freq: pointer to the given frequency
 * _____________________________________________________________________________
 */
void print_one_freq(frequency *freq){
	printf("id: %d value: %d\n", freq->id, freq->value);
}

/* _____________________________________________________________________________
 *	Prints all frequencies from the list
 *  @param *first: pointer to the first element in given list
 * _____________________________________________________________________________
 */
void print_all_freq(frequencies *first){
	frequencies *temp = first;
	printf("%s", "Available frequencies:\n");
	
	/*if top==null -> stack is empty */
	while(temp != NULL){
		print_one_freq(temp->frequency);
		temp = temp->next;
	}
	
}


