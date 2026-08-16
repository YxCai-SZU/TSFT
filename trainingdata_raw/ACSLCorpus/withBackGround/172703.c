#include <stdbool.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;
    predicate result_valid(integer r, integer a, integer b, integer c, integer d) =
        r == a + c || r == a + d || r == b + c || r == b + d;
    predicate result_range(integer r) = -200 <= r <= 200;
*/

/*@
    logic integer sum_ac(integer a, integer c) = a + c;
    logic integer sum_ad(integer a, integer d) = a + d;
    logic integer sum_bc(integer b, integer c) = b + c;
    logic integer sum_bd(integer b, integer d) = b + d;
*/

/*@
    lemma sum_range:
        \forall integer a, b, c, d;
            in_range(a) && in_range(b) && in_range(c) && in_range(d) ==>
            -200 <= sum_ac(a, c) <= 200 &&
            -200 <= sum_ad(a, d) <= 200 &&
            -200 <= sum_bc(b, c) <= 200 &&
            -200 <= sum_bd(b, d) <= 200;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c) && in_range(d);
    ensures result_valid(\result, a, b, c, d) && result_range(\result);
*/
int func(int a, int b, int c, int d)
{
    int v[4];
    int min_value;
    int i;
    
    //@ assert -100 <= a <= 100;
    //@ assert -100 <= b <= 100;
    //@ assert -100 <= c <= 100;
    //@ assert -100 <= d <= 100;
    
    v[0] = a + c;
    v[1] = a + d;
    v[2] = b + c;
    v[3] = b + d;
    
    //@ assert v[0] == sum_ac(a, c);
    //@ assert v[1] == sum_ad(a, d);
    //@ assert v[2] == sum_bc(b, c);
    //@ assert v[3] == sum_bd(b, d);
    
    min_value = v[0];
    i = 1;
    
    /*@
        loop invariant 0 <= i <= 4;
        loop invariant \exists integer j; 0 <= j < i && min_value == v[j];
        loop invariant \forall integer k; 0 <= k < i ==> min_value <= v[k];
        loop invariant v[0] == sum_ac(a, c);
        loop invariant v[1] == sum_ad(a, d);
        loop invariant v[2] == sum_bc(b, c);
        loop invariant v[3] == sum_bd(b, d);
        loop invariant -200 <= min_value <= 200;
        loop assigns i, min_value;
    */
    while (i < 4)
    {
        //@ assert 0 <= i < 4;
        //@ assert -200 <= v[i] <= 200;
        
        if (v[i] < min_value)
        {
            min_value = v[i];
        }
        
        i = i + 1;
    }
    
    //@ assert result_valid(min_value, a, b, c, d);
    //@ assert result_range(min_value);
    return min_value;
}
