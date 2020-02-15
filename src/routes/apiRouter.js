const express = require('express');
const router = express.Router();

const Sample = require('../models/sample');
const User = require('../models/user');

router.get('/samples', async (req, res) => {
    const validApiKey = await User.exists({apiKey: req.query.apiKey});

    if(validApiKey) {
        const samples = await Sample.find();
        res.send(samples);
    } else {
        res.sendStatus(401);
    }
});

router.post('/samples/new', async (req, res) => {
    const validApiKey = await User.exists({apiKey: req.body.apiKey});

    if(validApiKey) {
        const sample = new Sample(req.body);
        await sample.save();
        res.sendStatus(201);
    } else {
        res.sendStatus(401);
    }
});

module.exports = router;