easy-exif
=========

[![npm](https://badgen.net/npm/v/easy-exif)](https://npm.im/easy-exif)
![npm bundle size](https://badgen.net/packagephobia/publish/easy-exif)
[![Travis](https://badgen.net/travis/tuananh/easy-exif/develop)](https://travis-ci.org/tuananh/easy-exif)

Tiny [EXIF](https://en.wikipedia.org/wiki/Exif) metadata reader for Node.js in WebAssembly.

- Zero dependencies.
- 7.5 kB gzipped.

## Installation

```sh
npm install easy-exif
```

## Usage

```js
const { exif } = require('easy-exif')
const fs = require('fs')

const buf = fs.readFileSync('./samples/crosa.jpg')
console.log(await exif(buf))
```

Sample output

```json
{
  "make": "DJI",
  "model": "FC6520",
  "software": "v01.02.1504",
  "bitsPerSample": 0,
  "imageWidth": 1320,
  "imageHeight": 742,
  "imageDescription": "DCIM\\100MEDIA\\DJI_0001.JPG",
  "orientation": 1,
  "copyright": "",
  "dateTime": "2017:09:07 13:26:14",
  "dateTimeOriginal": "2017:09:07 13:26:14",
  "dateTimeDigitized": "2017:09:07 13:26:14",
  "subSecTimeOriginal": "",
  "exposureTime": 0.005,
  "fStop": 4,
  "exposureProgram": 1,
  "isoSpeedRatings": 100,
  "subjectDistance": 0,
  "exposureBiasValue": 0,
  "flash": 0,
  "flashReturnedLight": 0,
  "flashMode": 0,
  "meteringMode": 2,
  "focalLength": 15,
  "focalLengthIn35mm": 30,
  "geoLocation": {
    "latitude": -25.92544627777778,
    "latDegrees": 25,
    "latMinutes": 55,
    "latSeconds": 31.6066,
    "latDirection": 83,
    "longitude": 153.00958197222224,
    "lonDegrees": 153,
    "lonMinutes": 0,
    "lonSeconds": 34.4951,
    "lonDirection": 69,
    "altitude": -42.8,
    "precisionDOP": 0
  },
  "lensInfo": {
    "focalLengthMin": 0,
    "focalLengthMax": 0,
    "fStopMin": 0,
    "fStopMax": 0,
    "lensMake": "UnKnown",
    "lensModel": "DJI MFT 15mm F1.7 ASPH ",
    "focalPlaneXResolution": 0,
    "focalPlaneYResolution": 0
  }
}
```