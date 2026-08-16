#include <stdbool.h>

/*@
    requires (1 <= (a) <= 1000) && (1 <= (b) <= 1000) && 
             (1 <= (c) <= 1000) && (1 <= (d) <= 1000);
    ensures ((\result) == (((a)) + ((b)) + ((c))) || (\result) == (((a)) + ((b)) + ((d))) ||
        (\result) == (((a)) + ((c)) + ((d))) || (\result) == (((b)) + ((c)) + ((d))));
*/
int func(int a, int b, int c, int d)
{
    int vec[4];
    int min_val;
    int i;
    
    vec[0] = a + b + c;
    vec[1] = a + b + d;
    vec[2] = a + c + d;
    vec[3] = b + c + d;
    
    min_val = vec[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && min_val == vec[j];
        loop invariant \forall integer k; 0 <= k < i ==> min_val <= vec[k];
        loop assigns i, min_val;
    */
    while (i < 4)
    {
        if (vec[i] < min_val)
        {
            min_val = vec[i];
        }
        i = i + 1;
    }
    
    //@ assert ((min_val) == (((a)) + ((b)) + ((c))) || (min_val) == (((a)) + ((b)) + ((d))) ||         (min_val) == (((a)) + ((c)) + ((d))) || (min_val) == (((b)) + ((c)) + ((d))));
    return min_val;
}
