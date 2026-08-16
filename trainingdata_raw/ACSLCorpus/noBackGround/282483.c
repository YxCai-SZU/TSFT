#include <stdbool.h>
#include <stddef.h>

/*@ requires \valid_read(v + (0 .. 4)) && (\forall integer i; (0 <= (i) < 5) ==> (1 <= ((v)[i]) && ((v)[i]) <= 5)) && (\exists integer i; (0 <= (i) < 5) && (v)[i] == 0);
    ensures 1 <= \result && \result <= 5 && v[\result - 1] == 0;
    assigns \nothing;
 */
unsigned long func(const int *v)
{
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant (\forall integer i; (0 <= (i) < 5) ==> (1 <= ((v)[i]) && ((v)[i]) <= 5));
        loop invariant (\exists integer i; (0 <= (i) < 5) && (v)[i] == 0);
        loop invariant \forall integer j; 0 <= j < i ==> v[j] != 0;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert (0 <= (i) < 5);
        if (v[i] == 0) {
            //@ assert v[i] == 0;
            return (unsigned long)(i + 1);
        }
        //@ assert v[i] != 0;
        i++;
    }
    //@ assert \false;
    return 0;
}
