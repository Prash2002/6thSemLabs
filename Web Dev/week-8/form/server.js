var http = require("http");
var fs = require("fs");
var url = require("url");
var qs = require("querystring");

// const serv = http.createServer(function (req, res) {
//   res.writeHead(200, {
//     "Content-Type": "text/plain",
//   });
//   console.log("is this working?");
//   res.end("Hello HTTP!");
// });
// serv.listen(4000);

const server = http.createServer(function (req, res) {
  console.log("server started");
  var url_part = url.parse(req.url);
  //   console.log(url_part);

  if (url_part.pathname === "/") {
    fs.readFile("./index.html", function (err, data) {
      if (err) {
        res.writeHead(404);
        res.write("not found!");
      } else {
        console.log("Serving data from index.html");
        res.writeHead(200, { "Content-type": "text/html" });
        res.write(data);
      }
      res.end();
    });
  }
  if (req.method === "GET") {
    if (url_part.pathname === "/getData") {
      console.log("getting data");
      res.writeHead(200, { "Content-type": "text/html" });
      var queries = url_part.query.split("&");

      res.end(
        "Data on GET: " +
          queries[0].split("=")[1] +
          " " +
          queries[1].split("=")[1]
      );
    }
  }
  if (req.method === "POST") {
    if (url_part.pathname === "/getData") {
      console.log("getting POST data");
      var body;
      req.on("data", (data) => {
        body = data ;
        console.log("got log data" + data);
      });
      //   body = "name=yy&age=20";
      var postd = qs.parse(body);
      console.log("body " + body);
      //   console.log(postd);
      res.end("POST data is: " + postd.name + " " + postd.age);
    }
  }
});

server.listen(5000);
console.log("listening on port 5000");
