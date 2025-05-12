#include <catch2/catch_test_macros.hpp>
#include <cci_inspection>
#include <memory>
#include <sysc/kernel/sc_simcontext.h>

#include <string>
#include <unordered_map>

using ::cci::experimental::inspection::CAP_NONE;
using ::cci::experimental::inspection::CAP_READ;
using ::cci::experimental::inspection::CAP_READWRITE;
using ::cci::experimental::inspection::CAP_WRITE;
using ::cci::experimental::inspection::capabilities;
using ::cci::experimental::inspection::item_if;

class custom_discovery_impl
    : public cci::experimental::inspection::discovery_if {
  using item_if = cci::experimental::inspection::item_if;

public:
  custom_discovery_impl()
      : m_name("Custom CCI Discovery Interface") {};

  ~custom_discovery_impl() = default;
  std::string_view get_name() const { return m_name; }

  std::vector<std::shared_ptr<item_if>> get_items(std::string_view k) const {
    return std::vector<std::shared_ptr<item_if>>();
  }

  bool register_item(std::shared_ptr<item_if> item, std::string_view k) {
    return true;
  }

  bool unregister_item(std::shared_ptr<item_if> item, std::string_view k) {
    return false;
  }

private:
  std::string m_name;
};

cci::experimental::inspection::discovery_if *
cci::experimental::inspection::get_discovery_if(uint64_t api_version) {
  if (api_version != CCI_INSPECTION_API_VERSION) {
    return nullptr;
  }

  static custom_discovery_impl disc_impl;
  return &disc_impl;
}

TEST_CASE("Weak link", "") {
  using discovery_if = ::cci::experimental::inspection::discovery_if;
  discovery_if *portal = ::cci::experimental::inspection::get_discovery_if(
      CCI_INSPECTION_API_VERSION);
  CHECK(portal->get_name() == "Custom CCI Discovery Interface");
}

extern "C" int sc_main(int argc, char **argv) { return 0; }
