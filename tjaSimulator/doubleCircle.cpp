#include "doubleCircle.hpp"

#include "constants.hpp"

using namespace Constants;

DoubleCircle::DoubleCircle(double x_, double y_, double r_) noexcept
    : x{x_}, y{y_}, r{r_} {}

const DoubleCircle& DoubleCircle::draw(const Color& color) const {
  Circle{x, y, r}.draw().drawFrame(LineWidth::NoteEdge, Palette::Black);
  Circle{x, y, 0.76 * r}.draw(color);

  return *this;
}
