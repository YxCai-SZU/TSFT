#include <stdint.h>

/*@ predicate double_precond(integer x) = -64 <= x < 64; */
/*@ predicate triple_precond(integer x) = -42 <= x < 42; */

/*@ logic integer double_result(integer x) = 2 * x; */
/*@ logic integer triple_result(integer x) = 3 * x; */

/*@
    requires double_precond(x);
    ensures \result == double_result(x);
    assigns \nothing;
*/
int8_t double_value(int8_t x)
{
    int8_t y;
    //@ assert double_precond(x);
    y = x + x;
    //@ assert y == double_result(x);
    return y;
}

/*@
    requires triple_precond(x);
    ensures \result == triple_result(x);
    assigns \nothing;
*/
int8_t triple_value(int8_t x)
{
    int8_t y;
    //@ assert triple_precond(x);
    y = x + x + x;
    //@ assert y == triple_result(x);
    return y;
}

/*@
    ensures \true;
    assigns \nothing;
*/
void print_result(int8_t r)
{
    // Implementation omitted for verification
}

int main()
{
    int8_t n1;
    int8_t n2;
    int8_t n3;
    int8_t n4;
    
    n1 = double_value(10);
    //@ assert n1 == 20;
    n2 = triple_value(10);
    //@ assert n2 == 30;
    n3 = double_value(-21);
    //@ assert n3 == -42;
    n4 = triple_value(-14);
    //@ assert n4 == -42;
    
    print_result(n1);
    print_result(n2);
    print_result(n3);
    print_result(n4);
    
    return 0;
}
