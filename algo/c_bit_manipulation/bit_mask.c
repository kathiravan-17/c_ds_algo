#include <stdio.h>
#include <stdint.h>

#define BIT(n) (UINT32_C(1) << (n))

int main(void)
{
    uint32_t mask = BIT(5);

    printf("Mask = 0x%X\n", mask);
    printf("Decimal = %u\n", mask);

    return 0;
}
