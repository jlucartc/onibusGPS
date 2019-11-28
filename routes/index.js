var express = require('express');
const http = require('http');
const cp = require("child_process");

var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {

  var data = '123';


  var command = "curl -X GET --header 'Accept: application/json' --header 'Authorization: key ttn-account-v2.AXVZUWtEus1MMpVF8qGf8a7jQEbkU4sUA9sM3WsGkDI' 'https://bus_gps_data.data.thethingsnetwork.org/api/v2/query?last=7d'";

  cp.exec(command,function(err,stdout,stderr){
  	
  	if(err){ 

  		console.log('error');

  	}else{

  		console.log("Tipo: "+typeof(stdout));

  		var data = JSON.parse(stdout);

  		var raw = data[data.length-1].raw.split("/");

  		console.log("Dado: "+raw);

  		res.render('index', { title: 'Express' , data: raw });

  	} 
  
  });

  

});


module.exports = router;
