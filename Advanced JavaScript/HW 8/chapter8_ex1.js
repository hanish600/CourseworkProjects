class Person
{
    age_;
    name_="";
    constructor(name,age)
    {
       this.name_=name;
       this.age_=age;
    }
    describe()
    {
        console.log(this.name_,",",this.age_," years old");
    }
};

let person = new Person("John",19);
person.describe();