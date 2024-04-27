
void _string_to_title(long *param_1)

{
  bool bVar1;
  int iVar2;
  ulong local_20;
  
  if (param_1 == (long *)0x0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The String object is NULL in string_to_title.\n");
  }
  else if (*param_1 == 0) {
    _fprintf(*(FILE **)PTR____stderrp_10000a038,
             "Error: The dataStr of String object is NULL in string_to_title.\n");
  }
  else {
    bVar1 = true;
    for (local_20 = 0; local_20 < (ulong)param_1[1]; local_20 = local_20 + 1) {
      if ((bVar1) && (iVar2 = _isalpha((int)*(char *)(*param_1 + local_20)), iVar2 != 0)) {
        iVar2 = _toupper((int)*(char *)(*param_1 + local_20));
        *(char *)(*param_1 + local_20) = (char)iVar2;
        bVar1 = false;
      }
      else {
        iVar2 = _isalpha((int)*(char *)(*param_1 + local_20));
        if (iVar2 == 0) {
          bVar1 = true;
        }
        else {
          iVar2 = _tolower((int)*(char *)(*param_1 + local_20));
          *(char *)(*param_1 + local_20) = (char)iVar2;
        }
      }
    }
  }
  return;
}

