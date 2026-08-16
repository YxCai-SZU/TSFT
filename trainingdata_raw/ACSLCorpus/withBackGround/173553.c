#include <stddef.h>
#include <limits.h>

/*@
    predicate is_seq(int *arr, integer len) =
        len >= 0 && \valid(arr + (0 .. len-1));

    logic integer seq_first(int *arr, integer len) = arr[0];
    logic integer seq_last(int *arr, integer len) = arr[len-1];

    predicate seq_max(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[i] <= arr[len-1];

    predicate seq_min(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[0] <= arr[i];
*/

/*@
    assigns \nothing;
*/
void example4(void) {
    int s[5];
    int i;
    /*@ loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 10 * j;
        loop assigns i, s[0..4];
    */
    for (i = 0; i < 5; i++) {
        s[i] = 10 * i;
    }
    //@ assert is_seq(&s[0], 5);
    //@ assert s[3] == 30;
    //@ assert seq_first(&s[0], 5) == 0;
    //@ assert seq_last(&s[0], 5) == 40;
    //@ assert seq_max(&s[0], 5);
    //@ assert seq_min(&s[0], 5);
}

/*@
    assigns \nothing;
*/
void example5(void) {
    int s[5] = {2, 4, 6, 8, 10};
    //@ assert is_seq(&s[0], 5);
    //@ assert s[3] == 8;
    //@ assert seq_first(&s[0], 5) == 2;
    //@ assert seq_last(&s[0], 5) == 10;
    //@ assert seq_max(&s[0], 5);
    //@ assert seq_min(&s[0], 5);
}

/*@
    assigns \nothing;
*/
void example6(void) {
    int s[6];
    int i;
    /*@ loop invariant 0 <= i <= 6;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 3 * j;
        loop assigns i, s[0..5];
    */
    for (i = 0; i < 6; i++) {
        s[i] = 3 * i;
    }
    //@ assert is_seq(&s[0], 6);
    //@ assert seq_first(&s[0], 6) == 0;
    //@ assert seq_last(&s[0], 6) == 15;
    //@ assert seq_max(&s[0], 6);
    //@ assert seq_min(&s[0], 6);
}

/*@
    assigns \nothing;
*/
void example7(void) {
    int s[7];
    int i;
    /*@ loop invariant 0 <= i <= 7;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 5 * j;
        loop assigns i, s[0..6];
    */
    for (i = 0; i < 7; i++) {
        s[i] = 5 * i;
    }
    //@ assert is_seq(&s[0], 7);
    //@ assert seq_first(&s[0], 7) == 0;
    //@ assert seq_last(&s[0], 7) == 30;
    //@ assert seq_max(&s[0], 7);
    //@ assert seq_min(&s[0], 7);
}

/*@
    assigns \nothing;
*/
void example8(void) {
    int s[8];
    int i;
    /*@ loop invariant 0 <= i <= 8;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 4 * j;
        loop assigns i, s[0..7];
    */
    for (i = 0; i < 8; i++) {
        s[i] = 4 * i;
    }
    //@ assert is_seq(&s[0], 8);
    //@ assert seq_first(&s[0], 8) == 0;
    //@ assert seq_last(&s[0], 8) == 28;
    //@ assert seq_max(&s[0], 8);
    //@ assert seq_min(&s[0], 8);
}

/*@
    assigns \nothing;
*/
void example9(void) {
    int s[9];
    int i;
    /*@ loop invariant 0 <= i <= 9;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == 2 * j;
        loop assigns i, s[0..8];
    */
    for (i = 0; i < 9; i++) {
        s[i] = 2 * i;
    }
    //@ assert is_seq(&s[0], 9);
    //@ assert seq_first(&s[0], 9) == 0;
    //@ assert seq_last(&s[0], 9) == 16;
    //@ assert seq_max(&s[0], 9);
    //@ assert seq_min(&s[0], 9);
}

/*@
    assigns \nothing;
*/
void example10(void) {
    int s[10];
    int i;
    /*@ loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] == j;
        loop assigns i, s[0..9];
    */
    for (i = 0; i < 10; i++) {
        s[i] = i;
    }
    //@ assert is_seq(&s[0], 10);
    //@ assert seq_first(&s[0], 10) == 0;
    //@ assert seq_last(&s[0], 10) == 9;
    //@ assert seq_max(&s[0], 10);
    //@ assert seq_min(&s[0], 10);
}
