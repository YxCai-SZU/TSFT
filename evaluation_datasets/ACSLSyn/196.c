#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b, integer c, integer d, integer e, integer k) =
        0 <= a <= 123 &&
        0 <= b <= 123 &&
        0 <= c <= 123 &&
        0 <= d <= 123 &&
        0 <= e <= 123 &&
        0 <= k <= 123 &&
        a < b &&
        b < c &&
        c < d &&
        d < e;

    logic integer distance(integer a, integer e) = e - a;

    lemma dist_calculation:
        \forall integer a, e; distance(a, e) == e - a;

    lemma dist_range:
        \forall integer a, e; 0 <= a <= 123 && 0 <= e <= 123 ==> distance(a, e) <= 123;
*/

bool func_range(unsigned int a, unsigned int b, unsigned int c,
          unsigned int d, unsigned int e, unsigned int k)
{
    unsigned int dist;

    //@ assert a < b && b < c && c < d && d < e;
    dist = e - a;

    //@ assert dist == e - a;
    //@ assert dist <= 123;

    return e - a <= k;
}

/*@ predicate valid_nums(int a, int b) = 
      1 <= a <= 16 && 1 <= b <= 16 && a + b <= 16; */

/*@ lemma max_property: 
      \forall integer a, integer b, integer m; 
      (a > b && m == a) || (a <= b && m == b) ==> 
      (m == a || m == b); */

bool func_max(int n, int *nums) {
    int a;
    int b;
    int max_val;
    
    a = nums[0];
    b = nums[1];
    
    //@ assert valid_nums(a, b);
    
    if (a > b) {
        max_val = a;
    } else {
        max_val = b;
    }
    
    //@ assert max_val == a || max_val == b;
    
    return max_val <= 8;
}

bool validate_packet(unsigned int a, unsigned int b, unsigned int c,
                     unsigned int d, unsigned int e, unsigned int k,
                     int n, int *nums)
{
    bool range_valid = func_range(a, b, c, d, e, k);
    bool size_valid = func_max(n, nums);
    
    //@ assert range_valid == (e - a <= k);
    //@ assert size_valid == (nums[0] <= 8 && nums[1] <= 8);
    
    bool result = range_valid && size_valid;
    
    //@ assert result <==> (e - a <= k && nums[0] <= 8 && nums[1] <= 8);
    
    return result;
}
