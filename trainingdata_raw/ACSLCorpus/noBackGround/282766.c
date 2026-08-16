#include <stddef.h>
#include <stdint.h>

/*@
    requires
        ((a_len) == 5) &&
        (\forall integer i; 0 <= i < (a_len) ==> (a)[i] == i + 1) &&
        (1 <= (b_len) && (b_len) <= 5) &&
        (\forall integer i; 0 <= i < (b_len) ==> ((b)[i] == i + 1 || (b)[i] == 0)) &&
        (\exists integer i; 0 <= i < (b_len) && (b)[i] == 0);
    ensures
        \result >= 0 &&
        \result < 5 &&
        b[\result] == 0;
*/
int32_t func(int32_t *a, size_t a_len, int32_t *b, size_t b_len)
{
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= b_len;
        loop invariant \forall integer k; 0 <= k < i ==> b[k] != 0;
        loop invariant \exists integer j; i <= j < b_len && b[j] == 0;
        loop assigns i;
        loop variant b_len - i;
    */
    while (i < b_len)
    {
        //@ assert 0 <= i < b_len;
        if (b[i] == 0)
        {
            //@ assert b[i] == 0;
            //@ assert i >= 0;
            //@ assert i < 5;
            return (int32_t)i;
        }
        //@ assert b[i] != 0;
        i = i + 1;
    }
    return -1;
}
