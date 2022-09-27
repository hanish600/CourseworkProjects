function reverseNumber(sum)
{
    let lastDigit;
    let num=sum;
    sum=0;
    while (num)
    {
        lastDigit = num % 10;
        sum *= 10;
        sum += lastDigit;
        num = Math.floor(num / 10);
    }
    return sum;
}

console.log(reverseNumber(123));