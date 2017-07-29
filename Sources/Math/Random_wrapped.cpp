#include <Kore/pch.h>
#include <Kore/System.h>
#include <Kore/Math/Random.h>

#include <stdlib.h>
#include <limits>

#include "../CWrapper.h"

#ifdef __cplusplus
extern "C" {
#endif

// Kore::Random::init
// void Kore_Random_init(int seed) {
void Kore_Random_init() {
  // Kore::Random::init(seed);
  Kore::Random::init(static_cast<int>(Kore::System::timestamp() % std::numeric_limits<int>::max()));
}

#ifdef __cplusplus
}
#endif
