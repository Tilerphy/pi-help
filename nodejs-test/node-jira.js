function jira_get(path){
    "use strict";
    var https = require("https");
    var options ={
            hostname:"jira.avepoint.net",
            method:"GET",
            auth: "zbsun:sunzongbao2007",
            rejectUnauthorized: false,
            path: path
        };
    
    var p = new Promise((resolve, reject)=>{
            var req = https.request(options, (res)=>{
                res.on("data", (d)=>{
                        resolve(d);
                    });
            });
            req.on("error",reject);
            req.end();
            
        });
    
    return p;
}

function jira_post(path, data, contenttype="application/x-www-form-urlencoded"){
    "use strict";
    var https = require("https");
    var querystring = require("querystring");
    var postData = querystring.stringify(data);
    var options ={
            hostname:"jira.avepoint.net",
            method:"POST",
            auth: "zbsun:sunzongbao2007",
            rejectUnauthorized: false,
            path: path,
            headers:{
                "Content-Type": contenttype,
                "Content-Length": Buffer.byteLength(postData)
            }
        };
    
    var p = new Promise((resolve, reject)=>{
            var req = https.request(options, (res)=>{
                res.on("data", (d)=>{
                        resolve(d);
                    });
            });
            req.on("error",reject);
            req.write(postData);
            req.end();
            
        });
    
    return p;
}

module.exports.jira_get = jira_get;
module.exports.jira_post = jira_post;