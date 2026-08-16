/*@
    predicate a_equals_b(integer a, integer b) = a == b;
    predicate b_equals_c(integer b, integer c) = b == c;
    predicate a_equals_c(integer a, integer c) = a == c;
*/

/*@
    requires a == b;
    requires b == c;
    requires -1000000000 <= a <= 1000000000;
    requires -1000000000 <= b <= 1000000000;
    requires -1000000000 <= c <= 1000000000;
    ensures \result == a;
*/
int func(int a, int b, int c)
{
    //@ assert a == b;
    //@ assert b == c;
    //@ assert a == c;
    
    return a;
}

int main()
{
    return 0;
}
