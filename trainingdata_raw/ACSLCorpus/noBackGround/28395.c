#include <limits.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0..(n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    ensures \result >= 1 && \result <= n;
    assigns \nothing;
*/
int func(int n, int *p)
{
    int min = INT_MAX;
    int count = 0;
    int index = 0;

    /*@
        loop invariant (0 <= (index) <= (n) &&
        0 <= (count) <= (index) &&
        ((index) > 0 ==> (\forall integer i; 0 <= i < (index) ==> (p)[i] >= 1 && (p)[i] <= (n))) &&
        ((index) > 0 ==> (\forall integer i, j; 0 <= i < j < (index) ==> (p)[i] != (p)[j])) &&
        ((min) == INT_MAX || (\exists integer i; 0 <= i < (index) && (min) == (p)[i])) &&
        ((count) == 0 || (\exists integer i; 0 <= i < (index) && (min) == (p)[i])) &&
        ((index) > 0 ==> (count) >= 1));
        loop assigns index, count, min;
        loop variant n - index;
    */
    while (index < n)
    {
        int item = p[index];
        //@ assert item >= 1 && item <= n;
        
        if (item <= min)
        {
            //@ assert item <= min;
            count += 1;
            min = item;
            //@ assert count >= 1;
        }
        //@ assert count == 0 || (\exists integer i; 0 <= i <= index && min == p[i]);
        
        index += 1;
        //@ assert index <= n;
    }
    
    //@ assert count >= 1;
    //@ assert count <= n;
    return count;
}
