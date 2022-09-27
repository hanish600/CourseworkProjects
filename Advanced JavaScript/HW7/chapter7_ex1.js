const iterator =
{
    constructor(limit)
    {
        this.count=1;
        this.limit=limit;
    },
    data: [1,53,4,72,46],
    [Symbol.iterator]()
    {
        return this;
    },
    next() 
    {
        if (this.count<=this.limit)
        {
            return {done : false, value: this.count++};
        }
        else{
            return {done : true, value: undefined};
        }
    }
};
let arr = ['apple', 'bannana', 'monkey'];
let iter1= arr[Symbol.iterator]();
for (let x of iter1)
{
    document.write(x);
}