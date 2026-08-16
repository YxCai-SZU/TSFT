#include <stdbool.h>

/*@ predicate is_valid_range(integer a, integer b, integer c, integer d, integer e) =
   0 <= a <= 123 && 0 <= b <= 123 && 0 <= c <= 123 && 
   0 <= d <= 123 && 0 <= e <= 123 &&
   a < b && b < c && c < d && d < e;
*/

/*@ logic integer abs_diff(integer x, integer y) =
   x > y ? x - y : y - x;
*/

/*@ lemma diff_property: 
   \forall integer a, b, c, d, e, k;
   is_valid_range(a,b,c,d,e) && 0 <= k <= 123 ==>
   (abs_diff(a,b) <= k && abs_diff(b,c) <= k && 
    abs_diff(c,d) <= k && abs_diff(d,e) <= k) ==>
   (b - a <= k && c - b <= k && d - c <= k && e - d <= k);
*/

/*@ requires is_valid_range(a,b,c,d,e);
    requires 0 <= k <= 123;
    ensures \result == true <==> 
            (b - a <= k && c - b <= k && d - c <= k && e - d <= k);
*/
bool func(int a, int b, int c, int d, int e, int k) {
    int x;
    int y;
    int z;
    int w;
    
    //@ assert a < b && b < c && c < d && d < e;
    
    x = a > b ? a - b : b - a;
    y = b > c ? b - c : c - b;
    z = c > d ? c - d : d - c;
    w = d > e ? d - e : e - d;
    
    //@ assert x == abs_diff(a,b);
    //@ assert y == abs_diff(b,c);
    //@ assert z == abs_diff(c,d);
    //@ assert w == abs_diff(d,e);
    
    if (x <= k && y <= k && z <= k && w <= k) {
        //@ assert b - a <= k && c - b <= k && d - c <= k && e - d <= k;
        return true;
    } else {
        //@ assert x > k || y > k || z > k || w > k;
        return false;
    }
}
