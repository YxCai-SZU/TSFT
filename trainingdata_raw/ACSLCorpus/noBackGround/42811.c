#include <stdbool.h>
#include <stddef.h>

/*@
  requires ((n) > 0 && (n) <= 100 &&
      \forall integer i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
  ensures ((\result) >= 0 && (\result) <= (n) &&
      \forall integer i; 0 <= i < (n) ==> 
        (i % 2 == 0 && (a)[i] % 2 == 1) ==> (\result) > 0);
*/
size_t func(size_t n, int *a)
{
    size_t count = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= count <= index;
      loop invariant count <= n;
      loop invariant \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
      loop invariant index > 0 ==> 
        \forall integer j; 0 <= j < index && j % 2 == 0 && a[j] % 2 == 1 ==> count > 0;
      loop assigns count, index;
      loop variant n - index;
    */
    while (index < n)
    {
        int value = a[index];
        if (index % 2 == 0 && value % 2 == 1)
        {
            count++;
        }
        index++;
    }
    
    //@ assert ((count) >= 0 && (count) <= (n) &&       \forall integer i; 0 <= i < (n) ==>          (i % 2 == 0 && (a)[i] % 2 == 1) ==> (count) > 0);
    return count;
}
