#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100;

    logic integer expr1(integer a, integer b) = (a * 2 + b * 2) * 2;
    logic integer expr2(integer a, integer b) = 2 * 2 * (a + b) - 2 * (a + b) + 2 * (a + b);

    lemma expr_equality:
        \forall integer a, b;
        bounds(a, b) ==> expr1(a, b) == expr2(a, b);
*/

bool func1(unsigned int a, unsigned int b)
{
    unsigned int a2, b2, sum2, prod1, sum, prod2, sub, final;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;

    a2 = a * 2;
    //@ assert 0 <= a2 && a2 <= 200;

    b2 = b * 2;
    //@ assert 0 <= b2 && b2 <= 200;

    sum2 = a2 + b2;
    //@ assert 0 <= sum2 && sum2 <= 400;

    prod1 = sum2 * 2;
    //@ assert prod1 <= 800;

    sum = a + b;
    //@ assert 0 <= sum && sum <= 200;

    prod2 = 2 * 2 * sum;
    //@ assert 0 <= prod2 && prod2 <= 800;

    sub = prod2 - 2 * sum;
    //@ assert sub <= 800;

    final = sub + 2 * sum;
    //@ assert final <= 800;

    //@ assert final == 2 * 2 * sum - 2 * sum + 2 * sum;
    //@ assert prod1 == final;

    return true;
}

/*@
    predicate is_triangle(integer a, integer b, integer c) =
        a + b == c || b + c == a || c + a == b;
*/

bool func2(int a, int b, int c)
{
    int min;
    int mid;
    int max;
    bool condition1;
    bool condition2;
    bool condition3;
    bool result;

    if (a >= b && a >= c)
    {
        max = a;
        if (b >= c)
        {
            mid = b;
            min = c;
        }
        else
        {
            mid = c;
            min = b;
        }
    }
    else if (b >= a && b >= c)
    {
        max = b;
        if (a >= c)
        {
            mid = a;
            min = c;
        }
        else
        {
            mid = c;
            min = a;
        }
    }
    else
    {
        max = c;
        if (a >= b)
        {
            mid = a;
            min = b;
        }
        else
        {
            mid = b;
            min = a;
        }
    }

    condition1 = max - mid == min;
    condition2 = mid - min == max;
    condition3 = min + mid == max;
    result = condition1 || condition2 || condition3;

    //@ assert result == true <==> is_triangle(a, b, c);

    if (result)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*@
    predicate valid_triangle_dimensions(integer a, integer b, integer c) =
        0 <= a <= 100 && 0 <= b <= 100 && 0 <= c <= 100 &&
        (a + b == c || b + c == a || c + a == b);

    predicate valid_expression(integer a, integer b) =
        0 <= a && a <= 100 && 0 <= b && b <= 100 &&
        (a * 2 + b * 2) * 2 == 2 * 2 * (a + b) - 2 * (a + b) + 2 * (a + b);
*/

bool process_triangle_with_expression(int a, int b, int c)
{
    bool triangle_result;
    bool expression_result;

    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= c && c <= 100;

    triangle_result = func2(a, b, c);
    expression_result = func1(a, b);

    //@ assert triangle_result == true <==> is_triangle(a, b, c);
    //@ assert expression_result == true <==> (a * 2 + b * 2) * 2 == 2 * 2 * (a + b) - 2 * (a + b) + 2 * (a + b);

    //@ assert triangle_result && expression_result ==> (valid_triangle_dimensions(a, b, c) && valid_expression(a, b));

    return triangle_result && expression_result;
}
