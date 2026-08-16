
int func(int l, int r, int d)
{
    int count;
    int i;
    int j;
    int is_multiple;

    count = 0;
    i = l;

    
    while (i <= r)
    {
        j = 0;
        is_multiple = 0;

        
        while (j < d)
        {
            if ((i - j) == 0)
            {
                is_multiple = 1;
                break;
            }
            j += 1;
        }

        //@ assert is_multiple == 1 || j == d;

        if (is_multiple)
        {
            count += 1;
        }

        i += 1;
    }

    return count;
}
