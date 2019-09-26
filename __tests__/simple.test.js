const fs = require('fs')
const { exif } = require('../')

test('extract exif metadata without error', async () => {
    const buf = fs.readFileSync(__dirname + '/../samples/crosa.jpg')
    await exif(buf)
})
