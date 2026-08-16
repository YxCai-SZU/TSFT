#include <stdbool.h>

/*@ predicate is_increasing(integer a, integer b, integer c) =
      a < b && b < c;
*/
/*@ predicate is_decreasing(integer a, integer b, integer c) =
      a > b && b > c;
*/

/*@
  requires \valid_read(s + (0..2));
  requires 1 <= s[0] <= 100;
  requires 1 <= s[1] <= 100;
  requires 1 <= s[2] <= 100;
  ensures \result == true <==> 
          (is_increasing(s[0], s[1], s[2]) || 
           is_decreasing(s[0], s[1], s[2]));
*/
bool func(const long s[3])
{
    bool inc;
    bool dec;
    bool result;

    inc = s[0] < s[1] && s[1] < s[2];
    //@ assert inc == (s[0] < s[1] && s[1] < s[2]);
    
    dec = s[0] > s[1] && s[1] > s[2];
    //@ assert dec == (s[0] > s[1] && s[1] > s[2]);
    
    result = inc || dec;
    return result;
}
