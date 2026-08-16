#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == (a + b) * c || 
            \result == a * b + c || 
            \result == a + b + c;
*/
int func(int a, int b, int c) {
    int answers[3];
    int answers_len = 3;
    int min_val;
    int i;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    
    answers[0] = (a + b) * c;
    //@ assert answers[0] == (((a) + (b)) * (c));
    
    answers[1] = a * b + c;
    //@ assert answers[1] == ((a) * (b) + (c));
    
    answers[2] = a + b + c;
    //@ assert answers[2] == ((a) + (b) + (c));
    
    min_val = answers[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= answers_len;
        loop invariant \exists integer k; 0 <= k < i && min_val == answers[k];
        loop invariant \forall integer j; 0 <= j < i ==> min_val <= answers[j];
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant answers_len == 3;
        loop assigns i, min_val;
        loop variant answers_len - i;
    */
    while (i < answers_len) {
        if (answers[i] < min_val) {
            min_val = answers[i];
        }
        i = i + 1;
    }
    
    //@ assert min_val == (((a) + (b)) * (c)) || min_val == ((a) * (b) + (c)) || min_val == ((a) + (b) + (c));
    return min_val;
}
