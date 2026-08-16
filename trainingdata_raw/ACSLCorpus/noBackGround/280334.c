#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100 && 1 <= (K) && (K) <= 100);
    ensures \result == true <==> (((N) / 2 >= (K)) || ((N) % 2 != 0 && ((N) / 2) + 1 >= (K)));
    assigns \nothing;
*/
bool func(unsigned long N, unsigned long K)
{
    bool result;

    //@ assert (1 <= (N) && (N) <= 100 && 1 <= (K) && (K) <= 100);

    if (N / 2 >= K) {
        result = true;
        //@ assert result == true <==> (((N) / 2 >= (K)) || ((N) % 2 != 0 && ((N) / 2) + 1 >= (K)));
        return result;
    } else {
        if (N % 2 != 0 && (N / 2) + 1 >= K) {
            result = true;
            //@ assert result == true <==> (((N) / 2 >= (K)) || ((N) % 2 != 0 && ((N) / 2) + 1 >= (K)));
            return result;
        } else {
            //@ assert N / 2 < K && (N % 2 == 0 || (N / 2) + 1 < K);
            result = false;
            //@ assert result == true <==> (((N) / 2 >= (K)) || ((N) % 2 != 0 && ((N) / 2) + 1 >= (K)));
            return result;
        }
    }
}
