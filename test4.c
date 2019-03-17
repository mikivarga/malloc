int main()
{
char *str1, *str2;

str1 = (char *)malloc(24);

str1[10] = 'A';
str1[1] = 'B';
str2 = (char *)malloc(110);
//malloc(1024 * 1024);
//malloc(1024 * 1024 * 16);
//malloc(1024 * 1024 * 128);
show_alloc_mem_ex();
return (0);
}