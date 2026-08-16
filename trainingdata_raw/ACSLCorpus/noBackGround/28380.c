#include <stdbool.h>

/*@
    requires (1 <= (a) <= 9);
    requires (1 <= (b) <= 9);
    requires (1 <= (c) <= 9);
    ensures \result == true <==> ((((b)) * 10 + ((c))) % 4 < 1 ||
        (((a)) * 10 + ((b))) % 4 < 1 ||
        (((c)) * 10 + ((a))) % 4 < 1);
*/
bool func(int a, int b, int c)
{
    int n1;
    int n2;
    int n3;
    bool ans;

    //@ assert 10 <= ((a) * 10 + (b)) <= 99;
    n1 = a * 10 + b;

    //@ assert 10 <= ((b) * 10 + (c)) <= 99;
    n2 = b * 10 + c;

    //@ assert 10 <= ((c) * 10 + (a)) <= 99;
    n3 = c * 10 + a;

    ans = false;

    if (n1 % 4 == 0 || n2 % 4 == 0 || n3 % 4 == 0)
    {
        ans = true;
    }

    //@ assert ans == true <==> ((((b)) * 10 + ((c))) % 4 < 1 ||         (((a)) * 10 + ((b))) % 4 < 1 ||         (((c)) * 10 + ((a))) % 4 < 1);
    return ans;
}
