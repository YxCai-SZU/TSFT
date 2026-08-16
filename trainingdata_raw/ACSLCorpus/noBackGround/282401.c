#include <stdbool.h>
#include <stddef.h>

/*@
  requires (1 <= (n) <= 20);
  requires \valid(v+(0..n-1));
  requires \valid(c+(0..n-1));
  requires \forall integer j; 0 <= j < n ==> (1 <= (v[j]) <= 50);
  requires \forall integer j; 0 <= j < n ==> (1 <= (c[j]) <= 50);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (((n)) * 50);
*/
int func(int n, int* v, int* c) {
    int sum = 0;
    int i = 0;
    
    //@ assert (1 <= (n) <= 20);
    //@ assert sum >= 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant sum >= 0;
        loop invariant sum <= ((i) * 50);
        loop assigns sum, i;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) < (n));
        //@ assert (1 <= (v[i]) <= 50);
        //@ assert (1 <= (c[i]) <= 50);
        
        int diff = v[i] - c[i];
        if (diff > 0) {
            sum += diff;
        }
        
        //@ assert sum >= 0;
        //@ assert sum <= ((i + 1) * 50);
        i++;
    }
    
    //@ assert sum >= 0;
    return sum;
}
