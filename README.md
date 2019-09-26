easy-exif
=========

Tiny EXIF reader for Node.js in WebAssembly.

## Installation

```sh
npm install easy-exif
```

## Usage

```js
const { exif } = require('easy-exif')

console.log(await exif(new Buffer.from('')))
```