#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 200000;
  requires \valid(a + (0 .. n-1));
  requires ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n;
*/
int func(long long n, int *a) {
    int count = 0;
    unsigned long long i = 0;
    
    //@ assert ((n) >= 1 && (n) <= 200000 &&       \valid((a) + (0 .. (n)-1)) &&       \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant ((n) >= 1 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < (unsigned long long)n) {
        int value = a[i];
        
        //@ assert value >= 1 && value <= 1000000000;
        
        if (value & 1) {
            count++;
        }
        
        i++;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    
    return count;
}
