
bool _string_empty(long param_1)

{
  bool bVar1;
  
  if (param_1 == 0) {
    bVar1 = true;
  }
  else {
    bVar1 = *(long *)(param_1 + 8) == 0;
  }
  return bVar1;
}

