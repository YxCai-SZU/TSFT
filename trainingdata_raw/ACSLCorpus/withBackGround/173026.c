#include <stdbool.h>

/*@ predicate is_valid_month(integer m) = 1 <= m && m <= 12; */
/*@ predicate is_valid_day(integer d) = 1 <= d && d <= 31; */
/*@ predicate is_special_month(integer m) = 
      m == 2 || m == 4 || m == 7 || m == 9 || m == 11 || m == 1; */

/*@ requires \valid(v + (0..1));
    requires is_valid_month(v[0]) && is_valid_day(v[1]);
    ensures \result == (v[0] == 2 || v[0] == 4 || v[0] == 7 || v[0] == 9 || v[0] == 11 || v[0] == 1);
    assigns \nothing;
 */
bool func(unsigned int v[2]) {
    //@ assert is_valid_month(v[0]);
    //@ assert is_valid_day(v[1]);
    return v[0] == 2 || v[0] == 4 || v[0] == 7 || v[0] == 9 || v[0] == 11 || v[0] == 1;
}
