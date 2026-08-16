/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= 0 && \result <= a;
*/
int func(int a, int b, int c, int k)
{
    int k_flag;
    int cnt;
    int i;

    k_flag = 0;
    cnt = 0;
    i = 0;

    /*@
        loop invariant (0 <= (i) && (i) <= (a) &&
        0 <= (k_flag) && (k_flag) <= (k) &&
        0 <= (cnt) && (cnt) <= (i));
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
        loop invariant k_flag <= k && cnt <= a;
        loop assigns k_flag, cnt, i;
        loop variant a - i;
    */
    while (i < a)
    {
        if (k_flag == k)
        {
            break;
        }
        cnt += 1;
        k_flag += 1;
        i += 1;
    }

    i = 0;
    /*@
        loop invariant (0 <= (i) && (i) <= (b) &&
        0 <= (k_flag) && (k_flag) <= (k) &&
        0 <= (cnt) && (cnt) <= (a));
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
        loop invariant k_flag <= k && cnt <= a;
        loop assigns k_flag, i;
        loop variant b - i;
    */
    while (i < b)
    {
        if (k_flag == k)
        {
            break;
        }
        k_flag += 1;
        i += 1;
    }

    i = 0;
    /*@
        loop invariant (0 <= (i) && (i) <= (c) &&
        0 <= (k_flag) && (k_flag) <= (k) &&
        0 <= (cnt) && (cnt) <= (a));
        loop invariant (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100 &&
        (a) + (b) + (c) >= (k));
        loop invariant k_flag <= k && cnt <= a;
        loop assigns k_flag, i;
        loop variant c - i;
    */
    while (i < c)
    {
        if (k_flag == k)
        {
            break;
        }
        k_flag += 1;
        i += 1;
    }

    //@ assert cnt >= 0 && cnt <= a;
    return cnt;
}
