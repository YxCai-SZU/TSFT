
unsigned int func(unsigned int x)
{
    unsigned int result;
    unsigned int remaining;
    unsigned int num_500;
    unsigned int num_5;

    result = 0;
    remaining = x;

    num_500 = x / 500;
    result = result + num_500 * 1000;
    remaining = remaining - num_500 * 500;

    //@ assert result == (x / 500) * 1000;
    //@ assert remaining == x % 500;

    num_5 = remaining / 5;
    result = result + num_5 * 5;
    remaining = remaining - num_5 * 5;

    //@ assert result == (x / 500) * 1000 + ((x % 500) / 5) * 5;

    return result;
}
