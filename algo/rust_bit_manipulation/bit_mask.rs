// 1u32 = the literal 1 with type u32 (unsigned 32-bit), like UINT32_C(1) in C.
// The suffix fixes the type, so 1u32 << 5 is a u32 shift = 0x20 (32).
fn main() {
    let mask: u32 = 1u32 << 5;

    println!("Mask = 0x{:X}", mask);
    println!("Decimal = {}", mask);
}
