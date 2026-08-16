#include <stdbool.h>

/*@
    requires \valid_read(numbers + (0 .. 2));
    requires (\forall integer i; 0 <= i < 3 ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 100));
    ensures \result <==> (
        (((numbers)[(0)]) + ((numbers)[(1)]) == ((numbers)[(2)])) ||
        (((numbers)[(1)]) + ((numbers)[(2)]) == ((numbers)[(0)])) ||
        (((numbers)[(2)]) + ((numbers)[(0)]) == ((numbers)[(1)]))
    );
    assigns \nothing;
*/
bool func(int *numbers)
{
    bool result = false;
    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    //@ assert (\forall integer i; 0 <= i < 3 ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 100));
    //@ assert 3 == 3;

    sum1 = numbers[0] + numbers[1];
    sum2 = numbers[1] + numbers[2];
    sum3 = numbers[2] + numbers[0];

    if (sum1 == numbers[2] || sum2 == numbers[0] || sum3 == numbers[1])
    {
        result = true;
    }

    return result;
}
