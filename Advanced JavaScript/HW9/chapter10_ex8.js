function guessingGame(amount)
{
    const answer=Math.floor(Math.random() * 11);
    let guesses = 0;
    let loop=true;
    return function(guess)
    {
        
        if (loop)
        {
            ++guesses;
            if (guess === answer)
            {
                loop=false;
                return "You got it!";
            }
            else if (guesses > amount-1)
            {
                loop = false;
                let txt="No more guesses the answer was ";
                txt+=answer;
                return txt;
            }
            else if (guess > answer)
            {
                return "You're too high!";
            }
            else
            {
                return "You're too low";
            }
        }
        else
        {
            return "You are all done playing!";
        }
    }
}

var game = guessingGame(5);
console.log(game(1));
console.log(game(8));
console.log(game(5));
console.log(game(7));
console.log(game(1));
console.log();
var game2 = guessingGame(3);
console.log(game2(5));
console.log(game2(3));
console.log(game2(1));
console.log(game2(1));