/*@
predicate valid_range(integer v) = 3 <= v && v <= 20;

logic integer max_val(integer x, integer y) = x > y ? x : y;

lemma max_val_property:
    \forall integer a, b;
    valid_range(a) && valid_range(b) ==>
    (max_val(a, b) == a || max_val(a, b) == b);
*/

/*@
requires valid_range(a) && valid_range(b);
ensures \result >= 0;
ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
assigns \nothing;
*/
int func(int a, int b)
{
    int max;
    int res;

    //@ assert valid_range(a) && valid_range(b);
    
    if (a > b) {
        max = a;
    } else {
        max = b;
    }
    
    //@ assert max == max_val(a, b);
    
    res = max + max - 1;
    
    if (res >= 0) {
        //@ assert res == 2 * max - 1;
        //@ assert max == a || max == b;
        //@ assert res == 2 * a - 1 || res == 2 * b - 1;
        return res;
    } else {
        //@ assert res < 0;
        return a + b;
    }
}
