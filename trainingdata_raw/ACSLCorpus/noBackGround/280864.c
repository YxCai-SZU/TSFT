#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((n) >= 2 && (n) <= 100000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (aa)[i] && (aa)[i] <= 1000000000);
    ensures \result == true <==> (\exists integer i; 0 <= i < n && aa[i] % 2 == 0);
    assigns \nothing;
*/
bool func(size_t n, int *aa) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant count <= index;
        loop invariant ((n) >= 2 && (n) <= 100000 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (aa)[i] && (aa)[i] <= 1000000000);
        loop invariant index > 0 ==> (count > 0 <==> (\exists integer i; 0 <= i < (index) && (aa)[i] % 2 == 0));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        int a = aa[index];
        if (a % 2 == 0) {
            count += 1;
        }
        index += 1;
    }
    
    bool result = count > 0;
    //@ assert result == (count > 0);
    return result;
}
