#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */
/*@ predicate is_odd(integer n) = n % 2 != 0; */

/*@ logic integer max(integer a, integer b) = (a > b) ? a : b; */
/*@ logic integer min(integer a, integer b) = (a < b) ? a : b; */

/*@ lemma max_comm: \forall integer a, b; max(a,b) == max(b,a); */
/*@ lemma min_comm: \forall integer a, b; min(a,b) == min(b,a); */

/*@ requires n < 1000;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
 */
bool is_even_func(unsigned int n)
{
    //@ assert n < 1000;
    return n % 2 == 0;
}

/*@ requires n < 1000;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
 */
bool is_odd_func(unsigned int n)
{
    //@ assert n < 1000;
    return n % 2 != 0;
}

/*@ requires side < 1000;
    ensures \result == side * side * side;
    assigns \nothing;
 */
unsigned int volume_cube(unsigned int side)
{
    unsigned int result;
    
    //@ assert side < 1000;
    //@ assert side * side < 1000 * 1000;
    //@ assert side * side * side < 1000 * 1000 * 1000;
    
    result = side * side * side;
    return result;
}

/*@ requires length < 1000 && width < 1000 && height < 1000;
    ensures \result == length * width * height;
    assigns \nothing;
 */
unsigned int volume_rectangular_prism(unsigned int length, unsigned int width, unsigned int height)
{
    unsigned int result;
    
    //@ assert length < 1000;
    //@ assert width < 1000;
    //@ assert height < 1000;
    //@ assert length * width < 1000 * 1000;
    //@ assert length * width * height < 1000 * 1000 * 1000;
    
    result = length * width * height;
    return result;
}
