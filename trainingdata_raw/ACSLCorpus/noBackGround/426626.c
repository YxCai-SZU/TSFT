#include <stddef.h>
#include <stdint.h>

/*@
    requires ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0..(n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (int64_t)(n) &&
        \forall size_t i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures 1 <= \result <= (int)n;
    assigns \nothing;
*/
int32_t func(size_t n, int64_t *p)
{
    int32_t count = 1;
    size_t index = 1;
    size_t p_count = (size_t)p[0];
    
    //@ assert 1 <= index <= n;
    
    /*@
        loop invariant 1 <= index <= n;
        loop invariant 1 <= count <= (int)index;
        loop invariant p_count <= n;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
        \valid((p) + (0..(n)-1)) &&
        \forall size_t i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (int64_t)(n) &&
        \forall size_t i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
        loop assigns count, index, p_count;
        loop variant n - index;
    */
    while (index < n)
    {
        if (p_count > (size_t)p[index])
        {
            count += 1;
            p_count = (size_t)p[index];
        }
        
        index += 1;
    }
    
    //@ assert 1 <= count <= (int)n;
    return count;
}
