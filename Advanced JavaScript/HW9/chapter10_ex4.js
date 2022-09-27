function sort(...values)
{
    let i,j;
    let length=values.length;
    for (i=0;i<length;i++)
    {
        // last item is sorted
        for (j=0;j<length-i-1;j++)
        {
            if (values[j] > values[j+1])
            {
                let tmp=values[j];
                values[j]=values[j+1];
                values[j+1]=tmp;
            }
        }
    }
    return values;
}
console.log(sort(10,54,23,90,1,35,6,12));