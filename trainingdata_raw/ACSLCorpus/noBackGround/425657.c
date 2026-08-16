/*@
    requires \valid(result);
    requires 0 <= x <= 8 && 0 <= y <= 8;
    ensures *result == x * y;
    assigns *result;
*/
void func(unsigned int x, unsigned int y, unsigned int *result)
{
    // Variable declarations at top
    unsigned int tmp;

    //@ assert ((x) <= 8 && (y) <= 8);
    //@ assert ((x) * (y)) <= 64;
    //@ assert x * y <= 64;

    tmp = x * y;
    *result = tmp;
}
