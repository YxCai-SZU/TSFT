#include <stdbool.h>

/*@ predicate sorted(int *arr, integer len) =
      \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

/*@ lemma sorted_helper:
      \forall int *arr, integer len;
      len > 1 ==>
      (sorted(arr, len) <==>
        (\forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1]));
*/

/*@ requires \valid(listval + (0 .. len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == true <==> sorted(listval, len);
*/
bool is_sorted(int *listval, int len) {
    int i = 0;
    /*@ loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> listval[j] <= listval[j + 1];
        loop invariant len > 1;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (listval[i] > listval[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    assigns \nothing;
    ensures \result == true <==> (a < b && b < c);
*/
bool func(int a, int b, int c) {
    //@ assert 1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;
    return a < b && b < c;
}

/*@ requires \valid(listval + (0 .. len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == true <==> sorted(listval, len);
*/
bool is_sorted_helper(int *listval, int len) {
    int i = 0;
    /*@ loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> listval[j] <= listval[j + 1];
        loop invariant len > 1;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (listval[i] > listval[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}
