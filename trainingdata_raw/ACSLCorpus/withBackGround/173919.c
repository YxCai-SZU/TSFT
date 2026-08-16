/*@
    logic integer square(integer x) = x * x;

    lemma square_nonlinear_arith:
        \forall integer x; x >= 0 ==> square(x) >= 0;
*/

/*@
    requires x >= 0;
    ensures \result == square(x);
    assigns \nothing;
*/
int compute_square(int x)
{
    //@ assert square(x) >= 0;
    return x * x;
}

int main()
{
    int result1;
    int result2;
    int result3;
    
    //@ assert square(5) >= 0;
    result1 = compute_square(5);
    
    //@ assert square(15) >= 0;
    result2 = compute_square(15);
    
    //@ assert square(21) >= 0;
    result3 = compute_square(21);
    
    return 0;
}
