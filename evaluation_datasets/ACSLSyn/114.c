#include <stdbool.h>

/*@
    predicate is_valid_input(integer input) =
        1 <= input && input <= 10000;

    predicate result_condition(integer result, integer input) =
        result >= 0 ==>
            result * 108 >= input * 100 &&
            (result * 108) - (input * 100) <= 999;

    lemma product_bounds:
        \forall integer x; 0 <= x <= 100000 ==>
            x * 108 <= 100000 * 108 && x * 108 >= 0;
*/

int func(int input)
{
    int x;
    int product;
    int difference;
    int result;

    x = 0;
    while (x < 100000)
    {
        //@ assert x * 108 <= 100000 * 108;
        product = x * 108;
        difference = product - input * 100;

        if (0 <= difference && difference <= 999)
        {
            result = x;
            //@ assert result_condition(result, input);
            return result;
        }

        x = x + 1;
    }

    result = -1;
    return result;
}

/*@
    predicate positive(integer v) = v > 0;
*/

int verify_nonlinear_arithmetic(int x, int y, int z) {
    //@ assert positive(x);
    //@ assert positive(y);
    //@ assert positive(z);
    
    int result = ((x * y + z) % y == (y * x + z) % y);
    
    //@ assert result == 1;
    return result;
}

/*@
    predicate valid_verification(integer result, integer input, integer verified) =
        (result >= 0 ==> (verified == 1 && result_condition(result, input))) &&
        (result == -1 ==> verified == 1);
*/

int process_and_verify(int input) {
    int result = func(input);
    int verified_result;
    
    /*@
        assert result >= 0 || result == -1;
    */
    
    if (result >= 0) {
        //@ assert result_condition(result, input);
        verified_result = verify_nonlinear_arithmetic(result, 108, input * 100);
        //@ assert verified_result == 1;
        //@ assert result_condition(result, input);
    } else {
        //@ assert result == -1;
        verified_result = verify_nonlinear_arithmetic(1, 2, 3);
        //@ assert verified_result == 1;
    }
    
    //@ assert valid_verification(result, input, verified_result);
    return result;
}
