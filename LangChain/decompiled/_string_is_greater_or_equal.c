
bool _string_is_greater_or_equal(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  
  iVar1 = _string_compare(param_1,param_2);
  return -1 < iVar1;
}

