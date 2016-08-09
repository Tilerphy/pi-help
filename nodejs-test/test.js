var jira = require("./node-jira");
var jenkins = require("./node-jenkins");
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
    
    
jenkins.jenkins_login("zbsun", "").then((res)=>{
        return jenkins.jenkins_post(res, "/job/Component/job/AvePointServiceFramework/job/AvePointServiceFramework_1.0.0/build?delay=0sec", null);
    }).then((d)=>{
        //console.log(d);
    })
    .catch((e)=>{
        console.log(e);
    });