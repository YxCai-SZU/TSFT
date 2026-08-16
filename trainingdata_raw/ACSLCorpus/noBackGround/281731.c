#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(v + (0 .. 4));
    requires (\forall integer i; 0 <= i < (5) ==> ((v)[i] == 0 || (v)[i] == 1));
    requires (\exists integer i; 0 <= i < (5) && (v)[i] == 1);
    ensures 0 <= \result < 5;
    ensures v[\result] == 1;
*/
long func(long* v)
{
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant (\exists integer i; 0 <= i < (5) && (v)[i] == 1);
        loop invariant \forall integer k; 0 <= k < i ==> v[k] == 0;
        loop invariant (\forall integer i; 0 <= i < (5) ==> ((v)[i] == 0 || (v)[i] == 1));
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert (\forall integer i; 0 <= i < (5) ==> ((v)[i] == 0 || (v)[i] == 1)) ==> (v[i] == 0 || v[i] == 1);
        
        if (v[i] == 1) {
            return (long)i;
        }
        
        i++;
    }
    
    return -1;
}
