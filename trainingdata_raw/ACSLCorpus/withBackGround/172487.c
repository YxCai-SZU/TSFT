#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_within_range{L}(unsigned int *s, size_t len, unsigned int lower, unsigned int upper) =
        \forall size_t i; 0 <= i < len ==> (s[i] >= lower && s[i] <= upper);

    predicate is_strictly_increasing{L}(unsigned int *s, size_t len) =
        \forall size_t i; 0 <= i < len - 1 ==> s[i] < s[i + 1];

    predicate is_strictly_decreasing{L}(unsigned int *s, size_t len) =
        \forall size_t i; 0 <= i < len - 1 ==> s[i] > s[i + 1];

    predicate is_sorted{L}(unsigned int *s, size_t len) =
        is_strictly_increasing(s, len) || is_strictly_decreasing(s, len);
*/

/*@
    requires \valid_read(v + (0 .. len-1));
    requires is_within_range(v, len, lower, upper);
    requires is_sorted(v, len);
    ensures \result == true;
*/
bool func(unsigned int *v, size_t len, unsigned int lower, unsigned int upper)
{
    //@ assert is_within_range(v, len, lower, upper);
    //@ assert is_sorted(v, len);
    return true;
}
