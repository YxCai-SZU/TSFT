#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(xs + (0 .. len-1));
    requires len >= 1;
    requires \forall integer i; 0 <= i < len ==> 1 <= xs[i] <= 1000000000;
    assigns \nothing;
    ensures \result == true <==> \forall integer i; 0 <= i < len ==> xs[i] % 2 == 0;
*/
bool func(size_t *xs, size_t len) {
    bool all_even = true;
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant all_even == true <==> (\forall integer j; 0 <= j < (i) ==> (xs)[j] % 2 == 0);
        loop assigns i, all_even;
        loop variant len - i;
    */
    while (i < len) {
        if (xs[i] % 2 != 0) {
            all_even = false;
        }
        i++;
    }
    return all_even;
}

int main() {
    return 0;
}
