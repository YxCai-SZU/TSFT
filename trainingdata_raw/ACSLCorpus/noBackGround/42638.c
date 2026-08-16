#include <stdbool.h>
#include <limits.h>

/*@ requires (1 <= (n) <= 200000);
    requires \valid(ps+(0..n-1));
    requires \forall integer i; 0 <= i < n ==> (1 <= (ps[i]) <= (n));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (ps)[i] != (ps)[j]);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n; */
int func(int n, int *ps) {
    int cnt = 0;
    int min = INT_MAX;
    int index = 0;
    
    /*@ assert (1 <= (n) <= 200000); */
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant cnt >= 0;
        loop invariant cnt <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (1 <= (ps[i]) <= (n));
        loop invariant index > 0 ==> (\forall integer i, j; 0 <= i < j < (index) ==> (ps)[i] != (ps)[j]);
        loop invariant (1 <= (n) <= 200000);
        loop assigns cnt, min, index; */
    while (index < n) {
        int p = ps[index];
        
        if (min >= p) {
            cnt = cnt + 1;
            min = p;
        }
        
        index = index + 1;
    }
    
    /*@ assert cnt >= 0; */
    return cnt;
}
