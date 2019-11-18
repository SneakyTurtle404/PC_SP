#ifndef _TRANSMITTERS_H
#define _TRANSMITTERS_H
#include "frequencies.h"

/* ----------------------------STRUCTURES-------------------------------------- */

/*______________________________________________________________________________
 * Structure represents coordinates of transmitter.
 * _____________________________________________________________________________
 */
	typedef struct XYcoor{
		double x;
		double y;
	}coordinates; 

/*______________________________________________________________________________
 * Structure represents list of neighbouring transmitters.
 * _____________________________________________________________________________
 */
	typedef struct transNeighbours{
		struct thetransmitter *transmitter;
		struct theneigbours *next;
	}neighbours;

/*______________________________________________________________________________
 * Structure represents transmitter.
 * _____________________________________________________________________________
 */
	typedef struct oneTrans{
		int id;
		coordinates *coordinates;	/* xy possition */
		neighbours *neighbours;		/* neighbouring transmitters */
		frequency *frequency;		/* assigned frequency */
	}transmitter;

/*______________________________________________________________________________
 * Structure represents element in linked list of transmitters.
 * _____________________________________________________________________________
 */
	typedef struct allTrans{
		transmitter *transmitter;
		struct allTrans *next;	/* pointer to next transmitter in the list */
	}transmitters;


/* ----------------------------END-OF-STRUCTURES-------------------------------------------*/


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
transmitters* add_transmitter(transmitters *last, int id, double x, double y);


/* _____________________________________________________________________________
 *	Creates neighbour from given transmitter neigh and adds it to list of neighbours of transmitter tran.
 *  @param *t: transmitter
 *  @param *n: neighbour transmitter
 * _____________________________________________________________________________
 */
void add_neighbour(transmitter *t, transmitter *n);

/* _____________________________________________________________________________
 *	Prints one neighbour transmitter to the console
 *  @param *t: pointer to the given neighbour
 * _____________________________________________________________________________
 */
void print_neighbour(transmitter *t);

/* _____________________________________________________________________________
 *	Prints one transmitter to the console
 *  @param *t: pointer to the given transmitter
 * _____________________________________________________________________________
 */
void print_one_trans(transmitter *t);


/* _____________________________________________________________________________
 *	Prints all transmitters in given list of transmitters,
 *  @param *first: pointer to the first element in this list.
 * _____________________________________________________________________________
 */
void print_all_trans(transmitters *first);

/* _____________________________________________________________________________
 *	Sets transmission radius of all transmitters.
 *  @param *radius: transmitters radius
 * _____________________________________________________________________________
 */
void set_radius(int radius);

/* _____________________________________________________________________________
 *	Returns transmission radius of all transmitters.
 * _____________________________________________________________________________
 */
int get_radius();

/* _____________________________________________________________________________
 *	Frees all memory allocated for list of transmitters
 *	@param first: pointer for the first element in this list.
 * _____________________________________________________________________________
 */
void free_transmitters(transmitters *first);

/*----------------END-OF-FUNCTIONS ----------------------------------------------------*/



#endif
