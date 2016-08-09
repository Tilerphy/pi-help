function jenkins_login(username, password, schema="http"){
    var http = require(schema);
    var q = require("querystring");
    var postData = {
            j_username:username,
            j_password:password,
            from: "/",
            json:'{"j_username":+"'+username+'",+"j_password":+"'+password+'",+"from":+"/"}' 
        };
    var q_postData = q.stringify(postData);
    var options = {
            hostname:"jenkins.avepoint.net",
            method:"POST",
            path: "/j_acegi_security_check",
            headers:{
                "Content-Type": "application/x-www-form-urlencoded",
                "Content-Length": Buffer.byteLength(q_postData)
            }
        };
        
    var p = new Promise((resolve, reject)=>{
            var req = http.request(options, (res)=>{
                    var tmpRes = "";
                    console.log(Object.keys(res));
                    console.log(res.headers);
                    res.on("data", (d)=>{
                        
                            tmpRes += d.toString();
                        });
                    res.on("end",()=>{
                            
                            resolve(res);
                        });
                });
            req.on("error", (e)=>{
                    reject(e);
                });
            req.write(q_postData);
            req.end();
        });
    return p;
}

function jenkins_get(login_res, path){
    var http = require("http");
    var options = {
            hostname:"jenkins.avepoint.net",
            method:"GET",
            path: path,
            headers:{
                "Cookie": login_res.headers['set-cookie']
            }
        };
        
    var p = new Promise((resolve, reject)=>{
            var req = http.request(options, (res)=>{
                    var tmpRes = "";
                    console.log(Object.keys(res));
                    console.log(res.headers);
                    res.on("data", (d)=>{
                            tmpRes += d.toString();
                        });
                    res.on("end",()=>{
                            resolve(res);
                        });
                });
            req.on("error", (e)=>{
                    reject(e);
                });
            req.end();
        });
    return p;
}

function jenkins_post(login_res, path, data){
    var http = require("http");
    var dataString = require("querystring").stringify(data);
    var options = {
            hostname:"jenkins.avepoint.net",
            method:"POST",
            path: path,
            headers:{
                "Content-Type":"application/x-www-form-urlencoded",
                "Content-Length": data ? Buffer.byteLength(dataString) : 0,
                "Cookie": login_res.headers['set-cookie']
            }
        };
        
    var p = new Promise((resolve, reject)=>{
            var req = http.request(options, (res)=>{
                    var tmpRes = "";
                    console.log(Object.keys(res));
                    console.log(res.headers);
                    res.on("data", (d)=>{
                            tmpRes += d.toString();
                        });
                    res.on("end",()=>{
                            resolve(res);
                        });
                });
            req.on("error", (e)=>{
                    reject(e);
                });
            if(data){req.write(dataString);}else{}
            req.end();
        });
    return p;
}
module.exports.jenkins_login = jenkins_login;
module.exports.jenkins_get = jenkins_get;
module.exports.jenkins_post= jenkins_post;
