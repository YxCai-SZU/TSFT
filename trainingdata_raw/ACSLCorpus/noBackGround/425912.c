#include <stdbool.h>

/*@ requires (1 <= (n) <= 100 && 1 <= (x) <= 10000);
    requires n >= 1 && n <= 100;
    requires x >= 1 && x <= 10000;
    requires \valid(lengths + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (lengths)[i] <= 100);
    ensures \result >= 1 && \result <= n + 1;
    assigns \nothing;
*/
int func(int n, int x, int *lengths) {
    int di;
    int i;
    int l;
    
    di = 0;
    i = 1;
    
    /*@ loop invariant 1 <= i <= n + 1;
        loop invariant 0 <= di <= 100 * i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (lengths)[i] <= 100);
        loop invariant (1 <= (n) <= 100 && 1 <= (x) <= 10000);
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= lengths[j] <= 100;
        loop assigns i, di, l;
        loop variant n + 1 - i;
    */
    while (i <= n) {
        l = lengths[i - 1];
        di = di + l;
        
        if (di > x) {
            //@ assert di > x && i >= 1 && i <= n;
            return i;
        } else if (i == n) {
            //@ assert i == n && di <= x;
            return i + 1;
        }
        i = i + 1;
    }
    
    //@ assert 0 <= di <= 100 * (n + 1);
    return n + 1;
}
