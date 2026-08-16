#include <stdbool.h>
#include <stddef.h>

/*@ requires n == len;
    requires 1 <= n;
    requires 1 <= len;
    requires (\forall integer i; 0 <= i < (len) ==> (1 <= (a)[i] && (a)[i] <= 1000));
    requires \valid(a + (0 .. len-1));
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> 
        ((a)[i] % 2 == 0 ==> ((a)[i] % 3 == 0 || (a)[i] % 5 == 0)));
    assigns \nothing;
 */
bool func(size_t n, int *a, size_t len) {
    size_t i = 0;
    bool res = true;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant res == true <==> 
          \forall integer j; 0 <= j < i ==> 
            (a[j] % 2 == 0 ==> (a[j] % 3 == 0 || a[j] % 5 == 0));
        loop invariant 1 <= n;
        loop invariant 1 <= len;
        loop invariant (\forall integer i; 0 <= i < (len) ==> (1 <= (a)[i] && (a)[i] <= 1000));
        loop assigns i, res;
        loop variant len - i;
    */
    while (i < len) {
        int num = a[i];
        if (num % 2 == 0) {
            bool is_divisible_by_3 = (num % 3 == 0);
            bool is_divisible_by_5 = (num % 5 == 0);
            if (!(is_divisible_by_3 || is_divisible_by_5)) {
                res = false;
            }
        }
        i++;
    }
    return res;
}
