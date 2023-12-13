#include "include/utils.h"

void ReadLebUnsigned(u64 *o_value, u32 i_maxNumBits, bytes *io_bytes, bytes i_end)
{
    u64 result = 0;
    u32 shift = 0;
    u8 byte = 0;
    do
    {
        if (io_bytes >= i_end)
        {
            printf("ReadLebUnsigned: unexpected end\n");
            return;
        }
        byte = *io_bytes;
        io_bytes++;
        result |= ((u64)(byte & 0x7f)) << shift;
        shift += 7;
    } while (byte & 0x80);
    if (shift > i_maxNumBits)
    {
        printf("ReadLebUnsigned: number too large\n");
        return;
    }
    *o_value = result;
}