// Function Outline
function makePromiseWithConstructor(itShouldResolve)
{
    let rand = Math.random() * 10;
    if (rand <= 3)
    {
        itShouldResolve = "falsey";
        return itShouldResolve;
    }
    else
    {
        itShouldResolve = "truthy";
        return itShouldResolve;
    }
}

// Promise Constructor
const promiseConstruct = new Promise((resolve,reject) =>
{
    const result = makePromiseWithConstructor(null);
    if (result == "falsey")
    {
        resolve();
    }
    else
    {
        reject();
    }
});

promiseConstruct.then(() =>
{
    console.log("The result was truthy. ");
});

promiseConstruct.catch(() =>
{
    console.log("The result was falsey. ");
});