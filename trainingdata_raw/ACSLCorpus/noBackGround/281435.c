#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 100000 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
size_t func(size_t n, uint32_t *a)
{
    size_t count = 0;
    size_t j = 0;

    /*@
        loop invariant ((((n)) >= 1 && ((n)) <= 100000 &&
        \valid(((a)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 1000000000) &&
        0 <= (j) <= (n) &&
        0 <= (count) <= (j));
        loop invariant n - j >= 0;
        loop assigns j, count;
        loop variant n - j;
    */
    while (j < n)
    {
        //@ assert ((((n)) >= 1 && ((n)) <= 100000 &&         \valid(((a)) + (0 .. ((n))-1)) &&         \forall integer i; 0 <= i < ((n)) ==> ((a))[i] >= 1 && ((a))[i] <= 1000000000) &&         0 <= (j) <= (n) &&         0 <= (count) <= (j));
        
        if (j == 0 || j == 1)
        {
            count += 1;
        }
        else
        {
            uint32_t prev_value = a[j - 2];
            uint32_t next_value = a[j];
            
            //@ assert prev_value >= 1 && prev_value <= 1000000000;
            //@ assert next_value >= 1 && next_value <= 1000000000;
            
            if (prev_value < next_value)
            {
                count += 1;
            }
        }
        
        j += 1;
        //@ assert count <= j;
    }
    
    //@ assert count <= n;
    return count;
}
