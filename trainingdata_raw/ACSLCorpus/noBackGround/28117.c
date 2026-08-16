#include <stddef.h>
#include <stdbool.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
size_t func(size_t n, int *a)
{
    size_t count = 0;
    size_t index = 0;
    
    //@ ghost int *old_a = a;
    //@ ghost size_t old_n = n;
    
    /*@ loop invariant (0 <= (index) <= (n) &&
    0 <= (count) <= (index) &&
    ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> (a)[i] > 0 && (a)[i] <= 100) &&
    (((n)) > 0 && ((n)) <= 100 &&
    \valid(((a)) + (0 .. ((n))-1)) &&
    \forall integer i; 0 <= i < ((n)) ==> ((a))[i] > 0 && ((a))[i] <= 100) &&
    (count) <= (index));
        loop invariant a == old_a;
        loop invariant n == old_n;
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n)
    {
        //@ assert index < n;
        //@ assert a[index] > 0 && a[index] <= 100;
        
        if (index % 2 == 0 && a[index] % 2 == 1)
        {
            //@ assert count < index + 1;
            count += 1;
        }
        
        //@ assert index + 1 <= n;
        index += 1;
    }
    
    //@ assert count <= n;
    return count;
}
