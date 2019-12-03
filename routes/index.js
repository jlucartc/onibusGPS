var express = require('express');
const http = require('http');
const cp = require("child_process");
var MongoClient = require('mongodb').MongoClient;
var url = "mongodb://localhost:27017";
const assert = require('assert');


var router = express.Router();

/* GET home page. */
router.get('/', function(req,res,next) {

  var data = '123';


  var command = "curl -X GET --header 'Accept: application/json' --header 'Authorization: key ttn-account-v2.AXVZUWtEus1MMpVF8qGf8a7jQEbkU4sUA9sM3WsGkDI' 'https://bus_gps_data.data.thethingsnetwork.org/api/v2/query?last=1d'";

  MongoClient.connect(url,function(err,client){

  	var db = "onibus_gps_db";

  	if (err) throw err; 
  	cp.exec(command,function(err,stdout,stderr){

	  	if(err){ 

	  		console.log('error');

	  	}else{

	  		// transformando stdout em JSON
	  		var data = JSON.parse(stdout);

	  		// conta quantos dispositivos estão cadastrados no banco;

	  		client.db(db).collection('ttn_data').countDocuments({},{},function(err,data){

	  			if(err) throw err;
	  			console.log("Quantidade de dispositivos registrados: ",data);

	  		});

	  		// itera sobre todos os dados obtido e atualiza os dados do banco
	  		for(var i = 0; i < data.length; i++){

	  			var d = JSON.parse(JSON.stringify(data[i]));

	  			d._id = d.device_id;


	  			client.db(db).collection("ttn_data").find({_id : d._id}).toArray(function(err,docs){

	  				console.log(docs);

	  				console.log("data: ",docs[0].time);

	  				if(docs.length == 1){

		  				if(d.time > docs[0].time){

		  					client.db(db).collection("ttn_data").update({_id : d._id},d,{},function(err,res){
		  						console.log("Atualizando ",d._id);
		  					});

		  				}

	  				}else{

							client.db(db).collection("ttn_data").insertOne(d,{},function(err,res){console.log("Inserindo ",d._id)});

	  				}

	  			});


	  		}

	  		var dispositivos = client.db(db).collection("ttn_data").find().toArray(function(err,docs){

	  			for(var j = 0; j < docs.length; j++){

	  				delete docs[j]._id;
	  				delete docs[j].time;
	  				docs[j].raw = new Buffer(docs[j].raw, 'base64').toString('ascii');

	  			}

	  			res.render('index', { title: 'Express' , data: JSON.stringify(docs) });

	  		});

	  		

	  	} 

  	});

  });

  /*cp.exec(command,function(err,stdout,stderr){
  	
  	if(err){ 

  		console.log('error');

  	}else{

  		console.log("Tipo: "+typeof(stdout));

  		var data = JSON.parse(stdout);

  		var raw = data[data.length-1].raw.split("/");

  		console.log("Dado: "+raw);

  		res.render('index', { title: 'Express' , data: raw });

  	} 
  
  });*/

  

});


module.exports = router;
