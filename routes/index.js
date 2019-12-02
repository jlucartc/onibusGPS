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


  var command = "curl -X GET --header 'Accept: application/json' --header 'Authorization: key ttn-account-v2.AXVZUWtEus1MMpVF8qGf8a7jQEbkU4sUA9sM3WsGkDI' 'https://bus_gps_data.data.thethingsnetwork.org/api/v2/query?last=7d'";

  MongoClient.connect(url,function(err,client){

  	var db = "onibus_gps_db";

  	if (err) throw err; 
  	cp.exec(command,function(err,stdout,stderr){

	  	if(err){ 

	  		console.log('error');

	  	}else{

	  		// transformando stdout em JSON
	  		var data = JSON.parse(stdout);

	  		// iniciando objecto da coleção de dados desejada
	  		//var collection = db.collection('ttn_data');

	  		// conta quantos dispositivos estão cadastrados no banco;

	  		client.db(db).collection('ttn_data').countDocuments({},{},function(err,data){

	  			if(err) throw err;
	  			console.log("Quantidade de dispositivos registrados: ",data);

	  		});

	  		// itera sobre todos os dados obtido e atualiza os dados do banco
	  		console.log("comprimento: ",data.length);
	  		for(i = 0; i < data.length; i++){

	  			//console.log(data[i]);
	  			//console.log(i);

	  			var d = JSON.parse(JSON.stringify(data[i]));

	  			// retira o campo de 'time' e 'raw' do objeto, deixando apenas o id
	  			delete d.time;
	  			delete d.raw;

	  			//console.log("Data: ",data[i]);
	  			//console.log("d: ",d);

	  			// busca o objeto apenas com base em seu id
	  			client.db(db).collection("ttn_data").findOne(d,{},function(err,doc){
	  				
	  				console.log(data[i]);
	  				console.log(err);

	  				if(err){

	  					client.db(db).collection("ttn_data").insert(d,{},function(error,result){

	  						console.log("Resultado: ",result);

	  					});

	  				}else{

		  				// checa se da entrada atual é maior do que a registrada no banco
		  				
		  				if(data[i].time > doc.time){

		  					client.db(db).collection("ttn_data").replaceOne(doc,data[i]);

		  				}
		  			}
	  			});

	  		}

	  		client.db(db).collection("ttn_data").find().forEach(function(doc){

	  			console.log("Doc: ",doc);


	  		},function(err){

	  			console.log("erro");

	  		});

	  		console.log("raw: ",data[data.length-1]);

	  		var raw = data[data.length-1].raw.split("/");

	  		console.log("Dado: "+raw);

	  		res.render('index', { title: 'Express' , data: raw });

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
