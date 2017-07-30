/*
 * AckermanFunction.hpp
 *
 *  Created on: 30-Jul-2017
 *      Author: gsharma
 */

#ifndef ACKERMANFUNCTION_HPP_
#define ACKERMANFUNCTION_HPP_


/*
 *	The function
 *
 *  a(x, y) = y+1 if x == 0, a(x-1, 1) if y == 0, a(x-1, a(x, y-1)) otherwise
 */
 
int ackerman(int x, int y);


#endif /* ACKERMANFUNCTION_HPP_ */
