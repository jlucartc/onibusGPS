var express = require('express');
const http = require('http');
const cp = require("child_process");
//var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017";
//const assert = require('assert');


var router = express.Router();

/* GET home page. */
router.get('/', function(req,res,next) {

  var data = '123';


  var command = "cat ~/Desktop/output20191210.txt";

  	var db = "onibus_gps_db";

  	cp.exec(command,function(err,stdout,stderr){

	  	if(err){ 

	  		console.log('error');

	  	}else{

	  		var data = JSON.parse(stdout).reverse();
	  		var dispositivos = new Array();
	  		var ids = new Array();

	  		for(var i = 0; i < data.length; i++){

	  			if(ids.indexOf(data[i].device_id) < 0){

	  				ids.push(data[i].device_id);
	  				data[i].raw = new Buffer(JSON.parse(JSON.stringify(data[i].raw)),'base64').toString('ascii');
	  				dispositivos.push(data[i])
	  				console.log("Data:",data[i]);

	  			}

	  		}

	  		res.render('index', { title: 'Ônibus GPS' , data: JSON.stringify(dispositivos) });

	  	} 

  	});

});


module.exports = router;
