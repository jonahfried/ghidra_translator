
void _string_swap_case(long *param_1)

{
  int iVar1;
  ulong local_18;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str is NULL in string_swap_case\n");
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,"Error: str->dataStr is NULL in string_swap_case\n")
    ;
  }
  else {
    for (local_18 = 0; local_18 < (ulong)param_1[1]; local_18 = local_18 + 1) {
      iVar1 = _islower((int)*(char *)(*param_1 + local_18));
      if (iVar1 == 0) {
        iVar1 = _isupper((int)*(char *)(*param_1 + local_18));
        if (iVar1 != 0) {
          iVar1 = _tolower((int)*(char *)(*param_1 + local_18));
          *(char *)(*param_1 + local_18) = (char)iVar1;
        }
      }
      else {
        iVar1 = _toupper((int)*(char *)(*param_1 + local_18));
        *(char *)(*param_1 + local_18) = (char)iVar1;
      }
    }
  }
  return;
}

