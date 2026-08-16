#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 200000 &&
        \valid((p) + (0 .. (n)-1)) &&
        (\forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n)) &&
        (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *p) {
    int result = 0;
    int max;
    int min;
    int i = 0;
    
    //@ assert n > 0 && n <= 200000;
    //@ assert \valid(p + (0 .. n-1));
    
    max = p[0];
    min = p[0];
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant result >= 0;
        loop invariant result <= i;
        loop invariant max >= min;
        loop invariant ((i) > 0 ==> (\forall integer k; 0 <= k < (i) ==> (p)[k] <= (max) && (p)[k] >= (min)));
        loop invariant \forall integer j; 0 <= j < n ==> (j < i ==> p[j] <= max && p[j] >= min);
        loop assigns i, result, max, min;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        //@ assert \valid(p + i);
        
        if (p[i] <= max && p[i] <= min) {
            //@ assert p[i] <= max && p[i] <= min;
            result += 1;
            //@ assert result >= 1;
        }
        
        if (p[i] > max) {
            //@ assert p[i] > max;
            max = p[i];
            //@ assert max == p[i];
        }
        
        if (p[i] < min) {
            //@ assert p[i] < min;
            min = p[i];
            //@ assert min == p[i];
        }
        
        i += 1;
        //@ assert i <= n;
    }
    
    //@ assert i == n;
    //@ assert result >= 0;
    //@ assert result <= n;
    return result;
}
