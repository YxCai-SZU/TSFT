/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate result_condition(integer r, integer a, integer b) =
        r <= (a - b * 2) || r == 0;

    lemma func_lemma:
        \forall integer a, integer b;
        (1 <= a && a <= 10000 && 1 <= b && b <= 10000) ==>
        ((a - b * 2 > 0) ==> (a - b * 2 >= 0 && (a - b * 2 <= (a - b * 2) || a - b * 2 == 0))) &&
        ((a - b * 2 <= 0) ==> (0 >= 0 && (0 <= (a - b * 2) || 0 == 0)));
*/

/*@
    requires 1 <= a && a <= 10000;
    requires 1 <= b && b <= 10000;
    ensures \result >= 0;
    ensures \result <= (a - b * 2) || \result == 0;
*/
int func(int a, int b)
{
    int result;
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    
    if (a - b * 2 > 0) {
        //@ assert a - b * 2 >= 0;
        result = a - b * 2;
    } else {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert is_nonnegative(result);
    //@ assert result_condition(result, a, b);
    return result;
}

int main() {
    return 0;
}
