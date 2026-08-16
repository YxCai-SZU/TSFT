#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000);
    ensures ((\result) == (((a)) + ((b)) + ((c)) + ((d))) || (\result) == (((a)) + ((b)) + ((c)) - ((d))) || (\result) == (((a)) + ((b)) - ((c)) + ((d))) ||
        (\result) == (((a)) - ((b)) + ((c)) + ((d))) || (\result) == (-((a)) + ((b)) + ((c)) + ((d))) || (\result) == (((a)) + ((b)) - ((c)) - ((d))) ||
        (\result) == (((a)) - ((b)) + ((c)) - ((d))) || (\result) == (-((a)) + ((b)) + ((c)) - ((d))) || (\result) == (((a)) + ((b)) + ((c)) + ((d))));
*/
int func(int a, int b, int c, int d) {
    int s[8];
    int max_val;
    int i;

    s[0] = a + b + c + d;
    s[1] = a + b + c - d;
    s[2] = a + b - c + d;
    s[3] = a - b + c + d;
    s[4] = -a + b + c + d;
    s[5] = a + b - c - d;
    s[6] = a - b + c - d;
    s[7] = -a + b + c - d;

    max_val = s[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= 8;
        loop invariant \exists integer j; 0 <= j < i && max_val == s[j];
        loop invariant \forall integer k; 0 <= k < i ==> max_val >= s[k];
        loop invariant s[0] == a + b + c + d;
        loop invariant s[1] == a + b + c - d;
        loop invariant s[2] == a + b - c + d;
        loop invariant s[3] == a - b + c + d;
        loop invariant s[4] == -a + b + c + d;
        loop invariant s[5] == a + b - c - d;
        loop invariant s[6] == a - b + c - d;
        loop invariant s[7] == -a + b + c - d;
        loop invariant (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000);
        loop assigns i, max_val;
    */
    while (i < 8) {
        //@ assert 0 <= i < 8;
        if (s[i] > max_val) {
            max_val = s[i];
        }
        i = i + 1;
    }
    //@ assert ((max_val) == (((a)) + ((b)) + ((c)) + ((d))) || (max_val) == (((a)) + ((b)) + ((c)) - ((d))) || (max_val) == (((a)) + ((b)) - ((c)) + ((d))) ||         (max_val) == (((a)) - ((b)) + ((c)) + ((d))) || (max_val) == (-((a)) + ((b)) + ((c)) + ((d))) || (max_val) == (((a)) + ((b)) - ((c)) - ((d))) ||         (max_val) == (((a)) - ((b)) + ((c)) - ((d))) || (max_val) == (-((a)) + ((b)) + ((c)) - ((d))) || (max_val) == (((a)) + ((b)) + ((c)) + ((d))));
    return max_val;
}
