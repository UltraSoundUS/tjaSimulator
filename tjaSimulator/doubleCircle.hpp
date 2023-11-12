#pragma once
#include <Siv3D.hpp>  // Siv3D v0.6.12

// 二重円
// ノートで使うことを想定
struct DoubleCircle {
  double x;
  double y;
  double r;

  DoubleCircle(double x_, double y_, double r_) noexcept;

  const DoubleCircle& draw(const Color& color) const;
};
