#include <limits.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + b || \result == c + d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int train_passengers;
    int bus_passengers;
    int result;

    train_passengers = a + b;
    bus_passengers = c + d;

    //@ assert train_passengers >= 2 && train_passengers <= 20000;
    //@ assert bus_passengers >= 2 && bus_passengers <= 20000;

    if (train_passengers > bus_passengers)
    {
        result = train_passengers;
    }
    else
    {
        result = bus_passengers;
    }

    //@ assert result == train_passengers || result == bus_passengers;
    return result;
}

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a + b || \result == c + d;
    ensures \result >= 1;
    assigns \nothing;
*/
int func2(int a, int b, int c, int d)
{
    int train_passengers;
    int bus_passengers;
    int result;

    train_passengers = a + b;
    bus_passengers = c + d;

    //@ assert train_passengers >= 2 && train_passengers <= 20000;
    //@ assert bus_passengers >= 2 && bus_passengers <= 20000;

    if (train_passengers > bus_passengers)
    {
        //@ assert train_passengers >= 1;
        result = train_passengers;
    }
    else
    {
        //@ assert bus_passengers >= 1;
        result = bus_passengers;
    }

    //@ assert result == train_passengers || result == bus_passengers;
    return result;
}
