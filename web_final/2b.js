//  Write a node.js Express and Mongo program to accept Student_name,USN,semester,exam_fee from
// web page and delete all the students who have not paid exam fees

var express = require("express");
var mongo = require("mongodb").MongoClient;

var app = express();

app.get("/", function (req, res) {
  res.sendFile(__dirname + "/2b.html");
});

app.get("/process_get", function (req, res) {
  var input = {
    name: req.query.name,
    usn: req.query.usn,
    sem: req.query.sem,
    fee: req.query.fee,
  };
  mongo.connect("mongodb://127.0.0.1:27017", function (err, client) {
    if (err) res.sendStatus(500);
    var stud = client.db("final").collection("student");
    stud.insertOne(input);
    stud.deleteMany({ fee: "no" });
    stud.find({}).toArray(function (err, result) {
      if (err) res.send(err);

      res.setHeader("Content-Type", "text/html");
      for (var i = 0; i < result.length; i++) {
        res.write(
          "<h5>" +
            result[i].name +
            " " +
            result[i].sem +
            " " +
            result[i].usn +
            " " +
            result[i].fee +
            "</h5> "
        );
      }
      res.end();
    });
  });
});

app.listen(5000, function () {
  //   console.log(server.address().address  );
});
