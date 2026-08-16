#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100) && (-100 <= (b) <= 100) && (-100 <= (c) <= 100) && (-100 <= (d) <= 100);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
*/
long func(long a, long b, long c, long d) {
    long answers[4];
    long max_value;
    long i;
    
    //@ assert a * c >= -10000 && a * c <= 10000;
    answers[0] = a * c;
    
    //@ assert a * d >= -10000 && a * d <= 10000;
    answers[1] = a * d;
    
    //@ assert b * c >= -10000 && b * c <= 10000;
    answers[2] = b * c;
    
    //@ assert b * d >= -10000 && b * d <= 10000;
    answers[3] = b * d;
    
    max_value = answers[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer k; 0 <= k < i && max_value == answers[k];
        loop invariant \forall integer j; 0 <= j < i ==> max_value >= answers[j];
        loop invariant max_value == a * c || max_value == a * d || max_value == b * c || max_value == b * d;
        loop assigns i, max_value;
        loop variant 4 - i;
    */
    while (i < 4) {
        if (answers[i] > max_value) {
            max_value = answers[i];
        }
        i = i + 1;
    }
    
    return max_value;
}

int main() {
    return 0;
}
