/*@
    predicate non_negative(integer a) = a >= 0;
    predicate sum_one(integer a, integer b, integer c, integer d) = a + b + c + d == 1;
    predicate result_range(integer r) = r >= 0 && r <= 4;

    logic integer min_val(integer a, integer b, integer c, integer d) =
        (a < b) ?
            ((a < c) ?
                ((a < d) ? a : d)
                :
                ((c < d) ? c : d))
            :
            ((b < c) ?
                ((b < d) ? b : d)
                :
                ((c < d) ? c : d));

    lemma min_val_non_negative:
        \forall integer a,b,c,d;
            non_negative(a) && non_negative(b) && non_negative(c) && non_negative(d) ==>
            min_val(a,b,c,d) >= 0;

    lemma min_val_le_one:
        \forall integer a,b,c,d;
            non_negative(a) && non_negative(b) && non_negative(c) && non_negative(d) &&
            sum_one(a,b,c,d) ==>
            min_val(a,b,c,d) <= 1;
*/

/*@
    requires \valid(v + (0..3));
    requires v[0] >= 0 && v[1] >= 0 && v[2] >= 0 && v[3] >= 0;
    requires v[0] + v[1] + v[2] + v[3] == 1;
    ensures \result >= 0 && \result <= 4;
    assigns \nothing;
*/
long func(long v[4])
{
    long x;
    long y;
    long z;
    long w;
    long ans;
    long min_val;

    x = v[0];
    y = v[1];
    z = v[2];
    w = v[3];

    //@ assert non_negative(x) && non_negative(y) && non_negative(z) && non_negative(w);
    //@ assert sum_one(x,y,z,w);

    if (x == 1 || y == 1 || z == 1 || w == 1)
    {
        ans = 1;
    }
    else
    {
        if (x < y)
        {
            if (x < z)
            {
                if (x < w)
                {
                    min_val = x;
                }
                else
                {
                    min_val = w;
                }
            }
            else
            {
                if (z < w)
                {
                    min_val = z;
                }
                else
                {
                    min_val = w;
                }
            }
        }
        else
        {
            if (y < z)
            {
                if (y < w)
                {
                    min_val = y;
                }
                else
                {
                    min_val = z;
                }
            }
            else
            {
                if (z < w)
                {
                    min_val = z;
                }
                else
                {
                    min_val = w;
                }
            }
        }

        //@ assert min_val == min_val(x,y,z,w);
        //@ assert min_val >= 0;
        //@ assert min_val <= 1;

        ans = 4 * min_val;
    }

    //@ assert result_range(ans);
    return ans;
}
