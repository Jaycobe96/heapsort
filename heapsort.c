
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int32_t base_t;

//HeapSort (zero indexed)
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

static void read_input(base_t *Arr, size_t size) {
    for(size_t i = 0; i < size; i++) {
        base_t val = 0;
        scanf("%i ", &val);
        Arr[i] = val;
    }
}

static void read_var(base_t *var) {
    scanf("%u", var);
}

static void* alloc_array(size_t size) {
    return malloc(sizeof(base_t) * size);
}

static void print_Arr_int32(int32_t* Arr, size_t sta, size_t sto) {
    printf("\n ");
    for(size_t i = sta; i <= sto; i++) {
        printf("%i ", Arr[i]);
    }
    printf("\n ");
}

int main()
{
    base_t A_test[10] = {8, 5, 3, 9, 6, 1, 3, 18, 0, 20};
    print_Arr_int32(A_test, 0, 9);
    size_t n = sizeof(A_test)/sizeof(base_t);
    heapsort(A_test, n);
    print_Arr_int32(A_test, 0, 9);
    return 0;
}
