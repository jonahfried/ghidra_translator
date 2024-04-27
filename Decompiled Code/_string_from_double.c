
undefined8 _string_from_double(undefined8 param_1)

{
  undefined8 uVar1;
  undefined local_38 [40];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___snprintf_chk(param_1,local_38,0x20,0,0x20,"%f");
  uVar1 = _string_create(local_38);
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

