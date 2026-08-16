/*@
    requires (2 <= (a) && (a) <= 100) && (2 <= (b) && (b) <= 100);
    ensures \result == a * b - a - b + 1;
    ensures \result > 0;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int result;
    
    //@ assert a > 0 && a <= 100;
    //@ assert b > 0 && b <= 100;
    //@ assert a * b >= a + b;
    //@ assert a * b <= 100 * 100;
    //@ assert a * b - a >= b;
    //@ assert a * b - a - b + 1 <= 99 * 99;
    
    result = a * b - a - b + 1;
    return result;
}
