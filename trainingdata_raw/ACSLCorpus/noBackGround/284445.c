/*@
    requires (-100 <= (A) <= 100) && (-100 <= (B) <= 100) && (-100 <= (C) <= 100) && (-100 <= (D) <= 100);
    ensures \result == ((A) + (B)) ||
            \result == ((A) + (C)) ||
            \result == ((A) + (D)) ||
            \result == ((B) + (C)) ||
            \result == ((B) + (D)) ||
            \result == ((C) + (D));
*/
int func(int A, int B, int C, int D)
{
    int max_sum;
    int temp_sum;

    //@ assert -200 <= A + B <= 200;
    max_sum = A + B;

    //@ assert -200 <= A + C <= 200;
    temp_sum = A + C;
    if (temp_sum > max_sum) {
        max_sum = temp_sum;
    }

    //@ assert -200 <= A + D <= 200;
    temp_sum = A + D;
    if (temp_sum > max_sum) {
        max_sum = temp_sum;
    }

    //@ assert -200 <= B + C <= 200;
    temp_sum = B + C;
    if (temp_sum > max_sum) {
        max_sum = temp_sum;
    }

    //@ assert -200 <= B + D <= 200;
    temp_sum = B + D;
    if (temp_sum > max_sum) {
        max_sum = temp_sum;
    }

    //@ assert -200 <= C + D <= 200;
    temp_sum = C + D;
    if (temp_sum > max_sum) {
        max_sum = temp_sum;
    }

    return max_sum;
}
