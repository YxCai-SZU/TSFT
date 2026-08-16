#include <stdbool.h>
#include <stddef.h>

/*@
    requires n > 0;
    requires \valid_read(vec + (0 .. n-1));
    assigns \nothing;
    ensures \result == true <==> (\forall integer j; 0 <= j < (n) ==>
            ((vec)[j] % 2 == 0 ==> (vec)[j] % 3 == 0 || (vec)[j] % 5 == 0));
*/
bool func(size_t n, size_t *vec) {
    bool flag = true;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n;
        loop invariant flag == true <==> (\forall integer j; 0 <= j < (i) ==>
            ((vec)[j] % 2 == 0 ==> (vec)[j] % 3 == 0 || (vec)[j] % 5 == 0));
        loop assigns i, flag;
        loop variant n - i;
    */
    while (i < n) {
        size_t value = vec[i];
        if (value % 2 == 0) {
            if (value % 3 != 0 && value % 5 != 0) {
                flag = false;
            }
        }
        i++;
    }
    return flag;
}
