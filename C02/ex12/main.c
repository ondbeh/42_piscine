#include <unistd.h>

// Function prototype for ft_print_memory
void *ft_print_memory(void *addr, unsigned int size);

int main() {
    // Test 1: Standard string with printable and non-printable characters
    char data1[] = "Bonjour les aminches...\t\n\tc'est fou\ttout ce qu'on peut faire avec...\n\nprint_memory\n\nlol.lol\n ";
    write(1, "Test 1:\n", 8);
    ft_print_memory(data1, sizeof(data1));
    write(1, "\n", 1);

    // Expected Output for Test 1:
    // 0000000107ff9f40: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin
    // 0000000107ff9f50: 6368 6573 2e2e 2e09 0a09 6327 6573 7420 ches....'.c'est 
    // 0000000107ff9f60: 666f 7520 746f 7574 2063 6520 7175 206f fou tout ce qu on
    // 0000000107ff9f70: 2070 6575 7420 6661 6972 6520 6176 6563 peut faire avec.
    // 0000000107ff9f80: 0a0a 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..
    // 0000000107ff9f90: 0a09 6c6f 6c2e 6c6f 6c0a 2000 0000 0000 ..lol.lol. ....

    // Test 2: Empty string
    char data2[] = "";
    write(1, "Test 2:\n", 8);
    ft_print_memory(data2, sizeof(data2) - 1);
    write(1, "\n", 1);

    // Expected Output for Test 2:
    // (Nothing should be displayed)

    // Test 3: String with only non-printable characters
    char data3[] = "\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0A\x0B\x0C\x0D\x0E\x0F";
    write(1, "Test 3:\n", 8);
    ft_print_memory(data3, sizeof(data3) - 1);
    write(1, "\n", 1);

    // Expected Output for Test 3:
    // 0000000107ff9fa0: 0102 0304 0506 0708 090a 0b0c 0d0e 0f   ................
    
    // Test 4: String with exactly 16 characters
    char data4[] = "1234567890abcdef";
    write(1, "Test 4:\n", 8);
    ft_print_memory(data4, sizeof(data4) - 1);
    write(1, "\n", 1);

    // Expected Output for Test 4:
    // 0000000107ff9fb0: 3132 3334 3536 3738 3930 6162 6364 6566 1234567890abcdef

    // Test 5: String with more than 16 characters (32 characters total)
    char data5[] = "This is a test string with exactly 32 characters.";
    write(1, "Test 5:\n", 8);
    ft_print_memory(data5, sizeof(data5) - 1);
    write(1, "\n", 1);

    // Expected Output for Test 5:
    // 0000000107ff9fc0: 5468 6973 2069 7320 6120 7465 7374 2073 This is a test s
    // 0000000107ff9fd0: 7472 696e 6720 7769 7468 2065 7861 6374 tring with exact
    // 0000000107ff9fe0: 6c79 2033 3220 6368 6172 6163 7465 7273 ly 32 characters
    
    // Test 6: Memory with embedded null bytes
    char data6[] = "Hello\0world\0! This contains null\0bytes.";
    write(1, "Test 6:\n", 8);
    ft_print_memory(data6, sizeof(data6) - 1);
    write(1, "\n", 1);

    // Expected Output for Test 6:
    // 0000000107ff9ff0: 4865 6c6c 6f00 776f 726c 6400 2120 5468 Hello.world.! Th
    // 0000000107ffa000: 6973 2063 6f6e 7461 696e 7320 6e75 6c6c is contains null
    // 0000000107ffa010: 0062 7974 6573 2e00                    .bytes..

    return 0;
}
