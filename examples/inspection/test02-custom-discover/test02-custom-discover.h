#include <cci_inspection>

#include <string>

class custom_discovery_impl
    : public cci::experimental::inspection::discovery_if {
  using item_if = cci::experimental::inspection::item_if;

public:
  custom_discovery_impl()
      : m_name("Custom CCI Discovery Interface") {};

  virtual ~custom_discovery_impl() = default;

  std::string_view get_name() const { return m_name; }

  std::vector<std::shared_ptr<item_if>> get_items(std::string_view k) const {
    return std::vector<std::shared_ptr<item_if>>();
  }

  bool register_item(std::shared_ptr<item_if> item, std::string_view k) {
    return false;
  }

  bool unregister_item(std::shared_ptr<item_if> item, std::string_view k) {
    return false;
  }

private:
  std::string m_name;
};
