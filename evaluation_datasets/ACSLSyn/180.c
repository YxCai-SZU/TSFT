#include <stdbool.h>
#include <stddef.h>

/*@
    predicate map_ext_equal{L1,L2}(int *values1, int *values2, integer size) =
        \forall integer i; 0 <= i < size ==> \at(values1[i],L1) == \at(values2[i],L2);
*/

/*@
    lemma map_extensional_equal{L1,L2}:
        \forall int *values1, *values2, integer size;
        map_ext_equal{L1,L2}(values1, values2, size) ==>
        (\forall integer i; 0 <= i < size ==> \at(values1[i],L1) == \at(values2[i],L2));
*/

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100;
    logic integer square(integer n) = n * n;
    lemma square_bounded: \forall integer n; is_valid_n(n) ==> square(n) <= 10000;
*/

size_t func(size_t n) {
    size_t ans = n;
    
    //@ assert is_valid_n(n);
    
    if (n > 0) {
        //@ assert n > 0 && n <= 100;
        //@ assert square(n) <= 10000;
        ans = n * n;
    }
    
    //@ assert ans == square(n);
    return ans;
}

void fill_array_with_square(int *values, size_t size) {
    size_t n = size;
    size_t square_val = func(n);
    
    for (size_t i = 0; i < size; i++) {
        values[i] = (int)square_val;
    }
    
    //@ assert map_ext_equal{Here,Here}(values, values, size);
}

int main() {
    int buffer[5];
    
    fill_array_with_square(buffer, 5);
    
    //@ assert \forall integer i; 0 <= i < 5 ==> buffer[i] == 25;
    
    return 0;
}
