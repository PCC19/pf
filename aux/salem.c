int main(void)
{
    int value = 4718592;
    int i;
    double result;
    double mult;
    i = 22;
    result = 1;
    mult = 2;
    while (i >= 0)
    {
        if ((value & pot_b(i, 2)) == pot_b(i, 2))
        {
            printf("%ld\n", pot_b(i, 2));
            result += 1 / mult;
        }
        mult *= 2;
        i--;
    }
    result *= pot_b(4, 2);
    printf("%f\n", result);
    return (0);
}
