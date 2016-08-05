var jira = require("./node-jira");
jira.jira_get("/rest/api/2/project")
    .then((d)=>{
            console.log(d);
        });