#include <stdbool.h>
#include <stddef.h>

enum Fruit_Tag {
    Apple,
    Lemon,
    Berry
};

struct Fruit {
    enum Fruit_Tag tag;
    union {
        struct {
            char* variety;
            unsigned char sweetness;
        } Apple;
        struct {
            char* variety;
            unsigned char sourness;
        } Lemon;
        struct {
            char* type_;
            unsigned char seeds;
        } Berry;
    } data;
};

/*@ predicate is_valid_fruit(struct Fruit f) =
      f.tag == Apple || f.tag == Lemon || f.tag == Berry;
*/

/*@ predicate is_apple_or_lemon(struct Fruit f) =
      f.tag == Apple || f.tag == Lemon;
*/

/*@ predicate satisfies_condition(struct Fruit f) =
      f.tag == Apple || (f.tag == Lemon && f.data.Lemon.sourness > 5);
*/

/*@ logic integer fruit_count(struct Fruit* basket, integer length) =
      length;
*/

/*@ lemma all_satisfy_condition:
      \forall struct Fruit* basket, integer length;
      (\forall integer i; 0 <= i < length ==> satisfies_condition(basket[i])) ==>
      (\forall integer j; 0 <= j < length ==> satisfies_condition(basket[j]));
*/

/*@ requires length > 0;
    requires \forall integer i; 0 <= i < length ==> is_apple_or_lemon(fruit_basket[i]);
    ensures \result == true <==> 
            (\forall integer i; 0 <= i < length ==> satisfies_condition(fruit_basket[i]));
*/
bool func(struct Fruit* fruit_basket, size_t length)
{
    size_t i = 0;
    bool result = true;
    
    /*@ loop invariant 0 <= i <= length;
        loop invariant \forall integer j; 0 <= j < i ==> satisfies_condition(fruit_basket[j]);
        loop invariant \forall integer k; 0 <= k < length ==> is_apple_or_lemon(fruit_basket[k]);
        loop invariant result == true;
        loop assigns i, result;
        loop variant length - i;
    */
    while (i < length) {
        struct Fruit fruit = fruit_basket[i];
        
        if (fruit.tag == Lemon) {
            if (fruit.data.Lemon.sourness <= 5) {
                result = false;
                //@ assert !satisfies_condition(fruit);
                return result;
            }
        }
        
        i = i + 1;
    }
    
    //@ assert \forall integer j; 0 <= j < length ==> satisfies_condition(fruit_basket[j]);
    return result;
}

int main() {
    return 0;
}
