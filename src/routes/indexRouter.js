const express = require('express');
const router = express.Router();
const uuidAPIKey = require('uuid-apikey');

const User = require('../models/user');

router.post('/users/new', async (req, res) => {
    const user = new User(req.body);
    user.set(uuidAPIKey.create());

    await user.save()
        .then(() => { 
            res.sendStatus(200);
        }).catch(err => {
            console.log(err);
            res.sendStatus(500);
        });
});

module.exports = router;