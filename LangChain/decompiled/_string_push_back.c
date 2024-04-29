
void _string_push_back(long *param_1,undefined param_2)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_push_back.\n");
  }
  else {
    if ((ulong)param_1[2] <= param_1[1] + 1U) {
      lVar1 = param_1[2];
      lVar2 = _memory_pool_allocate(param_1[3],lVar1 << 1);
      if (lVar2 == 0) {
        _fprintf(*(FILE **)PTR____stderrp_10000a038,
                 "Error: Memory allocation failed in string_push_back.\n");
        return;
      }
      if (*param_1 != 0) {
        ___memcpy_chk(lVar2,*param_1,param_1[1],0xffffffffffffffff);
      }
      *param_1 = lVar2;
      param_1[2] = lVar1 << 1;
    }
    *(undefined *)(*param_1 + param_1[1]) = param_2;
    param_1[1] = param_1[1] + 1;
    *(undefined *)(*param_1 + param_1[1]) = 0;
  }
  return;
}

