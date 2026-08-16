#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == ((a) + (b)) || \result == ((b) + (c)) || 
            \result == ((c) + (d)) || \result == ((d) + (a));
    ensures 2 <= \result <= 200;
*/
int func(int a, int b, int c, int d) {
    int answers[4];
    int max_val;
    int i;

    answers[0] = a + b;
    answers[1] = b + c;
    answers[2] = c + d;
    answers[3] = d + a;

    max_val = answers[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && max_val == answers[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= answers[k];
        loop invariant answers[0] == ((a) + (b));
        loop invariant answers[1] == ((b) + (c));
        loop invariant answers[2] == ((c) + (d));
        loop invariant answers[3] == ((d) + (a));
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
        loop assigns i, max_val;
    */
    while (i < 4) {
        //@ assert 0 <= i < 4;
        if (answers[i] > max_val) {
            max_val = answers[i];
        }
        i++;
    }

    //@ assert max_val == ((a) + (b)) || max_val == ((b) + (c)) || max_val == ((c) + (d)) || max_val == ((d) + (a));
    return max_val;
}
