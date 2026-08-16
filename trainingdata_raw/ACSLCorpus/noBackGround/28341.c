#include <stdbool.h>
#include <stdlib.h>

/*@
    requires \valid(arr + (0..len-1));
    ensures \result == (len >= 10);
    assigns \nothing;
*/
bool is_at_least_ten_elements(int *arr, int len) {
    return len >= 10;
}

/*@
    requires \valid(vec + (0..9));
    assigns vec[0..9];
*/
void test_is_at_least_ten_elements(int *vec) {
    int i = 0;
    
    /*@
        loop invariant 0 <= i <= 10;
        loop invariant \forall integer j; 0 <= j < i ==> vec[j] == 0;
        loop assigns i, vec[0..9];
        loop variant 10 - i;
    */
    while (i < 10) {
        //@ assert 0 <= i < 10;
        vec[i] = 0;
        i++;
    }
    
    //@ assert i == 10;
    //@ assert ((10) >= 10);
}
