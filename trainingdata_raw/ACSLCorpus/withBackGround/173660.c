#include <stdbool.h>

/*@ predicate is_valid_array(int* a, integer len) =
      len == 3 &&
      1 <= a[0] && a[0] <= 100 &&
      1 <= a[1] && a[1] <= 100 &&
      1 <= a[2] && a[2] <= 100;
*/

/*@ logic integer sum_two(integer a, integer b) = a + b; */

/*@ logic integer total_sum(int* a, integer len) =
      a[0] + a[1] + a[2]; */

/*@ lemma sum_bounds:
      \forall int* a, integer len;
      is_valid_array(a, len) ==>
      sum_two(a[0], a[1]) >= 0 &&
      sum_two(a[0], a[1]) <= total_sum(a, len) &&
      sum_two(a[1], a[2]) >= 0 &&
      sum_two(a[1], a[2]) <= total_sum(a, len) &&
      sum_two(a[2], a[0]) >= 0 &&
      sum_two(a[2], a[0]) <= total_sum(a, len); */

/*@ lemma ans_property:
      \forall int* a, integer len, integer ans;
      is_valid_array(a, len) &&
      (ans == sum_two(a[0], a[1]) ||
       ans == sum_two(a[1], a[2]) ||
       ans == sum_two(a[2], a[0])) ==>
      ans >= 0 && ans <= total_sum(a, len); */

/*@ requires 
      \valid(v + (0 .. 2)) &&
      is_valid_array(v, 3);
    ensures
      \result >= 0 &&
      \result <= v[0] + v[1] + v[2] &&
      (\result == v[0] + v[1] ||
       \result == v[1] + v[2] ||
       \result == v[2] + v[0]); */
int func(int* v)
{
    int ans;
    int i;
    
    ans = v[0] + v[1];
    
    i = 0;
    /*@ loop invariant 
          0 <= i <= 3 &&
          is_valid_array(v, 3) &&
          ans >= 0 &&
          ans <= v[0] + v[1] + v[2];
        loop assigns i;
        loop variant 3 - i; */
    while (i < 3)
    {
        i = i + 1;
    }
    
    //@ assert ans == v[0] + v[1];
    
    if (ans < v[1] + v[2])
    {
        ans = v[1] + v[2];
    }
    
    //@ assert ans == v[0] + v[1] || ans == v[1] + v[2];
    
    i = 0;
    /*@ loop invariant 
          0 <= i <= 3 &&
          is_valid_array(v, 3) &&
          ans >= 0 &&
          ans <= v[0] + v[1] + v[2];
        loop assigns i;
        loop variant 3 - i; */
    while (i < 3)
    {
        i = i + 1;
    }
    
    if (ans < v[2] + v[0])
    {
        ans = v[2] + v[0];
    }
    
    //@ assert ans == v[0] + v[1] || ans == v[1] + v[2] || ans == v[2] + v[0];
    
    return ans;
}
