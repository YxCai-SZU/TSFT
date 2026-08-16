#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(v+(0..4));
    requires ((5) == 5);
    requires \forall integer i; 0 <= i < 5 ==> ((v)[(i)] == (i) + 1 || (v)[(i)] == 0);
    requires (\exists integer i; 0 <= i < (5) && (v)[i] == 0);
    ensures \result >= 1 && \result <= 5;
    ensures v[\result-1] == 0;
*/
int func(int *v) {
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant ((5) == 5);
        loop invariant \forall integer j; 0 <= j < 5 ==> ((v)[(j)] == (j) + 1 || (v)[(j)] == 0);
        loop invariant (\exists integer i; 0 <= i < (5) && (v)[i] == 0);
        loop invariant (\forall integer k; 0 <= k < (i) ==> (v)[k] != 0);
        loop assigns i;
        loop variant 5-i;
    */
    while (i < 5) {
        if (v[i] == 0) {
            return (int)(i + 1);
        }
        i++;
    }
    
    // Proof that this point is unreachable
    /*@ assert \false; */
    return -1;
}

int main() {
    return 0;
}
