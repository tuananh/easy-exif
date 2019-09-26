const fs = require('fs').promises
const Module = require('./dist/easyexif')

let cachedInstance
const instance = Module()

function callWasmBinding(methodName, ...args) {
    return new Promise((resolve) => {
        if (!cachedInstance) {
            instance.onRuntimeInitialized = () => {
                cachedInstance = instance
                const result = instance[methodName](...args)
                resolve(result)
            }
        } else {
            const result = cachedInstance[methodName](...args)
            resolve(result)
        }
    })
}

async function exif() {
    const buf = await fs.readFile(__dirname + '/samples/crosa.jpg')
    console.log(buf.buffer);

    return callWasmBinding('exif', buf.buffer, buf.buffer.byteLength)
}

exif().then(console.log)

module.exports = { exif }