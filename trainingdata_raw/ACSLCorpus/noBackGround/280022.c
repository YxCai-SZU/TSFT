#include <stdbool.h>
#include <stddef.h>

/*@ requires 0 <= len <= 0x80000000;
    ensures \result == 1 <==> (\forall integer i; 0 <= i < (len) / 2 ==> (x)[i] == (x)[(len) - i - 1]);
*/
bool is_palindrome(char *x, int len)
{
    int i = 0;
    //@ ghost int original_len = len;

    /*@ loop invariant 0 <= i <= len / 2;
        loop invariant len == original_len;
        loop invariant \forall integer j; 0 <= j < i ==> x[j] == x[len - j - 1];
        loop invariant 0 <= len <= 0x80000000;
        loop assigns i;
        loop variant len / 2 - i;
    */
    while (i < len / 2) {
        //@ assert 0 <= i < len / 2;
        if (x[i] != x[len - i - 1]) {
            //@ assert !(\forall integer i; 0 <= i < (len) / 2 ==> (x)[i] == (x)[(len) - i - 1]);
            return false;
        }
        //@ assert x[i] == x[len - i - 1];
        i++;
        //@ assert \forall integer j; 0 <= j < i ==> x[j] == x[len - j - 1];
    }

    //@ assert \forall integer j; 0 <= j < len / 2 ==> x[j] == x[len - j - 1];
    //@ assert (\forall integer i; 0 <= i < (len) / 2 ==> (x)[i] == (x)[(len) - i - 1]);
    return true;
}
