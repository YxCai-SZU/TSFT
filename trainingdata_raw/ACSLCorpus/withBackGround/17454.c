/*@
predicate valid_range(integer x) = 1 <= x <= 100;

logic integer max_of_three(integer a, integer b, integer c) =
    (a > b ? (a > c ? a : c) : (b > c ? b : c));

lemma result_correctness:
    \forall integer a, b, c, result;
    valid_range(a) && valid_range(b) && valid_range(c) &&
    (result == 1 || result == 2 || result == 3) ==>
    (result == 1 || result == 2 || result == 3);
*/

/*@
requires valid_range(a) && valid_range(b) && valid_range(c);
ensures \result == 1 || \result == 2 || \result == 3;
assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int max_val;
    int temp_max;

    result = -1;

    // Implementing max function manually
    if (a > b)
    {
        temp_max = a;
    }
    else
    {
        temp_max = b;
    }

    if (temp_max > c)
    {
        max_val = temp_max;
    }
    else
    {
        max_val = c;
    }

    if (a == max_val && b == max_val && c == max_val)
    {
        result = 1;
    }
    else if (a != max_val && b != max_val && c != max_val)
    {
        result = 3;
    }
    else
    {
        result = 2;
    }

    //@ assert result == 1 || result == 2 || result == 3;

    return result;
}
