#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    requires \valid(x + (0 .. len-1));
    requires ((len) >= 1 && (len) <= 200000 &&
        \forall size_t i; 0 <= i < (len) ==> ((x)[i] == 0 || (x)[i] == 1));
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= (int64_t)len;
*/
int64_t func(int64_t* x, size_t len)
{
    int64_t sum = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant sum >= 0;
        loop invariant sum <= (int64_t)index;
        loop invariant ((len) >= 1 && (len) <= 200000 &&
        \forall size_t i; 0 <= i < (len) ==> ((x)[i] == 0 || (x)[i] == 1));
        loop assigns sum, index;
        loop variant len - index;
    */
    while (index < len)
    {
        int64_t val = x[index];
        
        //@ assert val == 0 || val == 1;
        
        if (index % 2 == 0 && val == 1)
        {
            sum += 1;
        }
        
        index += 1;
        
        //@ assert sum <= (int64_t)index;
    }
    
    return sum;
}
