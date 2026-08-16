/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result == ((a) + (b)) || \result == ((a) - (b)) || \result == ((a) * (b));
*/
int func(int a, int b)
{
    int sum;
    int diff;
    int prod;
    int max_val;

    sum = a + b;
    diff = a - b;
    prod = a * b;

    //@ assert sum == ((a) + (b)) && diff == ((a) - (b)) && prod == ((a) * (b));

    if (sum > diff)
    {
        if (sum > prod)
        {
            max_val = sum;
        }
        else
        {
            max_val = prod;
        }
    }
    else
    {
        if (diff > prod)
        {
            max_val = diff;
        }
        else
        {
            max_val = prod;
        }
    }

    //@ assert max_val == sum || max_val == diff || max_val == prod;
    return max_val;
}

int main()
{
    return 0;
}
