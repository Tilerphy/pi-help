var jira = require("./node-jira");
jira.jira_get("/rest/api/2/myself")
    .then((d)=>{
            console.log(d.name);
            return d.name;
        })
    .then((name)=>{
                return Promise.all([jira.jira_get("/rest/api/2/search?jql="+encodeURIComponent("assignee="+name+" and resolution=Unresolved")+"&maxResults=0"),
                                  jira.jira_get("/rest/api/2/search?jql="+encodeURIComponent("assignee="+name)+"&maxResults=0")]);
        })
    .then((result)=>{
                console.log(result[0].total*100/result[1].total);
                
        })
    .catch((e)=>{
                console.log(e);
        });