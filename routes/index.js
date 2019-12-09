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


  var command = "curl -X GET --header 'Accept: application/json' --header 'Authorization: key ttn-account-v2.AXVZUWtEus1MMpVF8qGf8a7jQEbkU4sUA9sM3WsGkDI' 'https://bus_gps_data.data.thethingsnetwork.org/api/v2/query?last=1d'";

  //MongoClient.connect(url,function(err,client){

  	var db = "onibus_gps_db";

  	//if (err) throw err; 
  	cp.exec(command,function(err,stdout,stderr){

	  	if(err){ 

	  		console.log('error');

	  	}else{

	  		// transformando stdout em JSON
	  		var data = JSON.parse(stdout).reverse();

	  		// conta quantos dispositivos estão cadastrados no banco;


	  		/*client.db(db).collection('ttn_data').countDocuments({},{},function(err,data){

	  			if(err) throw err;
	  			console.log("Quantidade de dispositivos registrados: ",data);

	  		});*/

	  		console.log(data);

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

	  		// itera sobre todos os dados obtido e atualiza os dados do banco

	  		res.render('index', { title: 'Ônibus GPS' , data: JSON.stringify(dispositivos) });

	  		

	  	} 

  	});

  //});

});


module.exports = router;
