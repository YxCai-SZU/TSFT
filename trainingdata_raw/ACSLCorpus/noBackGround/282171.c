/*@
requires ((a) > (b)) && (((c)) > (c));
ensures ((a) > (c));
*/
void complex_example(int a, int b, int c)
{
    //@ assert ((a) > (b));
    //@ assert (((c)) > (c));
    //@ assert ((a) > (c));
}

/*@
requires ((a) <= (b));
ensures ((a) <= (b));
*/
void less_than_or_equal(int a, int b)
{
    //@ assert ((a) <= (b));
}

/*@
requires ((a) >= (b));
ensures ((a) >= (b));
*/
void greater_than_or_equal(int a, int b)
{
    //@ assert ((a) >= (b));
}

/*@
requires ((a) == (b));
ensures ((a) == (b));
*/
void equivalence(int a, int b)
{
    //@ assert ((a) == (b));
}

/*@
requires ((a) > (b)) && (((c)) > (c));
ensures ((a) > (c));
*/
void multiple_steps(int a, int b, int c)
{
    //@ assert ((a) > (b));
    //@ assert (((c)) > (c));
    //@ assert ((a) > (c));
}

/*@
requires ((a) > (b)) && (((c)) > (c));
ensures ((a) > (c));
*/
void complex_logic(int a, int b, int c)
{
    //@ assert ((a) > (b));
    //@ assert (((c)) > (c));
    //@ assert ((a) > (c));
}

/*@
requires ((a) > (b));
ensures ((a) > (b));
*/
void no_additional_steps(int a, int b)
{
    //@ assert ((a) > (b));
}

/*@
requires ((a) > (b));
ensures ((a) > (b));
*/
void required(int a, int b)
{
    //@ assert ((a) > (b));
}

/*@
requires ((a) > (b));
ensures ((a) > (b));
*/
void ensures_example(int a, int b)
{
    //@ assert ((a) > (b));
}

/*@
requires ((a) > (b)) && (((c)) > (c));
ensures ((a) > (c));
*/
void main_proof(int a, int b, int c)
{
    //@ assert ((a) > (b));
    //@ assert (((c)) > (c));
    //@ assert ((a) > (c));
}
