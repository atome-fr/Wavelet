#pragma once

#include <pluginterfaces/base/ftypes.h>

#define VERSION "0.0.0.1"
#define PLUGIN_NAME "Wavelet"
#define COMPANY_NAME "Atome.io"
#define COMPANY_URL "https://atome.io"
#define COMPANY_EMAIL "contact@atome.io"

//#define NOTE_FREQUENCY_OFFSET 1.059463094359295264561825f

const float MIDI_NOTES_FREQUENCIES[] = {
8.18f, 8.66f, 9.18f, 9.72f, 10.30f, 10.91f, 11.56f, 12.25f, 12.98f, 13.75f, 14.57f, 15.43f,
16.35f, 17.32f, 18.35f, 19.45f, 20.60f, 21.83f, 23.12f, 24.50f, 25.96f, 27.50f, 29.14f, 30.87f,
32.70f, 34.65f, 36.71f, 38.89f, 41.20f, 43.65f, 46.25f, 49.00f, 51.91f, 55.00f, 58.27f, 61.74f,
65.41f, 69.30f, 73.42f, 77.78f, 82.41f, 87.31f, 92.50f, 98.00f, 103.83f, 110.00f, 116.54f, 123.47f,
130.81f, 138.59f, 146.83f, 155.56f, 164.81f, 174.61f, 185.00f, 196.00f, 207.65f, 220.00f, 233.08f, 246.94f,
261.63f, 277.18f, 293.66f, 311.13f, 329.63f, 349.23f, 369.99f, 392.00f, 415.30f, 440.00f, 466.16f, 493.88f,
523.25f, 554.37f, 587.33f, 622.25f, 659.26f, 698.46f, 739.99f, 783.99f, 830.61f, 880.00f, 932.33f, 987.77f,
1046.50f, 1108.73f, 1174.66f, 1244.51f, 1318.51f, 1396.91f, 1479.98f, 1567.98f, 1661.22f, 1760.00f, 1864.66f,
1975.53f, 2093.00f, 2217.46f, 2349.32f, 2489.02f, 2637.02f, 2793.83f, 2959.96f, 3135.96f, 3322.44f, 3520.00f,
3729.31f, 3951.07f, 4186.01f, 4434.92f, 4698.64f, 4978.03f, 5274.04f, 5587.65f, 5919.91f, 6271.93f, 6644.88f,
7040.00f, 7458.62f, 7902.13f, 8372.02f, 8869.84f, 9397.27f, 9956.06f, 10548.08f, 11175.30f, 11839.82f, 12543.85f, 13289.75f
};



namespace io::atome::wavelet {
	static const Steinberg::FUID ProcessorUID(0xbc00f531, 0x19a89841, 0x612dcc8c, 0x45bbceed);
	static const Steinberg::FUID ControllerUID(0x2afcd1cb, 0x6defd15e, 0x239a1b9e, 0x86959eaf);
} // namespace