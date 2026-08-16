#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= len <= 10;
    requires \valid(arr + (0 .. len-1));
    requires (1 <= (len) <= 10 &&
        \forall integer i; 0 <= i < (len) ==> ((arr)[i] == 0 || (arr)[i] == 1));
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) && i % 2 == 0 ==> (arr)[i] == 0);
    assigns \nothing;
*/
bool func(int *arr, size_t len) {
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= len;
        loop invariant \forall integer i; 0 <= i < index && i % 2 == 0 ==> arr[i] == 0;
        loop invariant (1 <= (len) <= 10 &&
        \forall integer i; 0 <= i < (len) ==> ((arr)[i] == 0 || (arr)[i] == 1));
        loop assigns index;
        loop variant len - index;
    */
    while (index < len) {
        int e = arr[index];
        
        //@ assert e == 0 || e == 1;
        
        if (e != 0 && index % 2 == 0) {
            //@ assert !(\forall integer i; 0 <= i < (len) && i % 2 == 0 ==> (arr)[i] == 0);
            return false;
        }
        
        index++;
    }
    
    //@ assert (\forall integer i; 0 <= i < (len) && i % 2 == 0 ==> (arr)[i] == 0);
    return true;
}
