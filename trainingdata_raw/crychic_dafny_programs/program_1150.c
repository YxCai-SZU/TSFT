// Generated C + ACSL

typedef struct {
    int createdAt;
} Order;

/*@
    requires orders_len >= 0;
    requires orders != \null;
    requires \valid(orders + (0 .. orders_len-1));
    assigns orders[0 .. orders_len-1];
*/
void AlterOrderCreatedAtField(Order* orders, int orders_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= orders_len;
  loop invariant \forall integer j; 0 <= j < i ==> orders[j].createdAt >= 0;
  loop assigns i, orders[0..orders_len-1].createdAt;
  loop variant orders_len - i;
*/
  while ((i < orders_len))
    {
      orders[i].createdAt = 0;
      i = (i + 1);
    }
}