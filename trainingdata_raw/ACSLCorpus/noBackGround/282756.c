#include <stddef.h>
#include <stdint.h>

/*@
    requires ((len) > 0 && \valid((v) + (0 .. (len)-1)));
    ensures \forall integer j; 0 <= j < len ==> \result >= v[j];
    assigns \nothing;
*/
unsigned char max_value(unsigned char *v, size_t len)
{
    unsigned char max;
    size_t i;

    //@ assert len > 0;
    max = v[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> max >= v[j];
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len)
    {
        //@ assert 0 <= i < len;
        if (v[i] > max)
        {
            max = v[i];
        }
        i = i + 1;
    }

    //@ assert \forall integer j; 0 <= j < len ==> max >= v[j];
    return max;
}
