const express = require('express');
const app = express();
const path = require('path');
const morgan = require('morgan');
const mongoose = require('mongoose');

// connecting to db
mongoose.connect('mongodb://localhost/samples-mongo', { useUnifiedTopology: true, useNewUrlParser: true})
    .then(db => console.log('DB CONNECTED'))
    .catch(err => console.log(err));

// importing routes
const indexRoutes = require('./routes/index');

// settings
app.set('port', process.env.PORT || 3000);
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

// middlewares
app.use(morgan('dev'));
app.use(express.json());

// routes
app.use('/', indexRoutes);

// server
app.listen(app.get('port'), () => {
    console.log(`SERVER LISTENING ON PORT ${app.get('port')}`);
});