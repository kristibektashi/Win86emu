/////////////////////////////////////////////////////////////////////////
// $Id: bit16.cc,v 1.20 2010/10/18 22:19:45 sshwarts Exp $
/////////////////////////////////////////////////////////////////////////
//
//  Copyright (C) 2001-2009  The Bochs Project
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA B 02110-1301 USA
/////////////////////////////////////////////////////////////////////////

#define NEED_CPU_REG_SHORTCUTS 1
#include "bochs.h"
#include "cpu.h"
#define LOG_THIS BX_CPU_THIS_PTR

#if BX_CPU_LEVEL >= 3

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BSF_GwEwR(bxInstruction_c *i)
{
  Bit16u op2_16 = BX_READ_16BIT_REG(i->rm());

  if (op2_16 == 0) {
    assert_ZF(); /* op1_16 undefined */
  }
  else {
    Bit16u op1_16 = 0;
    while ((op2_16 & 0x01) == 0) {
      op1_16++;
      op2_16 >>= 1;
    }

    SET_FLAGS_OSZAPC_LOGIC_16(op1_16);
    clear_ZF();

    /* now write result back to destination */
    BX_WRITE_16BIT_REG(i->nnn(), op1_16);
  }
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BSR_GwEwR(bxInstruction_c *i)
{
  Bit16u op2_16 = BX_READ_16BIT_REG(i->rm());

  if (op2_16 == 0) {
    assert_ZF(); /* op1_16 undefined */
  }
  else {
    Bit16u op1_16 = 15;
    while ((op2_16 & 0x8000) == 0) {
      op1_16--;
      op2_16 <<= 1;
    }

    SET_FLAGS_OSZAPC_LOGIC_16(op1_16);
    clear_ZF();

    /* now write result back to destination */
    BX_WRITE_16BIT_REG(i->nnn(), op1_16);
  }
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BT_EwGwM(bxInstruction_c *i)
{
  bx_address op1_addr;
  Bit16u op1_16, op2_16, index;
  Bit32s displacement32;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  op2_16 = BX_READ_16BIT_REG(i->nnn());
  index = op2_16 & 0x0f;
  displacement32 = ((Bit16s) (op2_16&0xfff0)) / 16;
  op1_addr = eaddr + 2 * displacement32;

  /* pointer, segment address pair */
  op1_16 = read_virtual_word(i->seg(), op1_addr & i->asize_mask());

  set_CF((op1_16 >> index) & 0x01);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BT_EwGwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->rm());
  op2_16 = BX_READ_16BIT_REG(i->nnn());
  op2_16 &= 0x0f;
  set_CF((op1_16 >> op2_16) & 0x01);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTS_EwGwM(bxInstruction_c *i)
{
  bx_address op1_addr;
  Bit16u op1_16, op2_16, index;
  Bit32s displacement32;
  bx_bool bit_i;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  op2_16 = BX_READ_16BIT_REG(i->nnn());
  index = op2_16 & 0x0f;
  displacement32 = ((Bit16s) (op2_16 & 0xfff0)) / 16;
  op1_addr = eaddr + 2 * displacement32;

  /* pointer, segment address pair */
  op1_16 = read_RMW_virtual_word(i->seg(), op1_addr & i->asize_mask());
  bit_i = (op1_16 >> index) & 0x01;
  op1_16 |= (((Bit16u) 1) << index);
  write_RMW_virtual_word(op1_16);

  set_CF(bit_i);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTS_EwGwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->rm());
  op2_16 = BX_READ_16BIT_REG(i->nnn());
  op2_16 &= 0x0f;
  set_CF((op1_16 >> op2_16) & 0x01);
  op1_16 |= (((Bit16u) 1) << op2_16);

  /* now write result back to the destination */
  BX_WRITE_16BIT_REG(i->rm(), op1_16);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTR_EwGwM(bxInstruction_c *i)
{
  bx_address op1_addr;
  Bit16u op1_16, op2_16, index;
  Bit32s displacement32;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  op2_16 = BX_READ_16BIT_REG(i->nnn());
  index = op2_16 & 0x0f;
  displacement32 = ((Bit16s) (op2_16&0xfff0)) / 16;
  op1_addr = eaddr + 2 * displacement32;

  /* pointer, segment address pair */
  op1_16 = read_RMW_virtual_word(i->seg(), op1_addr & i->asize_mask());
  bx_bool temp_cf = (op1_16 >> index) & 0x01;
  op1_16 &= ~(((Bit16u) 1) << index);

  /* now write back to destination */
  write_RMW_virtual_word(op1_16);

  set_CF(temp_cf);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTR_EwGwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->rm());
  op2_16 = BX_READ_16BIT_REG(i->nnn());
  op2_16 &= 0x0f;
  set_CF((op1_16 >> op2_16) & 0x01);
  op1_16 &= ~(((Bit16u) 1) << op2_16);

  /* now write result back to the destination */
  BX_WRITE_16BIT_REG(i->rm(), op1_16);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTC_EwGwM(bxInstruction_c *i)
{
  bx_address op1_addr;
  Bit16u op1_16, op2_16, index_16;
  Bit16s displacement16;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  op2_16 = BX_READ_16BIT_REG(i->nnn());
  index_16 = op2_16 & 0x0f;
  displacement16 = ((Bit16s) (op2_16 & 0xfff0)) / 16;
  op1_addr = eaddr + 2 * displacement16;

  op1_16 = read_RMW_virtual_word(i->seg(), op1_addr & i->asize_mask());
  bx_bool temp_CF = (op1_16 >> index_16) & 0x01;
  op1_16 ^= (((Bit16u) 1) << index_16);  /* toggle bit */
  write_RMW_virtual_word(op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTC_EwGwR(bxInstruction_c *i)
{
  Bit16u op1_16, op2_16;

  op1_16 = BX_READ_16BIT_REG(i->rm());
  op2_16 = BX_READ_16BIT_REG(i->nnn());
  op2_16 &= 0x0f;

  bx_bool temp_CF = (op1_16 >> op2_16) & 0x01;
  op1_16 ^= (((Bit16u) 1) << op2_16);  /* toggle bit */
  BX_WRITE_16BIT_REG(i->rm(), op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BT_EwIbM(bxInstruction_c *i)
{
  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  Bit16u op1_16 = read_virtual_word(i->seg(), eaddr);
  Bit8u  op2_8  = i->Ib() & 0xf;

  set_CF((op1_16 >> op2_8) & 0x01);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BT_EwIbR(bxInstruction_c *i)
{
  Bit16u op1_16 = BX_READ_16BIT_REG(i->rm());
  Bit8u  op2_8  = i->Ib() & 0xf;

  set_CF((op1_16 >> op2_8) & 0x01);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTS_EwIbM(bxInstruction_c *i)
{
  Bit8u op2_8 = i->Ib() & 0xf;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  Bit16u op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  bx_bool temp_CF = (op1_16 >> op2_8) & 0x01;
  op1_16 |= (((Bit16u) 1) << op2_8);
  write_RMW_virtual_word(op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTS_EwIbR(bxInstruction_c *i)
{
  Bit8u op2_8 = i->Ib() & 0xf;

  Bit16u op1_16 = BX_READ_16BIT_REG(i->rm());
  bx_bool temp_CF = (op1_16 >> op2_8) & 0x01;
  op1_16 |= (((Bit16u) 1) << op2_8);
  BX_WRITE_16BIT_REG(i->rm(), op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTC_EwIbM(bxInstruction_c *i)
{
  Bit8u op2_8 = i->Ib() & 0xf;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  Bit16u op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  bx_bool temp_CF = (op1_16 >> op2_8) & 0x01;
  op1_16 ^= (((Bit16u) 1) << op2_8);  /* toggle bit */
  write_RMW_virtual_word(op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTC_EwIbR(bxInstruction_c *i)
{
  Bit8u op2_8 = i->Ib() & 0xf;

  Bit16u op1_16 = BX_READ_16BIT_REG(i->rm());
  bx_bool temp_CF = (op1_16 >> op2_8) & 0x01;
  op1_16 ^= (((Bit16u) 1) << op2_8);  /* toggle bit */
  BX_WRITE_16BIT_REG(i->rm(), op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTR_EwIbM(bxInstruction_c *i)
{
  Bit8u op2_8 = i->Ib() & 0xf;

  bx_address eaddr = BX_CPU_CALL_METHODR(i->ResolveModrm, (i));

  Bit16u op1_16 = read_RMW_virtual_word(i->seg(), eaddr);
  bx_bool temp_CF = (op1_16 >> op2_8) & 0x01;
  op1_16 &= ~(((Bit16u) 1) << op2_8);
  write_RMW_virtual_word(op1_16);

  set_CF(temp_CF);
}

void BX_CPP_AttrRegparmN(1) BX_CPU_C::BTR_EwIbR(bxInstruction_c *i)
{
  Bit8u op2_8 = i->Ib() & 0xf;

  Bit16u op1_16 = BX_READ_16BIT_REG(i->rm());
  bx_bool temp_CF = (op1_16 >> op2_8) & 0x01;
  op1_16 &= ~(((Bit16u) 1) << op2_8);
  BX_WRITE_16BIT_REG(i->rm(), op1_16);

  set_CF(temp_CF);
}

/* F3 0F B8 */
void BX_CPP_AttrRegparmN(1) BX_CPU_C::POPCNT_GwEwR(bxInstruction_c *i)
{
  Bit16u op2_16 = BX_READ_16BIT_REG(i->rm());

  Bit16u op1_16 = 0;
  while (op2_16 != 0) {
    if (op2_16 & 1) op1_16++;
    op2_16 >>= 1;
  }

  Bit32u flags = op1_16 ? 0 : EFlagsZFMask;
  setEFlagsOSZAPC(flags);

  /* now write result back to destination */
  BX_WRITE_16BIT_REG(i->nnn(), op1_16);
}

#endif // (BX_CPU_LEVEL >= 3)