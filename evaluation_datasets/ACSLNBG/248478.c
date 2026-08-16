
unsigned int func(unsigned int a)
{
    // Variable declarations at scope top
    unsigned int result;

    //@ assert (1 <= (a) && (a) <= 10);
    //@ assert ((a) + (a) * (a) + (a) * (a) * (a)) <= 1331;

    result = a + a * a + a * a * a;

    //@ assert result == ((a) + (a) * (a) + (a) * (a) * (a));
    return result;
}
