#include <stdbool.h>
#include <stddef.h>

/*@
    predicate all_positive(int *list, integer len) =
        \forall integer i; 0 <= i < len ==> list[i] > 0;
*/

/*@
    requires 0 <= len < 0x80000000;
    requires \valid_read(list + (0 .. len-1));
    assigns \nothing;
    ensures \result <==> all_positive(list, len);
*/
bool check_all_positive(const int *list, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> list[j] > 0;
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        if (list[i] <= 0) {
            return false;
        }
        i++;
    }
    return true;
}
