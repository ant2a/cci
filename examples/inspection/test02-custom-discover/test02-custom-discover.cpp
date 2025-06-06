#include <catch2/catch_test_macros.hpp>
#include <sysc/kernel/sc_simcontext.h>
#include "test02-custom-discover.h"

cci::experimental::inspection::discovery_if *
cci::experimental::inspection::get_discovery_if(uint64_t api_version) {
  if (api_version != CCI_INSPECTION_API_VERSION) {
    return nullptr;
  }

  static custom_discovery_impl disc_impl;
  return &disc_impl;
}


TEST_CASE("Custom discover if", "") {
  using discovery_if = cci::experimental::inspection::discovery_if;
  discovery_if *portal = cci::experimental::inspection::get_discovery_if(
      CCI_INSPECTION_API_VERSION);
  CHECK(portal->get_name() == "Custom CCI Discovery Interface");
}

extern "C" int sc_main(int argc, char **argv) { return 0; }
