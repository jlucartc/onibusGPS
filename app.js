var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
const cp = require("child_process");
var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.get('/', function(req,res,next) {

  var data;
  var command = "curl -X GET --header 'Accept: application/json' --header 'Authorization: key ttn-account-v2.AXVZUWtEus1MMpVF8qGf8a7jQEbkU4sUA9sM3WsGkDI' 'https://bus_gps_data.data.thethingsnetwork.org/api/v2/query?last=12h'";
  console.log(command);

    cp.exec(command,function(err,stdout,stderr){

      if(err){ 

        console.log('error');

      }else{

        var data = JSON.parse(stdout).reverse();

        var uniqueIds = new Array();

        var reducedData = new Array();

        for(var i = 0; i < data.length; i++){

            if(uniqueIds.indexOf(data[i].device_id) < 0){

              data[i].raw = new Buffer(JSON.parse(JSON.stringify(data[i].raw)),'base64').toString('ascii');

              reducedData.push(data[i]);

              uniqueIds.push(data[i].device_id);

            }

        }

        res.render('index', { title: 'Ônibus GPS' , data: JSON.stringify(reducedData) });

      }

    }); 


});

app.listen(3000,function () {
  console.log('Example app listening on port 3000!');
});



module.exports = app;
