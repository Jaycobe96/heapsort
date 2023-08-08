/*
    Copyright 2023 Jakub Tomczak jaycobe9@gmail.com
    
    This code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY.

    Algorithm is designed with help of this book:
    Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest; Clifford Stein; Introduction to algorithms fourth edidtion.

    For any questions or remarks, contact me on e-mail address provided above.
*/

#ifndef HEAPSORT_H_
#define HEAPSORT_H_

#include <stdint.h>

// int32_t can be changed to other types
typedef int32_t base_t;

void heapsort(base_t* A, size_t n);

#endif /* HEAPSORT_H_ */
