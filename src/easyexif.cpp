#include <emscripten/bind.h>
#include <emscripten/val.h>
#include "../node_modules/easyexif/exif.cpp"

using namespace emscripten;

val exif(std::string raw_image, unsigned long size)
{
  const uint8_t* image_buffer = (uint8_t*)raw_image.c_str();
  easyexif::EXIFInfo result;
  int code = result.parseFrom(image_buffer, size);

  val output = val::object();
  output.set("make", result.Make.c_str());
  output.set("model", result.Model.c_str());
  output.set("software", result.Software.c_str());
  output.set("bitsPerSample", result.BitsPerSample);
  output.set("imageWidth", result.ImageWidth);
  output.set("imageHeight", result.ImageHeight);
  output.set("imageDescription", result.ImageDescription.c_str());
  output.set("orientation", result.Orientation);
  output.set("copyright", result.Copyright.c_str());
  output.set("dateTime", result.DateTime.c_str());
  output.set("dateTimeOriginal", result.DateTimeOriginal.c_str());
  output.set("dateTimeDigitized", result.DateTimeDigitized.c_str());
  output.set("subSecTimeOriginal", result.SubSecTimeOriginal.c_str());
  output.set("exposureTime", result.ExposureTime);
  output.set("fStop", result.FNumber);
  output.set("exposureProgram", result.ExposureProgram);
  output.set("isoSpeedRatings", result.ISOSpeedRatings);
  output.set("exposureProgram", result.ExposureProgram);
  output.set("subjectDistance", result.SubjectDistance);
  output.set("exposureBiasValue", result.ExposureBiasValue);
  output.set("flash", result.Flash);
  output.set("flashReturnedLight", result.FlashReturnedLight);
  output.set("flashMode", result.FlashMode);
  output.set("meteringMode", result.MeteringMode);
  output.set("focalLength", result.FocalLength);
  output.set("focalLengthIn35mm", result.FocalLengthIn35mm);

  val geo = val::object();
  geo.set("latitude", result.GeoLocation.Latitude);
  geo.set("latDegrees", result.GeoLocation.LatComponents.degrees);
  geo.set("latMinutes", result.GeoLocation.LatComponents.minutes);
  geo.set("latSeconds", result.GeoLocation.LatComponents.seconds);
  geo.set("latDirection", result.GeoLocation.LatComponents.direction);

  geo.set("longitude", result.GeoLocation.Longitude);
  geo.set("lonDegrees", result.GeoLocation.LonComponents.degrees);
  geo.set("lonMinutes", result.GeoLocation.LonComponents.minutes);
  geo.set("lonSeconds", result.GeoLocation.LonComponents.seconds);
  geo.set("lonDirection", result.GeoLocation.LonComponents.direction);

  geo.set("altitude", result.GeoLocation.Altitude);
  geo.set("precisionDOP", result.GeoLocation.DOP);
  output.set("geoLocation", geo);

  val lens_info = val::object();
  lens_info.set("focalLengthMin", result.LensInfo.FocalLengthMin);
  lens_info.set("focalLengthMax", result.LensInfo.FocalLengthMax);
  lens_info.set("fStopMin", result.LensInfo.FStopMin);
  lens_info.set("fStopMax", result.LensInfo.FStopMax);
  lens_info.set("lensMake", result.LensInfo.Make.c_str());
  lens_info.set("lensModel", result.LensInfo.Model.c_str());
  lens_info.set("focalPlaneXResolution", result.LensInfo.FocalPlaneXResolution);
  lens_info.set("focalPlaneYResolution", result.LensInfo.FocalPlaneYResolution);
  output.set("lensInfo", lens_info);

  return output;
}

EMSCRIPTEN_BINDINGS(my_module)
{
  function("exif", &exif);
}
