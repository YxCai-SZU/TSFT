#include <limits.h>

/*@
    predicate call_requires{L}(integer val) =
        val >= 0 && val <= UINT_MAX;

    predicate call_ensures{L}(integer val, integer res) =
        res == val % 10 && res < 10;
*/

/*@
    logic integer modulo_ten(integer x) =
        x % 10;
*/

/*@
    lemma modulo_ten_property:
        \forall integer x; x >= 0 && x <= UINT_MAX ==> 
            modulo_ten(x) == x % 10 && modulo_ten(x) < 10;
*/

/*@
    requires call_requires(val);
    ensures \result == modulo_ten(val);
    ensures \result == val % 10;
    ensures \result < 10;
*/
unsigned int apply_function(unsigned int val)
{
    //@ assert call_requires(val);
    unsigned int res = val % 10;
    //@ assert call_ensures(val, res);
    return res;
}

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
*/
int func(int a, int b)
{
    int sum = a + b;
    int diff = a - b;
    
    //@ assert -10000 <= a * b <= 10000;
    int prod = a * b;
    
    int max_val = sum;
    
    if (diff > max_val) {
        max_val = diff;
    }
    //@ assert max_val >= sum && max_val >= diff;
    
    if (prod > max_val) {
        max_val = prod;
    }
    //@ assert max_val >= sum && max_val >= diff && max_val >= prod;
    
    return max_val;
}

int main()
{
    unsigned int result = apply_function(142);
    //@ assert result == 2;
    return 0;
}
