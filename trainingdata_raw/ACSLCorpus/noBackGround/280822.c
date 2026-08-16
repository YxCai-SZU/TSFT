#include <stddef.h>

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func2(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func3(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func4(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func5(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func6(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func7(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func8(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func9(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}

/*@
    requires (0 <= (x) <= 1);
    ensures (((x) == 0 && (\result) == 1) || ((x) == 1 && (\result) == 0));
    assigns \nothing;
*/
size_t func10(size_t x)
{
    //@ assert 0 <= x <= 1;
    return 1 - x;
}
