#include <stdbool.h>

/* Original function 1: validates range and computes t >= s */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer div_100(integer x) = x / 100;
    logic integer mod_100(integer x) = x % 100;
    logic integer calc_s(integer y) = y / 5 + y % 5;

    lemma s_bound: \forall integer y; 0 <= y <= 99 ==> calc_s(y) <= 24;
*/

bool func1(unsigned int x) {
    unsigned int t;
    unsigned int Y;
    unsigned int s = 0;
    unsigned int temp_Y;

    //@ assert is_valid_range(x);
    
    t = x / 100;
    Y = x % 100;
    temp_Y = Y;

    s += temp_Y / 5;
    temp_Y %= 5;
    s += temp_Y;

    //@ assert t == div_100(x);
    //@ assert Y == mod_100(x);
    //@ assert s == calc_s(Y);
    //@ assert s <= 24;

    return t >= s;
}

/* Original function 2: checks condition holds */
/*@
    predicate condition_holds(integer a, integer b, integer c, integer k) =
        (a + b + c) >= k ||
        (a + b + c - a) >= k ||
        (a + b + c - b) >= k ||
        (a + b + c - c) >= k ||
        (a + b + c - a - b) >= k ||
        (a + b + c - a - c) >= k ||
        (a + b + c - b - c) >= k ||
        (a + b + c - a - b - c) >= k;
*/

bool func2(int a, int b, int c, int k)
{
    int count;
    int n;
    
    count = 0;
    n = k;
    
    //@ assert (a + b + c) >= k <==> (a + b + c) >= k;
    
    if ((a + b + c) >= k)
    {
        count += 1;
        //@ assert count == 1;
    }
    else
    {
        //@ assert count == 0;
    }
    
    //@ assert count > 0 <==> condition_holds(a, b, c, k);
    
    return count > 0;
}

/* Original function 3: compares product with threshold */
/*@
    predicate valid_params(integer n, integer a, integer b) =
        1 <= n && n <= 20 &&
        1 <= a && a <= 50 &&
        1 <= b && b <= 50;

    logic integer product(integer n, integer a) = n * a;

    predicate result_condition(integer n, integer a, integer b, bool r) =
        r == (product(n, a) < b);
*/

bool func3(int n, int a, int b)
{
    //@ assert 1 * 1 <= n * a && n * a <= 20 * 50;
    return (n * a) < b;
}

/* Original function 4: validates range and checks ordering condition */
/*@ predicate is_valid_range2(integer a, integer b, integer c, integer k) =
      1 <= a <= 7 && 1 <= b <= 7 && 1 <= c <= 7 && 1 <= k <= 7;
*/

/*@ logic integer distance_sum(integer a, integer b, integer c) =
      (b - a) + (c - b);
*/

/*@ lemma condition_equivalence:
      \forall integer a, b, c, k;
      is_valid_range2(a, b, c, k) ==>
      ((a < b && b < c) || (k >= distance_sum(a, b, c) + 1) || (a == b) || (b == c)) ==
      ((a < b && b < c) || (k >= (b - a) + (c - b) + 1) || (a == b) || (b == c));
*/

bool func4(int a, int b, int c, int k) {
    bool is_ok = false;
    
    //@ assert is_valid_range2(a, b, c, k);
    
    if (a < b && b < c) {
        is_ok = true;
    } else if (k >= (b - a) + (c - b) + 1) {
        is_ok = true;
    } else if (a == b || b == c) {
        is_ok = true;
    }
    
    //@ assert is_ok == true <==> (a < b && b < c || k >= (b - a) + (c - b) + 1 || a == b || b == c);
    
    return is_ok;
}

/* Synthesized function: Resource allocation validation in a manufacturing system
   Scenario: A factory processes raw material batches (x) where x/100 determines the batch count
   and x%100 determines the resource score. Three components (a,b,c) with resource requirements (k)
   are checked for feasibility. The system validates if the batch count meets resource threshold,
   if component combinations satisfy resource constraints, if product demand is below capacity,
   and if production sequence conditions are met.
*/
bool manufacturing_resource_validator(unsigned int x, int a, int b, int c, int k,
                                       int n, int a2, int b2,
                                       int a3, int b3, int c3, int k3)
{
    bool batch_ok = func1(x);
    bool components_ok = func2(a, b, c, k);
    bool demand_ok = func3(n, a2, b2);
    bool sequence_ok = func4(a3, b3, c3, k3);
    
    bool result = batch_ok && components_ok && demand_ok && sequence_ok;
    
    //@ assert result == true <==> (div_100(x) >= calc_s(mod_100(x))) && condition_holds(a, b, c, k) && (product(n, a2) < b2) && (a3 < b3 && b3 < c3 || k3 >= (b3 - a3) + (c3 - b3) + 1 || a3 == b3 || b3 == c3);
    
    return result;
}
