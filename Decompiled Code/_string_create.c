
long * _string_create(char *param_1)

{
  long *plVar1;
  long lVar2;
  size_t local_30;
  
  plVar1 = (long *)_malloc(0x20);
  if (plVar1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory allocation failed for String object in string_create.\n");
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  if (param_1 == (char *)0x0) {
    local_30 = 0;
  }
  else {
    local_30 = _strlen(param_1);
  }
  plVar1[1] = local_30;
  plVar1[2] = local_30 + 0x20;
  lVar2 = _memory_pool_create(1000000);
  plVar1[3] = lVar2;
  if (plVar1[3] == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory pool creation failed in string_create.\n");
    _free(plVar1);
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  lVar2 = _memory_pool_allocate(plVar1[3],plVar1[2]);
  *plVar1 = lVar2;
  if (*plVar1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Memory pool allocation failed in string_create.\n");
    _memory_pool_destroy(plVar1[3]);
    _free(plVar1);
                    /* WARNING: Subroutine does not return */
    _exit(-1);
  }
  if (param_1 != (char *)0x0) {
    ___strcpy_chk(*plVar1,param_1,0xffffffffffffffff);
  }
  return plVar1;
}

