#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) > 0 && (n) <= 100000 &&
        \valid((aa) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (aa)[i] > 0 && (aa)[i] <= 1000000000);
    ensures \result == true <==> (\forall integer i; 0 <= i < (n) ==> (aa)[i] % 2 == 0);
    assigns \nothing;
*/
bool func(size_t n, int *aa) {
    bool is_all_even = true;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant is_all_even == true <==> (\forall integer i; 0 <= i < index ==> aa[i] % 2 == 0);
        loop assigns index, is_all_even;
        loop variant n - index;
    */
    while (index < n) {
        int a = aa[index];
        
        //@ assert a > 0 && a <= 1000000000;
        
        if (a % 2 != 0) {
            is_all_even = false;
            break;
        }
        
        index++;
    }

    //@ assert is_all_even == true <==> (\forall integer i; 0 <= i < (n) ==> (aa)[i] % 2 == 0);
    return is_all_even;
}
