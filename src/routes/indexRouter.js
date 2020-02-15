const express = require('express');
const router = express.Router();
const uuidAPIKey = require('uuid-apikey');

const User = require('../models/user');

router.post('/users/new', async (req, res) => {
    const user = new User(req.body);
    user.set(uuidAPIKey.create());

    await user.save()
        .then(() => { 
            res.sendStatus(201);
        }).catch(() => {
            res.sendStatus(409);
        });
});

router.post('/users/login', async (req, res) => {
    await User.findOne({username: req.body.username}).then(user => {
        if(user.password === req.body.password) {
            res.send(user.apiKey);
        } else {
            res.sendStatus(401);
        }
    }).catch(() => {
        res.sendStatus(401);
    });
});

module.exports = router;