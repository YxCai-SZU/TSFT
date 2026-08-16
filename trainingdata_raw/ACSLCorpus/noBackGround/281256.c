#include <stdbool.h>
#include <stddef.h>

/*@
    requires N >= 1 && N <= 100000;
    requires \valid(Hs + (0 .. N-1));
    requires ((N) >= 1 && (N) <= 100000 &&
        \forall size_t i; 0 <= i < (N) ==> (Hs)[i] >= 1 && (Hs)[i] <= 1000000000);
    ensures \result >= 0;
    ensures \result <= N;
*/
unsigned int func(size_t N, unsigned int *Hs)
{
    unsigned int count = 0;
    unsigned int flag = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= N;
        loop invariant ((count) >= 0 && (count) <= (index));
        loop assigns count, flag, index;
    */
    while (index < N)
    {
        unsigned int H = Hs[index];
        if (flag == 0)
        {
            count += 1;
            flag = H;
        }
        else if (flag <= H)
        {
            count += 1;
            flag = H;
        }
        //@ assert ((count) >= 0 && (count) <= (index + 1));
        index += 1;
    }
    return count;
}
