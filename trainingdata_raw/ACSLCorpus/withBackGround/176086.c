#include <stdbool.h>

/*@
    predicate sorted(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

/*@
    requires \valid_read(list1 + (0 .. len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == true <==> sorted(list1, len);
*/
bool is_sorted(const int *list1, unsigned int len) {
    unsigned int i;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant sorted(list1, i + 1);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (list1[i] > list1[i + 1]) {
            return false;
        }
        i += 1;
    }
    return true;
}

/*@
    predicate is_even(integer x) = x % 2 == 0;
*/

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    assigns \nothing;
    ensures \result == true <==> (is_even(a) || is_even(b));
*/
bool func(unsigned int a, unsigned int b) {
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;
    return (a % 2 == 0) || (b % 2 == 0);
}
