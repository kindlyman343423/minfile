//Dan Bernstein.
//djb2
unsigned long danhash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        // printf("%ld\n",hash);
    }
    return hash;
}