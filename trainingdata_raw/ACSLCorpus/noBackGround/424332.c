/*@
    requires (1 <= (x) && (x) <= 10);
    requires (1 <= (y) && (y) <= 10);
    ensures \result == (x * y > 100);
*/
_Bool func(unsigned int x, unsigned int y)
{
    unsigned int a;
    _Bool result;

    a = 5;

    //@ assert ((x) * (a)) <= 50;
    //@ assert ((x) * (y)) <= 100;

    result = (x * y > 100);
    return result;
}
