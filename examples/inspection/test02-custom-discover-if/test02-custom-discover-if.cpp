#include <catch2/catch_test_macros.hpp>
#include <sysc/kernel/sc_simcontext.h>
#include <cci_inspection>


TEST_CASE("Custom discover if", "") {
  using discovery_if = cci::experimental::inspection::discovery_if;
  discovery_if *portal = cci::experimental::inspection::get_discovery_if(
      CCI_INSPECTION_API_VERSION);
  CHECK(portal->get_name() == "Custom CCI Discovery Interface");
}

extern "C" int sc_main(int argc, char **argv) { return 0; }
