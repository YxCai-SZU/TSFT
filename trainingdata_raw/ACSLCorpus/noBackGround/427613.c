#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func2(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func3(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func4(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func5(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func6(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func7(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func8(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func9(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == ((((a) + (b)) % 2) == 0);
    assigns \nothing;
*/
bool func10(unsigned int a, unsigned int b)
{
    unsigned int c;
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100);
    c = a + b;
    //@ assert c == a + b;
    return (c % 2) == 0;
}
