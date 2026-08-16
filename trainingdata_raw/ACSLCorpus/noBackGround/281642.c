#include <stddef.h>
#include <stdbool.h>

/*@ requires s != t;
    requires ((s) == 1 || (s) == 2 || (s) == 3) && ((t) == 1 || (t) == 2 || (t) == 3);
    requires \valid(v + (0..len-1));
    requires len <= 10;
    requires \forall integer i; 0 <= i < len ==> ((v[i]) == 1 || (v[i]) == 2 || (v[i]) == 3);
    ensures \result <= len;
    ensures \forall integer i; 0 <= i < len && ((v[i]) != (s) && (v[i]) != (t)) ==> \result > 0;
    assigns \nothing;
 */
size_t func(int s, int t, int* v, size_t len) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i && ((v[j]) != (s) && (v[j]) != (t)) ==> count > 0;
        loop assigns i, count;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert i < len;
        if (v[i] != s && v[i] != t) {
            //@ assert ((v[i]) != (s) && (v[i]) != (t));
            count++;
        }
        i++;
    }
    return count;
}
