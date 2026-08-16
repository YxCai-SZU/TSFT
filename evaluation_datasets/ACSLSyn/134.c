/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;
    
    logic integer multiply_by_4(integer x) = x * 4;
    
    lemma multiplication_bounds:
        \forall integer x; 1 <= x <= 100 ==> 4 <= multiply_by_4(x) <= 400;
*/

int bound_check(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * y <= 1000;
    return 1;
}

int bound_check2(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * y <= 64;
    return 1;
}

int mul_is_distributive_add(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * (y + z) == x * y + x * z;
    return 1;
}

void lemma_mul_is_distributive_add(unsigned int x, unsigned int y, unsigned int z)
{
    //@ assert x * (y + z) == x * y + x * z;
}

int func(unsigned long long x, unsigned long long y) {
    int result;

    //@ assert 1 <= x <= 100;
    //@ assert 1 <= y <= 100;

    //@ assert x * 4 <= 400;
    //@ assert x * 4 >= 4;

    if (x * 4 >= y && y % 2 == 0) {
        //@ assert x * 4 >= y && y % 2 == 0;
        result = 1;
    } else {
        result = 0;
    }

    return result;
}

int process_data(unsigned int a, unsigned int b, unsigned int c, 
                 unsigned long long d, unsigned long long e)
{
    int status = 0;
    
    if (bound_check2(a, b, c)) {
        if (func(d, e)) {
            status = 1;
            //@ assert a * b <= 64;
            //@ assert d * 4 >= e && e % 2 == 0;
            //@ assert a * b <= 1000;
        }
    }
    
    //@ assert status == 1 ==> (a * b <= 64 && d * 4 >= e && e % 2 == 0 && a * b <= 1000);
    return status;
}
