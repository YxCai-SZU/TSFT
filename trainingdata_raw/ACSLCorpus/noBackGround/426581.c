#include <stdbool.h>

/*@ requires len >= 0;
    requires \valid(arr + (0 .. len-1));
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; 0 <= i < (len) && (arr)[i] < (number));
    ensures \result == false <==> !(\exists integer i; 0 <= i < (len) && (arr)[i] < (number));
*/
bool check_less(int *arr, int len, int number) {
    int i = 0;
    bool ret = false;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] >= (number));
        loop assigns i, ret;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert i >= 0 && i < len;
        if (arr[i] < number) {
            ret = true;
            //@ assert (\exists integer i; 0 <= i < (len) && (arr)[i] < (number));
            return ret;
        }
        //@ assert arr[i] >= number;
        i = i + 1;
    }
    //@ assert !(\exists integer i; 0 <= i < (len) && (arr)[i] < (number));
    ret = false;
    return ret;
}
