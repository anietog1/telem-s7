const express = require('express');
const app = express();
const path = require('path');
const morgan = require('morgan');
const mongoose = require('mongoose');

// connecting to db
mongoose.connect('mongodb://localhost/samples-mongo', {
        useUnifiedTopology: true,
        useNewUrlParser: true
    }).then(db => console.log('Database connected'))
    .catch(err => console.log(err));

// importing routes
const router = require('./routes/api');

// settings
app.set('port', process.env.PORT || 3000);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

// middlewares
app.use(morgan('dev'));
app.use(express.json());
app.use(express.static('public'));

// routes
app.use('/api', router);

// server
app.listen(app.get('port'), () => {
    console.log(`Listening on port ${app.get('port')}`);
});