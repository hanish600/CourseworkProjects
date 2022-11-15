const getUserById = (url) =>
{
    return new Promise((resolve,reject) =>
    {
        setTimeout(() =>
        {
            const usrObj =
            {
                "/users/u001/": [{ id:"u001",name:"Mike",
                 email: "mike@mike.mike",organizationId: "o001"}],
            }
            const data = usrObj[url];
            if (data)
            {
                // website is the organziation
                let website = "/orgs/";
                website+=String(usrObj[url][0].organizationId+"/");
                // requesting organization
                const orgData = getOrganizationById(
                    website);
                const newData = combinedata(usrObj[url],orgData);
                resolve({status: 200, newData});
            }
            else
            {
                reject({status: undefined});
            }
        },1000)
    })
};

const getOrganizationById = (website) => 
{
    const orgData=
    {
        "/orgs/o001/":
        [{
            id: "o001",
            name: "Research and Development"
        }]
    };
    const data=orgData[website];
    return data;
};

function combinedata(usrObj,orgData) {
    const combined= new Object();
    combined.uId=usrObj[0].id;
    combined.uName=usrObj[0].name;
    combined.uEmail=usrObj[0].email;
    combined.uOrg=usrObj[0].organizationId;
    combined.orgId=orgData[0].id;
    combined.orgName=orgData[0].name;
    return combined;
}

getUserById("/users/u001/")
.then((resultant) => {
    console.log(resultant);
})
.catch((err) =>
{
    console.log(undefined);
});