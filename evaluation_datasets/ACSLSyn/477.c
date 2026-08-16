#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 9;
    predicate two_equal_one_different(integer a, integer b, integer c) =
        (a == b && c != a) || (a == c && b != a) || (b == c && a != b);

    logic integer form1(integer a, integer b, integer c) = a * 100 + b * 10 + c;
    logic integer form2(integer a, integer b, integer c) = b * 100 + c * 10 + a;
    logic integer form3(integer a, integer b, integer c) = c * 100 + a * 10 + b;

    predicate is_valid_form(integer val, integer a, integer b, integer c) =
        val == form1(a, b, c) || val == form2(a, b, c) || val == form3(a, b, c);

    lemma forms_ge_100: \forall integer a, b, c; 
        valid_range(a) && valid_range(b) && valid_range(c) ==> 
        form1(a, b, c) >= 100 && form2(a, b, c) >= 100 && form3(a, b, c) >= 100;
*/

int max_val_func(int a, int b, int c)
{
    int max_val[3];
    int max_index;
    int i;

    max_val[0] = a * 100 + b * 10 + c;
    max_val[1] = b * 100 + c * 10 + a;
    max_val[2] = c * 100 + a * 10 + b;
    max_index = 0;
    i = 1;

    while (i < 3)
    {
        //@ assert 0 <= i < 3;
        //@ assert 0 <= max_index < 3;
        if (max_val[i] > max_val[max_index])
        {
            max_index = i;
        }
        i = i + 1;
    }

    //@ assert 0 <= max_index < 3;
    //@ assert is_valid_form(max_val[max_index], a, b, c);
    return max_val[max_index];
}

bool check_two_equal_one_different(int a, int b, int c)
{
    return (a == b && c != a) || (a == c && b != a) || (b == c && a != b);
}

/*@
    predicate valid_input(integer a, integer b, integer c) = 
        valid_range(a) && valid_range(b) && valid_range(c);
*/

int max_form(int a, int b, int c)
{
    return max_val_func(a, b, c);
}

int process_digits(int a, int b, int c)
{
    int max_val;
    bool has_special;

    max_val = max_form(a, b, c);
    
    //@ assert is_valid_form(max_val, a, b, c);
    //@ assert max_val >= 100;

    has_special = check_two_equal_one_different(a, b, c);
    
    //@ assert has_special == true <==> two_equal_one_different(a, b, c);

    return max_val;
}
