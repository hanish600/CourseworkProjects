function specialMultiply(num1,num2)
{
    if (arguments.length == 2)
    {
        return num1 * num2;
    }
    // first arg must be passed
    return function(num2) {
        return num1*num2;
    }
}
console.log(specialMultiply(3,4));
console.log(specialMultiply(3)(4));
console.log(specialMultiply(3));