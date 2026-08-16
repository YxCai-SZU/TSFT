#include <limits.h>

/*@ predicate is_valid_params(integer n, integer aa, integer bb, integer cc) =
      1 <= n && n <= 20 &&
      1 <= aa && aa <= 50 &&
      1 <= bb && bb <= 50 &&
      1 <= cc && cc <= 50;
*/

/*@ logic integer product(integer n, integer aa) = n * aa;
*/

/*@ logic integer sum(integer bb, integer cc) = bb + cc;
*/

/*@ lemma product_bounds: 
      \forall integer n, integer aa; 
      is_valid_params(n, aa, 1, 1) ==> 1 <= product(n, aa) <= 1000;
*/

/*@ lemma sum_bounds: 
      \forall integer bb, integer cc; 
      is_valid_params(1, 1, bb, cc) ==> 2 <= sum(bb, cc) <= 100;
*/

/*@ requires is_valid_params(n, aa, bb, cc);
    ensures \result == product(n, aa) || \result == sum(bb, cc);
    ensures \result <= product(n, aa);
    assigns \nothing;
*/
int func(int n, int aa, int bb, int cc) {
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= aa && aa <= 50;
    //@ assert 1 <= bb && bb <= 50;
    //@ assert 1 <= cc && cc <= 50;
    
    int product = n * aa;
    int sum = bb + cc;
    
    //@ assert product >= 1 && product <= 1000;
    //@ assert sum >= 2 && sum <= 100;
    
    if (product < sum) {
        //@ assert product == product(n, aa);
        //@ assert product <= product(n, aa);
        return product;
    } else {
        //@ assert sum == sum(bb, cc);
        //@ assert sum <= product(n, aa);
        return sum;
    }
}
