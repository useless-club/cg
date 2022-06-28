#ifndef CG_HPP
#define CG_HPP
#include <iostream>
#include <string>

namespace color {

constexpr auto black_fg = "30";
constexpr auto black_bg = "40";
constexpr auto red_fg = "31";
constexpr auto red_bg = "41";
constexpr auto green_fg = "32";
constexpr auto green_bg = "42";
constexpr auto yellow_fg = "33";
constexpr auto yellow_bg = "43";

constexpr auto blue_fg = "34";
constexpr auto blue_bg = "44";
constexpr auto magenta_fg = "35";
constexpr auto magenta_bg = "45";
constexpr auto cyan_fg = "36";
constexpr auto cyan_bg = "46";
constexpr auto white_fg = "37";
constexpr auto white_bg = "47";
} // namespace color

enum class option {
  reset = 0,
  bold = 1,
  underline = 4,
  inverse = 7,
  bold_off = 21,
  underline_off = 24,
  inverse_off = 27
};

std::string generate(std::string const &color1 = "",
                     std::string const &color2 = "",
                     option op = option::reset) {
  std::string _base = "\033[";
  _base += std::to_string(static_cast<int>(op));

  if (color1 != "")
    _base += ';' + color1;
  if (color2 != "")
    _base += ';' + color2;

  _base += 'm';
  return _base;
};

#endif // CG_HPP
