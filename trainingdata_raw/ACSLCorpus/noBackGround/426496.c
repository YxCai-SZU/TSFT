/*@
    requires (1 <= (A) && (A) <= 9 &&
        1 <= (B) && (B) <= 9 &&
        1 <= (C) && (C) <= 9);
    ensures ((\result) == (((A)) * 10 + ((B)) + ((C))) ||
        (\result) == (((A)) + ((B)) * 10 + ((C))) ||
        (\result) == (((A)) + ((B)) + ((C)) * 10));
    ensures \result >= 11;
    assigns \nothing;
*/
long func(long A, long B, long C)
{
    long max;
    long result;
    long temp_result;
    long count;

    // Calculate max of the three expressions
    if (A * 10 + B + C > A + B * 10 + C)
    {
        if (A * 10 + B + C > A + B + C * 10)
        {
            max = A * 10 + B + C;
        }
        else
        {
            max = A + B + C * 10;
        }
    }
    else if (A + B * 10 + C > A + B + C * 10)
    {
        max = A + B * 10 + C;
    }
    else
    {
        max = A + B + C * 10;
    }

    // Initialize variables
    result = max;
    temp_result = max;
    count = 0;

    /*@
        loop invariant 1 <= A && A <= 9;
        loop invariant 1 <= B && B <= 9;
        loop invariant 1 <= C && C <= 9;
        loop invariant temp_result >= 0;
        loop invariant count >= 0;
        loop invariant temp_result == max - count;
        loop invariant count <= max;
        loop assigns temp_result, count;
        loop variant temp_result;
    */
    while (temp_result >= 1)
    {
        temp_result -= 1;
        count += 1;
    }

    //@ assert count == max;

    if (count < max)
    {
        result = count + 1;
    }
    else
    {
        result = count;
    }

    //@ assert ((result) == (((A)) * 10 + ((B)) + ((C))) ||         (result) == (((A)) + ((B)) * 10 + ((C))) ||         (result) == (((A)) + ((B)) + ((C)) * 10));
    //@ assert result >= 11;

    return result;
}
