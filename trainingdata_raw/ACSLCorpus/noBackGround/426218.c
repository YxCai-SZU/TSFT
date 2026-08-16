#include <stdbool.h>

/*@
    requires \true;
    ensures \true;
*/
void example9(void) {
    int s[5];
    int s_add_10[5];
    int s_sub_10[5];
    int i;
    int max_val;
    int min_val;

    // Initialize s array
    s[0] = 40;
    s[1] = 30;
    s[2] = 20;
    s[3] = 10;
    s[4] = 0;

    // Initialize s_add_10 array
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s_add_10[j] == s[j] + 10;
        loop assigns i, s_add_10[0..4];
        loop variant 5 - i;
    */
    for (i = 0; i < 5; i++) {
        s_add_10[i] = s[i] + 10;
    }

    // Verify s_add_10 values
    //@ assert s_add_10[0] == 50;
    //@ assert s_add_10[1] == 40;
    //@ assert s_add_10[2] == 30;
    //@ assert s_add_10[3] == 20;
    //@ assert s_add_10[4] == 10;

    // Initialize s_sub_10 array
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s_sub_10[j] == s[j] - 10;
        loop assigns i, s_sub_10[0..4];
        loop variant 5 - i;
    */
    for (i = 0; i < 5; i++) {
        s_sub_10[i] = s[i] - 10;
    }

    // Verify s_sub_10 values
    //@ assert s_sub_10[0] == 30;
    //@ assert s_sub_10[1] == 20;
    //@ assert s_sub_10[2] == 10;
    //@ assert s_sub_10[3] == 0;
    //@ assert s_sub_10[4] == -10;

    // Find max value
    max_val = s[0];
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] <= max_val;
        loop invariant \exists integer j; 0 <= j < i && s[j] == max_val;
        loop assigns i, max_val;
        loop variant 5 - i;
    */
    for (i = 1; i < 5; i++) {
        if (s[i] > max_val) {
            max_val = s[i];
        }
    }
    //@ assert max_val == 40;

    // Find min value
    min_val = s[0];
    /*@
        loop invariant 0 <= i <= 5;
        loop invariant \forall integer j; 0 <= j < i ==> s[j] >= min_val;
        loop invariant \exists integer j; 0 <= j < i && s[j] == min_val;
        loop assigns i, min_val;
        loop variant 5 - i;
    */
    for (i = 1; i < 5; i++) {
        if (s[i] < min_val) {
            min_val = s[i];
        }
    }
    //@ assert min_val == 0;
}
