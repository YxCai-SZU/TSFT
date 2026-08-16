#include <stdbool.h>
#include <stddef.h>

/*@
    requires 2 <= n && n <= 200000;
    requires \valid_read(numbers + (0 .. n-1));
    requires ((n) >= 2 && (n) <= 200000 &&
        \forall integer k; 0 <= k < (n) ==> -1000000000 <= (numbers)[k] <= 1000000000);
    assigns \nothing;
    ensures \result == true <==> \exists integer j; 0 <= j < n && numbers[j] != 0;
*/
bool func(size_t n, const int numbers[]) {
    bool flag = false;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == false ==> (\forall integer j; 0 <= j < (i) ==> (numbers)[j] == 0);
        loop invariant flag == true ==> (\exists integer j; 0 <= j < (i) && (numbers)[j] != 0);
        loop invariant ((n) >= 2 && (n) <= 200000 &&
        \forall integer k; 0 <= k < (n) ==> -1000000000 <= (numbers)[k] <= 1000000000);
        loop assigns flag, i;
        loop variant n - i;
    */
    while (i < n) {
        if (numbers[i] != 0) {
            flag = true;
            break;
        }
        i++;
    }

    //@ assert flag == true <==> \exists integer j; 0 <= j < n && numbers[j] != 0;
    return flag;
}
