var express = require('express');
const http = require('http');

var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {

  res.render('index', { title: 'Express' });
});


module.exports = router;
