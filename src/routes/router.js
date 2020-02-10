const express = require('express');
const router = express.Router();

// samples
const Sample = require('../models/sample');

router.get('/samples', async (req, res) => {
    const samples = await Sample.find();
    res.send(samples);
});

router.post('/samples/new', async (req, res) => {
    const sample = new Sample(req.body);
    await sample.save();
    res.sendStatus(200);
});

module.exports = router;