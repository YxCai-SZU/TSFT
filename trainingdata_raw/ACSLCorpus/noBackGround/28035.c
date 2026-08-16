#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid(v+(0..4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> (v)[i] >= 0 && (v)[i] <= 123);
    requires k >= 0 && k <= 123;
    assigns \nothing;
    ensures \result == (v[4] - v[0] <= k);
*/
bool func(int* v, int k) {
    // Variable declarations
    int i;
    int vec[4];
    size_t vec_len = 0;
    bool result;
    
    i = 1;
    
    /*@ loop invariant 1 <= i <= 5;
        loop invariant vec_len == (size_t)(i - 1);
        loop invariant \forall integer j; 0 <= j < vec_len ==> vec[j] == v[j + 1];
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> (v)[i] >= 0 && (v)[i] <= 123);
        loop invariant k >= 0 && k <= 123;
        loop invariant vec_len < 5;
        loop assigns i, vec[0..3], vec_len;
        loop variant 5 - i;
    */
    while (i < 5) {
        vec[vec_len] = v[i];
        vec_len++;
        i++;
    }
    
    //@ assert vec_len == 4;
    //@ assert vec[vec_len - 1] == v[4];
    
    result = (vec[vec_len - 1] - v[0]) <= k;
    
    return result;
}
