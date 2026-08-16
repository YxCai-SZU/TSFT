#include <stdbool.h>

/*@ predicate strictly_increasing(integer a, integer b, integer c) =
      a < b && b < c;
    predicate strictly_decreasing(integer a, integer b, integer c) =
      a > b && b > c;
    predicate all_equal(integer a, integer b, integer c) =
      a == b && b == c;
    predicate k_positive_and_peak(integer a, integer b, integer c, integer k) =
      k > 0 && ( (b > a && c <= b) || (b < a && c >= b) );
    predicate result_condition(integer a, integer b, integer c, integer k) =
      strictly_increasing(a,b,c) ||
      strictly_decreasing(a,b,c) ||
      all_equal(a,b,c) ||
      k_positive_and_peak(a,b,c,k);
*/

/*@
  requires 1 <= a <= 7;
  requires 1 <= b <= 7;
  requires 1 <= c <= 7;
  requires 1 <= k <= 7;
  ensures \result == true <==> result_condition(a,b,c,k);
*/
bool func(int a, int b, int c, int k)
{
    bool result = false;
    
    //@ assert 1 <= a <= 7 && 1 <= b <= 7 && 1 <= c <= 7 && 1 <= k <= 7;
    
    if ((a < b && b < c) || (a > b && b > c) || (a == b && b == c))
    {
        //@ assert strictly_increasing(a,b,c) || strictly_decreasing(a,b,c) || all_equal(a,b,c);
        result = true;
    }
    else if (k > 0)
    {
        if (b > a && c <= b)
        {
            //@ assert k_positive_and_peak(a,b,c,k);
            result = true;
        }
        else if (b < a && c >= b)
        {
            //@ assert k_positive_and_peak(a,b,c,k);
            result = true;
        }
    }
    
    //@ assert result == true <==> result_condition(a,b,c,k);
    return result;
}
