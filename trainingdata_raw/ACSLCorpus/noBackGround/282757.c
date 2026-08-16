#include <stdbool.h>
#include <stddef.h>

/*@
    requires len < 0x80000000;
    requires \valid_read(arr + (0 .. len-1));
    ensures \result == true ==> (\forall integer j; 0 <= j < (len) ==> (arr)[j] >= 0);
    ensures \result == false ==> (\exists integer j; 0 <= j < (len) && (arr)[j] < 0);
    assigns \nothing;
*/
bool check_value(const int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (arr)[j] >= 0);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < 0) {
            //@ assert (\exists integer j; 0 <= j < (len) && (arr)[j] < 0);
            return false;
        }
        i = i + 1;
    }
    //@ assert (\forall integer j; 0 <= j < (len) ==> (arr)[j] >= 0);
    return true;
}

int main() {
    return 0;
}
