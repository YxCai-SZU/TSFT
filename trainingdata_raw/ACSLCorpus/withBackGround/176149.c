#include <stddef.h>
#include <limits.h>

/*@ predicate is_max(integer ret, integer a, integer b, integer c) =
      ret >= a && ret >= b && ret >= c &&
      (ret == a || ret == b || ret == c);
*/

/*@
  requires a >= INT_MIN && a <= INT_MAX;
  requires b >= INT_MIN && b <= INT_MAX;
  requires c >= INT_MIN && c <= INT_MAX;
  ensures \result >= a && \result >= b && \result >= c;
  ensures \result == a || \result == b || \result == c;
  assigns \nothing;
*/
int max_of_three(int a, int b, int c)
{
    int ret;
    //@ assert a >= INT_MIN && a <= INT_MAX;
    //@ assert b >= INT_MIN && b <= INT_MAX;
    //@ assert c >= INT_MIN && c <= INT_MAX;
    if (a >= b && a >= c) {
        ret = a;
    } else if (b >= a && b >= c) {
        ret = b;
    } else {
        ret = c;
    }
    //@ assert is_max(ret, a, b, c);
    return ret;
}

/*@ predicate valid_array(int *arr, integer len) =
      len >= 0 && len < 0x10000000;
*/

/*@ predicate count_invariant(integer i, integer len, integer count) =
      i >= 0 && i <= len && count <= i;
*/

/*@
  requires valid_array(list1, len);
  requires \valid(list1 + (0 .. len-1));
  ensures \result <= len;
  assigns \nothing;
*/
size_t count_greater_than(int *list1, size_t len, int threshold)
{
    size_t count = 0;
    size_t i = 0;
    /*@
      loop invariant count_invariant(i, len, count);
      loop invariant \forall integer k; 0 <= k < i ==> (list1[k] > threshold ==> count > 0);
      loop invariant \forall integer k; 0 <= k < i ==> (list1[k] <= threshold ==> count <= i - 1);
      loop invariant valid_array(list1, len);
      loop assigns i, count;
      loop variant len - i;
    */
    while (i < len)
    {
        if (list1[i] > threshold) {
            count += 1;
        }
        i += 1;
    }
    //@ assert count <= len;
    return count;
}
