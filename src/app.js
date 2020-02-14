require('dotenv').config();

const express = require('express');
const app = express();
const morgan = require('morgan');
const mongoose = require('mongoose');

// connecting to db
mongoose.connect(process.env.DB, {
        useUnifiedTopology: true,
        useNewUrlParser: true,
        useCreateIndex: true
    }).then(db => console.log('Database connected'))
    .catch(err => console.log(err));

// settings
app.set('port', process.env.PORT);

// middlewares
app.use(morgan('dev'));
app.use(express.json());
app.use(express.static('public'));

// routes
app.use('/api', require('./routes/apiRouter'));
app.use('/', require('./routes/indexRouter'));

// server
app.listen(app.get('port'), () => {
    console.log(`Listening on port ${app.get('port')}`);
});