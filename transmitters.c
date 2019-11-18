#include <stdlib.h>
#include <stdio.h>
#include "transmitters.h"


/*
 * Transmission radius for all transmitters
 */
static int radius;

/*----------------------------------- FUNCTIONS ----------------------------------------------------*/

/* _____________________________________________________________________________
 *	Creates transmitter from given parameters and link it to list of transmitters behind last.
 * @param *last: point to the last added element in transmitters list
 * @param id: id of new transmitter that's gonna be created
 * @param x: value of x-coordinate
 * @param y: value of y-coordinate
 * Returns the last added element in the list of transmitters.
 * _____________________________________________________________________________
 */
transmitters* add_transmitter(transmitters *last, int id, double x, double y){
	coordinates *newcoor;
	transmitter *newtran;
	transmitters *newtrans;
	
	/* creating new coordinates */
	newcoor = malloc(sizeof(coordinates));
	newcoor->x = x;
	newcoor->y = y;
	
	/* creating new transmitter */
	newtran = malloc(sizeof(transmitter));
	newtran->id = id;
	newtran->coordinates = newcoor;
	newtran->neighbours = NULL;
	newtran->frequency = NULL;
	
	/* creating transmitters for transmitters list */
	newtrans = malloc(sizeof(transmitters));
	newtrans->transmitter = newtran;
	newtrans->next = NULL;
	
	/* adding transmitters to the list */
	/* if last == NULL - return newTrans ( it' first element of transmitters list) */
	if(last){
		last->next = newtrans;
	}
		
	return newtrans;	
}


/* _____________________________________________________________________________
 *	Creates neighbour from given transmitter neigh and adds it to list of neighbours of transmitter tran.
 *  @param *t: transmitter
 *  @param *n: neighbour transmitter
 * _____________________________________________________________________________
 */
void add_neighbour(transmitter *t, transmitter *n){
	neighbours *newNbour;
	
	/* creating neighbour */
	newNbour = malloc(sizeof(neighbours));
	newNbour->transmitter = n;
	
	/* if it is first neighbour */
	if(!t->neighbours){
		newNbour->next = NULL;
		t->neighbours = newNbour;
	}else{                                    /* transmitter already have neighbour */
		newNbour->next = t->neighbours;
		t->neighbours = newNbour;
	}
}

/* _____________________________________________________________________________
 *	Prints one transmitter to the console
 *  @param *t: pointer to the given transmitter
 * _____________________________________________________________________________
 */
void print_one_trans(transmitter *t){
	/*
	printf("id: %2d X: %10f Y: %f\n", tran->id,	tran->coordinates->x,
												tran->coordinates->y);
	*/
										
	printf("%d %d\n", t->id, t->frequency->value);
}


/* _____________________________________________________________________________
 *	Prints one neighbour transmitter to the console
 *  @param *t: pointer to the given neighbour
 * _____________________________________________________________________________
 */
void print_neighbour(transmitter *t){
	
		neighbours *pom = t->neighbours;
	while(pom != NULL){
		print_one_trans(pom->transmitter);
		pom = pom->next;
	}
}


/* _____________________________________________________________________________
 *	Prints all transmitters in given list of transmitters,
 *  @param *first: pointer to the first element in this list.
 * _____________________________________________________________________________
 */
void print_all_trans(transmitters *first){
		transmitters *pom = first;
	/*
	printf("%s %d\n", "Transmission radius:",radius);
	printf("%s", "Transmitters:\n");
	*/
	while(pom != NULL){
		print_one_trans(pom->transmitter);
		
		/*
		printf("%s\n","neighbours:");
		transmitters_print_neighbour(pom->transmitter);
		printf("%s\n","----");
		*/
		
		pom = pom->next;
	}
}

/* _____________________________________________________________________________
 *	Sets transmission radius of all transmitters.
 *  @param *radius: transmitters radius
 * _____________________________________________________________________________
 */
void set_radius(int r){
		r = radius;
}





/*----------------END-OF-FUNCTIONS ----------------------------------------------------*/

