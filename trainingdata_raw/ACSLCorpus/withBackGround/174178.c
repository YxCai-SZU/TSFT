/*@
    predicate valid_range(integer v) = 0 <= v <= 1;

    logic integer func_spec(integer n, integer x) =
        n == 1 ?
            (x == 1 ? 1 : 1 - x)
        :
            (x == 1 ? 1 - n : 1);

    lemma func_lemma:
        \forall integer n, x;
            valid_range(n) && valid_range(x) ==>
            (
                func_spec(n, x) == 1 - n ||
                func_spec(n, x) == 1 - x ||
                func_spec(n, x) == 1
            );
*/

/*@
    requires valid_range(n) && valid_range(x);
    ensures \result == 1 - n || \result == 1 - x || \result == 1;
*/
int func(int n, int x)
{
    int result;
    //@ assert valid_range(n) && valid_range(x);
    
    if (n == 1) {
        if (x == 1) {
            result = 1;
        } else {
            result = 1 - x;
        }
    } else {
        if (x == 1) {
            result = 1 - n;
        } else {
            //@ assert 1 == 1 - n || 1 == 1 - x || 1 == 1;
            result = 1;
        }
    }
    
    //@ assert result == 1 - n || result == 1 - x || result == 1;
    return result;
}
