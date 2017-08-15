#include <Kore/pch.h>
#include <Kore/System.h>
#include <Kore/Math/Random.h>

#include <stdlib.h>
#include <limits>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

void Kore_Random_init() {
  Kore::Random::init(static_cast<int>(Kore::System::timestamp() % std::numeric_limits<int>::max()));
}

void Kore_Random_initSeed(int seed) {
  Kore::Random::init(seed);
}

s32 Kore_Random_get() {
	return Kore::Random::get();
}

s32 Kore_Random_getMax(s32 max) {
	return Kore::Random::get(max);
}

s32 Kore_Random_getMinMax(s32 min, s32 max) {
	return Kore::Random::get(min, max);
}

#ifdef __cplusplus
}
#endif
