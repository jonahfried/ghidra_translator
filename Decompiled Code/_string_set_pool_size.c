
undefined _string_set_pool_size(long *param_1,long param_2)

{
  long lVar1;
  undefined local_9;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input - \'str\' is NULL in string_set_pool_size.\n");
    local_9 = 0;
  }
  else if (param_2 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Invalid input - \'newSize\' is zero in string_set_pool_size.\n");
    local_9 = 0;
  }
  else {
    if (param_1[3] != 0) {
      _memory_pool_destroy(param_1[3]);
      param_1[3] = 0;
    }
    lVar1 = _memory_pool_create(param_2);
    param_1[3] = lVar1;
    if (param_1[3] == 0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to create a new memory pool in string_set_pool_size.\n");
      local_9 = 0;
    }
    else {
      if ((param_1[1] != 0) && (*param_1 != 0)) {
        lVar1 = _memory_pool_allocate(param_1[3],param_1[1] + 1);
        if (lVar1 == 0) {
          _fprintf(*(FILE **)PTR____stderrp_10000a038,
                   "Error: Failed to allocate memory for string data in the new pool in string_set_pool_size.\n"
                  );
          _memory_pool_destroy(param_1[3]);
          param_1[3] = 0;
          return 0;
        }
        ___memcpy_chk(lVar1,*param_1,param_1[1],0xffffffffffffffff);
        *(undefined *)(lVar1 + param_1[1]) = 0;
        *param_1 = lVar1;
      }
      local_9 = 1;
    }
  }
  return local_9;
}

