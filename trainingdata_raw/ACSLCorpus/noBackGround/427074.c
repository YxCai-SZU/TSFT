/*@
    requires 400 <= x && x < 2000;
    ensures \result >= 0;
    ensures x < 600 ==> \result == 8;
    ensures x >= 600 && x < 800 ==> \result == 7;
    ensures x >= 800 && x < 1000 ==> \result == 6;
    ensures x >= 1000 && x < 1200 ==> \result == 5;
    ensures x >= 1200 && x < 1400 ==> \result == 4;
    ensures x >= 1400 && x < 1600 ==> \result == 3;
    ensures x >= 1600 && x < 1800 ==> \result == 2;
    ensures x >= 1800 && x < 2000 ==> \result == 1;
    assigns \nothing;
*/
int func(int x)
{
    int result;

    //@ assert 400 <= x && x < 2000;

    if (x < 600) {
        //@ assert x < 600;
        result = 8;
    } else if (x < 800) {
        //@ assert x >= 600 && x < 800;
        result = 7;
    } else if (x < 1000) {
        //@ assert x >= 800 && x < 1000;
        result = 6;
    } else if (x < 1200) {
        //@ assert x >= 1000 && x < 1200;
        result = 5;
    } else if (x < 1400) {
        //@ assert x >= 1200 && x < 1400;
        result = 4;
    } else if (x < 1600) {
        //@ assert x >= 1400 && x < 1600;
        result = 3;
    } else if (x < 1800) {
        //@ assert x >= 1600 && x < 1800;
        result = 2;
    } else if (x < 2000) {
        //@ assert x >= 1800 && x < 2000;
        result = 1;
    } else {
        //@ assert x >= 2000;
        result = -1;
    }

    //@ assert result >= 0;
    return result;
}
