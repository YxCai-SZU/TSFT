#include <stdbool.h>

/*@ logic integer square_number(integer x) = x * x; */

/*@
  predicate is_within_bounds(integer n, integer k) =
    1 <= n <= 100 && 1 <= k <= 100;
*/

/*@
  lemma k_square_bounds:
    \forall integer k; 1 <= k <= 100 ==> 1 <= k * k <= 10000;
*/

/*@
  lemma comparison_always_possible:
    \forall integer n, integer k;
      is_within_bounds(n, k) ==> (n >= k * k || n < k * k);
*/

bool func1(int n, int k)
{
    //@ assert is_within_bounds(n, k);
    
    //@ assert 1 <= k * k <= 10000;
    
    //@ assert n >= k * k || n < k * k;
    
    return n >= k * k;
}

/*@
    predicate is_sum_eq(integer a, integer b, integer c) =
        a + b == c || b + c == a || c + a == b || a + b + c == 100;
 */

bool func2(int a, int b, int c)
{
    bool c_popcorn;
    bool m_popcorn;
    bool v_popcorn;
    bool answer;

    c_popcorn = false;
    m_popcorn = false;
    v_popcorn = false;

    if (a + b == c)
        c_popcorn = true;
    if (b + c == a)
        m_popcorn = true;
    if (c + a == b)
        v_popcorn = true;
    if (a + b + c == 100)
    {
        c_popcorn = true;
        m_popcorn = true;
        v_popcorn = true;
    }

    answer = false;
    if (a + b + c <= 100)
    {
        answer = c_popcorn || m_popcorn || v_popcorn || (a + b + c == 100);
    }
    else
    {
        answer = false;
    }

    //@ assert answer == true <==> a + b + c <= 100 && is_sum_eq(a, b, c);

    return answer;
}

/*@
    predicate valid_triangle_property(integer x, integer y, integer z) =
        1 <= x <= 100 && 1 <= y <= 100 && 1 <= z <= 100 &&
        ((x + y + z <= 100 && is_sum_eq(x, y, z)) || 
         (x + y + z > 100 && x >= z * z));
*/

bool complex_scenario(int a, int b, int c)
{
    bool result;
    
    if (a + b + c <= 100)
    {
        result = func2(a, b, c);
    }
    else
    {
        result = func1(a, c);
    }
    
    //@ assert result == true <==> valid_triangle_property(a, b, c);
    
    return result;
}

int main()
{
    return 0;
}
