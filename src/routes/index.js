const express = require('express');
const router = express.Router();

const Sample = require('../models/sample');

router.get('/', async (req, res) => {
    const samples = await Sample.find();
    res.render('index', { samples });
});

router.post('/submit', async (req, res) => {
    const sample = new Sample(req.body);
    await sample.save();
    res.redirect('/');
});

module.exports = router;