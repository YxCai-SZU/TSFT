/*@
    predicate is_zero(integer x) = x == 0;
    predicate is_one(integer x) = x == 1;
    logic integer complement(integer x) = (x == 0) ? 1 : 0;
    
    lemma complement_zero: \forall integer x; is_zero(x) ==> complement(x) == 1;
    lemma complement_one: \forall integer x; is_one(x) ==> complement(x) == 0;
*/

/*@
    requires 0 <= X <= 1;
    ensures (X == 0 ==> \result == 1) && (X == 1 ==> \result == 0);
*/
int func(int X)
{
    int result;
    
    //@ assert X == 0 || X == 1;
    
    if (X == 0) {
        result = 1;
        //@ assert is_zero(X);
        //@ assert complement(X) == 1;
    } else {
        result = 0;
        //@ assert is_one(X);
        //@ assert complement(X) == 0;
    }
    
    //@ assert (X == 0 && result == 1) || (X == 1 && result == 0);
    return result;
}
