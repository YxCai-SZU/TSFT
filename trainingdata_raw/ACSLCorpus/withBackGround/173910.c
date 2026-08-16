/*@
    predicate x_in_range(integer x) = 1 <= x <= 100;

    lemma x_plus_2_gt_x: \forall integer x; x_in_range(x) ==> x + 2 > x;
    lemma x_plus_3_gt_x_plus_2: \forall integer x; x_in_range(x) ==> x + 3 > x + 2;
    lemma x_plus_3_gt_x: \forall integer x; x_in_range(x) ==> x + 3 > x;
*/

/*@
    requires 1 <= x <= 100;
    ensures \result > x + 2;
    ensures \result > x;
*/
int func(int x)
{
    //@ assert x + 2 > x;
    //@ assert x + 3 > x + 2;
    //@ assert x + 3 > x;
    
    int result;
    result = x + 3;
    
    //@ assert result > x + 2;
    //@ assert result > x;
    
    return result;
}

int main()
{
    return 0;
}
