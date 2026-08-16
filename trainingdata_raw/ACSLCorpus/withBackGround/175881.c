#include <stdbool.h>

/*@ predicate is_multiple(integer i, integer j) = i == j; */

/*@
    lemma count_bounds:
        \forall integer l, integer r, integer d, integer i, integer count;
        1 <= l <= r <= 100 && 1 <= d <= 100 &&
        l <= i <= r + 1 && 0 <= count <= i - l ==>
        0 <= count <= r - l + 1;
*/

/*@
    requires 1 <= l <= r <= 100;
    requires 1 <= d <= 100;
    ensures \result >= 0;
    ensures \result <= r - l + 1;
*/
int func(int l, int r, int d)
{
    int count = 0;
    int i = l;
    
    /*@
        loop invariant l <= i <= r + 1;
        loop invariant 0 <= count <= i - l;
        loop invariant 1 <= l <= r <= 100;
        loop invariant 1 <= d <= 100;
        loop assigns i, count;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        int j = 0;
        bool is_multiple = false;
        
        /*@
            loop invariant 0 <= j <= d;
            loop invariant 1 <= d <= 100;
            loop assigns j, is_multiple;
            loop variant d - j;
        */
        while (j < d)
        {
            //@ assert 0 <= j < d;
            if (i == j)
            {
                is_multiple = true;
                break;
            }
            j++;
        }
        
        if (is_multiple)
        {
            count++;
        }
        i++;
    }
    
    //@ assert 0 <= count <= r - l + 1;
    return count;
}
