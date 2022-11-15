// Exercise 1

// create buffer size 2
let sharedArrayBuff = new SharedArrayBuffer(2);

// create uint16array from buffer
let typedArr = new Uint16Array(sharedArrayBuff);

// part A
// index = 0, increment=5;
// add 5 in index 0
Atomics.add(typedArr,0,5);
console.log(typedArr);

// part B
// subtract 5 in index 0
Atomics.sub(typedArr,0,5);
console.log(typedArr);

// part C
// bitwise and in index 0 position
Atomics.and(typedArr,0,0b1100);
console.log(typedArr);

// part D
// bitwise or in index 0 position
Atomics.or(typedArr,0,0b1111);
console.log(typedArr);

// part E
// exchange value two in index 0 position
Atomics.exchange(typedArr,0,2);
console.log(typedArr);

// Exercise 2
console.log();
console.log("Exercise 2: ");
// 1 encode text
// Use encodeURI for full URL and encodeURIComponent for query strings
// Use encode/decode text for utf-8
console.log(`encodeURI("https://test.com/path to a pdf.pdf")`)
console.log(`http://test.com/?search=\${encodeURIComponent('encode param')}`);


// 2 decode text
// Use decodeURI for full URL and decodeURIComponent for query strings
console.log(`decodeURI("http://testing.com/")`)
console.log(`decodeURIComponent("http%3A%2F%2Ftesting.com%2F")`);

console.log("Examples of encoded txt instead");
const txtEnc=new TextEncoder();
const encTxt=txtEnc.encode("Hello World");
console.log(encTxt);
console.log("Examples of decoded txt");
const encodedTxt=Uint32Array.of(102,111,111);
const txtDec=new TextDecoder();
const decTxt = txtDec.decode(encodedTxt);
console.log(decTxt);
console.log("Other functions include textEncoderStream and TextDecoderStream for txtEncoder/Decoder in the form of transform stream")
console.log("Use cases include for text chunks inside a function")
console.log("For example: `const decodedTextStream = new ReadableStream({ async start(controller) {for await (let chunk of chars()) {controller.enqueue(chunk);}controller.close();}})`");
// Exercise 3
console.log();
console.log("Exercise 3: ");
console.log("starting date.now()");
const start = Date.now();
setTimeout(() => {
    const timeFin = Date.now()-start;
    console.log("Program exec spd = ",(timeFin/1000),"secs");
},1000);
// Exercise 4
console.log();
console.log("Exercise 4");
// Creating frags
console.log("const dfrag = document.createDocumentFragent()");
// appending frags
console.log("drag.appendChild(li)");

// Exercise 5
console.log();
console.log("Exercise 5");
console.log("Generate a signature key");
console.log("Use the method crypto.subtle.generateKey(paramters,extractable?,keyUsage);");
console.log("Generate key using keyparams");
console.log("1) create a keyParams functions 2) Use crypto.subtle.generateKey(keyParams, extractable?, keyUsages);");
console.log("Encrypting keys");
console.log("Use crypto.subtle.encrypt(algorithm,key,data)");
console.log("Decrypting keys");
console.log("Use crypto.subtle.decrypt(algorithm,key,data)");

// Exercise 6
console.log();
console.log("Exercise 6");
console.log("1) crypto.subtle.sign(algorithm,key,data) 2) crypto.subtle.verify(algo,key,signature,data)")

// Exercise 7
console.log();
console.log("Exercise 7");
function divide(numerator,deno)
{
    try {
        if (deno==0)
        {
            throw new Error("Attempted to divide by zero");
        }
    }
    catch (err)
    {
        console.log(err);
        return;
    }
    return numerator/deno;
}

console.log("dividing 7/0 will throw an error and catch ");
divide(7,0);
console.log("dividing 14/7",divide(14,7));

console.log();
console.log("Result of ex. 3");