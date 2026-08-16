// Generated C + ACSL

typedef struct {
  char* productName;
  int productLevel;
} Product;

/*@
    requires newName != \null;
    requires newName_len > 0 && newName_len <= 200;
    requires \valid_read(newName + (0 .. newName_len-1));
    requires newLevel >= 1;
    requires \valid(this);
    assigns this->productName, this->productLevel;
    ensures \result == 1;
*/
int UpdateProduct(Product* this, char* newName, int newName_len, int newLevel)
{
  this->productName = newName;
  this->productLevel = newLevel;
  return 1;
}

/*@
  predicate IsValid(char *warehouseCode, integer warehouseCode_len,
                    char *warehouseName, integer warehouseName_len,
                    char *address, integer address_len,
                    integer warehouseType, integer yn) =
    warehouseCode_len <= 99 && warehouseCode_len > 0 &&
    warehouseName_len <= 255 && warehouseName_len > 0 &&
    address_len <= 255 && address_len > 0 &&
    warehouseType >= 1 &&
    (yn == 0 || yn == 1);
*/