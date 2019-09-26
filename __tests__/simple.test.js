const fs = require('fs')
const { exif } = require('../')
var test = require('tape')

test('extract exif metadata without error', async function (t) {
    const buf = fs.readFileSync(__dirname + '/../samples/crosa.jpg')
    await exif(buf)
    t.end()
})