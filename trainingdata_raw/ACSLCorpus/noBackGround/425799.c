#include <stdbool.h>

/*@ requires \valid_read(arr + (0 .. len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == true ==> (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    ensures \result == false ==> (\exists integer i; 0 <= i < (len) - 1 && (arr)[i] > (arr)[i + 1]);
*/
bool is_sorted(int *arr, int len) {
    int i = 0;
    /*@ loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] > arr[i + 1]) {
            //@ assert (\exists integer i; 0 <= i < (len) - 1 && (arr)[i] > (arr)[i + 1]);
            return false;
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    return true;
}

/*@ requires 1 <= n <= 20;
    requires 1 <= a <= 50;
    requires 1 <= b <= 50;
    ensures \result == n * a || \result == b;
    ensures \result <= b;
*/
int func(int n, int a, int b) {
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert n * a <= 20 * 50;
    
    int product = n * a;
    if (product < b) {
        //@ assert product <= b;
        return product;
    } else {
        //@ assert b <= b;
        return b;
    }
}
