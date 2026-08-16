#include <stdbool.h>

/*@ predicate can_distribute_evenly_possible(integer a, integer b, integer c) =
      (a + b == c) || (b + c == a) || (c + a == b);
*/

/*@
  requires 1 <= a && a <= 100;
  requires 1 <= b && b <= 100;
  requires 1 <= c && c <= 100;
  ensures \result == true <==> can_distribute_evenly_possible(a, b, c);
*/
bool can_distribute_evenly(unsigned long long a, unsigned long long b, unsigned long long c) {
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    bool is_possible = (a + b == c) || (b + c == a) || (c + a == b);
    
    //@ assert is_possible == ((a + b == c) || (b + c == a) || (c + a == b));
    return is_possible;
}

/*@ logic integer max_product(integer a, integer b, integer c, integer d) =
      \max(\max(a * c, a * d), \max(b * c, b * d));
*/

/*@ lemma product_bounds:
      \forall integer a, b, c, d;
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100 ==>
        a * c <= 10000 && a * d <= 10000 && b * c <= 10000 && b * d <= 10000;
*/

/*@
  requires 1 <= a && a <= 100;
  requires 1 <= b && b <= 100;
  requires 1 <= c && c <= 100;
  requires 1 <= d && d <= 100;
  ensures \result == a * c || \result == a * d || \result == b * c || \result == b * d;
*/
long long func(long long a, long long b, long long c, long long d) {
    long long max_val;
    long long temp_val;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;
    
    //@ assert a * c <= 10000;
    max_val = a * c;
    
    temp_val = a * d;
    //@ assert a * d <= 10000;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = b * c;
    //@ assert b * c <= 10000;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    temp_val = b * d;
    //@ assert b * d <= 10000;
    if (temp_val > max_val) {
        max_val = temp_val;
    }
    
    //@ assert max_val == a * c || max_val == a * d || max_val == b * c || max_val == b * d;
    return max_val;
}
