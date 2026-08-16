/*@
predicate valid_conditions(integer a, integer b, integer c, integer d) =
    a + 2 == b - 1 &&
    b + 2 == c - 1 &&
    c + 2 == d - 1 &&
    a >= 1 && b >= 1 && c >= 1 && d >= 1;

lemma sum_example_2: \forall integer a, b; a + 2 == b - 1 ==> a + 2 <= b + 1;
*/

#include <stdint.h>

/*@
  requires valid_conditions(a, b, c, d);
  ensures \result == a + b + c + d;
  assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at scope top
    int result;
    
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert c >= 1;
    //@ assert d >= 1;
    
    //@ assert b - 1 == a + 2;
    //@ assert c - 1 == b + 2;
    //@ assert d - 1 == c + 2;
    
    result = a + b + c + d;
    return result;
}

int main()
{
    return 0;
}
