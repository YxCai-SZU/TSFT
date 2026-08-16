#include <stdbool.h>

/*@ predicate is_negative(integer number) = number < 0; */

/*@
  requires \true;
  assigns \nothing;
  ensures \result == (number < 0);
  ensures \result ==> number < 0;
*/
bool is_negative(long number)
{
    //@ assert number < 0 ==> number < 0;
    return number < 0;
}
