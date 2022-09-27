function findLogestWord(text)
{
    let txtArr=text.split(" ");
    let longestWord=txtArr[0].length,index=0,largestIndex=0;
    for (index=0;index < txtArr.length; ++index)
    {
        if (txtArr[index].length > longestWord)
        {
            longestWord=txtArr[index].length;
            largestIndex=index;
        }
    }
    return txtArr[largestIndex];
}
console.log(findLogestWord("Jack and Jill went up the hill"));