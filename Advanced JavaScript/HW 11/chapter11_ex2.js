const rejectPromise = Promise.reject("Boo");
rejectPromise.catch((err) =>
{
    console.log("rejected string: ", err);
});