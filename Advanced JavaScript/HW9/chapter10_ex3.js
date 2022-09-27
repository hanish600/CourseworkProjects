function factorial(num=6)
{
    if (num==1 || num == 0)
    {
        return 1;
    }
    return num * factorial(num-1);
}
console.log(factorial(3));
console.log(factorial(5));