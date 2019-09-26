const assert = require('assert')
const Module = require(__dirname + '/dist/easyexif')

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

/**
 * extract EXIF meta data from image buffer
 * @param {Buffer} buf file buffer
 * @returns {object} metadata object
 */
async function exif(buf) {
    assert(buf instanceof Buffer, 'first argument must be instance of Buffer')
    
    return callWasmBinding('exif', buf.buffer, buf.buffer.byteLength)
}

module.exports = { exif }