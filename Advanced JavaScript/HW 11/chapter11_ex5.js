const axios = require("axios").default;
const fetchStarWars = (url = "https://swapi.dev/api/people/") =>
{
    return axios.get(url);
}

const printMovieLists = ({data}) =>
{
    searchList({data});
    return Promise.resolve();
}

function searchList({data})
{
    let arraySize=data["results"].length;
    for (let i=0;i<arraySize;++i)
    {
        let character = data["results"][i]["name"];
        if (character==="Luke Skywalker" || 
        character==="Obi-Wan Kenobi" ||
        character==="Darth Vader")
        {
            async function fetchingMovies()
            {
                
                for (let j=0;j<data["results"][i]["films"].length;++j)
                {
                    const movie = await axios.get(data["results"][i]["films"][j])
                    .then()
                    {
                        console.log(character);
                        console.log(movie.data["title"]);
                        console.log();
                    };
                };
            };
            fetchingMovies();
        }
    }
    return arr;
}


fetchStarWars()
.then(printMovieLists);