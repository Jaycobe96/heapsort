/*
    Copyright 2023 Jakub Tomczak jaycobe9@gmail.com
    
    This code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    Algorithm is designed with help of this book:
    Thomas H. Cormen; Charles E. Leiserson; Ronald L. Rivest; Clifford Stein; Introduction to algorithms fourth edidtion.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>


static size_t heapsort_parent(size_t i) {
    return ((i+1) >> 1)-1;
}

static size_t heapsort_left(size_t i) {
    return ((i+1) << 1)-1;
}

static size_t heapsort_right(size_t i) {
    return ((i+1) << 1);
}

static void heapsort_max_heapify(base_t* A, size_t n, size_t i) {
    size_t l = heapsort_left(i);
    size_t r = heapsort_right(i);
    size_t largest;
    if(l < n && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }
    if(r < n && A[r] > A[largest]) {
        largest = r;
    }
    if(largest != i) {
        base_t temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        heapsort_max_heapify(A, n, largest);
    }
}

static void heapsort_build_max_heap(base_t* A, size_t n) {
    for(size_t i = (n >> 1)-1; i > 0; i--) {
        heapsort_max_heapify(A, n, i);
    }
    heapsort_max_heapify(A, n, 0);
}

static void heapsort(base_t* A, size_t n) {
    heapsort_build_max_heap(A, n);
    for(size_t i = n-1; i > 0; i--) {
        base_t temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        n--;
        heapsort_max_heapify(A, n, 0);
    }
}
