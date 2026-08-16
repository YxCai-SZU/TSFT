#include <stdbool.h>
#include <stddef.h>

/*@
  requires n >= 1 && n <= 100;
  requires \valid(aa + (0 .. n-1));
  requires \forall integer j; 0 <= j < n ==> aa[j] >= 1 && aa[j] <= 100;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n;
*/
int func(int n, int *aa) {
    int count;
    size_t i;
    int a;
    
    count = 0;
    i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer j; 0 <= j < n ==> aa[j] >= 1 && aa[j] <= 100;
        loop invariant \valid(aa + (0 .. n-1));
        loop assigns i, count, a;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        a = aa[i];
        
        //@ assert a >= 1 && a <= 100;
        
        if ((a & 1) == 1 && (count & 1) == 0) {
            count = count + 1;
        }
        
        i = i + 1;
    }
    
    return count;
}
