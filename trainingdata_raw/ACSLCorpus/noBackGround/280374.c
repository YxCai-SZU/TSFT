#include <stdbool.h>
#include <stdint.h>

/*@
  requires n >= 1 && n <= 20;
  requires \valid(arr + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 20 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 100);
  ensures ((\result) >= 0 && (\result) <= (n));
*/
int64_t func(uint32_t n, int64_t *arr)
{
    // Variable declarations at top of scope
    int64_t count = 0;
    uint32_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant ((n) >= 1 && (n) <= 20 &&
      \forall integer i; 0 <= i < (n) ==> (arr)[i] >= 1 && (arr)[i] <= 100);
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n)
    {
        int64_t num = arr[index];
        
        //@ assert num >= 1 && num <= 100;
        
        if (((index + 1) % 2 == 0) || ((index + 1) % 2 != 0 && (num & 1) == 1))
        {
            count += 1;
        }
        
        index += 1;
        
        //@ assert count >= 0 && count <= index;
    }
    
    //@ assert ((count) >= 0 && (count) <= (n));
    return count;
}
