#include <stddef.h>
#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (x) && (x) <= 10000 &&
        \valid((ls) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (ls)[i] && (ls)[i] <= 100);
    ensures 1 <= \result && \result <= n + 1;
    assigns \nothing;
*/
uint32_t func(size_t n, size_t x, size_t *ls)
{
    uint32_t count = 1;
    size_t sum = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant 1 <= count <= index + 1;
        loop invariant sum == 0 || (index > 0 && sum <= index * 100);
        loop assigns index, sum, count;
        loop variant n - index;
    */
    while (index < n)
    {
        //@ assert 0 <= index < n;
        sum += ls[index];
        
        if (sum <= x)
        {
            //@ assert sum <= x;
            count += 1;
        }
        
        index += 1;
        //@ assert count <= index + 1;
    }
    
    //@ assert 1 <= count <= n + 1;
    return count;
}
