var express = require("express");
var mongo = require("mongodb").MongoClient;
var app = express();

app.get("/", function (req, res) {
  res.sendFile(__dirname + "/1b.html");
});

app.get("/get_fail", function (req, res) {
  var details = {
    usn: req.query.usn,
    name: req.query.name,
    scode: req.query.scode,
    cie: parseInt(req.query.cie),
  };

  mongo.connect("mongodb://127.0.0.1:27017", function (err, client) {
    var db = client.db("mydb");
    var studs = db.collection("students1b");
    studs.insertOne(details);
    studs.find({ cie: { $lt: 20 } }).toArray(function (err, results) {
      res.write("<h1>" + results[0].usn + "</h1>");
      res.end();
      client.close();
    });
  });
});

var server = app.listen(5000, function () {
  var add = server.address().address;
  var port = server.address().port;
  console.log("server connected at :" + add + ":" + port);
});
