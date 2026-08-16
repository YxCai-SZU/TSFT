#include <stdbool.h>
#include <limits.h>

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p+(0..n-1));
    requires (\forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (p)[i] && (p)[i] <= (n));
    ensures \result >= 0 && \result <= n;
*/
int func(int n, int *p) {
    int answer = 0;
    int min_bound = INT_MAX;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant answer >= 0;
        loop invariant answer <= index;
        loop invariant \forall integer k; 0 <= k < index ==> 1 <= p[k] && p[k] <= n;
        loop invariant \forall integer k, l; 0 <= k < l < index ==> p[k] != p[l];
        loop invariant 1 <= min_bound <= INT_MAX;
        loop invariant answer <= n;
        loop assigns answer, min_bound, index;
        loop variant n - index;
    */
    while (index < n) {
        int p_i = p[index];
        if (p_i <= min_bound) {
            answer += 1;
            min_bound = p_i;
        }
        index += 1;
        
        //@ assert \forall integer k; 0 <= k < index ==> 1 <= p[k] && p[k] <= n;
    }
    return answer;
}
