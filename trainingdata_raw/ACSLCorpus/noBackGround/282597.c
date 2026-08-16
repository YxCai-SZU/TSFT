#include <stddef.h>

/*@
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == len;
*/
size_t seq_len(int *arr, size_t len) {
    return len;
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires 0 <= idx && idx < len;
    assigns \nothing;
    ensures \result == arr[idx];
*/
int seq_index(int *arr, size_t len, size_t idx) {
    return arr[idx];
}

/*@
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == (len == 4);
*/
int test5_seq2_len(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (len == 4);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 4;
    assigns \nothing;
    ensures \result == (len + 1 == 5);
*/
int test5_pushed_seq_len(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (len + 1 == 5);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 5;
    assigns \nothing;
    ensures \result == (len == 5);
*/
int test5_reversed_seq_len(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (len == 5);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 5;
    assigns \nothing;
    ensures \result == (arr[0] == 25 && arr[1] == 15 && arr[2] == 10 && arr[3] == 12 && arr[4] == 0);
*/
int test5_reversed_seq_content(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (arr[0] == 25 && arr[1] == 15 && arr[2] == 10 && arr[3] == 12 && arr[4] == 0);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 5;
    assigns \nothing;
    ensures \result == 0;
*/
int test5_min_val(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return 0;
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 5;
    assigns \nothing;
    ensures \result == (arr[0] == 90 && arr[1] == 80 && arr[2] == 70 && arr[3] == 60 && arr[4] == 50);
*/
int create_and_reverse_original(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (arr[0] == 90 && arr[1] == 80 && arr[2] == 70 && arr[3] == 60 && arr[4] == 50);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 5;
    assigns \nothing;
    ensures \result == (arr[0] == 50 && arr[1] == 60 && arr[2] == 70 && arr[3] == 80 && arr[4] == 90);
*/
int create_and_reverse_reversed(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (arr[0] == 50 && arr[1] == 60 && arr[2] == 70 && arr[3] == 80 && arr[4] == 90);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 3;
    assigns \nothing;
    ensures \result == (len == 3);
*/
int create_three_elements_len(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (len == 3);
}

/*@
    requires \valid(arr + (0 .. len-1));
    requires len == 3;
    assigns \nothing;
    ensures \result == (arr[0] == 0 && arr[1] == 3 && arr[2] == 6);
*/
int create_three_elements_content(int *arr, size_t len) {
    //@ assert (\valid((arr) + (0 .. (len)-1)));
    return (arr[0] == 0 && arr[1] == 3 && arr[2] == 6);
}
