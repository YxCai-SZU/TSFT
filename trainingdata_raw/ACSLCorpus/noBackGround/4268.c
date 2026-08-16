#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(a + (0 .. len-1));
    requires ((len) >= 1 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (a)[i] <= 1000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> (((a)[i]) % 2 != 0 || ((a)[i]) % 3 == 0 || ((a)[i]) % 5 == 0));
    assigns \nothing;
*/
bool func(const int *a, size_t len) {
    size_t index = 0;
    bool result = true;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant result == true ==> (\forall integer j; 0 <= j < index ==> ((a[j]) % 2 != 0 || (a[j]) % 3 == 0 || (a[j]) % 5 == 0));
        loop invariant result == false ==> (\exists integer j; 0 <= j < index && !((a[j]) % 2 != 0 || (a[j]) % 3 == 0 || (a[j]) % 5 == 0));
        loop assigns index, result;
        loop variant len - index;
    */
    while (index < len) {
        int value = a[index];
        //@ assert value >= 1 && value <= 1000;
        
        if (value % 2 == 0 && (value % 3 != 0 && value % 5 != 0)) {
            result = false;
            //@ assert !((value) % 2 != 0 || (value) % 3 == 0 || (value) % 5 == 0);
            break;
        }
        //@ assert ((value) % 2 != 0 || (value) % 3 == 0 || (value) % 5 == 0);
        index++;
    }
    
    if (result) {
        //@ assert index == len;
        //@ assert (\forall integer i; 0 <= i < (len) ==> (((a)[i]) % 2 != 0 || ((a)[i]) % 3 == 0 || ((a)[i]) % 5 == 0));
    }
    return result;
}
