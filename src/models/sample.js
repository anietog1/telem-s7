const mongoose = require('mongoose');

const Schema = mongoose.Schema;

// based on https://mongoosejs.com/docs/geojson.html
// longitude goes first, then latitude
const pointSchema = new mongoose.Schema({
    type: {
        type: String,
        enum: ['Point'],
        required: true
    },
    coordinates: {
        type: [Number],
        required: true
    }
});

const sampleSchema = new Schema({
    temperature: {
        type: Number,
        required: true
    },
    humidity: {
        type: Number,
        required: true
    },
    location: {
        type: pointSchema,
        required: true
    }
});

module.exports = mongoose.model('sample', sampleSchema);