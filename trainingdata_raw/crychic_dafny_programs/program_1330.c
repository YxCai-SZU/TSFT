// Generated C + ACSL

/*@ logic integer add(integer x, integer y); */

/*@
  requires x >= 0;
  decreases x;
  ensures \result == x + y;
*/
int add(int x, int y)
{
  if (x == 0) {
    return y;
  } else {
    return 1 + add(x - 1, y);
  }
}

// ```c
// /*@
//   axiomatic prop_add_Zero_properties {
//     lemma prop_add_Zero_statement:
//       \forall integer x; add(x, Zero) == x;
//   }
// */
// ```

// ```c
// /*@
//   axiomatic prop_add_Succ_properties {
//     lemma prop_add_Succ_statement:
//       \forall integer x, y;
//         Succ(add(x, y)) == add(x, Succ(y));
//   }
// */
// ```

// ```c
// /*@
//   axiomatic prop_add_comm_properties {
//     lemma prop_add_comm_statement:
//       \forall integer x, y; x >= 0 && y >= 0 ==>
//         add(x, y) == add(y, x);
//   }
// */
// ```