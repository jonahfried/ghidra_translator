
undefined8 _string_from_int(undefined4 param_1)

{
  undefined8 uVar1;
  undefined local_1c [12];
  long local_10;
  
  local_10 = *(long *)PTR____stack_chk_guard_10000a030;
  ___sprintf_chk(local_1c,0,0xc,"%d",param_1);
  uVar1 = _string_create(local_1c);
  if (*(long *)PTR____stack_chk_guard_10000a030 == local_10) {
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  ___stack_chk_fail();
}

