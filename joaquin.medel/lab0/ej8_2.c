int main()
{
    char a = 0b0000111;
    char c = ~(a >> 2);
    printf("\n %x \n", c);

    return 0;
}