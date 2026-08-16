/*@
predicate sum_to_ten(integer x, integer y) = x + y == 10;

lemma lemma_sum_to_ten:
    \forall integer x, y; sum_to_ten(x, y) ==> y == 10 - x;

lemma establish_sum_to_ten:
    \forall integer x, y; sum_to_ten(x, y) ==> y == 10 - x;
*/

/*@
requires sum_to_ten(x, y);
ensures \result == 10 - x;
*/
int compute_y(int x, int y)
{
    //@ assert sum_to_ten(x, y);
    //@ assert y == 10 - x;
    return y;
}

int main()
{
    int x;
    int y;
    
    x = 3;
    y = 7;
    
    //@ assert sum_to_ten(x, y);
    int result = compute_y(x, y);
    
    return 0;
}
