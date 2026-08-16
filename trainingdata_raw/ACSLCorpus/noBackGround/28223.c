#include <stddef.h>

/*@
    requires 0 < len;
    requires \valid(L + (0 .. len-1));
    ensures \exists integer i; 0 <= i < len && \result == L[i];
    ensures \forall integer k; 0 <= k < len ==> \result >= L[k];
*/
int max_in_list(int *L, int len)
{
    int max = L[0];
    int i = 1;
    //@ ghost int witness_idx = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant \exists integer k; 0 <= k < i && max == L[k];
        loop invariant \forall integer k; 0 <= k < i ==> max >= L[k];
        loop assigns max, i, witness_idx;
        loop variant len - i;
    */
    while (i < len)
    {
        if (L[i] > max)
        {
            max = L[i];
            //@ ghost witness_idx = i;
        }
        i = i + 1;
    }
    return max;
}
