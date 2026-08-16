#include <stdbool.h>

/*@
    predicate condition_holds(integer x) =
        x % 200 == 0 || x % 200 > 50;

    predicate is_odd_product(integer a, integer b) =
        (a * b) % 2 != 0;

    logic integer product_in_range(integer a, integer b) =
        a * b;

    lemma product_range:
        \forall integer a, b;
        1 <= a <= 3 && 1 <= b <= 3 ==> 1 <= product_in_range(a, b) <= 9;
*/

bool func_x(int x)
{
    bool result;
    
    //@ assert 1 <= x && x <= 100000;
    
    if (x % 200 == 0 || x % 200 > 50) {
        //@ assert condition_holds(x);
        result = true;
    } else {
        //@ assert !condition_holds(x);
        result = false;
    }
    
    return result;
}

bool func_ab(int a, int b)
{
    int product;
    bool is_odd;

    //@ assert 1 <= a && a <= 3;
    //@ assert 1 <= b && b <= 3;
    //@ assert 1 <= a * b && a * b <= 9;

    product = a * b;

    switch (product)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 9:
            is_odd = true;
            break;
        default:
            is_odd = false;
            break;
    }

    return is_odd;
}

bool process_data(int x, int a, int b)
{
    bool cond1 = func_x(x);
    bool cond2 = func_ab(a, b);
    bool result = cond1 && cond2;
    
    //@ assert result <==> (condition_holds(x) && is_odd_product(a, b));
    
    return result;
}
