/* 
 * Scenario: Financial transaction validation system
 * The synthesized function checks if a transaction ID (X) exists in a batch of processed transactions
 * and verifies that the batch size doesn't cause overflow, ensuring data integrity
 */

/*@
    predicate is_in_range(integer X) = 1 <= X <= 100000;
    predicate result_range(integer r) = r == 0 || r == 1;
    logic integer as_i32(integer X) = X;
*/

int func1(long long X)
{
    int n = 0;
    int i = 0;
    
    while (i < 1001)
    {
        int n_temp = i * 8;
        //@ assert n_temp == i * 8;
        
        if (n_temp == (int)X)
        {
            n = 1;
            break;
        }
        i += 1;
    }
    //@ assert n == 0 || n == 1;
    return n;
}

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 10000;
    
    logic integer product(integer a, integer b) = a * b;
    
    lemma product_bound:
        \forall integer a, b;
        is_valid_range(a) && is_valid_range(b) ==> 
            product(a, b) <= 100000000;
*/

int func2(unsigned long long a, unsigned long long b) {
    unsigned long long product_val;
    int result;
    
    //@ assert is_valid_range(a);
    //@ assert is_valid_range(b);
    
    //@ assert product(a, b) <= 100000000;
    
    product_val = a * b;
    result = (product_val % 2 == 0) ? 1 : 0;
    
    //@ assert result == (product(a, b) % 2 == 0);
    
    return result;
}

/*@
    predicate valid_transaction(integer X, integer batch_a, integer batch_b) =
        is_in_range(X) && is_valid_range(batch_a) && is_valid_range(batch_b);
    
    predicate transaction_integrity(integer X, integer batch_a, integer batch_b, integer found, int batch_valid) =
        (found == 1 ==> is_in_range(X)) &&
        (batch_valid == (product(batch_a, batch_b) % 2 == 0));
*/

struct transaction_result {
    int found;
    int batch_valid;
};

struct transaction_result process_transaction(long long X, unsigned long long batch_a, unsigned long long batch_b)
{
    struct transaction_result res;
    
    int found = func1(X);
    //@ assert found == 0 || found == 1;
    
    int batch_valid = func2(batch_a, batch_b);
    //@ assert batch_valid == (product(batch_a, batch_b) % 2 == 0);
    
    res.found = found;
    res.batch_valid = batch_valid;
    
    //@ assert (found == 1 ==> is_in_range(X)) && (batch_valid == (product(batch_a, batch_b) % 2 == 0));
    
    return res;
}

int main()
{
    return 0;
}
