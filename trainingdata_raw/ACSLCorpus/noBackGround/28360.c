#include <stdbool.h>

/*@ requires \valid_read(arr + (0 .. 2));
    requires \forall integer i; 0 <= i <= 2 ==> arr[i] >= 0;
    ensures \result == (arr[0] < arr[1] && arr[1] < arr[2]);
*/
bool is_strictly_increasing_c(int *arr) {
    bool ret;
    //@ assert arr[0] >= 0 && arr[1] >= 0 && arr[2] >= 0;
    ret = arr[0] < arr[1] && arr[1] < arr[2];
    //@ assert ret == (arr[0] < arr[1] && arr[1] < arr[2]);
    return ret;
}

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <= a * b;
    ensures \result == a * b;
*/
unsigned int func_c(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int ret;
    //@ assert a * b <= 10000;
    ret = a * b;
    //@ assert ret <= a * b;
    return ret;
}
