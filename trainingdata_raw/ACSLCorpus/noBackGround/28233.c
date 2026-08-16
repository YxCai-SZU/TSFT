#include <stddef.h>
#include <stdbool.h>

/*@
    requires (1 <= (k) && (k) <= 500 &&
        1 <= (n) && (n) <= 100000 &&
        \valid_read((h) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (h)[i] && (h)[i] <= 500);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
    ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result >= 1);
*/
size_t func(size_t k, size_t n, size_t *h)
{
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index && index <= n;
        loop invariant 0 <= count && count <= index;
        loop invariant \forall integer i; 0 <= i < index ==> (h[i] >= k ==> count >= 1);
        loop assigns index, count;
    */
    while (index < n)
    {
        if (h[index] >= k)
        {
            //@ assert h[index] >= k;
            count += 1;
        }
        
        index += 1;
    }
    
    return count;
}
