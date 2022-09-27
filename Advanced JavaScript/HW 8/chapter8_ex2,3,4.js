class Book
{
    title_="";
    author_="";
    copyrightDate_=Date(null);
    isbn_="";
    pageCount_=0;
    static checkoutCount_=0;
    bookType_="";
    checkout=false;
    constructor(title,author,copyrightDate,
        isbn,pages,checkoutCount,type)
    {
        this.title_=String(title);
        this.author_=String(author);
        this.copyrightDate_=new Date(copyrightDate)
        this.isbn_=String(isbn);
        this.pageCount_=Number(pages);
        this.checkoutCount_=Number(checkoutCount);
        if (type==="Manual" || type==="Novel")
        {
            this.bookType_=String(type);
        }
        
        else
        {
            this.bookType_="unknown";
        }
    }
    set title(title)
    {
        this.title_=title;
    }
    set authors(author)
    {
        this.author_=author;
    }
    set copyrightDate(copyrightDate)
    {
        this.copyrightDate_=new Date(copyrightDate);
    }
    set isbn(isbn)
    {
        this.isbn_=isbn;
    }
    set pageCount(pages)
    {
        this.pageCount_=pages;
    }
    set checkoutCount(checkoutCount)
    {
        this.checkoutCount_=checkoutCount;
    }
    set bookType(bookType)
    {
        this.bookType_=bookType;
    }
    get title()
    {
        return this.title_;
    }
    get author()
    {
        return this.author_;
    }
    get copyrightDate()
    {
        return this.copyrightDate_;
    }
    get isbn()
    {
        return this.isbn_;
    }
    get pages()
    {
        return this.pageCount_;
    }
    get checkoutCount()
    {
        return this.checkoutCount_;
    }
    get bookType()
    {
        return this.bookType_;
    }
    isAvailable()
    {
        if (!this.checkout)
        {
            return true;
        }
        return false;
    }
    checkoutBook()
    {
        if (this.checkout)
        {
            console.log("This book is checked out. ")
            return false;
        }
        this.checkout=true;
        console.log("Checking out book...",'\n');
        return true;
    }
    displayBook()
    {
        console.log("Title: ",this.title_);
        console.log("Author: ",this.author_);
        console.log("Copyright Date: ",this.copyrightDate_);
        console.log("ISBN: ",this.isbn_);
        console.log("Total Pages: ",this.pageCount_);
        console.log("Times Checked Out: ",this.checkoutCount_);
        console.log("Type of Book: ",this.bookType_);
        if (this.checkout)
        {
            console.log("Available Status: Unavailable");
        }
        else
        {
            console.log("Available Status: Available",);
        }
    }
};

class Manual extends Book
{
    productName="";
    productCode="";
    manufacturerName="";
    constructor(title,author,copyrightDate,
        isbn,pages,checkoutCount,type,productName,
        productCode,manufacturerName)
    {
        super(title,author,copyrightDate,isbn,pages,checkoutCount,type);
        this.productName=String(productName);
        this.productCode=String(productCode);
        this.manufacturerName=String(manufacturerName);
    }
    set productName(productName)
    {
        this.productName=productName;
    }
    set productCode(productCode)
    {
        this.productCode=productCode;
    }
    set manufacturerName(manufacturerName)
    {
        this.manufacturerName=manufacturerName;
    }
    get productName()
    {
        return this.productName;
    }
    get productCode()
    {
        return this.productCode;
    }
    get manufacturerName()
    {
        return this.manufacturerName;
    }
    disp()
    {
        console.log("Product Name: ",this.productName);
        console.log("Product Code: ",this.productCode);
        console.log("Manufacturer Name: ",this.manufacturerName);
    }
    displayBook()
    {
        super.displayBook();
        this.disp();
    }
};

class Novel extends Book
{
    publisherName="";
    authorBirthDate=Date(null);
    authorPseudonyms=[];
    count=0;
    length=1;
    constructor(title,author,copyrightDate,
        isbn,pages,checkoutCount,type,publisherName,
        authorBirthDate,authorPseudonyms)
    {
        super(title,author,copyrightDate,isbn,pages,checkoutCount,type);
        this.publisherName=String(publisherName);
        this.authorBirthDate=new Date(authorBirthDate);
        this.authorPseudonyms[this.count++]=String(authorPseudonyms);
        ++this.length;
    }
    set publisherName(publisherName)
    {
        this.publisherName=publisherName;
    }
    set authorBirthDate(authorBirthDate)
    {
        this.authorBirthDate=new Date(authorBirthDate);
    }
    set authorPseudonyms(authorPseudonyms)
    {
        this.authorPseudonyms[this.count].push(authorPseudonyms);
        ++this.length;
    }
    get publisherName()
    {
        return this.publisherName;
    }
    get authorBirthDate()
    {
        return this.authorBirthDate;
    }
    get authorPseudonyms()
    {
        return this.authorPseudonyms[this.count];
    }
    disp()
    {
        console.log("Publisher Name: ",this.publisherName);
        console.log("Author Birth Day: ",this.authorBirthDate);
        process.stdout.write("Auther Pseudonyms: ");
        for (let i=0;i<this.length-1;++i)
        {
            process.stdout.write(this.authorPseudonyms[i]);
            if (i!=this.length-2)
            {
                process.stdout.write(', ');
            }
        }
        console.log('\n');
    }
    displayBooks()
    {
        super.displayBook();
        this.disp();
    }
};

let Novel1=new Novel("Pride and Prejudice",
"Jane Austen","1813","1111111111111",432,32,"Novel","T. Egerton, Whitehall",
"December 16, 1775","A Lady");

let Manual1=new Manual("Top Secret Shuttle Building Manual",
"Redacted","2013","0000000000000",1147,1,"Manual","NASA Space Shuttle",
"SECRET-001A","NASA")

// Using Polymorphism
console.log("Book 1",'\n');
Novel1.checkoutBook();
Novel1.displayBooks();
console.log("End of Book 1",'\n');

// Using Polymorphism
console.log("Book 2",'\n');
Manual1.checkoutBook();
Manual1.displayBook();
console.log("End of Book 2",'\n');