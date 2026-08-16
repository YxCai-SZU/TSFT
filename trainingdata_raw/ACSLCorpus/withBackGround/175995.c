/*@
    predicate in_range(integer v) = 1 <= v && v <= 100;

    lemma lemma_one_int:
        \forall integer x; in_range(x) ==> x * x * x <= 100 * 100 * 100;

    lemma lemma_two_int:
        \forall integer x, y; in_range(x) && in_range(y) ==> x * y <= 100 * 100;

    lemma lemma_three_int:
        \forall integer x, y, z; in_range(x) && in_range(y) && in_range(z) ==> x * y * z <= 100 * 100 * 100;
*/

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    requires 1 <= z && z <= 100;
    ensures \result == x * y * z;
    ensures \result <= 100 * 100 * 100;
*/
int multiply_three(int x, int y, int z)
{
    //@ assert in_range(x);
    //@ assert in_range(y);
    //@ assert in_range(z);
    
    int result;
    result = x * y;
    
    //@ assert result <= 100 * 100;
    result = result * z;
    
    //@ assert result <= 100 * 100 * 100;
    return result;
}

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result == x * y;
    ensures \result <= 100 * 100;
*/
int multiply_two(int x, int y)
{
    //@ assert in_range(x);
    //@ assert in_range(y);
    
    int result;
    result = x * y;
    
    //@ assert result <= 100 * 100;
    return result;
}

/*@
    requires 1 <= x && x <= 100;
    ensures \result == x * x * x;
    ensures \result <= 100 * 100 * 100;
*/
int cube(int x)
{
    //@ assert in_range(x);
    
    int result;
    int temp;
    
    temp = x * x;
    //@ assert temp <= 100 * 100;
    
    result = temp * x;
    //@ assert result <= 100 * 100 * 100;
    
    return result;
}

int main()
{
    int a, b, c;
    int res1, res2, res3;
    
    a = 50;
    b = 75;
    c = 25;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    res1 = multiply_two(a, b);
    //@ assert res1 <= 100 * 100;
    
    res2 = multiply_three(a, b, c);
    //@ assert res2 <= 100 * 100 * 100;
    
    res3 = cube(a);
    //@ assert res3 <= 100 * 100 * 100;
    
    return 0;
}
