function addNumber(...args)
{
    return sum = args.reduce(function(a,b)
    {
        return a+b;
    }, 0);
}
console.log(addNumber(2,4,5));
console.log(addNumber(10,45,34,130))