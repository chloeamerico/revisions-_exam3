

int main(void)
{
	int	x;

	// Test NULL pointer
	x = ft_printf("Pointer test: %p\n", (void *)0);
	printf("return value :%d\n", x);
    x = printf("Pointer test: %p\n", (void *)0);
	printf("return value :%d\n", x);

    // Test character
    x = ft_printf("Character test: %c\n", 'A');
	printf("return value :%d\n", x);
x =     printf("Character test: %c\n", 'A');
	printf("return value :%d\n", x);

    // Test pourcentage avec ft_printf
    x = ft_printf("Percentage test: %%\n");
    printf("ft_printf return value: %d\n", x);

    // Test pourcentage avec printf standard
    x = printf("Percentage test: %%\n");
    printf("printf return value: %d\n", x);

    // Test string
    x = ft_printf("String test: %s\n", "");
	printf("return value :%d\n", x);
x =     printf("String test: %s\n", "");
	printf("return value :%d\n", x);

    // Test pointer
    x = 42;
    x = ft_printf("Pointer test: %p\n", &x);
	printf("return value :%d\n", x);
    x = 42;
x =     printf("Pointer test: %p\n", &x);
	printf("return value :%d\n", x);


    // Test integer (decimal)
    x = ft_printf("Integer test: %d\n", 12345);
	printf("return value :%d\n", x);
x =     printf("Integer test: %d\n", 12345);
	printf("return value :%d\n", x);

    // Test integer (signed)
    x = ft_printf("Signed integer test: %i\n", -6789);
	printf("return value :%d\n", x);
x =     printf("Signed integer test: %i\n", -6789);
	printf("return value :%d\n", x);

    // Test unsigned integer
    x = ft_printf("Unsigned integer test: %u\n", 3000000000u);
	printf("return value :%d\n", x);
x =     printf("Unsigned integer test: %u\n", 3000000000u);
	printf("return value :%d\n", x);

    // Test hexadecimal (lowercase)
    x = ft_printf("Hexadecimal test (lowercase): %x\n", 255);
	printf("return value :%d\n", x);
x =     printf("Hexadecimal test (lowercase): %x\n", 255);
	printf("return value :%d\n", x);

    // Test hexadecimal (uppercase)
    x = ft_printf("Hexadecimal test (uppercase): %X\n", 255);
	printf("return value :%d\n", x);
x =     printf("Hexadecimal test (uppercase): %X\n", 255);
	printf("return value :%d\n", x);

    // Test mixing all formats
    x = ft_printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n",
              'Z', "42", &x, 42, -42, 42, 42, 42);
	printf("return value :%d\n", x);
x =     printf("Mix test: %c, %s, %p, %d, %i, %u, %x, %X\n",
              'Z', "42", &x, 42, -42, 42, 42, 42);
	printf("return value :%d\n", x);
	
    x = ft_printf("Pointer test: %p\n", (void *)0);
	printf("return value :%d\n", x);
    x = printf("Pointer test: %p\n", (void *)0);
	printf("return value :%d\n", x);

    // printf("%d\n", printf(0));
    // ft_printf("%d\n", ft_printf(0));

    printf("%s\n", "");
    ft_printf("%s\n", "");

    return 0;
}