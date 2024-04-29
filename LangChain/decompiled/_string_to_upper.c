
void * _string_to_upper(long *param_1)

{
  int iVar1;
  ulong local_28;
  void *local_10;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: Input \'str\' is NULL in string_to_upper function.\n");
    local_10 = (void *)0x0;
  }
  else {
    local_10 = _malloc(param_1[1] + 1);
    if (local_10 == (void *)0x0) {
      _fprintf(*(FILE **)PTR____stderrp_10000a038,
               "Error: Failed to allocate memory for string_to_upper function.\n");
                    /* WARNING: Subroutine does not return */
      _exit(-1);
    }
    for (local_28 = 0; local_28 < (ulong)param_1[1]; local_28 = local_28 + 1) {
      iVar1 = _isalpha((int)*(char *)(*param_1 + local_28));
      if (((iVar1 == 0) || (*(char *)(*param_1 + local_28) < 'a')) ||
         ('z' < *(char *)(*param_1 + local_28))) {
        *(undefined *)((long)local_10 + local_28) = *(undefined *)(*param_1 + local_28);
      }
      else {
        iVar1 = _toupper((int)*(char *)(*param_1 + local_28));
        *(char *)((long)local_10 + local_28) = (char)iVar1;
      }
    }
    *(undefined *)((long)local_10 + param_1[1]) = 0;
  }
  return local_10;
}

