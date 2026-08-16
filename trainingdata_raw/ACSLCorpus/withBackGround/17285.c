#include <stdint.h>

/*@ predicate is_valid_sum(integer v0, integer v1, integer v2, integer result) =
      result == v0 + v2 || result == v1 + v2 || result == v0 + v1;
*/

/*@
  requires \valid(v + (0..2));
  requires 1 <= v[0] <= 20;
  requires 1 <= v[1] <= 20;
  requires 1 <= v[2] <= 20;
  ensures \result >= 0;
  ensures is_valid_sum(v[0], v[1], v[2], \result);
*/
int32_t func(int32_t* v) {
    int32_t answer;
    int32_t v0_plus_v1;
    int32_t v1_plus_v2;
    int32_t v0_plus_v2;

    answer = INT32_MIN;
    v0_plus_v1 = v[0] + v[1];
    v1_plus_v2 = v[1] + v[2];
    v0_plus_v2 = v[0] + v[2];

    //@ assert v0_plus_v1 == v[0] + v[1];
    answer = (v0_plus_v1 > answer) ? v0_plus_v1 : answer;

    //@ assert v1_plus_v2 == v[1] + v[2];
    answer = (v1_plus_v2 > answer) ? v1_plus_v2 : answer;

    //@ assert v0_plus_v2 == v[0] + v[2];
    answer = (v0_plus_v2 > answer) ? v0_plus_v2 : answer;

    //@ assert answer == v[0] + v[2] || answer == v[1] + v[2] || answer == v[0] + v[1];
    return answer;
}
