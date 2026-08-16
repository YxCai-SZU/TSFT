#include <stdbool.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \exists integer i; 0 <= i < len && \result == arr[i];
    ensures \forall integer i; 0 <= i < len ==> \result >= arr[i];
*/
int find_max(int *arr, int len) {
    int max;
    int i;
    max = arr[0];
    i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant (\exists integer k; 0 <= k < (i) && (arr)[k] == (max));
        loop invariant (\forall integer k; 0 <= k < (i) ==> (max) >= (arr)[k]);
        loop assigns max, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] > max) {
            max = arr[i];
        }
        i = i + 1;
    }
    return max;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    assigns \nothing;
    ensures \result == (a < b && b < c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool result = a < b && b < c;
    //@ assert result == (a < b && b < c);
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    assigns \nothing;
    ensures \result == (a < b && b < c);
*/
bool func2(unsigned int a, unsigned int b, unsigned int c) {
    bool result = a < b && b < c;
    //@ assert !(a < b && b < c) ==> result == false;
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    assigns \nothing;
    ensures \result == (a < b && b < c);
*/
bool func3(unsigned int a, unsigned int b, unsigned int c) {
    bool result = a < b && b < c;
    //@ assert a < b ==> (b < c ==> result == true);
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    assigns \nothing;
    ensures \result == (a < b && b < c);
*/
bool func4(unsigned int a, unsigned int b, unsigned int c) {
    bool result = a < b && b < c;
    //@ assert b < c ==> (a < b ==> result == true);
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    assigns \nothing;
    ensures \result == (a < b && b < c);
*/
bool func5(unsigned int a, unsigned int b, unsigned int c) {
    bool result = a < b && b < c;
    //@ assert a >= b ==> result == false;
    return result;
}

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    assigns \nothing;
    ensures \result == (a < b && b < c);
*/
bool func6(unsigned int a, unsigned int b, unsigned int c) {
    bool result = a < b && b < c;
    //@ assert b >= c ==> result == false;
    return result;
}
