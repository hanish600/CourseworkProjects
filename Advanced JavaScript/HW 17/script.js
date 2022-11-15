window.onload = function()
{
    // 1 
    console.log("Loaded");

    // 2
    let changeTxt = document.getElementById("change_heading");
    changeTxt.innerText = "Hello World";

    // 3
    let usrHover = document.querySelector("section");
    usrHover.addEventListener("mouseover", function(event) {
        let selection = document.querySelector(".selected");
        selection.innerText=event.target.className;
    })

    // 4
    let div = document.createElement("div");
    div.className="purple";
    div.style.backgroundColor="purple";
    usrHover.appendChild(div);

    // Part 2
    let btn=document.querySelector("button");
    let car1=document.querySelector(".car1");
    let car2=document.querySelector(".car2");
    car1.style.marginLeft=0;
    car2.style.marginLeft=0;
    // only one winner allowed
    let strWinner="";
    btn.addEventListener("click",function(event){
        btn.disabled = true;
        car1.timer = setInterval(function(){
            car1.style.marginLeft = parseInt(car1.style.marginLeft) + Math.random()*25*1.25 + 'px';
            if(parseInt(car1.style.marginLeft) > window.innerWidth && strWinner===""){
                alert("Car 1 wins!");
                strWinner="Car1";
            }
        },20)
    })
    btn.addEventListener("click",function(event){
        btn.disabled = true;
        car2.timer = setInterval(function(){
            car2.style.marginLeft = parseInt(car2.style.marginLeft) + Math.random()*25*1.25 + 'px';
            if(parseInt(car2.style.marginLeft) > window.innerWidth && strWinner===""){
                alert("Car 2 wins!");
                strWinner="Car2";
            }
        },20)
    })
}