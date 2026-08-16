/*@
    predicate leq(integer a, integer b) = a <= b;

    lemma transitivity:
        \forall integer a, b, c;
            leq(a, b) && leq(b, c) ==> leq(a, c);
*/

/*@
    requires leq(a, b) && leq(b, c);
    ensures leq(a, c);
*/
void calc_example_2(int a, int b, int c)
{
    //@ assert leq(a, b);
    //@ assert leq(b, c);
    //@ assert leq(a, c);
}

int main()
{
    return 0;
}

/*@
    requires leq(a, b) && leq(b, c);
    ensures leq(a, c);
*/
void func_input2(int a, int b, int c)
{
    //@ assert leq(a, b);
    //@ assert leq(b, c);
    //@ assert leq(a, c);
}

/*@
    requires leq(a, b) && leq(b, c);
    ensures leq(a, c);
*/
void func_input3(int a, int b, int c)
{
    //@ assert leq(a, b);
    //@ assert leq(b, c);
    //@ assert leq(a, c);
}

/*@
    requires leq(a, b) && leq(b, c);
    ensures leq(a, c);
*/
void func_input4(int a, int b, int c)
{
    int local_a = a;
    int local_b = b;
    int local_c = c;
    
    //@ assert leq(local_a, local_b);
    //@ assert leq(local_b, local_c);
    //@ assert leq(local_a, local_c);
}

/*@
    requires leq(a, b) && leq(b, c);
    ensures leq(a, c);
*/
void func_input5(int a, int b, int c)
{
    int local_a = a;
    int local_b = b;
    int local_c = c;
    
    //@ assert leq(local_a, local_b);
    //@ assert leq(local_b, local_c);
    //@ assert leq(local_a, local_c);
}
