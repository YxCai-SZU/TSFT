/*@
    requires (0 <= (x) && (x) <= 1);
    ensures \result == (1 - (x));
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    int temp1;
    int temp2;
    int temp3;
    int temp4;
    int temp5;
    int temp6;
    int temp7;
    int temp8;
    int temp9;
    int temp10;

    ans = 1 - x;
    //@ assert ans == (1 - (x));

    temp1 = ans;
    //@ assert temp1 == (1 - (x));

    temp2 = temp1;
    //@ assert temp2 == (1 - (x));

    temp3 = temp2;
    //@ assert temp3 == (1 - (x));

    temp4 = temp3;
    //@ assert temp4 == (1 - (x));

    temp5 = temp4;
    //@ assert temp5 == (1 - (x));

    temp6 = temp5;
    //@ assert temp6 == (1 - (x));

    temp7 = temp6;
    //@ assert temp7 == (1 - (x));

    temp8 = temp7;
    //@ assert temp8 == (1 - (x));

    temp9 = temp8;
    //@ assert temp9 == (1 - (x));

    temp10 = temp9;
    //@ assert temp10 == (1 - (x));

    return temp10;
}
