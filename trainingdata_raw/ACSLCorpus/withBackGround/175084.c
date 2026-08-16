#include <stdbool.h>
#include <stddef.h>

/*@
  predicate valid_index(integer i, integer len) = 0 <= i < len;
  predicate valid_range(integer val) = 1 <= val <= 1000000000;
  predicate valid_array(int* arr, integer len) =
    len >= 3 &&
    \forall integer i; 0 <= i < len ==> valid_range(arr[i]);
*/

/*@
  logic integer is_increasing(integer a, integer b, integer c) = (a < b && b < c) ? 1 : 0;
  logic integer is_decreasing(integer a, integer b, integer c) = (a > b && b > c) ? 1 : 0;
*/

/*@
  lemma index_0_valid: \forall int* arr, integer len; valid_array(arr, len) ==> valid_index(0, len);
  lemma index_1_valid: \forall int* arr, integer len; valid_array(arr, len) ==> valid_index(1, len);
  lemma index_2_valid: \forall int* arr, integer len; valid_array(arr, len) ==> valid_index(2, len);
*/

/*@
  requires valid_array(s, len);
  ensures \result == (is_increasing(s[0], s[1], s[2]) || is_decreasing(s[0], s[1], s[2]));
  assigns \nothing;
*/
bool func(int* s, int len) {
    int first;
    int second;
    int third;
    bool is_inc;
    bool is_dec;
    bool result;

    if (len < 3) {
        return false;
    }

    //@ assert valid_array(s, len);
    //@ assert valid_index(0, len);
    first = s[0];
    //@ assert valid_index(1, len);
    second = s[1];
    //@ assert valid_index(2, len);
    third = s[2];

    //@ assert first == s[0];
    //@ assert second == s[1];
    //@ assert third == s[2];

    is_inc = first < second && second < third;
    is_dec = first > second && second > third;

    //@ assert is_inc == (is_increasing(s[0], s[1], s[2]) != 0);
    //@ assert is_dec == (is_decreasing(s[0], s[1], s[2]) != 0);

    result = is_inc || is_dec;
    //@ assert result == (is_increasing(s[0], s[1], s[2]) || is_decreasing(s[0], s[1], s[2]));
    return result;
}
