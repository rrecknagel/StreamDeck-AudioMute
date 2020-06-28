#include "DefaultAudioDevices.h"

#include "AudioFunctions.h"

const std::string DefaultAudioDevices::DEFAULT_INPUT_ID(
  "com.fredemmott.sdmute.deviceIds.defaultInput");
const std::string DefaultAudioDevices::DEFAULT_OUTPUT_ID(
  "com.fredemmott.sdmute.deviceIds.defaultOutput");
const std::string DefaultAudioDevices::COMMUNICATIONS_INPUT_ID(
  "com.fredemmott.sdmute.deviceIds.communicationsInput");
const std::string DefaultAudioDevices::COMMUNICATIONS_OUTPUT_ID(
  "com.fredemmott.sdmute.deviceIds.communicationsOutput");

std::string DefaultAudioDevices::GetRealDeviceID(const std::string& dev) {
  if (dev == DEFAULT_INPUT_ID) {
    return GetDefaultAudioDeviceID(
      AudioDeviceDirection::INPUT, AudioDeviceRole::DEFAULT);
  }
  if (dev == DEFAULT_OUTPUT_ID) {
    return GetDefaultAudioDeviceID(
      AudioDeviceDirection::OUTPUT, AudioDeviceRole::DEFAULT);
  }
  if (dev == COMMUNICATIONS_INPUT_ID) {
    return GetDefaultAudioDeviceID(
      AudioDeviceDirection::INPUT, AudioDeviceRole::COMMUNICATION);
  }
  if (dev == COMMUNICATIONS_OUTPUT_ID) {
    return GetDefaultAudioDeviceID(
      AudioDeviceDirection::OUTPUT, AudioDeviceRole::COMMUNICATION);
  }
  return dev;
}

std::string DefaultAudioDevices::GetSpecialDeviceID(AudioDeviceDirection direction, AudioDeviceRole role) {
  if (direction == AudioDeviceDirection::INPUT && role == AudioDeviceRole::DEFAULT) {
    return DEFAULT_INPUT_ID;
  }
  if (direction == AudioDeviceDirection::OUTPUT && role == AudioDeviceRole::DEFAULT) {
    return DEFAULT_OUTPUT_ID;
  }
  if (direction == AudioDeviceDirection::INPUT && role == AudioDeviceRole::COMMUNICATION) {
    return COMMUNICATIONS_INPUT_ID;
  }
  if (direction == AudioDeviceDirection::OUTPUT && role == AudioDeviceRole::COMMUNICATION) {
    return COMMUNICATIONS_OUTPUT_ID;
  }
  return std::string();
}
