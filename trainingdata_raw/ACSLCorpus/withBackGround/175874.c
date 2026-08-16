#include <stdint.h>
#include <stdbool.h>

/*@ predicate call_requires(integer x) = x * x < 4294967295; */

/*@ predicate call_ensures(integer x, integer result) = result == x * x; */

/*@
  requires call_requires(x);
  ensures \result == x * x;
  assigns \nothing;
*/
uint32_t square_number(uint32_t x)
{
    uint32_t res;
    res = x * x;
    //@ assert res == x * x;
    return res;
}

/*@
  requires call_requires(val);
  requires \forall integer x, integer result; call_ensures(x, result) ==> result == x * x;
  ensures \result == val * val;
  assigns \nothing;
*/
uint32_t apply_square_function(uint32_t val)
{
    uint32_t res;
    res = square_number(val);
    //@ assert res == val * val;
    return res;
}

int main()
{
    uint32_t a;
    uint32_t result;
    
    a = 5;
    result = apply_square_function(a);
    //@ assert result == 25;
    
    return 0;
}
