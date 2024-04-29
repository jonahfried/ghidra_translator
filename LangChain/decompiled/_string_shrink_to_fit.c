
void _string_shrink_to_fit(long *param_1)

{
  long lVar1;
  long lVar2;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_shrink_to_fit.\n");
  }
  else if ((param_1[1] + 1 != param_1[2]) && (*param_1 != 0)) {
    lVar1 = param_1[1];
    lVar2 = _memory_pool_allocate(param_1[3],lVar1 + 1);
    if (lVar2 == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Memory allocation failed in string_shrink_to_fit.\n");
    }
    else {
      ___memcpy_chk(lVar2,*param_1,param_1[1],0xffffffffffffffff);
      *(undefined *)(lVar2 + param_1[1]) = 0;
      *param_1 = lVar2;
      param_1[2] = lVar1 + 1;
    }
  }
  return;
}

