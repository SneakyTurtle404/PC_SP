#ifndef _FREQUENCIES_H
#define _FREQUENCIES_H

/* --------------------------------------STRUCTURES--------------------------------------------- */


/* _____________________________________________________________________________
 *	This is sctructure of one frequency that contains it's id and value.
 * _____________________________________________________________________________
 */
 typedef struct oneFreq{
	int id;
  	int value;
}frequency;

/* _____________________________________________________________________________
 *	This is sctructure that represents an element in linked list of frequencies.
 * _____________________________________________________________________________
 */
 typedef struct allFreq{
	frequency *frequency;
	struct allFreq *next;	/* pointer to next frequency in the list */
}frequencies;

/* ----------------------------------END-OF-STRUCTURES--------------------------------------------- */


/*----------------------------------- FUNCTIONS ----------------------------------------------------*/

/* _____________________________________________________________________________
 *	Creates and adds new frequency to the end of the list 
 * @param *last: point to the last added element in list of frequencies
 * @param id: id of new frequency that's gonna be created
 * @param value: value of new frequency that's gonna be created
 * return last e=added element in the list
 * _____________________________________________________________________________
 */
frequencies *add_freq(frequencies *last, int id, int value);


/* _____________________________________________________________________________
 *	Prints one frequency to the output
 *  @param *freq: pointer to the given frequency
 * _____________________________________________________________________________
 */
void print_one_freq(frequency *freq);

/* _____________________________________________________________________________
 *	Prints all frequencies from the list
 *  @param *first: pointer to the first element in given list
 * _____________________________________________________________________________
 */
void print_all_freq(frequencies *first);

/* _____________________________________________________________________________
 *	Frees all  memory allocated to frequencies list
 *  @param *first: pointer to the first element in the list
 * _____________________________________________________________________________
 */
void free_frequencies(frequencies *first);

/* END OF FUNCTIONS*/

#endif
