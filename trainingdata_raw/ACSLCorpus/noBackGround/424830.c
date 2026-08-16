#include <stdbool.h>

/*@ requires k >= 1 && k <= 1000000000;
    requires \valid(test_tup + (0 .. 4));
    requires ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (test_tup)[i] && (test_tup)[i] <= 123 &&
    (\forall integer i; 0 <= i < ((5))-1 ==> ((test_tup))[i] < ((test_tup))[i+1]));
    ensures \result == true <==> \exists integer i; 0 <= i < 5 && test_tup[i] == k;
    assigns \nothing;
*/
bool check_k(int *test_tup, int k) {
    int i = 0;
    
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> test_tup[j] != k;
        loop invariant ((5) == 5 &&
    \forall integer i; 0 <= i < (5) ==> 0 <= (test_tup)[i] && (test_tup)[i] <= 123 &&
    (\forall integer i; 0 <= i < ((5))-1 ==> ((test_tup))[i] < ((test_tup))[i+1]));
        loop invariant k >= 1 && k <= 1000000000;
        loop assigns i;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (test_tup[i] == k) {
            return true;
        }
        i++;
    }
    return false;
}
