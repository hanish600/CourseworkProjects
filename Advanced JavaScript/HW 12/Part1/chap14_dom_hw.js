// #1
const query=document.querySelector("#page-header");
console.log("query: ",query);
// #2
const nodeType=document.getElementById("page-header").nodeType;
console.log("nodeType: ",nodeType);
// #3
const nodeName=document.getElementById("page-header").nodeName;
console.log("nodeName: ",nodeName);
// #4
const childNodes_Available=document.getElementById("page-header").hasChildNodes();
console.log("child nodes: ",childNodes_Available);
// #5
const parentNodes=document.getElementById("page-header").parentElement;
console.log("Parent Node: ",parentNodes);
// #6
const childNodes=document.getElementById("page-header").childNodes
console.log("Child Nodes: ",childNodes);
// #7
console.log("sliced array: ",Array.prototype.slice.call(childNodes));
// #8
const firstItemChild=document.getElementById("page-header").firstChild
console.log("first child: ",firstItemChild);
// #9
const book_title_node=firstItemChild.nextElementSibling;
console.log("next sibling: ",book_title_node);
// #10
const book_title_node_clone=book_title_node.cloneNode(true);
console.log("True Copy of sibling: ",book_title_node_clone);
// #11
const bannerNode=query.appendChild(book_title_node_clone);
console.log("afterBanner: ",bannerNode);
// #12
const removingNode=bannerNode.parentElement.removeChild(book_title_node);
console.log("After removing node: ",removingNode);
// #13
const divs=document.getElementsByTagName("div");
console.log("Getting all divs: ",divs);
// #14
const getAll=document.getElementsByTagName("*");
console.log("Getting all elements: ",getAll);
// #15
const bookList=document.getElementById("book-list");
console.log("Getting all bookLists: ",bookList);
// #16
const createNewTxt=document.createTextNode("These are my favorite chapters!");
console.log("New txtNode",createNewTxt);
// #17
document.body.appendChild(createNewTxt);
// #18
const style=document.createElement("style");
console.log("style: ",style);
// #19
const newTxt=document.createTextNode("body{background-color:orange}");
style.appendChild(newTxt);
console.log("new style: ",style);
// #20
document.getElementsByTagName("head")[0].appendChild(style);



