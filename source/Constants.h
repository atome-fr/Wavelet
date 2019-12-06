#pragma once

#include <pluginterfaces/base/ftypes.h>

#define VERSION "0.0.0.1"
#define PLUGIN_NAME "Wavelet"
#define COMPANY_NAME "Atome.io"
#define COMPANY_URL "https://atome.io"
#define COMPANY_EMAIL "contact@atome.io"

namespace io::atome::wavelet {
	static const Steinberg::FUID ProcessorUID(0xbc00f531, 0x19a89841, 0x612dcc8c, 0x45bbceed);
	static const Steinberg::FUID ControllerUID(0x2afcd1cb, 0x6defd15e, 0x239a1b9e, 0x86959eaf);
} // namespace