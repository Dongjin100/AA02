var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});
router.get('/aa02',function(req, res, next){
	res.render('aa02',{title: 'Express App',
id: 'AA02',
name: 'Dongjin'})
})
module.exports = router;
