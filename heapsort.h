/*
    Copyright 2023 Jakub Tomczak jaycobe9@gmail.com
    
    This code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    Algorithm is designed with help of this book:
    Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest; Clifford Stein; Introduction to algorithms fourth edidtion.
*/

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <stdint.h>
#include "ml_types.h"

typedef ml_data_type base_t;

void heapsort(base_t* A, size_t n);

#endif /* HEAPSORT_H_ */
