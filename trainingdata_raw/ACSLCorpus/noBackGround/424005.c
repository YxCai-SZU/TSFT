#include <limits.h>

/*@
    requires ((x) >= -1290 && (x) <= 1290);
    ensures \result == ((x) * (x) * (x));
    assigns \nothing;
*/
int compute_cuber(int x) {
    //@ assert ((x) >= -1290 && (x) <= 1290);
    int result;
    result = x * x * x;
    //@ assert result == ((x) * (x) * (x));
    return result;
}

/*@
    assigns \nothing;
*/
int main() {
    int test_values[5];
    int results[5];
    int i;
    
    test_values[0] = -1290;
    test_values[1] = 1290;
    test_values[2] = 0;
    test_values[3] = -1;
    test_values[4] = 2;
    
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> ((test_values[j]) >= -1290 && (test_values[j]) <= 1290);
        loop invariant \forall integer j; 0 <= j < i ==> results[j] == ((test_values[j]) * (test_values[j]) * (test_values[j]));
        loop assigns i, results[0..4];
    */
    for (i = 0; i < 5; i++) {
        //@ assert ((test_values[i]) >= -1290 && (test_values[i]) <= 1290);
        results[i] = compute_cuber(test_values[i]);
    }
    
    //@ assert results[0] == -1290 * 1290 * 1290;
    //@ assert results[1] == 1290 * 1290 * 1290;
    //@ assert results[2] == 0;
    //@ assert results[3] == -1;
    //@ assert results[4] == 8;
    
    return 0;
}
