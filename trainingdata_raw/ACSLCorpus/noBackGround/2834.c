#include <stdbool.h>

/*@
    requires \valid_read(test_tup + (0..2*len-1));
    requires len >= 0;
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; (0) <= i < (len) &&
        ((\at((test_tup)[2*i], Here)) == ((k)) || (\at((test_tup)[2*i+1], Here)) == ((k))));
*/
bool check_k(int *test_tup, int len, int k) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> !((test_tup[2*j]) == (k) || (test_tup[2*j+1]) == (k));
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        int a = test_tup[2*i];
        int b = test_tup[2*i+1];
        if (a == k || b == k) {
            //@ assert ((a) == (k) || (b) == (k));
            return true;
        }
        i++;
    }
    return false;
}
