/*@
    requires (1 <= (a) && (a) <= 1000) && (1 <= (b) && (b) <= 1000) && (1 <= (c) && (c) <= 1000) && (1 <= (d) && (d) <= 1000);
    ensures \result == ((a) + (b) + (c)) || \result == ((a) + (b) + (d)) ||
            \result == ((a) + (c) + (d)) || \result == ((b) + (c) + (d));
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int min_ab;
    int min_cd;
    int min_all;
    int s1;
    int s2;
    int s3;
    int s4;
    int min_sum;

    if (a < b) {
        min_ab = a;
    } else {
        min_ab = b;
    }

    if (c < d) {
        min_cd = c;
    } else {
        min_cd = d;
    }

    if (min_ab < min_cd) {
        min_all = min_ab;
    } else {
        min_all = min_cd;
    }

    s1 = a + b + c;
    s2 = a + b + d;
    s3 = a + c + d;
    s4 = b + c + d;

    min_sum = s1;
    //@ assert min_sum == ((a) + (b) + (c));
    if (s2 < min_sum) {
        min_sum = s2;
        //@ assert min_sum == ((a) + (b) + (d));
    }
    //@ assert min_sum == ((a) + (b) + (c)) || min_sum == ((a) + (b) + (d));
    if (s3 < min_sum) {
        min_sum = s3;
        //@ assert min_sum == ((a) + (c) + (d));
    }
    //@ assert min_sum == ((a) + (b) + (c)) || min_sum == ((a) + (b) + (d)) || min_sum == ((a) + (c) + (d));
    if (s4 < min_sum) {
        min_sum = s4;
        //@ assert min_sum == ((b) + (c) + (d));
    }
    //@ assert min_sum == ((a) + (b) + (c)) || min_sum == ((a) + (b) + (d)) || min_sum == ((a) + (c) + (d)) || min_sum == ((b) + (c) + (d));

    return min_sum;
}
