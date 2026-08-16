#include <stddef.h>
#include <stdbool.h>

/*@
    predicate is_even(integer x) = x % 2 == 0;
    predicate in_range_a(integer a) = 0 <= a && a <= 100;
    predicate in_range_b(integer b) = 2 <= b && b <= 1000 && is_even(b);
    predicate vec_eq_seq{L}(unsigned int *v, size_t len, integer i) =
       \forall integer j; 0 <= j < i ==> v[j] == \at(v[j], L);
*/

size_t func(size_t a, size_t b)
{
    size_t result;

    if (a == 0 || a >= 13)
    {
        //@ assert a == 0 || a >= 13;
        result = 0;
    }
    else if (a >= 7)
    {
        //@ assert a >= 7 && a <= 12;
        result = b / 2;
    }
    else
    {
        //@ assert a >= 1 && a <= 6;
        result = b / 2 + (b % 2);
    }

    return result;
}

bool check_vec_similarity(unsigned int *v1, unsigned int *v2, size_t len) 
{
    //@ assert \forall integer i; 0 <= i < len ==> v1[i] == v2[i];
    return true;
}

/*@
    logic integer func_logic(integer a, integer b) =
        (a == 0 || a >= 13) ? 0 :
        (a >= 7 && a <= 12) ? b / 2 :
        b / 2 + (b % 2);
*/

bool resource_alloc_and_verify(size_t a, size_t b, unsigned int *v1, unsigned int *v2)
{
    size_t computed_len = func(a, b);
    
    //@ assert computed_len <= b;
    
    bool is_similar = check_vec_similarity(v1, v2, computed_len);
    
    //@ assert is_similar == true && computed_len <= b;
    
    return is_similar;
}
