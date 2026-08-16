/*@
predicate is_special(integer x) = x == 7 || x == 5 || x == 3;

lemma special_range: \forall integer x; 1 <= x && x <= 9 && is_special(x) ==> x == 7 || x == 5 || x == 3;
*/

/*@
requires 1 <= X && X <= 9;
ensures \result == (X == 7 || X == 5 || X == 3);
assigns \nothing;
*/
int func(int X)
{
    //@ assert 1 <= X && X <= 9;
    return (X == 7 || X == 5 || X == 3);
}

/*@
requires 1 <= X && X <= 9;
ensures \result == 0 || \result == 1;
assigns \nothing;
*/
int func2(int X)
{
    int result;
    //@ assert 1 <= X && X <= 9;
    
    if (X == 7 || X == 5 || X == 3) {
        result = 1;
    } else {
        //@ assert 0 <= X && X <= 9;
        result = 0;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
