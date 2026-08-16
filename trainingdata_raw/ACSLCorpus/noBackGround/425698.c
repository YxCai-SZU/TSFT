#include <stdbool.h>
/*@
    requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 200000 &&
        \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
        \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
long func(int n, int *p) {
    long answer = 0;
    long max = p[0];
    long min = p[0];
    int i = 0;
    
    /*@
        loop invariant (0 <= (i) <= (n) &&
        0 <= (answer) <= (i) &&
        (((n)) >= 1 && ((n)) <= 200000 &&
        \forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n)) &&
        \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&
        (max) >= (min) &&
        \forall integer k; 0 <= k < (i) ==> (p)[k] <= (max) && (p)[k] >= (min) &&
        (answer) <= (i));
        loop invariant i <= n;
        loop assigns i, answer, max, min;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert (0 <= (i) <= (n) &&         0 <= (answer) <= (i) &&         (((n)) >= 1 && ((n)) <= 200000 &&         \forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n)) &&         \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&         (max) >= (min) &&         \forall integer k; 0 <= k < (i) ==> (p)[k] <= (max) && (p)[k] >= (min) &&         (answer) <= (i));
        
        if (p[i] <= max && p[i] <= min) {
            answer += 1;
        }
        if (p[i] > max) {
            max = p[i];
        }
        if (p[i] < min) {
            min = p[i];
        }
        i += 1;
    }
    
    //@ assert answer <= n;
    return answer;
}
