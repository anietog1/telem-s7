const express = require('express');
const router = express.Router();

const User = require('../models/user');

router.post('/users/new', async (req, res) => {
    const user = new User(req.body);
    await user.save();
    res.sendStatus(200);
});

module.exports = router;