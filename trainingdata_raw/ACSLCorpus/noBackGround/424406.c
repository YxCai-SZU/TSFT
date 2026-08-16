#include <stdbool.h>
#include <stdint.h>

/*@ requires (2 <= (n) && (n) <= 50);
    requires \valid(a + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) && ((a)[i]) <= 50));
    assigns \nothing;
    ensures \result == true <==> (\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 0);
*/
bool func(uint32_t n, int32_t *a) {
    uint32_t count = 0;
    uint32_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((a)[i]) && ((a)[i]) <= 50));
        loop invariant (count > 0) <==> (\exists integer j; 0 <= j < i && a[j] % 2 == 0);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        //@ assert (1 <= (a[i]) && (a[i]) <= 50);
        if (a[i] % 2 == 0) {
            //@ assert a[i] % 2 == 0 && 1 <= a[i] && a[i] <= 50;
            count += 1;
        }
        i += 1;
    }
    //@ assert (count > 0) <==> (\exists integer i; 0 <= i < (n) && (a)[i] % 2 == 0);
    return count > 0;
}
