#include <stdbool.h>
#include <limits.h>

/*@ requires 2 <= n <= 10;
    requires \valid(p+(0..n-1));
    requires ((n) >= 2 && (n) <= 10 &&
      \forall integer i; 0 <= i < (n) ==> 
        (p)[i] >= 100 && (p)[i] <= 10000 && (p)[i] % 2 == 0);
    ensures \result >= 0;
    ensures \result <= n * 10000;
*/
int func(int n, int *p) {
    int max_val;
    int sum;
    int i;
    
    max_val = p[0];
    sum = 0;
    i = 0;
    
    /*@ loop invariant (0 <= (i) <= (n) &&
      (sum) >= 0 &&
      (sum) <= (i) * 10000 &&
      (max_val) >= 100 && (max_val) <= 10000 &&
      \forall integer j; 0 <= j < (i) ==> 
        (p)[j] >= 100 && (p)[j] <= 10000 && (p)[j] % 2 == 0 &&
      \forall integer k; 0 <= k < (n) ==> 
        (p)[k] >= 100 && (p)[k] <= 10000 && (p)[k] % 2 == 0);
        loop assigns i, sum, max_val;
        loop variant n - i;
    */
    while (i < n) {
        int item;
        
        //@ assert 0 <= i < n;
        item = p[i];
        
        if (item >= max_val) {
            max_val = item;
        }
        
        //@ assert max_val >= 100 && max_val <= 10000;
        //@ assert item >= 100 && item <= 10000;
        //@ assert max_val - item >= 0;
        
        sum += max_val - item;
        i += 1;
        
        //@ assert sum >= 0;
        //@ assert sum <= i * 10000;
    }
    
    //@ assert sum >= 0;
    //@ assert sum <= n * 10000;
    return sum;
}
