// #1
const products = document.getElementById("products");
console.log("products: ",products);
// #2a
const form=document.getElementsByTagName("form")
console.log("form: ",form);
// #2b
const querySecond=document.querySelector("form");
console.log("second query input: ",querySecond[1]);
// #2c
const queryAll=document.querySelectorAll("input");
console.log("all inputs:");
for (let i=0;i<queryAll.length;++i)
{
    console.log(queryAll[i]);
}
// #2d
console.log(document.getElementsByTagName("form")[0].outerHTML)
// #3
function display()
{
    alert("Submitted!");
    addNewLine();
}
document.addEventListener("submit",display);
// #4,5,6
let val=0;
function addNewLine()
{
    let txt=document.querySelector('[name="description"]').value;
    let txt2=document.querySelector('[name="quantity"]').value;
    let createNewTxt=document.createTextNode(txt);
    let createNewTxt2=document.createTextNode(txt2);
    let row = document.createElement("tr");
    let html ='<td>' + createNewTxt.nodeValue + '</td>' + 
    '<td>' + createNewTxt2.nodeValue + '</td>'
    + '<td>' + ' <button id=val "button onclick="rmChild(this)">Remove</button> ' 
    + '</td>';
    row.innerHTML=html;
    products.appendChild(row);
    val+=parseInt(createNewTxt2.nodeValue);
    document.getElementById("total").innerHTML=val;
}

function rmChild(button)
{
    let child=button.parentNode.parentNode.firstChild;
    child=child.nextSibling.innerHTML;
    val-=parseInt(child);
    document.getElementById("total").innerHTML=val;
    products.removeChild(button.parentNode.parentNode);
}