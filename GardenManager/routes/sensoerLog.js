 var express = require('express');
 var router = express.Router();

 router.use('/',function(req,res,next){
     console.log(Date.now());
     next();
 });

 router.post('/',function(req,res,next){
    console.log(req.body);
    console.log(req.body.Test2);
    res.send("OK");
 })

 module.exports = router;
