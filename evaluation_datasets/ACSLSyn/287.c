#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef struct HashMap HashMap;

/*@
    axiomatic HashMapSpec {
        logic integer hashmap_get(HashMap *m, integer key);
        
        predicate valid_hashmap(HashMap *m) = \valid(m);
        predicate hashmap_contains_key(HashMap *m, integer key) = 
            \exists integer v; hashmap_get(m, key) == v;
    }
*/

void hashmap_insert(HashMap *m, int key, int value);

bool hashmap_contains_key(HashMap *m, int key);

/*@
    lemma insert_check_lemma:
        \forall HashMap *m; \forall integer k, v;
        hashmap_contains_key(m, k) && hashmap_get(m, k) == v ==>
        hashmap_contains_key(m, k) && hashmap_get(m, k) == v;
*/

void insert_and_check(HashMap *m)
{
    int key;
    int value;
    bool exists;
    
    key = 5;
    value = 10;
    //@ assert key == 5 && value == 10;
    
    hashmap_insert(m, key, value);
    //@ assert hashmap_contains_key(m, 5);
    
    exists = hashmap_contains_key(m, key);
    //@ assert exists == true;
}

void insert_three_and_check(HashMap *m)
{
    int key1, key2, key3;
    int value1, value2, value3;
    bool exists5, exists10, exists15;
    
    key1 = 5;
    value1 = 10;
    //@ assert key1 == 5 && value1 == 10;
    
    hashmap_insert(m, key1, value1);
    //@ assert hashmap_contains_key(m, 5);
    
    exists5 = hashmap_contains_key(m, key1);
    //@ assert exists5 == true;
    
    key2 = 10;
    value2 = 20;
    //@ assert key2 == 10 && value2 == 20;
    
    hashmap_insert(m, key2, value2);
    //@ assert hashmap_contains_key(m, 10);
    
    exists10 = hashmap_contains_key(m, key2);
    //@ assert exists10 == true;
    
    key3 = 15;
    value3 = 30;
    //@ assert key3 == 15 && value3 == 30;
    
    hashmap_insert(m, key3, value3);
    //@ assert hashmap_contains_key(m, 15);
    
    exists15 = hashmap_contains_key(m, key3);
    //@ assert exists15 == true;
}

/*@
    predicate valid_input(integer a, integer b) =
        3 <= a && a <= 20 && 3 <= b && b <= 20;

    predicate result_cases(integer a, integer b, integer result) =
        result == a * 2 - 1 ||
        result == b * 2 - 1 ||
        result == a + b ||
        result == b * 2;
*/

int func(int a, int b)
{
    int a_mut = a;
    int b_mut = b;
    bool swapped = false;

    if (a_mut > b_mut)
    {
        int temp = a_mut;
        a_mut = b_mut;
        b_mut = temp;
        swapped = true;
    }

    if (swapped)
    {
        if (b_mut >= a_mut * 2)
        {
            //@ assert b_mut >= a_mut * 2;
            return a_mut * 2 - 1;
        }
        else
        {
            //@ assert b_mut < a_mut * 2;
            return b_mut * 2 - 1;
        }
    }
    else
    {
        if (a_mut >= b_mut * 2)
        {
            //@ assert a_mut >= b_mut * 2;
            return b_mut * 2 - 1;
        }
        else
        {
            //@ assert a_mut < b_mut * 2;
            return a_mut + b_mut;
        }
    }
}

/*@
    predicate remainder_in_range(integer n, integer a) =
        n % 500 <= a;
*/

bool func2(unsigned int n, unsigned int a)
{
    unsigned int n_unsigned;
    unsigned int a_unsigned;
    unsigned int n_unsigned_mod_500;
    unsigned int remainder;

    n_unsigned = (unsigned int)n;
    a_unsigned = (unsigned int)a;
    n_unsigned_mod_500 = n_unsigned % 500;
    
    //@ assert n_unsigned_mod_500 < 500;
    remainder = n_unsigned_mod_500;
    
    //@ assert remainder == n_unsigned_mod_500;
    return remainder <= a_unsigned;
}


void process_student_scores(HashMap *m, int a, int b, unsigned int n, unsigned int a_rem)
{
    insert_three_and_check(m);
    //@ assert hashmap_contains_key(m, 5) && hashmap_get(m, 5) == 10;
    //@ assert hashmap_contains_key(m, 10) && hashmap_get(m, 10) == 20;
    //@ assert hashmap_contains_key(m, 15) && hashmap_get(m, 15) == 30;
    
    int bonus = func(a, b);
    //@ assert result_cases(a, b, bonus);
    
    bool remainder_ok = func2((unsigned int)bonus, a_rem);
    //@ assert remainder_ok == (bonus % 500 <= a_rem);
    
    //@ assert hashmap_contains_key(m, 5) && hashmap_get(m, 5) == 10 && hashmap_contains_key(m, 10) && hashmap_get(m, 10) == 20 && hashmap_contains_key(m, 15) && hashmap_get(m, 15) == 30 && result_cases(a, b, bonus) && (remainder_ok == (bonus % 500 <= a_rem));
}
