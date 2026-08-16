/*@
    requires a == 1 && b == 2 && c == 3;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_transitive_order(int a, int b, int c)
{
    //@ assert a == 1;
    //@ assert b == 2;
    //@ assert c == 3;
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 1;
}

/*@
    requires a == 1 && b == 2 && c == 3;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_inference_exercise(int a, int b, int c)
{
    //@ assert a == 1;
    //@ assert b == 2;
    //@ assert c == 3;
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 1;
}

int main()
{
    int a;
    int b;
    int c;
    
    a = 1;
    b = 2;
    c = 3;
    
    calc_example_transitive_order(a, b, c);
    calc_example_inference_exercise(a, b, c);
    
    return 0;
}
