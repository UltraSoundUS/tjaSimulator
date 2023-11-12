#include <Siv3D.hpp>  // Siv3D v0.6.12

#include "constants.hpp"
#include "doubleCircle.hpp"

using namespace Constants;

void Main() {
  // サイズの設定
  Scene::SetResizeMode(ResizeMode::Keep);
  Scene::Resize(1920, 600);

  // 背景色
  Scene::SetBackground(Palette::White);

  while (System::Update()) {
    // 判定部
    // TODO: 後ほど実装

    // 彩画部
    // 数字ベタ書きも多いが後々修正

    // レーン
    Rect{500, 100, 1420, 400}.draw(Color{44, 44, 44});
    // 判定枠
    Circle{617.5, 300, 50}.drawFrame(LineWidth::NoteEdge);
    Circle{617.5, 300, 50 * 5 / 3}.drawFrame(LineWidth::NoteEdge);

    // ノーツ
    for (int i = 0; i < 14; ++i) {
      auto color = (i / 2) % 2 == 0 ? NoteColor::Don : NoteColor::Ka;
      DoubleCircle{1920 - 88.75 * i, 300, 50}.draw(color);
    }

    // レーンの左
    Rect{0, 100, 500, 400}.draw(Palette::Black);
    Rect{0, 100 + LineWidth::RectEdge, 500 - LineWidth::RectEdge,
         400 - 2 * LineWidth::RectEdge}
        .draw(NoteColor::Don);
  }
}

//
// - Debug ビルド:
// プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力]
// ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー →
// [ソリューションのリビルド]）が必要な場合があります。
//
