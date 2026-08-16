#include <stdbool.h>
#include <stddef.h>

/*@
    requires 0 <= n <= len;
    requires (\forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] <= 100);
    ensures \result == true ==> (\exists integer i; 0 <= i < (n) && (arr)[i] == (x));
    ensures \result == false ==> (\forall integer i; 0 <= i < (n) ==> (arr)[i] != (x));
*/
bool contains_element(int *arr, size_t len, size_t n, int x) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] != x;
        loop assigns i;
        loop variant n - i;
    */
    while (i < n && i < len) {
        //@ assert 0 <= i < n && i < len;
        if (arr[i] == x) {
            //@ assert (\exists integer i; 0 <= i < (n) && (arr)[i] == (x));
            return true;
        }
        i++;
    }
    //@ assert (\forall integer i; 0 <= i < (n) ==> (arr)[i] != (x));
    return false;
}
