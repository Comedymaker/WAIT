#include "include/utils.h"

void ReadLebUnsigned(u64 *o_value, u32 i_maxNumBits, bytes *io_bytes, bytes i_end)
{
    u64 value = 0;

    u32 shift = 0;
    bytes ptr = *io_bytes;

    while (ptr < i_end)
    {
        u64 byte = pgm_read_byte_far(ptr);
        ptr++;

        value |= ((byte & 0x7f) << shift);
        shift += 7;

        if ((byte & 0x80) == 0)
        {
            break;
        }

        if (shift >= i_maxNumBits)
        {
            panicf("lebOverflow!");
            break;
        }
    }

    *o_value = value;
    *io_bytes = ptr;
}
void ReadLebSigned(i64 *o_value, u32 i_maxNumBits, bytes *io_bytes, bytes i_end)
{

    i64 value = 0;

    u32 shift = 0;
    bytes ptr = *io_bytes;

    while (ptr < i_end)
    {
        u64 byte = pgm_read_byte_far(ptr);
        ptr++;

        value |= ((byte & 0x7f) << shift);
        shift += 7;

        if ((byte & 0x80) == 0)
        {
            if ((byte & 0x40) && (shift < 64)) // do sign extension
            {
                u64 extend = 0;
                value |= (~extend << shift);
            }
            break;
        }

        if (shift >= i_maxNumBits)
        {
            panicf("leb overflow");
        }
    }
    *o_value = value;
    *io_bytes = ptr;
}
void ReadLEB_u7(u8 *o_value, bytes *io_bytes, bytes i_end)
{
    u64 value;
    ReadLebUnsigned(&value, 7, io_bytes, i_end);
    *o_value = (u8)value;
}
void ReadLEB_u32(u32 *o_value, bytes *io_bytes, bytes i_end)
{
    u64 value;
    ReadLebUnsigned(&value, 32, io_bytes, i_end);
    *o_value = (u32)value;
}
void Read_u8(u8 *o_value, bytes *io_bytes, bytes i_end)
{
    bytes ptr = *io_bytes;

    if (ptr < i_end)
    {
        *o_value = pgm_read_byte_far(ptr);
        ptr += sizeof(u8);
        *io_bytes = ptr;
    }
    else
        panicf("Wasm Underrun");
}

void Read_u32(u32 *o_value, bytes *io_bytes, bytes i_end)
{
    bytes ptr = *io_bytes;
    ptr += sizeof(u32);
    
    if (ptr <= i_end)
    {
        *o_value = pgm_read_dword_far(*io_bytes);
        // memcpy(o_value, *io_bytes, sizeof(u32));
        BSWAP_u32(*o_value);
        *io_bytes = ptr;
    }
    else
    {
        panic();
    }
}

void ReadLEB_i7(i8 *o_value, bytes *io_bytes, bytes i_end)
{
    i64 value;
    ReadLebSigned(&value, 7, io_bytes, i_end);
    *o_value = (i8)value;
}
void ReadLEB_i32(i32 *o_value, bytes *io_bytes, bytes i_end)
{
    i64 value;
    ReadLebSigned(&value, 32, io_bytes, i_end);
    *o_value = (i32)value;
}

void ReadLEB_i64(i64 *o_value, bytes *io_bytes, bytes i_end)
{
    i64 value;
    ReadLebSigned(&value, 64, io_bytes, i_end);
    *o_value = value;
}