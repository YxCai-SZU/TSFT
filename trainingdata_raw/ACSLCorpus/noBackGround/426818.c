#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
  requires (0 < (n) <= 200000);
  requires (\valid((a) + (0 .. (n)-1)));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
  ensures 0 <= \result <= n;
  assigns \nothing;
*/
uint32_t func(size_t n, int32_t* a)
{
    uint32_t count = 0;
    size_t index = 0;
    
    //@ assert 0 <= index <= n;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant (0 < (n) <= 200000);
        loop invariant (\valid((a) + (0 .. (n)-1)));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int32_t num = a[index];
        size_t sum = 0;
        size_t inner_index = 0;
        
        //@ assert 0 <= inner_index <= n;
        
        /*@ loop invariant 0 <= inner_index <= n;
            loop invariant 0 <= sum <= inner_index;
            loop invariant (0 < (n) <= 200000);
            loop invariant (\valid((a) + (0 .. (n)-1)));
            loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 1000000);
            loop assigns sum, inner_index;
            loop variant n - inner_index;
        */
        while (inner_index < n) {
            //@ assert 0 <= inner_index < n;
            if (a[inner_index] % num == 0) {
                sum += 1;
            }
            inner_index += 1;
        }
        
        //@ assert inner_index == n;
        if (sum == 1) {
            count += 1;
        }
        index += 1;
    }
    
    //@ assert index == n;
    //@ assert 0 <= count <= n;
    return count;
}
